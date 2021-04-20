#pragma once
#include "sandbird/sandbird.h"
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "shlwapi.lib")
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <map>
#include "Core_functions.h"

namespace http {
	int handler(sb_Event* evt);
	void run(int port, std::string ip, int w_port);
	extern std::map<const std::string, long long> cooldown = {
		
	};
}

std::string http_port = "";
std::string http_ip = "";
sb_Options options;
sb_Server* http_server;
string header_server_ip = "127.0.0.1";
int header_configPort = 17091;

std::string format(const char* msg, ...) {
	char fmt[1024] = { 0 };
	va_list va;
	va_start(va, msg);
	vsnprintf(fmt, 1024, msg, va);
	va_end(va);
	return std::string(fmt);
}

uint8_t* read_file(const char* file, uint32_t* size) {
	FILE* fp;
	fopen_s(&fp, file, "rb");
	if (!fp) {
		string file_name = file;
		SendConsole("Failed to read " + file_name + " returned 404", "ERROR");
		return nullptr;
	}
	fseek(fp, 0, SEEK_END);
	const uint32_t fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	uint8_t* data = static_cast<uint8_t*>(malloc(fsize));
	if (data) {
		memset(data, 0, fsize);
		fread(data, fsize, 1, fp);
		fclose(fp);
		if (size)
			*size = fsize;
		return data;
	}
	return nullptr;
}



int http::handler(sb_Event* evt) {
	if (evt->type == SB_EV_REQUEST) {
		string address = evt->address;
		string request = evt->method;
		if (strstr(evt->path, "/growtopia/server_data.php") != nullptr && request == "POST") {
			try {
				long long current_time = GetCurrentTimeInternalSeconds();
				sb_send_status(evt->stream, 200, "OK");
				sb_send_header(evt->stream, "Content-Type", "text/plain");
				string req_address = address;
				char reply[1024];
				string info = "server|" + header_server_ip + "\nport|" + to_string(header_configPort) + "\ntype|1\n#maint|`4Oh no! `oWait 0 seconds before logging in again!\nbeta_server|%s\nbeta_port|1945\nbeta_type|1\nmeta|ni.com\nRTENDMARKERBS1001\n";
				if (cooldown.find(address) == cooldown.end()) {
					goto ok;
				} else if (cooldown.at(address) > current_time) {
					info = "server|" + header_server_ip + "\nport|" + to_string(header_configPort) + "\ntype|1\nmaint|`4Oh no! `oWait " + to_string(cooldown.at(address) - current_time) + " seconds before logging in again!\nbeta_server|%s\nbeta_port|1945\nbeta_type|1\nmeta|ni.com\nRTENDMARKERBS1001\n";
					memcpy(reply, info.c_str(), info.size() + 1);
					sb_writef(evt->stream, format(reply, http_ip.c_str(), http_port.c_str(), http_ip.c_str()).c_str());
				} else {
				ok:
					if (cooldown.find(address) == cooldown.end()) {
						cooldown.insert({ address, (GetCurrentTimeInternalSeconds() + (6)) });
					} else {
						cooldown.at(address) = (GetCurrentTimeInternalSeconds() + (6));
					}
					memcpy(reply, info.c_str(), info.size() + 1);
					sb_writef(evt->stream, format(reply, http_ip.c_str(), http_port.c_str(), http_ip.c_str()).c_str());
				}
			} catch (const std::out_of_range& e) {
				cout << e.what() << endl;
			}
		} else if ((strstr(evt->path, "/game/") != NULL && request == "GET" || strstr(evt->path, "/social/") != NULL && request == "GET" || strstr(evt->path, "/interface/") != NULL && request == "GET" || strstr(evt->path, "/audio/") != NULL) && request == "GET") {
			uint32_t size = 0;
			const char* path = evt->path + 1;
			uint8_t* content = read_file(path, &size);
			if (content) {
				sb_send_status(evt->stream, 200, "OK");
				sb_send_header(evt->stream, "Content-Type", "application/x-www-form-urlencoded");
				sb_send_header(evt->stream, "Content-Length", format("%d", size).c_str());
				sb_send_header(evt->stream, "beserver", "06");
				sb_send_header(evt->stream, "Connection", "keep-alive");
				sb_send_header(evt->stream, "Accept-Ranges", "bytes");
				sb_write(evt->stream, content, size);
			} 
		} else if (strstr(evt->path, "/render/") != NULL && request == "GET") {
			string path = evt->path + 1;
			ifstream read_map(path);
			if (!read_map.is_open()) {
				return SB_RES_CLOSE;
			}
			std::stringstream sstr;
			while (read_map >> sstr.rdbuf());
			string test = sstr.str();
			sb_send_status(evt->stream, 200, "OK");
			sb_send_header(evt->stream, "Content-Type", "text/html");
			sb_writef(evt->stream, test.c_str());
		} else {
			return SB_RES_CLOSE;
		}
	}
	return SB_RES_OK;
}

#ifdef _WIN32
#include <Windows.h>
#endif

void util_sleep(int32_t ms) {
#ifdef _WIN32
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif

}
void http::run(int port, string ip, int w_port) {
	header_server_ip = ip;
	header_configPort = w_port;
	http_port = to_string(port);
	http_ip = "0.0.0.0";
	options.handler = handler;
	options.host = http_ip.c_str();
	options.port = http_port.c_str();
	http_server = sb_new_server(&options);
	if (!http_server) {
		SendConsole("HTTP failed to start service, is " + http_ip + ":" + http_port + " already running?", "HTTP");
		system("PAUSE");
		exit(0);
	} else {
		SendConsole("HTTP service started, listening on " + http_ip + ":" + http_port, "HTTP");
	} while (true) {
		sb_poll_server(http_server, 10);
		util_sleep(1);
	}
	sb_close_server(http_server);
}