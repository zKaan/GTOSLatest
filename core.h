#pragma once
#include "Core_functions.h"
#include <cctype>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <locale>
#include <string>
#include <time.h>
#include <vector>
#include "json.hpp"
#include <regex>
#include <thread>
#include <experimental/filesystem>
#include "enet/include/enet.h"
ENetPeer* proxy_peer;
ENetHost* client;
#define BlastProperties_Null 0
#define BlastProperties_RandomDeco1 1
#define BlastProperties_RandomDeco2 2
#define BlastProperties_WaterLevelD2 4
#define Property_Zero 0
#define Property_NoSeed 1
#define Property_Dropless 2
#define Property_Beta 4
#define Property_Mod 8
#define Property_Chemical 12
#define Property_Untradable 16
#define Property_Wrenchable 32
#define Property_MultiFacing 64
#define Property_Permanent 128
#define Property_AutoPickup 256
#define Property_WorldLock 512
#define Property_NoSelf 1024
bool loop_freeze = false;
#define Property_RandomGrow 2048
#define Property_Public 4096
#define Property_Foreground 8192
bool cout_cch = false;
#define Property_NoBlock 16384
typedef __int16 __int16_t;
#pragma warning(disable:4996)
using namespace std;
bool logs = false;
using namespace std::chrono;
using json = nlohmann::json;
bool wuplog = false;
string lastday = "";
bool autosave = true;
int maxItems = 0;
bool visibleparticles = true;
bool GlobalMaintenance = false;
int worldthreading = 12;
bool Connected = false;
int global_loop_tick = 0;
int loop_world = 0;
ENetHost* server;
int itemdathash = 0;
long long int lastSave = 0;
int coredatasize = 0;
int cId = 1;
BYTE* itemsDat = 0;
int itemsDatSize = 0;
int resultnbr1 = 0;
int resultnbr2 = 0;
int specialdrop = 0;
bool antiproxy = false;
bool clearpeer = true;
int hasil = 0;
int prize = 0;
int gem_multiplier = 0;
bool webhooks = true;
string server_discord = "";
vector<thread> threads;
vector<string> whitelist;
vector<string> creators;
bool serverIsFrozen = false;
vector<string> unknown_packets;
string server_name = "";
bool ServerIsBusy = false;
bool usedtinyblast = false;
bool usedlargeblast = false;
bool usedthermoblast = false;
bool usedcaveblast = false;
int genwidth = 0;
int genheight = 0;
int genforeground = 0;
int genbedrock = 0;
int genbackground = 0;
long long int quest = 0;
bool restartForUpdate = false;
long long int restartTime = 0;
unsigned short tipqueue = 0;
bool worldproperlock;
int serverhash;
int serverversion;
int serverport;
int serverrolecount;
bool HarvestEvent = false;
bool FarmingEvent = false;
bool GrowganothEvent = false;
bool ValentineEvent = false;
bool LunarEvent = false;
bool SuperpineappleEvent = false;
bool jammers = true;
bool WinterfestEvent = false;
bool SurgeryDay = false;
bool GeigerDay = false;
int DailyItem = 0;
int DailyItemCount = 0;
string CacheIP = "168.119.144.125";
string sip = "";
string suser = "";
string spass = "";
string server_ip = "127.0.0.1";
string server_website = "";
string server_email = "";
int configPort = 0;
string sdatabase = "";
#define cloth0 cloth_hair
#define cloth1 cloth_shirt
#define cloth2 cloth_pants
#define cloth3 cloth_feet
#define cloth4 cloth_face
#define cloth5 cloth_hand
#define cloth6 cloth_back
#define cloth7 cloth_mask
#define cloth8 cloth_necklace
#define cloth9 cloth_ances
#define STRINT(x, y) (*(int*)(&(x)[(y)]))
#define STR16(x, y) (*(uint16_t*)(&(x)[(y)]))
vector<string> guildmem;
vector<string> guildelder;
vector<string> guildco;
#define GetPeerData(peer) ((PlayerInfo*)(peer->data))
map<int, string> role_chat;
map<int, vector<string>> role_commands;
map<int, string> role_prefix;
map<string, int> role_name;
map<int, string> role_nameko;
map<int, int> custom_gem_block;
map<int, int> custom_drop_block;
map<int, int> custom_drop_chance;
map<int, int> item_multiplier;
map<int, bool> one_hit;
map<int, bool> triple_punch;
map<int, bool> triple_place;
map<int, bool> explosive;
map<int, int> break_effect;
map<int, string> dialogs;
vector<string> sub_commands{};

enum LabelStyles
{
	
	LABEL_BIG,
	LABEL_SMALL
};

enum SpacerTypes
{
	SPACER_BIG,
	SPACER_SMALL
};

enum CheckboxTypes
{
	CHECKBOX_SELECTED,
	CHECKBOX_NOT_SELECTED
};

struct AllStores
{
	string fg = "";
	string storeName = "";
	string whose = "";
	int notifications = 0;
};

inline void toUpperCase(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

inline void toLowerCase(std::string& str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

template <typename T>
void Remove(std::basic_string<T>& Str, const T* CharsToRemove)
{
	typename std::basic_string<T>::size_type pos = 0;
	while ((pos = Str.find_first_of(CharsToRemove, pos)) != std::basic_string<T>::npos)
	{
		Str.erase(pos, 1);
	}
}

inline string ReadAllFile(const string& fileName)
{
	const ifstream f(fileName);
	stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}

inline std::string currentDateTime()
{
	auto now = time(nullptr);
	struct tm tstruct;
	char buf[80];
	// ReSharper disable once CppDeprecatedEntity
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y/%m/%d %X", &tstruct);
	return buf;
}

inline void sendData(ENetPeer* peer, int num, char* data, const int len)
{
	const auto packet = enet_packet_create(nullptr, len + 5, ENET_PACKET_FLAG_RELIABLE);
	memcpy(packet->data, &num, 4);
	if (data != nullptr) {
		memcpy(packet->data + 2, data, len);
	}
	char zero = 0;
	memcpy(packet->data + 2 + len, &zero, 1);
	enet_peer_send(peer, 0, packet);
	//enet_host_flush(server);
}

inline void send_packet_proxy(ENetPeer* peer, string data, int iop = 2) {
	ENetPacket* v3 = enet_packet_create(nullptr, data.length() + 5, 1);
	memcpy(v3->data, &iop, 4);
	memcpy((v3->data) + 4, data.c_str(), data.length());
	enet_peer_send(peer, 0, v3);
}

inline int getPacketId(char* data)
{
	return *data;
}

inline char* getPacketData(char* data)
{
	return data + 4;
}

inline string space2underscore(std::string text)
{
	for (string::iterator it = text.begin(); it != text.end(); ++it)
	{
		if (*it == ' ')
		{
			*it = '_';
		}
	}
	return text;
}

inline void SendDiscordNotification(const string text, const string webhook) {
	const auto superrealtext = space2underscore(text);
	const auto themessage = "php system.php " + superrealtext + " " + webhook + "";
	const auto c = themessage.c_str();
	system(c);
}

string json_to_string(json info) {
	string new_data = info;
	return new_data;
}

int json_to_int(json info) {
	int new_data = info;
	return new_data;
}

bool json_to_bool(json info) {
	int new_data = info;
	if (new_data == 1) return true;
	return false;
}

string char_to_string(const char* info) {
	string new_data = info;
	return new_data;
}

struct gamepacket_t
{
private:
	int index = 0;
	int len = 0;
	byte* packet_data = new byte[61];

public:
	gamepacket_t(int delay = 0, int NetID = -1) {

		len = 61;
		int MessageType = 0x4;
		int PacketType = 0x1;
		int CharState = 0x8;

		memset(packet_data, 0, 61);
		memcpy(packet_data, &MessageType, 4);
		memcpy(packet_data + 4, &PacketType, 4);
		memcpy(packet_data + 8, &NetID, 4);
		memcpy(packet_data + 16, &CharState, 4);
		memcpy(packet_data + 24, &delay, 4);
	};
	~gamepacket_t() {
		delete[] packet_data;
	}

	void Insert(string a) {
		byte* data = new byte[len + 2 + a.length() + 4];
		memcpy(data, packet_data, len);
		delete[] packet_data;
		packet_data = data;
		data[len] = index;
		data[len + 1] = 0x2;
		int str_len = a.length();
		memcpy(data + len + 2, &str_len, 4);
		memcpy(data + len + 6, a.data(), str_len);
		len = len + 2 + a.length() + 4;
		index++;
		packet_data[60] = (byte)index;
	}
	void Insert(int a) {
		byte* data = new byte[len + 2 + 4];
		memcpy(data, packet_data, len);
		delete[] packet_data;
		packet_data = data;
		data[len] = index;
		data[len + 1] = 0x9;
		memcpy(data + len + 2, &a, 4);
		len = len + 2 + 4;
		index++;
		packet_data[60] = (byte)index;
	}
	void Insert(unsigned int a) {
		byte* data = new byte[len + 2 + 4];
		memcpy(data, packet_data, len);
		delete[] packet_data;
		packet_data = data;
		data[len] = index;
		data[len + 1] = 0x5;
		memcpy(data + len + 2, &a, 4);
		len = len + 2 + 4;
		index++;
		packet_data[60] = (byte)index;
	}
	void Insert(float a) {
		byte* data = new byte[len + 2 + 4];
		memcpy(data, packet_data, len);
		delete[] packet_data;
		packet_data = data;
		data[len] = index;
		data[len + 1] = 0x1;
		memcpy(data + len + 2, &a, 4);
		len = len + 2 + 4;
		index++;
		packet_data[60] = (byte)index;
	}
	void Insert(float a, float b) {
		byte* data = new byte[len + 2 + 8];
		memcpy(data, packet_data, len);
		delete[] packet_data;
		packet_data = data;
		data[len] = index;
		data[len + 1] = 0x3;
		memcpy(data + len + 2, &a, 4);
		memcpy(data + len + 6, &b, 4);
		len = len + 2 + 8;
		index++;
		packet_data[60] = (byte)index;
	}
	void Insert(float a, float b, float c) {
		byte* data = new byte[len + 2 + 12];
		memcpy(data, packet_data, len);
		delete[] packet_data;
		packet_data = data;
		data[len] = index;
		data[len + 1] = 0x4;
		memcpy(data + len + 2, &a, 4);
		memcpy(data + len + 6, &b, 4);
		memcpy(data + len + 10, &c, 4);
		len = len + 2 + 12;
		index++;
		packet_data[60] = (byte)index;
	}
	void CreatePacket(ENetPeer* peer) {
		ENetPacket* packet = enet_packet_create(packet_data, len, 1);
		enet_peer_send(peer, 0, packet);
	}
};
struct GamePacket {
	BYTE* data;
	int len;
	int indexes;
};

std::size_t number_of_files_in_directory(std::experimental::filesystem::path path)
{
    using std::experimental::filesystem::directory_iterator;
    return std::distance(directory_iterator(path), directory_iterator{});
}

inline void send_packet(ENetPeer* peer, const char* data)
{
	ENetPacket* packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
}

inline string text_encode(char* text)
{
	string ret = "";
	while (text[0] != 0)
	{
		switch (text[0])
		{
		case '\n':
			ret += "\\n";
			break;
		case '\t':
			ret += "\\t";
			break;
		case '\b':
			ret += "\\b";
			break;
		case '\\':
			ret += "\\\\";
			break;
		case '\r':
			ret += "\\r";
			break;
		default:
			ret += text[0];
			break;
		}
		text++;
	}
	return ret;
}

inline int ch2n(char x)
{
	switch (x)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	default:
		break;
	}
	return 0;
}

char* GetTextPointerFromPacket(ENetPacket* packet) {
	char zero = 0;
	memcpy(packet->data + packet->dataLength - 1, &zero, 1);
	return (char*)(packet->data + 4);
}

bool allCharactersSame(string s) {
	return (s.find_first_not_of("`") == string::npos);
}

inline BYTE* GetStructPointerFromTankPacket(ENetPacket* packet)
{
	const unsigned int packetLenght = packet->dataLength;
	BYTE* result = nullptr;
	if (packetLenght >= 0x3C)
	{
		BYTE* packetData = packet->data;
		result = packetData + 4;
		if (*static_cast<BYTE*>(packetData + 16) & 8)
		{
			if (packetLenght < *reinterpret_cast<int*>(packetData + 56) + 60)
			{
				result = nullptr;
			}
		}
		else
		{
			int zero = 0;
			memcpy(packetData + 56, &zero, 4);
		}
	}
	return result;
}

inline std::vector<std::string> split_into_lines(const std::string& string) {
	std::stringstream stream(string);
	std::vector<std::string> res;
	while (true) {
		std::string line;
		std::getline(stream, line);
		if (!stream.good())
			break;
		res.push_back(line);
	}
	return res;
}

inline int GetMessageTypeFromPacket(ENetPacket* packet) {
	int result = 0;
	if (packet->dataLength > 3u) {
		result = *(packet->data);
	}
	return result;
}

inline void CreateMessageBox123() {
	MessageBox(nullptr, "t", "a", MB_OKCANCEL);
}

inline vector<string> explode(const string& delimiter, const string& str)
{
	vector<string> arr{};
	const int strleng = str.length();
	const int delleng = delimiter.length();
	if (delleng == 0)
		return arr;
	int i = 0;
	int k = 0;
	while (i < strleng)
	{
		int j = 0;
		while (i + j < strleng && j < delleng && str[i + j] == delimiter[j])
			j++;
		if (j == delleng)
		{
			arr.push_back(str.substr(k, i - k));
			i += delleng;
			k = i;
		}
		else
		{
			i++;
		}
	}
	arr.push_back(str.substr(k, i - k));
	return arr;
}

inline string getStrLower(string txt)
{
	string ret;
	for (char c : txt) ret += tolower(c);
	return ret;
}

inline string getStrUpper(string txt)
{
	string ret;
	for (char c : txt) ret += toupper(c);
	return ret;
}

inline bool has_only_digits(const string s)
{
	return s.find_first_not_of("0123456789") == string::npos;
}

inline bool has_only_digits_wnegative(const string s)
{
	return s.find_first_not_of("-0123456789") == string::npos;
}

static inline void ltrim(string& s)
{
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch)
	{
		return !isspace(ch);
	}));
}

static inline void rtrim(string& s)
{
	s.erase(find_if(s.rbegin(), s.rend(), [](int ch)
	{
		return !isspace(ch);
	}).base(), s.end());
}

static inline void trim(string& s)
{
	ltrim(s);
	rtrim(s);
}

static inline string trimString(string s)
{
	trim(s);
	return s;
}

inline int countSpaces(string& str)
{
	auto count = 0;
	try {
		const int length = str.length();
		for (auto i = 0; i < length; i++)
		{
			const int c = str.at(i);
			if (isspace(c))
				count++;
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return count;
}

inline void removeExtraSpaces(string& str)
{
	try {
		const int n = str.length();
		auto i = 0, j = -1;
		auto spaceFound = false;
		while (++j < n && str.at(j) == ' ');
		while (j < n)
		{
			if (str.at(j) != ' ')
			{
				if ((str.at(j) == '.' || str.at(j) == ',' || str.at(j) == '?') && i - 1 >= 0 && str.at(i - 1) == ' ')
					str.at(i - 1) = str.at(j++);
				else
					str.at(i++) = str.at(j++);
				spaceFound = false;
			}
			else if (str.at(j++) == ' ')
			{
				if (!spaceFound)
				{
					str.at(i++) = ' ';
					spaceFound = true;
				}
			}
		}
		if (i <= 1)
			str.erase(str.begin() + i, str.end());
		else
			str.erase(str.begin() + i, str.end());
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline ifstream::pos_type filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

inline uint32_t HashString(unsigned char* str, const int len)
{
	if (!str) return 0;
	auto n = static_cast<unsigned char*>(str);
	uint32_t acc = 0x55555555;
	if (len == 0)
	{
		while (*n)
			acc = (acc >> 27) + (acc << 5) + *n++;
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			acc = (acc >> 27) + (acc << 5) + *n++;
		}
	}
	return acc;
}

inline unsigned char* getA(const string fileName, int* pSizeOut, bool bAddBasePath, bool bAutoDecompress)
{
	// ReSharper disable once CppDeprecatedEntity
	const auto fp = fopen(fileName.c_str(), "rb");
	if (!fp)
	{
		SendConsole("File not found (getA)", "ERROR");
		if (!fp) return nullptr;
	}
	fseek(fp, 0, SEEK_END);
	*pSizeOut = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	const auto pData = static_cast<unsigned char*>(new unsigned char[((*pSizeOut) + 1)]);
	if (!pData)
	{
		printf("Out of memory opening %s?", fileName.c_str());
		return nullptr;
	}
	pData[*pSizeOut] = 0;
	fread(pData, *pSizeOut, 1, fp);
	fclose(fp);
	return pData;
}

inline string hexStr(BYTE* data, int len)
{
	std::stringstream ss;
	ss << std::hex;
	for (auto i(0); i < len; ++i)
	{
		ss << std::hex << std::setfill('0');
		ss << std::setw(2) << static_cast<int>(data[i]);
	}
	return ss.str();
}

class GTDialog
{
public:
	string dialogstr = "";
	void appendStart();
	void addSpacer(SpacerTypes type);
	void addLabelWithIcon(string text, int tileid, LabelStyles type);
	void addLabelWithIconButton(string text, int tileid, string buttontext);
	void addButton(string buttonname, string buttontext);
	void addPicker(string pickername, string pickertext, string headText);
	void addCheckbox(string checkboxname, string string, CheckboxTypes type);
	void addTextBox(string str);
	void addSmallText(string str);
	void addItemWithCustomText(string itemID, string textUnderButton, string buttonName);
	void addStaticBlueFrame(string itemID, string textUnderFrame, string buttonName, bool isEndLine);
	void addInputBox(string name, string text, string cont, int size);
	void addStaticBlueFrameWithIdCountText(string itemID, string count, string textUnderFrame, string buttonName, bool isEndLine);
	void addQuickExit();
	void addNewLineAfterFrame();
	void endDialog(string name, string accept, string nvm);
	void addCustom(string name);
	string finishDialog() const;

	explicit operator string() const
	{
		return this->dialogstr;
	}
};

inline void GTDialog::addSpacer(const SpacerTypes type)
{
	switch (type)
	{
	case SPACER_BIG:
		this->dialogstr.append("add_spacer|big|\n");
		break;
	case SPACER_SMALL:
		this->dialogstr.append("add_spacer|small|\n");
		break;
	default:
		break;
	}
}

inline void GTDialog::addItemWithCustomText(const string itemID, const string textUnderButton, const string buttonName)
{
	this->dialogstr.append("\nadd_button_with_icon|" + buttonName + "|" + textUnderButton + "|staticBlueFrame|" + itemID + "|");
}

inline void GTDialog::addNewLineAfterFrame()
{
	this->dialogstr.append("\nadd_button_with_icon||END_LIST|noflags|0|0|");
}

inline void GTDialog::addPicker(const string pickername, const string pickertext, const string headText)
{
	this->dialogstr.append("\nadd_item_picker|" + pickername + "|" + pickertext + "|" + headText + "|");
}

inline void GTDialog::addStaticBlueFrame(const string itemID, const string textUnderFrame, const string buttonName, const bool isEndLine)
{
	if (isEndLine == false)
	{
		this->dialogstr.append("\nadd_button_with_icon|" + buttonName + "||staticBlueFrame|" + itemID + "|" + textUnderFrame + "|");
	}
	else
	{
		this->dialogstr.append("\nadd_button_with_icon||END_LIST|noflags|0|0|\nadd_button_with_icon|" + buttonName + "||staticBlueFrame|" + itemID + "|" + textUnderFrame + "|");
	}
}

inline void GTDialog::addStaticBlueFrameWithIdCountText(const string itemID, string count, const string textUnderFrame, const string buttonName, const bool isEndLine)
{
	if (isEndLine == false)
	{
		this->dialogstr.append("\nadd_button_with_icon|" + buttonName + "|" + textUnderFrame + "|frame|" + itemID + "|" + count + "|");
	}
	else
	{
		this->dialogstr.append("\nadd_button_with_icon||END_LIST|noflags|0|0|\nadd_button_with_icon|" + buttonName + "|" + textUnderFrame + "|frame|" + itemID + "|" + count + "|");
	}
}

inline void GTDialog::addLabelWithIcon(const string text, const int tileid, const LabelStyles type)
{
	switch (type)
	{
	case LABEL_BIG:
		this->dialogstr.append("add_label_with_icon|big|" + text + "|left|" + to_string(tileid) + "|\n");
		break;
	case LABEL_SMALL:
		this->dialogstr.append("add_label_with_icon|small|" + text + "|left|" + to_string(tileid) + "|\n");
		break;
	default:
		break;
	}
}

inline void GTDialog::addLabelWithIconButton(const string text, const int tileid, const string buttontext)
{
	this->dialogstr.append("add_label_with_icon_button|mid|" + text + "|left|" + to_string(tileid) + "|" + buttontext + "|\n");
}

inline void GTDialog::addButton(const string buttonname, const string buttontext)
{
	this->dialogstr.append("add_button|" + buttonname + "|" + buttontext + "|noflags|0|0|\n");
}

inline void GTDialog::addCheckbox(const string checkboxname, const string string, const CheckboxTypes type)
{
	switch (type)
	{
	case CHECKBOX_SELECTED:
		this->dialogstr.append("add_checkbox|" + checkboxname + "|" + string + "|1|\n");
		break;
	case CHECKBOX_NOT_SELECTED:
		this->dialogstr.append("add_checkbox|" + checkboxname + "|" + string + "|0|\n");
		break;
	default:
		break;
	}
}

inline void GTDialog::appendStart()
{
	this->dialogstr.append("text_scaling_string|Dirttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt|\nset_default_color|\n");	
}

inline void GTDialog::addTextBox(const string str)
{
	this->dialogstr.append("add_textbox|" + str + "|left|\n");
}

inline void GTDialog::addSmallText(const string str)
{
	this->dialogstr.append("add_smalltext|" + str + "|\n");
}

inline void GTDialog::addInputBox(const string name, const string text, const string cont, const int size)
{
	this->dialogstr.append("add_text_input|" + name + "|" + text + "|" + cont + "|" + to_string(size) + "|\n");
}

inline void GTDialog::addQuickExit()
{
	this->dialogstr.append("add_quick_exit|\n");
}

inline void GTDialog::endDialog(const string name, const string accept, const string nvm)
{
	this->dialogstr.append("end_dialog|" + name + "|" + nvm + "|" + accept + "|\n");
}

inline void GTDialog::addCustom(const string name)
{
	this->dialogstr.append(name + "\n");
}

inline string GTDialog::finishDialog() const
{
	return this->dialogstr;
}

inline bool world_exist(string name) {
	return experimental::filesystem::exists("save/worlds/_" + name + ".json");
}

inline json toJson(const char* jsonString) {
	json jsonObj;
	std::stringstream(jsonString) >> jsonObj;
	return jsonObj;
}

inline string JsonToString(json data) {
	stringstream JsonConvert;
	JsonConvert << data;
	string DataNew = JsonConvert.str();
	return DataNew;
}
