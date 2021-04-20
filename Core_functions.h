#pragma once
#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <chrono>
using namespace std::chrono;
using namespace std;
#pragma warning(disable : 4996)



inline long long GetCurrentTimeInternalSeconds() {
	return (duration_cast<seconds>(system_clock::now().time_since_epoch())).count();
}

inline void SendConsole(const string text, const string type) {
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 15;
	if (type == "INFO") {
		k = 10;
	} else if (type == "WARN") {
		k = 14;
	} else if (type == "ERROR") {
		k = 12;
	} else if (type == "HTTP") {
		k = 13;
	} else if (type == "MYSQL") {
		k = 11;
	} else if (type == "CHAT") {
		k = 15;
	}
	SetConsoleTextAttribute(hConsole, k);
	cout << "[" + type + "]: " << text << endl;
}