#pragma once
#include <cctype>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <fstream>
#include <iomanip>
#include <regex>
#include <iostream>
#include <locale>
#include <sstream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include "proton/hash.hpp"
#include "proton/variant.hpp"
bool disconnected = true;
using namespace std;
int m_user = 0;
int m_token = 0;
string m_server = "213.179.209.168";
int m_port = 17198;
#define MALLOC(type, ...) (type*)(malloc(sizeof(type) __VA_ARGS__))
#define PRINTS(msg, ...) printf("[SERVER]: " msg, __VA_ARGS__);
class player {
public:
	std::string name{};
	std::string country{};
	int netid = -1;
	int userid = -1;
	vector2_t pos{};
	bool invis{};
	bool mod{};
	player() {

	}
	bool operator==(const player& right) const
	{
		return netid == right.netid && userid == right.userid;
	}
	player(std::string name, int netid, int uid) {
		this->name = name;
		this->netid = netid;
		this->userid = uid;
	}
};
class world {
public:
	std::string name{};
	int width;
	int height;
	int tiles_count;
	std::vector<player> players{};
	player local{};
	bool connected{};
};
world m_world;

const std::string emptyString = "";
std::string ExtractString(std::string source, std::string start, std::string end)
{
	std::size_t startIndex = source.find(start);

	// If the starting delimiter is not found on the string
	// stop the process, you're done!
	//
	if (startIndex == std::string::npos)
	{
		return emptyString;
	}

	// Adding the length of the delimiter to our starting index
	// this will move us to the beginning of our sub-string.
	//
	startIndex += start.length();

	// Looking for the end delimiter
	//
	const std::string::size_type endIndex = source.find(end, startIndex);

	// Returning the substring between the start index and
	// the end index. If the endindex is invalid then the
	// returned value is empty string.
	return source.substr(startIndex, endIndex - startIndex);
}

inline void SendConsoleProxy(string text, const string type) {
	if (text.find("[CB]") != string::npos || text.find("[SB]") != string::npos || text.find("[BC]") != string::npos) {
		string output = "";
		if (text.find("[CB]") != string::npos) {
			output = ExtractString(text, "[```$", "```#]");
		} else if (text.find("[SB]") != string::npos) {
			output = ExtractString(text, "[```$", "```5]");
		} else if (text.find("[BC]") != string::npos) {
			output = ExtractString(text, "[```$", "```p]");
		}
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (static_cast<PlayerInfo*>(currentPeer->data)->radio) {
				Player::OnConsoleMessage(currentPeer, text);
				static_cast<PlayerInfo*>(currentPeer->data)->lastSbbWorld = output;
				Player::PlayAudio(currentPeer, "audio/beep.wav", 0);
			}
		}
	}
	time_t currentTime;
	time(&currentTime);
	const auto localTime = localtime(&currentTime);
	const auto Hour = localTime->tm_hour;
	const auto Min = localTime->tm_min;
	const auto Sec = localTime->tm_sec;
	cout << "[" + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec) + " " + type + """]: " << text << endl;
}

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

#define fnv32(s) (cexpr<uint32_t, hs::hash32(s)>::value)

#define get_packet_type(packet) (packet->dataLength > 3 ? *packet->data : 0)

#define PRINTC(msg, ...) printf(__VA_ARGS__);



enum {
	PACKET_STATE = 0,
	PACKET_CALL_FUNCTION,
	PACKET_UPDATE_STATUS,
	PACKET_TILE_CHANGE_REQUEST,
	PACKET_SEND_MAP_DATA,
	PACKET_SEND_TILE_UPDATE_DATA,
	PACKET_SEND_TILE_UPDATE_DATA_MULTIPLE,
	PACKET_TILE_ACTIVATE_REQUEST,
	PACKET_TILE_APPLY_DAMAGE,
	PACKET_SEND_INVENTORY_STATE,
	PACKET_ITEM_ACTIVATE_REQUEST,
	PACKET_ITEM_ACTIVATE_OBJECT_REQUEST,
	PACKET_SEND_TILE_TREE_STATE,
	PACKET_MODIFY_ITEM_INVENTORY,
	PACKET_ITEM_CHANGE_OBJECT,
	PACKET_SEND_LOCK,
	PACKET_SEND_ITEM_DATABASE_DATA,
	PACKET_SEND_PARTICLE_EFFECT,
	PACKET_SET_ICON_STATE,
	PACKET_ITEM_EFFECT,
	PACKET_SET_CHARACTER_STATE,
	PACKET_PING_REPLY,
	PACKET_PING_REQUEST,
	PACKET_GOT_PUNCHED,
	PACKET_APP_CHECK_RESPONSE,
	PACKET_APP_INTEGRITY_FAIL,
	PACKET_DISCONNECT,
	PACKET_BATTLE_JOIN,
	PACKET_BATTLE_EVEN,
	PACKET_USE_DOOR,
	PACKET_SEND_PARENTAL,
	PACKET_GONE_FISHIN,
	PACKET_STEAM,
	PACKET_PET_BATTLE,
	PACKET_NPC,
	PACKET_SPECIAL,
	PACKET_SEND_PARTICLE_EFFECT_V2,
	GAME_ACTIVE_ARROW_TO_ITEM,
	GAME_SELECT_TILE_INDEX
};

enum {
	NET_MESSAGE_UNKNOWN = 0,
	NET_MESSAGE_SERVER_HELLO,
	NET_MESSAGE_GENERIC_TEXT,
	NET_MESSAGE_GAME_MESSAGE,
	NET_MESSAGE_GAME_PACKET,
	NET_MESSAGE_ERROR,
	NET_MESSAGE_TRACK,
	NET_MESSAGE_CLIENT_LOG_REQUEST,
	NET_MESSAGE_CLIENT_LOG_RESPONSE,
};

struct gameupdatepacket_t {
	uint8_t m_type;
	uint8_t m_netid;
	uint8_t m_jump_amount;
	uint8_t m_count;
	int32_t m_player_flags;
	int32_t m_item;
	int32_t m_packet_flags;
	float m_struct_flags;
	int32_t m_int_data;
	float m_vec_x;
	float m_vec_y;
	float m_vec2_x;
	float m_vec2_y;
	float m_particle_time;
	uint32_t m_state1;
	uint32_t m_state2;
	uint32_t m_data_size;
	uint32_t m_data;
};

namespace events {

	namespace out {
		bool variantlist(gameupdatepacket_t* packet);
		bool pingreply(gameupdatepacket_t* packet);
		bool generictext(std::string packet);
		bool gamemessage(std::string packet);
		bool state(gameupdatepacket_t* packet);

	}; // namespace out
	namespace in {
		bool variantlist(gameupdatepacket_t* packet);
		bool generictext(std::string packet);
		bool gamemessage(std::string packet);
		bool sendmapdata(gameupdatepacket_t* packet);
		bool state(gameupdatepacket_t* packet);
		bool tracking(std::string packet);
	}; // namespace in
};

typedef struct gametankpacket_t {
	int32_t m_type;
	char m_data;
} gametextpacket_t;

namespace utils {
	char* get_text(ENetPacket* packet);
	gameupdatepacket_t* get_struct(ENetPacket* packet);
	int random(int min, int max);
	std::string generate_rid();
	uint32_t hash(uint8_t* str, uint32_t len);
	std::string generate_mac(const std::string& prefix = "02");
	std::string hex_str(unsigned char data);
	std::string random(uint32_t length);
	__forceinline uint8_t* get_extended(gameupdatepacket_t* packet) {
		return reinterpret_cast<uint8_t*>(&packet->m_data_size);
	}
	__forceinline uint32_t* get_extended_big(gameupdatepacket_t* packet) {
		return reinterpret_cast<uint32_t*>(&packet->m_data_size);
	}
	__forceinline uint16_t* get_extended_16(gameupdatepacket_t* packet) {
		return reinterpret_cast<uint16_t*>(&packet->m_data_size);
	}
	bool replace(std::string& str, const std::string& from, const std::string& to);
	bool is_number(const std::string& s);
} // namespace utils

char* utils::get_text(ENetPacket* packet) {
	gametankpacket_t* tank = reinterpret_cast<gametankpacket_t*>(packet->data);
	memset(packet->data + packet->dataLength - 1, 0, 1);
	return static_cast<char*>(&tank->m_data);
}

gameupdatepacket_t* utils::get_struct(ENetPacket* packet) {
	if (packet->dataLength < sizeof(gameupdatepacket_t) - 4)
		return nullptr;
	gametankpacket_t* tank = reinterpret_cast<gametankpacket_t*>(packet->data);
	gameupdatepacket_t* gamepacket = reinterpret_cast<gameupdatepacket_t*>(packet->data + 4);
	if (gamepacket->m_packet_flags & 8) {
		if (packet->dataLength < gamepacket->m_data_size + 60) {
			printf("got invalid packet. (too small)\n");
			return nullptr;
		}
		return reinterpret_cast<gameupdatepacket_t*>(&tank->m_data);
	}
	else
		gamepacket->m_data_size = 0;
	return gamepacket;
}

void proxy_send(variantlist_t& list, int32_t netid = -1, int32_t delay = 0) {

	uint32_t data_size = 0;
	void* data = list.serialize_to_mem(&data_size, nullptr);

	//optionally we wouldnt allocate this much but i dont want to bother looking into it
	auto update_packet = MALLOC(gameupdatepacket_t, +data_size);
	auto game_packet = MALLOC(gametextpacket_t, +sizeof(gameupdatepacket_t) + data_size);

	if (!game_packet || !update_packet)
		return;

	memset(update_packet, 0, sizeof(gameupdatepacket_t) + data_size);
	memset(game_packet, 0, sizeof(gametextpacket_t) + sizeof(gameupdatepacket_t) + data_size);
	game_packet->m_type = NET_MESSAGE_GAME_PACKET;

	update_packet->m_type = PACKET_CALL_FUNCTION;
	update_packet->m_player_flags = netid;
	update_packet->m_packet_flags |= 8;
	update_packet->m_int_data = delay;
	memcpy(&update_packet->m_data, data, data_size);
	update_packet->m_data_size = data_size;
	memcpy(&game_packet->m_data, update_packet, sizeof(gameupdatepacket_t) + data_size);
	free(update_packet);

	const auto packet = enet_packet_create(game_packet, data_size + sizeof(gameupdatepacket_t), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(proxy_peer, 0, packet);
	enet_host_flush(client);
	free(game_packet);
}

inline void disconnect() {
	disconnected = true;
	enet_peer_disconnect(proxy_peer, 0);
	enet_host_destroy(client);
	client = nullptr;
}

inline void connect_to_proxy() {
	SendConsoleProxy("Connecting to growtopia1.com (ip=" + m_server + ";port=" + to_string(m_port) + ")", "INFO");
	client = enet_host_create(nullptr, 1, 2, 0, 0);
	if (!client) {
		SendConsoleProxy("Failed to start reverse proxy server", "ERROR");
		return;
	}
	client->checksum = enet_crc32;
	const auto code = enet_host_compress_with_range_coder(client);
	if (code != 0)
		SendConsoleProxy("enethost compressing failed", "ERROR");
	enet_host_flush(client);
	SendConsoleProxy("Started reverse proxy", "INFO");
	ENetAddress addressproxy;
	enet_address_set_host(&addressproxy, m_server.c_str());
	addressproxy.port = m_port;
	proxy_peer = enet_host_connect(client, &addressproxy, 2, 0);
	disconnected = false;
	return;
}

void redirect_server(variantlist_t& varlist) {
	m_port = varlist[1].get_uint32();
	m_token = varlist[2].get_uint32();
	m_user = varlist[3].get_uint32();
	auto str = varlist[4].get_string();
	auto doorid = str.substr(str.find("|"));
	m_server = str.erase(str.find("|")); 
	SendConsoleProxy("Sub-Server switching to " + m_server + ":" + to_string(m_port), "INFO");
	proxy_send(varlist);
	disconnect();
	connect_to_proxy();
}

bool events::in::variantlist(gameupdatepacket_t* packet) {
	variantlist_t varlist{};
	auto extended = utils::get_extended(packet);
	extended += 4; //since it casts to data size not data but too lazy to fix this
	varlist.serialize_from_mem(extended);
	const auto func = varlist[0].get_string();

	//probably subject to change, so not including in switch statement.

	switch (hs::hash32(func.c_str())) {
		//solve captcha

	case fnv32("OnConsoleMessage"): {
		const auto content = varlist[1].get_string();
		SendConsoleProxy(content, "CHAT");
		return true;
	} break;
	case fnv32("OnDialogRequest"): {
		auto content = varlist[1].get_string();
		//SendConsoleProxy(content, "CHAT");
		return true;
	} break;
	case fnv32("OnSendToServer"):
	{
		redirect_server(varlist);
		break;
	}
	}
	return false;
}

bool events::in::sendmapdata(gameupdatepacket_t* packet) {
	return false;
}

bool events::in::state(gameupdatepacket_t* packet) {
	return false;
}

bool events::in::tracking(std::string packet) {
	return true;
}

bool events::in::gamemessage(std::string packet) {
	return false;
}

bool events::out::generictext(std::string packet) {
	return false;
}

bool events::in::generictext(std::string packet) {
	return false;
}

bool events::out::gamemessage(std::string packet) {
	if (packet == "action|quit") {
		//g_server->quit();
		return true;
	}

	return false;
}

inline string getProperName(string name) {
	string newS;
	for (auto c : name) newS += (c >= 'A' && c <= 'Z') ? c - ('A' - 'a') : c;
	string ret;
	for (auto i = 0; i < newS.length(); i++)
	{
		if (newS[i] == '`') i++;
		else ret += newS[i];
	}
	string ret2;
	for (auto c : ret) if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) ret2 += c;
	return ret2;
}

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

void handle_incoming() {
	ENetEvent event;
	while (enet_host_service(client, &event, 0) > 0) {
		switch (event.type) {
		case ENET_EVENT_TYPE_CONNECT:
		{
			send_packet_proxy(proxy_peer, "tankIDName|Dragerc\ntankIDPass|t0ky04life\nrequestedName|BraveSmell\nf|1\nprotocol|121\ngame_version|3.56\nfz|7248232\nlmode|1\ncbits|0\nplayer_age|57\nGDPR|1\nhash2|-235265705\nmeta|ni.com\nfhash|-716928004\nrid|015914CB09114641005BEE760D7D8BF8\nplatformID|0\ndeviceVersion|0\ncountry|us\nhash|382353116\nmac|9c:fc:e8:e5:63:93\nuser|" + to_string(m_user) + "\ntoken|" + to_string(m_token) + "\nwk|E60FBF2FF3B5B5D3781FBBB4B1A67210\nzf|-2144598778");
			send_packet_proxy(proxy_peer, "action|enter_game");
			break;
		}
		case ENET_EVENT_TYPE_RECEIVE:
		{
			if (event.packet->data)
			{
				const auto packet_type = get_packet_type(event.packet);
				switch (packet_type)
				{
				case NET_MESSAGE_GENERIC_TEXT:
					if (events::in::generictext(utils::get_text(event.packet))) {
						enet_packet_destroy(event.packet);
						return;
					}
					break;
				case NET_MESSAGE_GAME_MESSAGE:
					if (events::in::gamemessage(utils::get_text(event.packet))) {
						enet_packet_destroy(event.packet);
						return;
					}
					break;
				case NET_MESSAGE_GAME_PACKET:
				{
					auto* packet = utils::get_struct(event.packet);
					if (!packet)
						break;

					switch (packet->m_type) {
					case PACKET_CALL_FUNCTION:
						if (events::in::variantlist(packet))
						{
							enet_packet_destroy(event.packet);
							return;
						}
						break;

					case PACKET_SEND_MAP_DATA:
						if (events::in::sendmapdata(packet))
						{
							enet_packet_destroy(event.packet);
							return;
						}
						break;

					case PACKET_STATE:
						if (events::in::state(packet))
						{
							enet_packet_destroy(event.packet);
							return;
						}
						break;
					default: break;
					}
				} break;
				case NET_MESSAGE_TRACK:
					if (events::in::tracking(utils::get_text(event.packet))) {
						enet_packet_destroy(event.packet);
						return;
					}
					break;
				case NET_MESSAGE_CLIENT_LOG_REQUEST: return;

				default: {
					break;
				}
				}
			}
			if (!client)
				return;
			enet_peer_send(proxy_peer, 0, event.packet);
			enet_host_flush(client);
		} break;
		default: PRINTS("UNKNOWN event: %d\n", event.type); break;
		}
	}
}

inline void listener() {
	connect_to_proxy();
	while (true && !disconnected) {
		handle_incoming();
		Sleep(1);
	}
}
