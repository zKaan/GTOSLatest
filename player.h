#pragma once
#include "core.h"

struct InventoryItem {
	__int16_t itemID;
	__int16_t itemCount;
};

struct PlayerInventory {
	vector<InventoryItem> items;
};

struct TradeItem {
	int id;
	int count;
};

struct PlayerInfo {
	int rift_cape_r = 1;
	int rift_cape_g = 1;
	int rift_cape_b = 1;
	int rift_collar_r = 1;
	int rift_collar_g = 1;
	int rift_collar_b = 1;
	int rift_type = 0;
	int rift_cape_color = 111255;
	int rift_collar_color = 111255;
	int geigerx = 64;
	int geigery = 64;
	string lastnormalworld = "";
	bool passed_data_check = false;
	string NickPrefix = "";
	bool Fishing = false;
	bool TriggerFish = false;
	int FishPosX = 0;
	int timeBanned = 0;
	int FishPosY = 0;
	string LastBait = "None";
	string zf = "";
	int magplantitemid = 0;
	int weather = 0;
	int magplantx = 0;
	int magplanty = 0;
	string suckername = "";
	int suckerid = 0;
	string email = "";
	bool HasLogged = false;
	bool GemBuffDrop = false;
	bool PunchPotion = false;
	int usedPunchPotion = 0;
	int last_ban_days = 0;
	int last_ban_hours = 0;
	int last_ban_minutes = 0;
	string last_ban_reason = "";
	int lastPunchPotion = 0;
	bool PlacePotion = false;
	int usedPlacePotion = 0;
	int lastPlacePotion = 0;
	bool isDr = false;
	bool quest_active = false;
	string chatcolor = "";
	bool Growid = false;
	int wrenchedBlockLocation = -1;
	int displayfg = 0;
	int displaybg = 0;
	int displaypunchx = 0;
	int LastX = 0;
	bool UpdateFinisheds = true;
	int LastY = 0;
	int displaypunchy = 0;
	int SubscribtionEndDay = 0;
	string subtype = "";
	string subdate = "";
	int lastdailyGems = 0;
	int packetinsec = 0;
	long long int packetsec = 0;
	int timeTogetToken = 0;
	int trashgemmeritem = 0;
	int bootybreaken = 0;
	string OriName = "";
	int wrenchx = 0;
	int wrenchy = 0;
	long long int lastdealchange = 0;
	long long int lastSPIN = 0;
	int lastdroppeditemid = 0;
	int lastPunchX = -1;
	string lastvendbuycount = "";
	int laststorebuyprice = 0;
	int laststorebuyid = 0;
	int laststorebuycount = 0;
	int laststoresellworldlocks = 0;
	int laststoreselldiamondlocks = 0;
	int laststoresellid = 0;
	int laststoresellcount = 0;
	bool blockLogin = false;
	int lastPunchY = -1;
	int lastPunchForeground = 0;
	int totalpunch = 0;
	int lastPunchBackground = 0;
	bool usedCP = false;
	int TotalKills = 0;
	string sid = "none";
	bool isIn = false;
	string notebook = "";
	string lastquest = "";
	string choosing_quest = "";
	int netID = 0;
	long long int startedTest = 0;
	string Chatname = "";
	bool Subscriber = false;
	int lastdropitemcount = 0;
	int lastdropitem = 0;
	int quest_step = 1;
	int lasttrashitem = 0;
	int quest_progress = 0;
	int lasttrashitemcount = 0;
	int wrenchsession = 0;
	bool ZiuriIKaire = false;
	bool haveGrowId = false;
	bool needsaveinventory = false;
	int lavaLevel = 0;
	bool RotatedLeft = false;
	bool isRotatedLeft = false;
	string tankIDName = "";
	string tankIDPass = "";
	string requestedName = "";
	string rawName = "";
	int warns = 0;
	int bans = 0;
	string lastworld = "";
	string displayName = "";
	int guildBg = 0;
	int guildFg = 0;
	string guildStatement = "";
	string guildLeader = "";
	string displayNamebackup = "";
	string displayUsername = "";
	vector<string> guildmatelist;
	vector<string> guildMembers;
	vector<string> worldsowned;
	vector<string> lastworlds;
	int guildlevel = 0;
	int guildexp = 0;
	bool isinvited = false;
	string createGuildName = "";
	string createGuildStatement = "";
	string createGuildFlagBg = "";
	string createGuildFlagFg = "";
	string guild = "";
	int guild_rank = 0;
	string lastgm = "";
	string lastgmname = "";
	string lastgmworld = "";
	string guildlast = "";
	string msgName = "";
	bool isNicked = false;
	string country = "";
	string gameversion = "";
	string rid = "none";
	string gid = "none";
	string aid = "none";
	bool ltitle = false;
	bool ltitleunlocked = false;
	string vid = "none";
	string wkid = "";
	string metaip = "";
	string hash2 = "";
	string hash = "";
	string fhash = "";
	string mac = "none";
	string token = "";
	string user = "";
	string deviceversion = "";
	string doorID = "";
	string cbits = "";
	string lmode = "";
	string gdpr = "";
	string f = "";
	string fz = "";
	string hpid = "";
	string platformID = "";
	string player_age = "1";
	int adminLevel = 0;
	vector<TradeItem> tradeItems{};
	bool trade = false;
	int trade_netid = -1;
	bool trade_accept = false;
	bool trade_confirmed = false;
	string currentWorld = "EXIT";
	bool radio = true;
	int x = 0;
	int y = 0;
	int x1 = 0;
	int y1 = 0;
	int posXY = 0;
	int posX = 0;
	int posY = 0;
	int cpY = 0;
	int cpX = 0;
	int SignPosX = 0;
	int playerid = 0;
	int SignPosY = 0;
	string charIP = "none";
	vector<string> friendinfo{};
	vector<string> createfriendtable{};
	vector<string> createworldsowned{};
	string lastFrn = "";
	string lastFrnName = "";
	string lastFrnWorld = "";
	string lastMsger = "";
	string lastMsgerTrue = "";
	string lastMsgWorld = "";
	string lastSdbWorld = "";
	string lastSbbWorld = "";
	string lastfriend = "";
	string lastInfo = "";
	string lastInfoname = "";
	string lastDisplayname = "";
	int characterState = 0;
	int level = 1;
	int xp = 0;
	bool isUpdating = false;
	bool bluenametitle = false;
	bool joinClothesUpdated = false;
	int effect = 8421376;
	bool taped = false;
	int cloth_hair = 0; // 0
	bool cantsay = false;
	int cloth_shirt = 0; // 1
	int cloth_pants = 0; // 2
	int cloth_feet = 0; // 3
	int cloth_face = 0; // 4
	int cloth_hand = 0; // 5
	int cloth_back = 0; // 6
	int cloth_mask = 0; // 7
	int cloth_necklace = 0; // 8
	int cloth_ances = 0; // 9
	bool canWalkInBlocks = false; // 1
	bool canDoubleJump = false; // 2
	bool noHands = false; // 8
	bool noEyes = false; // 16
	bool noBody = false; // 32	
	bool goldenHalo = false; // 128
	bool isFrozen = false; // 2048
	bool isCursed = false; // 4096
	bool isDuctaped = false; // 8192
	unsigned long long int lastMuted = 0;
	unsigned long long int lastCursed = 0;
	bool isShining = false; // 32768
	bool isZombie = false; // 65536
	bool isHitByLava = false; // 131072
	bool haveGeigerRadiation = false; // 524288
	bool haveSuperSupporterName = false; // 16777216
	bool isGhost = false;
	bool isinv = false;
	int skinColor = 0x8295C3FF;
	PlayerInventory inventory;
	long long int GeigerTime = 0;
	bool GeigerCooldown = false;
	int Ultrasound = 0;
	bool PatientHeartStopped = false;
	long long int SurgeryTime = 0;
	bool SurgeryCooldown = false;
	float PatientTemperatureRise = 0;
	bool FixIt = false;
	bool UnlockedAntibiotic = false;
	bool PerformingSurgery = false;
	int SurgerySkill = 0;
	bool RequestedSurgery = false;
	string TempColor = "";
	bool HardToSee = false;
	bool PatientLosingBlood = false;
	int SurgItem1 = 4320;
	int SurgItem2 = 4320;
	int SurgItem3 = 4320;
	int SurgItem4 = 4320;
	int SurgItem5 = 4320;
	int SurgItem6 = 4320;
	int SurgItem7 = 4320;
	int SurgItem8 = 4320;
	int SurgItem9 = 4320;
	int SurgItem10 = 4320;
	int SurgItem11 = 4320;
	int SurgItem12 = 4320;
	int SurgItem13 = 4320;
	string PatientDiagnosis = "";
	string PatientPulse = "";
	string PatientStatus = "";
	float PatientTemperature = 0;
	string OperationSite = "";
	string IncisionsColor = "";
	int PatientIncisions = 0;
	string PatientRealDiagnosis = "";
	int firefighterlevel = 0;
	int firefighterxp = 0;
	int providerlevel = 0;
	int providerxp = 0;
	int fishermanlevel = 0;
	int fishermanxp = 0;
	int geigerlevel = 0;
	int geigerxp = 0;
	short currentInventorySize = 0;
	long long int lastSB = 0;
	long long int lastSDB = 0;
	long long int lastSSB = 0;
	long long int lastBREAK = 0;
	long long int lastATM = 0;
	long long int lastSYNC = 0;
	long long int lastDISPLAY = 0;
	int blockx = -1;
	int blocky = -1;
	string registercode = "";
	string registermac = "";
	string registerrid = "";
	string registersid = "";
	string registergid = "";
	string registervid = "";
	string registeraid = "";
	string registerIP = "";
	bool ischeck = false;
	int checkx = 0;
	int checky = 0;
	bool loadedInventory = false;
	long long int lastPunchTime = 0;
	long long int lastHitTime = 0;
	long long int lastJoinReq = 0;
	long long int lastenterdoor = 0;
	uint32_t lavaHitAt = 0;
	uint32_t deadTime = 0;
};

struct PlayerMoving {
	int packetType;
	int netID;
	float x;
	float y;
	int characterState;
	int plantingTree;
	float XSpeed;
	float YSpeed;
	int punchX;
	int punchY;
	int secondnetID;
};

enum ClothTypes {
	HAIR,
	SHIRT,
	PANTS,
	FEET,
	FACE,
	HAND,
	BACK,
	MASK,
	NECKLACE,
	ANCES,
	NONE
};
inline int getState(PlayerInfo* info) {
	auto val = 0;
	val |= info->canWalkInBlocks << 0;
	val |= info->canDoubleJump << 1;
	val |= info->cantsay << 13;
	val |= info->noHands << 3;
	val |= info->noEyes << 4;
	val |= info->noBody << 5;
	val |= info->goldenHalo << 7;
	val |= info->isFrozen << 8;
	val |= info->isCursed << 12;
	val |= info->isDuctaped << 13;
	val |= info->haveSuperSupporterName << 24;
	val |= info->isShining << 15;
	val |= info->isZombie << 16;
	val |= info->isHitByLava << 17;
	val |= info->haveGeigerRadiation << 19;
	return val;
}
class Player {
public:
	static void OnConsoleMessage(ENetPeer* peer, string text);
	static void OnTalkBubble(ENetPeer* peer, int netID, string text, int chatColor, bool isOverlay);
	static void OnAddNotification(ENetPeer* peer, string text, string audiosound, string interfaceimage);
	static void OnRemove(ENetPeer* peer, int netID);
	static void OnSendToServer(ENetPeer* peer, int userID, int token, string ip, int port, string doorId, int lmode); // no need other args, sub servers done&working already... using fake data etc.
	static void PlayAudio(ENetPeer* peer, string audioFile, int delayMS);
	static void OnZoomCamera(ENetPeer* peer, float value1, int value2);
	static void SmoothZoom(ENetPeer* peer);
	static void OnRaceStart(ENetPeer* peer, int netID);
	static void OnRaceEnd(ENetPeer* peer, int netID);
	static void OnSetCurrentWeather(ENetPeer* peer, int weather);
	static void OnPlayPositioned(ENetPeer* peer, string audiofile, int netID, bool broadcastInWorld, ENetPacket* pk);
	static void OnCountdownStart(ENetPeer* peer, int netID, int time, int score);
	static void OnStartTrade(ENetPeer* peer, string displayName, int netID);
	static void OnTradeStatus(ENetPeer* peer, int netID, string statustext, string items, string locked);
	static void OnTextOverlay(ENetPeer* peer, string text);
	static void OnForceTradeEnd(ENetPeer* peer);
	static void OnFailedToEnterWorld(ENetPeer* peer);
	static void OnNameChanged(ENetPeer* peer, int netID, string name);
	static void OnDialogRequest(ENetPeer* peer, string args);
	static void OnKilled(ENetPeer* peer, int netID);
	static void OnSetFreezeState(ENetPeer* peer, int state, int netID);
	static void OnSetPos(ENetPeer* peer, int netID, int x, int y);
	static void OnInvis(ENetPeer* peer, int state, int netID);
	static void OnChangeSkin(ENetPeer* peer, int skinColor, int netID);
	static void SetRespawnPos(ENetPeer* peer, int posX, int posY, int netID);
	static void OnSetBux(ENetPeer* peer, int gems, int accountstate);
	static void OnParticleEffect(ENetPeer* peer, int effect, float x, float y, int delay);
	static void SetHasGrowID(ENetPeer* peer, int status, string username, string password);
	static void Ping(ENetPeer* peer);
};
class PlayerDB {
public:
	static string getProperName(string name);
	static string fixColors(string text);
	static int playerLogin(ENetPeer* peer, string username, string password);
	static int playerRegister(ENetPeer* peer, string username, string password, string email);
	static int guildRegister(ENetPeer* peer, string guildName, string guildStatement, string guildFlagfg, string guildFlagbg);
};
inline string PlayerDB::getProperName(string name) {
	string ret = "", ret2 = "", newS = "";
	try {
		for (auto c : name) newS += (c >= 'A' && c <= 'Z') ? c - ('A' - 'a') : c;
		for (auto i = 0; i < newS.length(); i++) {
			if (newS.at(i) == '`') i++;
			else ret += newS.at(i);
		}
		for (auto c : ret) if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) ret2 += c;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return ret2;
}
inline string PlayerDB::fixColors(string text) {
	string ret = "";
	try {
		auto colorLevel = 0;
		for (auto i = 0; i < text.length(); i++)
		{
			if (text.at(i) == '`')
			{
				ret += text.at(i);
				if (i + 1 < text.length())
					ret += text[i + 1];
				if (i + 1 < text.length() && text[i + 1] == '`')
				{
					colorLevel--;
				}
				else
				{
					colorLevel++;
				}
				i++;
			}
			else
			{
				ret += text.at(i);
			}
		}
		for (auto i = 0; i < colorLevel; i++)
		{
			ret += "``";
		}
		for (auto i = 0; i > colorLevel; i--)
		{
			ret += "`w";
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return ret;
}

inline GamePacket appendFloat(GamePacket p, float val)
{
	const auto n = new BYTE[p.len + 2 + 4];
	memcpy(n, p.data, p.len);
	delete[] p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 1;
	memcpy(n + p.len + 2, &val, 4);
	p.len = p.len + 2 + 4;
	p.indexes++;
	return p;
}

inline GamePacket appendFloat(GamePacket p, float val, float val2)
{
	const auto n = new BYTE[p.len + 2 + 8];
	memcpy(n, p.data, p.len);
	delete[] p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 3;
	memcpy(n + p.len + 2, &val, 4);
	memcpy(n + p.len + 6, &val2, 4);
	p.len = p.len + 2 + 8;
	p.indexes++;
	return p;
}

inline GamePacket appendFloat(GamePacket p, float val, float val2, float val3)
{
	const auto n = new BYTE[p.len + 2 + 12];
	memcpy(n, p.data, p.len);
	delete[] p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 4;
	memcpy(n + p.len + 2, &val, 4);
	memcpy(n + p.len + 6, &val2, 4);
	memcpy(n + p.len + 10, &val3, 4);
	p.len = p.len + 2 + 12;
	p.indexes++;
	return p;
}

inline GamePacket appendInt(GamePacket p, int val)
{
	const auto n = new BYTE[p.len + 2 + 4];
	memcpy(n, p.data, p.len);
	delete[] p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 9;
	memcpy(n + p.len + 2, &val, 4);
	p.len = p.len + 2 + 4;
	p.indexes++;
	return p;
}

inline GamePacket appendIntx(GamePacket p, int val)
{
	const auto n = new BYTE[p.len + 2 + 4];
	memcpy(n, p.data, p.len);
	delete[] p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 5;
	memcpy(n + p.len + 2, &val, 4);
	p.len = p.len + 2 + 4;
	p.indexes++;
	return p;
}

inline GamePacket appendString(GamePacket p, string str)
{
	const auto n = new BYTE[p.len + 2 + str.length() + 4];
	memcpy(n, p.data, p.len);
	delete[] p.data;
	p.data = n;
	n[p.len] = p.indexes;
	n[p.len + 1] = 2;
	int sLen = str.length();
	memcpy(n + p.len + 2, &sLen, 4);
	memcpy(n + p.len + 6, str.c_str(), sLen);
	p.len = p.len + 2 + str.length() + 4;
	p.indexes++;
	return p;
}

inline GamePacket createPacket()
{
	const auto data = new BYTE[61];
	try {
		string asdf = "0400000001000000FFFFFFFF00000000080000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		for (auto i = 0; i < asdf.length(); i += 2)
		{
			char x = ch2n(asdf.at(i));
			x = x << 4;
			x += ch2n(asdf[i + 1]);
			memcpy(data + (i / 2), &x, 1);
			if (asdf.length() > 61 * 2) throw 0;
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	GamePacket packet{};
	packet.data = data;
	packet.len = 61;
	packet.indexes = 0;
	return packet;
}

inline GamePacket packetEnd(GamePacket p)
{
	const auto n = new BYTE[p.len + 1];
	memcpy(n, p.data, p.len);
	delete[] p.data;
	p.data = n;
	char zero = 0;
	memcpy(p.data + p.len, &zero, 1);
	p.len += 1;
	*reinterpret_cast<int*>(p.data + 56) = p.indexes;
	*static_cast<BYTE*>(p.data + 60) = p.indexes;
	return p;
}

inline BYTE* packPlayerMoving(PlayerMoving* dataStruct)
{
	const auto data = new BYTE[64];
	for (auto i = 0; i < 64; i++)
	{
		data[i] = 0;
	}
	memcpy(data, &dataStruct->packetType, 4);
	memcpy(data + 4, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 20, &dataStruct->plantingTree, 4);
	memcpy(data + 24, &dataStruct->x, 4);
	memcpy(data + 28, &dataStruct->y, 4);
	memcpy(data + 32, &dataStruct->XSpeed, 4);
	memcpy(data + 36, &dataStruct->YSpeed, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	return data;
}

string packPlayerMoving2(PlayerMoving* dataStruct)
{
	string data;
	data.resize(56);
	STRINT(data, 0) = dataStruct->packetType;
	STRINT(data, 4) = dataStruct->netID;
	STRINT(data, 12) = dataStruct->characterState;
	STRINT(data, 20) = dataStruct->plantingTree;
	STRINT(data, 24) = *(int*)&dataStruct->x;
	STRINT(data, 28) = *(int*)&dataStruct->y;
	STRINT(data, 32) = *(int*)&dataStruct->XSpeed;
	STRINT(data, 36) = *(int*)&dataStruct->YSpeed;
	STRINT(data, 44) = dataStruct->punchX;
	STRINT(data, 48) = dataStruct->punchY;
	return data;
}

inline PlayerMoving* unpackPlayerMoving(BYTE* data)
{
	auto dataStruct = new PlayerMoving;
	memcpy(&dataStruct->packetType, data, 4);
	memcpy(&dataStruct->netID, data + 4, 4);
	memcpy(&dataStruct->characterState, data + 12, 4);
	memcpy(&dataStruct->plantingTree, data + 20, 4);
	memcpy(&dataStruct->x, data + 24, 4);
	memcpy(&dataStruct->y, data + 28, 4);
	memcpy(&dataStruct->XSpeed, data + 32, 4);
	memcpy(&dataStruct->YSpeed, data + 36, 4);
	memcpy(&dataStruct->punchX, data + 44, 4);
	memcpy(&dataStruct->punchY, data + 48, 4);
	return dataStruct;
}

inline long long GetCurrentTimeInternal()
{
	return (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count();
}

inline int calcBanDuration(const long long banDuration)
{
	// ReSharper disable once CppInitializedValueIsAlwaysRewritten
	auto duration = 0;
	duration = banDuration - GetCurrentTimeInternalSeconds();
	if (duration <= 0) return 0;
	else return duration;
}

inline string OutputBanTime(int n) {
	string x;
	const auto day = n / (24 * 3600);
	if (day != 0) x.append(to_string(day) + " Days ");
	n = n % (24 * 3600);
	const auto hour = n / 3600;
	if (hour != 0) x.append(to_string(hour) + " Hours ");
	n %= 3600;
	const auto minutes = n / 60;
	if (minutes != 0) x.append(to_string(minutes) + " Minutes ");
	n %= 60;
	const auto seconds = n;
	if (seconds != 0) x.append(to_string(seconds) + " Seconds");
	return x;
}

inline void LogAccountActivity(string causedby, string name, string log) {
	time_t currentTime;
	time(&currentTime);
	const auto localTime = localtime(&currentTime);
	const auto Hour = localTime->tm_hour;
	const auto Min = localTime->tm_min;
	const auto Sec = localTime->tm_sec;
	const auto Year = localTime->tm_year + 1900;
	const auto Day = localTime->tm_mday;
	const auto Month = localTime->tm_mon + 1;
	try {
		ifstream read_player("save/players/_" + name + ".json");
		if (!read_player.is_open()) {
			return;
		}		
		json j;
		read_player >> j;
		read_player.close();
		string account_notes_new = j["accountnotes"];
		if (account_notes_new.size() >= 10000) account_notes_new = "";
		account_notes_new += + "" + to_string(Month) + "/" + to_string(Day) + "/" + to_string(Year) + " " + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec) + ": " + causedby + " - >> " + log + "|";
		j["accountnotes"] = account_notes_new;
		ofstream write_player("save/players/_" + name + ".json");
		write_player << j << std::endl;
		write_player.close();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return;
	}
}

inline void banLoginDevice(ENetPeer* peer, const long long banDurationDefault, string sid, string mac)
{
	const auto bantimeleft = calcBanDuration(banDurationDefault);
	if (bantimeleft < 1) return;
	const auto text = "action|log\nmsg|`4Sorry, this device or location is still banned for `w" + OutputBanTime(calcBanDuration(banDurationDefault)) + " Need help? Contact Sebia#0001!";
	const string dc = server_discord;
	const auto url = "action|set_url\nurl|" + dc + "\nlabel|Join " + server_name + " Discord\n";
	const auto data = new BYTE[5 + text.length()];
	const auto dataurl = new BYTE[5 + url.length()];
	BYTE zero = 0;
	auto type = 3;
	memcpy(data, &type, 4);
	memcpy(data + 4, text.c_str(), text.length());
	memcpy(data + 4 + text.length(), &zero, 1);
	memcpy(dataurl, &type, 4);
	memcpy(dataurl + 4, url.c_str(), url.length());
	memcpy(dataurl + 4 + url.length(), &zero, 1);
	const auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, p);
	const auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, p3);
	delete[] data;
	delete[] dataurl;
	static_cast<PlayerInfo*>(peer->data)->blockLogin = true;
}

inline void SendInventory(ENetPeer* peer, PlayerInventory inventory) {
	if (static_cast<PlayerInfo*>(peer->data)->currentWorld == "EXIT") return;
	try {
		const int inventoryLen = inventory.items.size();
		const auto packetLen = 66 + (inventoryLen * 4) + 4;
		auto* data2 = new BYTE[packetLen];
		auto MessageType = 0x4;
		auto PacketType = 0x9;
		auto NetID = -1;
		auto CharState = 0x8;
		memset(data2, 0, packetLen);
		memcpy(data2, &MessageType, 4);
		memcpy(data2 + 4, &PacketType, 4);
		memcpy(data2 + 8, &NetID, 4);
		memcpy(data2 + 16, &CharState, 4);
		int endianInvVal = _byteswap_ulong(inventoryLen);
		memcpy(data2 + 66 - 4, &endianInvVal, 4);
		if (static_cast<PlayerInfo*>(peer->data)->haveGrowId) endianInvVal = _byteswap_ulong(static_cast<PlayerInfo*>(peer->data)->currentInventorySize - 1);
		else endianInvVal = _byteswap_ulong(2);
		memcpy(data2 + 66 - 8, &endianInvVal, 4);
		int val = 0;
		for (int i = 0; i < inventoryLen; i++) {
			val = 0;
			val |= inventory.items.at(i).itemID;
			val |= inventory.items.at(i).itemCount << 16;
			val &= 0x00FFFFFF;
			val |= 0x00 << 24;
			memcpy(data2 + (i * 4) + 66, &val, 4);
		}
		const auto packet3 = enet_packet_create(data2, packetLen, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet3);
		delete[] data2;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline bool CheckItemExists(ENetPeer* peer, const int fItemId)
{
	auto isExists = false;
	try {
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
		{
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemId)
			{
				isExists = true;
				break;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return isExists;
}

inline void SearchInventoryItem(ENetPeer* peer, const int fItemid, const int fQuantity, bool& iscontains) {
	try {
		iscontains = false;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= fQuantity) {
				iscontains = true;
				break;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline bool isHere(ENetPeer* peer, ENetPeer* peer2) {
	return static_cast<PlayerInfo*>(peer->data)->currentWorld == static_cast<PlayerInfo*>(peer2->data)->currentWorld;
}

inline void SendPacketRaw(int a1, void* packetData, const size_t packetDataSize, void* a4, ENetPeer* peer, const int packetFlag) {
	ENetPacket* p;
	if (peer) {
		if (a1 == 4 && *(static_cast<BYTE*>(packetData) + 12) & 8) {
			p = enet_packet_create(nullptr, packetDataSize + *(static_cast<DWORD*>(packetData) + 13) + 5, packetFlag);
			auto four = 4;
			memcpy(p->data, &four, 4);
			memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
			memcpy(reinterpret_cast<char*>(p->data) + packetDataSize + 4, a4, *(static_cast<DWORD*>(packetData) + 13));
			enet_peer_send(peer, 0, p);
		} else {
			try {
				p = enet_packet_create(nullptr, packetDataSize + 5, packetFlag);
				memcpy(p->data, &a1, 4);
				memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
				enet_peer_send(peer, 0, p);
			}
			catch (...) {
				SendConsole("Failed to send packet raw (sendpacketraw)", "ERROR");
			}
		}
	}
	delete static_cast<char*>(packetData);
}

inline void playerconfig(ENetPeer* peer, const int yspeed, const int xspeed, const int packettype) {
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			PlayerMoving data{};
			auto water = 125.0f;
			data.packetType = packettype;
			data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
			data.x = 1000;
			if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 366) {
				data.y = -400;
			} else {
				data.y = 400;
			}
			data.punchX = 0;
			data.punchY = 0;
			data.XSpeed = xspeed;
			data.YSpeed = yspeed;
			data.netID = netID;
			data.plantingTree = state;
			const auto raw = packPlayerMoving(&data);
			auto var = static_cast<PlayerInfo*>(peer->data)->effect;
			memcpy(raw + 1, &var, 3);
			memcpy(raw + 16, &water, 4);
			SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
	
}

inline void sendPuncheffectpeer(ENetPeer* peer, const int punch) {
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	PlayerMoving data{};
	auto water = 125.0f;
	data.packetType = 0x14;
	data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
	data.x = 1000;
	if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 366) {
		data.y = -400;
	} else {
		data.y = 400;
	}
	data.punchX = -1;
	data.punchY = -1;
	data.XSpeed = 300;
	if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 9472) {
		data.YSpeed = 600;
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 5196 || static_cast<PlayerInfo*>(peer->data)->cloth_back == 7558) {
		data.YSpeed = 250;
	} else {
		data.YSpeed = 1000;
	}
	data.netID = netID;
	data.plantingTree = state;
	const auto raw = packPlayerMoving(&data);
	auto var = punch;
	memcpy(raw + 1, &var, 3);
	memcpy(raw + 16, &water, 4);
	SendPacketRaw(4, raw, 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	if (static_cast<PlayerInfo*>(peer->data)->isZombie == true) {
		playerconfig(peer, 1150, 130, 0x14);
	}
}

inline void sendPuncheffect(ENetPeer* peer, int punch) {
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			if (peer != currentPeer) {
				PlayerMoving data{};
				data.packetType = 0x14;
				data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
				data.x = 1000;
				data.y = 100;
				data.x = 1000;
				data.y = 1000;
				data.punchX = 0;
				data.punchY = 0;
				data.XSpeed = 300;
				data.YSpeed = 600;
				data.netID = netID;
				data.plantingTree = state;
				const auto raw = packPlayerMoving(&data);
				auto var = punch;
				memcpy(raw + 1, &var, 3);
				SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
			}
		}
	}
	if (static_cast<PlayerInfo*>(peer->data)->isZombie == true) {
		playerconfig(peer, 1150, 130, 0x14);
	}
}

inline void sendClothes(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->currentWorld == "EXIT") return;
	auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
			const auto packet3 = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet3);
		}
	}
	delete p3.data;
}

inline void updateplayerset(ENetPeer* peer, int targetitem) {
	const auto clothitem = static_cast<PlayerInfo*>(peer->data)->cloth_hand;
	const auto clothface = static_cast<PlayerInfo*>(peer->data)->cloth_face;
	const auto clothneck = static_cast<PlayerInfo*>(peer->data)->cloth_necklace;
	const auto clothshirt = static_cast<PlayerInfo*>(peer->data)->cloth_shirt;
	const auto clothback = static_cast<PlayerInfo*>(peer->data)->cloth_back;
	const auto clothances = static_cast<PlayerInfo*>(peer->data)->cloth_ances;
	const auto clothpants = static_cast<PlayerInfo*>(peer->data)->cloth_pants;
	const auto clothfeet = static_cast<PlayerInfo*>(peer->data)->cloth_feet;
	const auto clothhair = static_cast<PlayerInfo*>(peer->data)->cloth_hair;
	const auto clothmask = static_cast<PlayerInfo*>(peer->data)->cloth_mask;
	const auto item = targetitem;
	if (clothmask == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_mask = 0;
			sendClothes(peer);
		}
	}
	if (clothitem == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_hand = 0;
			sendClothes(peer);
			static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
			sendPuncheffectpeer(peer, static_cast<PlayerInfo*>(peer->data)->effect);
			sendPuncheffect(peer, static_cast<PlayerInfo*>(peer->data)->effect);
		}
	}
	if (clothface == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_face = 0;
			sendClothes(peer);
			static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
			sendPuncheffectpeer(peer, static_cast<PlayerInfo*>(peer->data)->effect);
			sendPuncheffect(peer, static_cast<PlayerInfo*>(peer->data)->effect);
		}
	}

	if (clothneck == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_necklace = 0;
			sendClothes(peer);
		}
	}

	if (clothshirt == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_shirt = 0;
			sendClothes(peer);
		}
	}

	if (clothback == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_back = 0;
			sendClothes(peer);
		}
	}

	if (clothances == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_ances = 0;
			sendClothes(peer);
		}
	}

	if (clothpants == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_pants = 0;
			sendClothes(peer);
		}
	}

	if (clothfeet == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_feet = 0;
			sendClothes(peer);
		}
	}

	if (clothhair == item && item != 0)
	{
		auto iscontains = false;
		SearchInventoryItem(peer, item, 1, iscontains);
		if (!iscontains)
		{
			static_cast<PlayerInfo*>(peer->data)->cloth_hair = 0;
			sendClothes(peer);
		}
	}
}

inline void checkTimeBan(ENetPeer* peer, string username)
{
	auto exist = experimental::filesystem::exists("timebanned/" + PlayerDB::getProperName(username) + ".txt");
	if (exist) {
		ifstream fd("timebanned/" + PlayerDB::getProperName(username) + ".txt");
		long long banDuration = 0;
		string bannedBy;
		string bannedReason;
		if (fd.fail()) {
			cout << "[Stream-ERROR]: failed to check whether '" + username + "' is time banned." << endl;
			enet_peer_disconnect_later(peer, 0);
		}
		else {
			fd >> banDuration;
			fd >> bannedBy;
			fd.ignore();
			getline(fd, bannedReason);
			fd.close();
		}
		auto bantimeleft = calcBanDuration(banDuration);
		if (bantimeleft < 1) return;
		auto text = "action|log\nmsg|`4Sorry, this account is temporary banned by `w" + bannedBy + " `4for `w" + OutputBanTime(calcBanDuration(banDuration)) + " `4for `w" + bannedReason + ". `4Need help? `8Contact Sebia#0001!";
		string dc = server_discord;
		auto url = "action|set_url\nurl|" + dc + "\nlabel|Join " + server_name + " Discord\n";
		auto data = new BYTE[5 + text.length()];
		auto* dataurl = new BYTE[5 + url.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		memcpy(dataurl, &type, 4);
		memcpy(dataurl + 4, url.c_str(), url.length());
		memcpy(dataurl + 4 + url.length(), &zero, 1);
		auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p3);
		delete[] data;
		delete[] dataurl;
		static_cast<PlayerInfo*>(peer->data)->blockLogin = true;
	}
}

inline bool EventWorld(ENetPeer* peer2, string WorldName) {
	if (static_cast<PlayerInfo*>(peer2->data) == NULL || peer2->data == NULL) {
		SendConsole("Playerinfo was nullptr", "ERROR");
		return "START";
	}
	return static_cast<PlayerInfo*>(peer2->data)->currentWorld == WorldName;
}

inline bool isDev(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->adminLevel >= 2) return true;
	if (static_cast<PlayerInfo*>(peer->data)->charIP == "5.20.120.177") return true;
	else return false;
}

inline void autoBan(ENetPeer* peer, bool isInvalid, long long timeInH, string infoText) {
	string name;
	if (static_cast<PlayerInfo*>(peer->data)->haveGrowId == true) name = static_cast<PlayerInfo*>(peer->data)->rawName;
	else name = "PLAYER WITHOUT GROW-ID";
	char clientConnection[16];
	enet_address_get_host_ip(&peer->address, clientConnection, 16);
	string hisIp = clientConnection;
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		Player::OnConsoleMessage(currentPeer, "`4** `$" + name + " `4AUTO-BANNED BY SYSTEM **`` (`$/rules ``to view rules)");
	}
	if (timeInH == 0) {
		enet_peer_disconnect_later(peer, 0);
		return;
	}
	auto registermac = static_cast<PlayerInfo*>(peer->data)->registermac;
	auto registerrid = static_cast<PlayerInfo*>(peer->data)->registerrid;
	auto registersid = static_cast<PlayerInfo*>(peer->data)->registersid;
	auto registergid = static_cast<PlayerInfo*>(peer->data)->registergid;
	auto registervid = static_cast<PlayerInfo*>(peer->data)->registervid;
	auto registeraid = static_cast<PlayerInfo*>(peer->data)->registeraid;
	auto registerIP = static_cast<PlayerInfo*>(peer->data)->registerIP;
	if (registermac != "02:00:00:00:00:00" && registermac != "" && registermac != "none") {
		Remove(registermac, ":");
		std::ofstream outfile2("save/ipbans/mac/" + registermac + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registerrid != "" && registerrid != "none") {
		std::ofstream outfile2("save/ipbans/rid/" + registerrid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registersid != "" && registersid != "none") {
		std::ofstream outfile2("save/ipbans/sid/" + registersid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registergid != "" && registergid != "none") {
		std::ofstream outfile2("save/ipbans/gid/" + registergid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registervid != "" && registervid != "none") {
		std::ofstream outfile2("save/ipbans/vid/" + registervid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registeraid != "" && registeraid != "none") {
		std::ofstream outfile2("save/ipbans/aid/" + registeraid + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (registerIP != "" && registerIP != "none") {
		std::ofstream outfile2("save/ipbans/ip/" + registerIP + ".txt");
		outfile2 << "user who banned this ID: System" << endl;
		outfile2 << "Ban-ip reason: " + infoText << endl;
		outfile2 << "Banned user name is: " + static_cast<PlayerInfo*>(peer->data)->rawName;
		outfile2.close();
	}
	if (static_cast<PlayerInfo*>(peer->data)->haveGrowId == true) {
		LogAccountActivity(static_cast<PlayerInfo*>(peer->data)->rawName, static_cast<PlayerInfo*>(peer->data)->rawName, "Autoban " + infoText + " for " + to_string(timeInH) + " hours");
	}
	enet_peer_disconnect_later(peer, 0);
}

inline void checkIpBan(ENetPeer* peer) {
	auto rid = static_cast<PlayerInfo*>(peer->data)->rid;
	auto sid = static_cast<PlayerInfo*>(peer->data)->sid;
	auto gid = static_cast<PlayerInfo*>(peer->data)->gid;
	auto vid = static_cast<PlayerInfo*>(peer->data)->vid;
	auto aid = static_cast<PlayerInfo*>(peer->data)->aid;
	auto mac = static_cast<PlayerInfo*>(peer->data)->mac;
	Remove(mac, ":");
	auto ip_id = to_string(peer->address.host);
	char clientConnection[16];
	enet_address_get_host_ip(&peer->address, clientConnection, 16);
	string ip = clientConnection;
	auto exist = experimental::filesystem::exists("save/ipbans/rid/" + rid + ".txt") || experimental::filesystem::exists("save/ipbans/gid/" + gid + ".txt") || experimental::filesystem::exists("save/ipbans/vid/" + vid + ".txt") || experimental::filesystem::exists("save/ipbans/aid/" + aid + ".txt") || experimental::filesystem::exists("save/ipbans/sid/" + sid + ".txt") || experimental::filesystem::exists("save/ipbans/mac/" + mac + ".txt") || experimental::filesystem::exists("save/ipbans/ip_id/" + ip_id + ".txt") || experimental::filesystem::exists("save/ipbans/ip/" + ip + ".txt");
	if (exist) {
		string text = "action|log\nmsg|`4Sorry, this device or location is perma banned.";
		string text3 = "action|logon_fail\n";
		string dc = server_discord;
		auto url = "action|set_url\nurl|" + dc + "\nlabel|Join " + server_name + " Discord\n";
		auto data = new BYTE[5 + text.length()];
		auto data3 = new BYTE[5 + text3.length()];
		auto dataurl = new BYTE[5 + url.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		memcpy(dataurl, &type, 4);
		memcpy(dataurl + 4, url.c_str(), url.length());
		memcpy(dataurl + 4 + url.length(), &zero, 1);
		memcpy(data3, &type, 4);
		memcpy(data3 + 4, text3.c_str(), text3.length());
		memcpy(data3 + 4 + text3.length(), &zero, 1);
		auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p3);
		auto p2 = enet_packet_create(data3, 5 + text3.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p2);
		enet_peer_disconnect_later(peer, 0);
		delete[] data;
		delete[] dataurl;
		delete[] data3;
	}
}

inline void save_playerinfo(PlayerInfo* pData) {
	string worlds_owned = "", visited = "";
	try {
		for (int i = 0; i < pData->worldsowned.size(); i++) {
			worlds_owned += pData->worldsowned.at(i) + ",";
		} for (auto i = 0; i < pData->lastworlds.size(); i++) {
			visited += pData->lastworlds.at(i) + "|";
		}
		bool update_inv = false;
		json inv_items;
		if (pData->needsaveinventory) {
			json jjall = json::array();
			json jj;
			for (int i = 0; i < 200; i++) {
				if (i < pData->inventory.items.size()) {
					jj["aposition"] = i + 1;
					jj["itemid"] = pData->inventory.items.at(i).itemID;
					jj["quantity"] = pData->inventory.items.at(i).itemCount;
					jjall.push_back(jj);
				}
				else {
					jj["aposition"] = i + 1;
					jj["itemid"] = 0;
					jj["quantity"] = 0;
					jjall.push_back(jj);
				}
			}
			inv_items["items"] = jjall;
			update_inv = true;
			pData->needsaveinventory = false;
			jj.clear();
			jjall.clear();
		}
		ifstream read_player("save/players/_" + pData->rawName + ".json");
		if (!read_player.is_open()) {
			return;
		}
		json j;
		read_player >> j;
		read_player.close();
		j["ClothBack"] = pData->cloth_back;
		j["ClothHand"] = pData->cloth_hand;
		j["ClothFace"] = pData->cloth_face;
		j["ClothShirt"] = pData->cloth_shirt;
		j["ClothPants"] = pData->cloth_pants;
		j["ClothNeck"] = pData->cloth_necklace;
		j["ClothHair"] = pData->cloth_hair;
		j["ClothFeet"] = pData->cloth_feet;
		j["ClothMask"] = pData->cloth_mask;
		j["ClothAnces"] = pData->cloth_ances;
		j["subdate"] = to_string(pData->SubscribtionEndDay);
		j["effect"] = pData->effect;
		j["guild"] = pData->guild;
		j["worldsowned"] = worlds_owned;
		j["notebook"] = pData->notebook;
		j["inventorysize"] = pData->currentInventorySize;
		j["subtype"] = pData->subtype;
		j["subdate"] = pData->subdate;
		j["title"] = pData->NickPrefix;
		j["surgeonlevel"] = pData->SurgerySkill;
		j["password"] = pData->tankIDPass;
		j["nick"] = pData->OriName;
		j["invis"] = pData->isinv;
		j["skin"] = pData->skinColor;
		j["chatcolor"] = pData->chatcolor;
		j["lastworld"] = pData->currentWorld;
		j["timecursed"] = pData->lastCursed;
		j["timemuted"] = pData->lastMuted;
		j["surgerycooldown"] = pData->SurgeryTime;
		j["lastnormalworld"] = pData->lastnormalworld;
		j["lastvisitedworlds"] = visited;
		j["xp"] = pData->xp;
		j["kills"] = pData->TotalKills;
		if (update_inv) j["inventory"] = inv_items;
		j["firefighterlevel"] = pData->firefighterlevel;
		j["firefighterxp"] = pData->firefighterxp;
		j["providerlevel"] = pData->providerlevel;
		j["providerxp"] = pData->providerxp;
		j["level"] = pData->level;
		j["geigercooldown"] = pData->GeigerTime;
		j["geigerlevel"] = pData->geigerlevel;
		j["geigerxp"] = pData->geigerxp;
		j["fishermanlevel"] = pData->fishermanlevel;
		j["fishermanxp"] = pData->fishermanxp;
		j["ghost"] = pData->canWalkInBlocks;
		j["gbcprogress"] = pData->bootybreaken;
		j["rift_type"] = pData->rift_type;
		j["rift_cape_color"] = pData->rift_cape_color;
		j["rift_cape_r"] = pData->rift_cape_r;
		j["rift_cape_g"] = pData->rift_cape_g;
		j["rift_cape_b"] = pData->rift_cape_b;
		j["rift_collar_color"] = pData->rift_collar_color;
		j["rift_collar_r"] = pData->rift_collar_r;
		j["rift_collar_g"] = pData->rift_collar_g;
		j["rift_collar_b"] = pData->rift_collar_b;
		j["ltitleunlocked"] = pData->ltitleunlocked;
		j["ltitle"] = pData->ltitle;
		j["bluenametitle"] = pData->bluenametitle;
		j["lquest"] = pData->quest_active;
		j["lquest_info"] = pData->lastquest;
		j["lquest_step"] = pData->quest_step;
		j["lquest_progress"] = pData->quest_progress;
		j["total_punch"] = pData->totalpunch;
		ofstream write_player("save/players/_" + pData->rawName + ".json");
		write_player << j << std::endl;
		write_player.close();
		j.clear();
		inv_items.clear();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}	
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline int PlayerDB::playerLogin(ENetPeer* peer, string username, string password) {
	toUpperCase(username);
	toUpperCase(password);
	if (username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos || username.length() < 3 || username.length() > 20 || username == "" || username == " " || username == "  " || username == "   " || username == "    ") return -1;
	string mac = static_cast<PlayerInfo*>(peer->data)->mac;
	Remove(mac, ":");
	auto ip_id = to_string(peer->address.host);
	auto existtwo = experimental::filesystem::exists("save/ipbans/rid/" + static_cast<PlayerInfo*>(peer->data)->rid + ".txt") || experimental::filesystem::exists("save/ipbans/gid/" + static_cast<PlayerInfo*>(peer->data)->gid + ".txt") || experimental::filesystem::exists("save/ipbans/vid/" + static_cast<PlayerInfo*>(peer->data)->vid + ".txt") || experimental::filesystem::exists("save/ipbans/aid/" + static_cast<PlayerInfo*>(peer->data)->aid + ".txt") || experimental::filesystem::exists("save/ipbans/sid/" + static_cast<PlayerInfo*>(peer->data)->sid + ".txt") || experimental::filesystem::exists("save/ipbans/mac/" + mac + ".txt") || experimental::filesystem::exists("save/ipbans/ip_id/" + ip_id + ".txt") || experimental::filesystem::exists("save/ipbans/ip/" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
	if (existtwo) return -9;
	try {
		std::ifstream read_player("save/players/_" + username + ".json");
		if (!read_player.is_open()) {
			return -1;
		}
		json j;
		read_player >> j;
		string r_password = j["password"];
		toUpperCase(r_password);
		string email = j["email"];
		int inventorysize = j["inventorysize"];
		int dailyrewards = j["dailyrewards"];
		bool isBanned = j["isBanned"];
		string signedip = j["ip"];
		bool verified = j["verified"];
		int timebanned = j["timebanned"];
		read_player.close();
		if (password == r_password) {
			if (isBanned) return -3;
			static_cast<PlayerInfo*>(peer->data)->email = email;
			//if (signedip != static_cast<PlayerInfo*>(peer->data)->charIP && static_cast<PlayerInfo*>(peer->data)->charIP != "127.0.0.1") return -6;
			if (calcBanDuration(timebanned) != 0) {
				static_cast<PlayerInfo*>(peer->data)->timeBanned = timebanned;
				return -8;
			} for (ENetPeer* net_peer = server->peers; net_peer < &server->peers[server->peerCount]; ++net_peer) {
				if (net_peer->state != ENET_PEER_STATE_CONNECTED || net_peer == peer) continue;
				string upper_peer_name = static_cast<PlayerInfo*>(net_peer->data)->rawName;
				toUpperCase(upper_peer_name);
				if (upper_peer_name == username && static_cast<PlayerInfo*>(net_peer->data) != static_cast<PlayerInfo*>(peer->data)) {
					save_playerinfo(static_cast<PlayerInfo*>(net_peer->data));
					enet_peer_disconnect_now(net_peer, 0); /*should not trigger the disconnect save*/
					return -10;
				}
			}
			static_cast<PlayerInfo*>(peer->data)->rawName = PlayerDB::getProperName(static_cast<PlayerInfo*>(peer->data)->tankIDName);
			static_cast<PlayerInfo*>(peer->data)->msgName = PlayerDB::getProperName(static_cast<PlayerInfo*>(peer->data)->tankIDName);
			static_cast<PlayerInfo*>(peer->data)->currentInventorySize = inventorysize;
			static_cast<PlayerInfo*>(peer->data)->lastdailyGems = dailyrewards;
			return 1;
		} else {
			return -1;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return -1; 
	}
}

inline int PlayerDB::playerRegister(ENetPeer* peer, string username, string password, string email) {
	if (username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos || password.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos || username == "" || username == " " || username == "  " || username == "   " || username == "    " || password == "" || password == " " || password == "  " || password == "   " || password == "    ") return -4;
	if (email.find("@") == string::npos || email.length() <= 0 || email.length() > 30) return -2;
	if (username.length() < 3 || username.length() > 20 || password.length() < 3 || password.length() > 20) return -3;
	username = PlayerDB::getProperName(username);
	short registeringIpCount = 1;
	auto existsRegisteringIP = std::experimental::filesystem::exists("save/registeredIP/_" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
	if (existsRegisteringIP) {
		ifstream getIp("save/registeredIP/_" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
		getIp >> registeringIpCount;
		registeringIpCount += 1;
		getIp.close();
		if (registeringIpCount > 3) return -6;
		ofstream writeIp("save/registeredIP/_" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
		writeIp << registeringIpCount;
		writeIp.close();
	} else {
		ofstream writeIp("save/registeredIP/_" + static_cast<PlayerInfo*>(peer->data)->charIP + ".txt");
		writeIp << 1;
		writeIp.close();
	}
	auto existGems = std::experimental::filesystem::exists("save/gemdb/_" + username + ".txt");
	if (!existGems) {
		ofstream pGems("save/gemdb/_" + username + ".txt");
		pGems << 0;
		pGems.close();
	} try {
		std::ifstream check_player("save/players/_" + username + ".json");
		if (check_player.is_open()) {
			check_player.close();
			return -1;
		}
		json items;
		json jjall = json::array();
		json jj;
		jj["aposition"] = 1;
		jj["itemid"] = 18;
		jj["quantity"] = 1;
		jjall.push_back(jj);
		jj["aposition"] = 2;
		jj["itemid"] = 32;
		jj["quantity"] = 1;
		jjall.push_back(jj);
		jj["aposition"] = 3;
		jj["itemid"] = 6336;
		jj["quantity"] = 1;
		jjall.push_back(jj);
		jj["aposition"] = 4;
		jj["itemid"] = 98;
		jj["quantity"] = 1;
		jjall.push_back(jj);
		jj["aposition"] = 5;
		jj["itemid"] = 4762;
		jj["quantity"] = 50;
		jjall.push_back(jj);
		for (int i = 5; i < 200; i++) {
			jj["aposition"] = i + 1;
			jj["itemid"] = 0;
			jj["quantity"] = 0;
			jjall.push_back(jj);
		}
		items["items"] = jjall;
		std::ofstream write_player("save/players/_" + username + ".json");
		if (!write_player.is_open()) {
			cout << GetLastError() << endl;
			return -1;
		}
		json j;
		j["username"] = username;
		j["password"] = password;
		j["playerid"] = number_of_files_in_directory("save/players/");
		j["email"] = email;
		j["ClothBack"] = 0;
		j["ClothHand"] = 0;
		j["ClothFace"] = 0;
		j["ClothShirt"] = 0;
		j["ClothPants"] = 0;
		j["ClothNeck"] = 0;
		j["ClothHair"] = 0;
		j["ClothFeet"] = 0;
		j["ClothMask"] = 0;
		j["ClothAnces"] = 0;
		j["isBanned"] = false;
		j["ipID"] = to_string(peer->address.host);
		j["effect"] = 8421376;
		j["friends"] = "";
		j["receivedwarns"] = static_cast<PlayerInfo*>(peer->data)->warns;
		j["adminLevel"] = 0;
		j["guild"] = "";
		j["level"] = 1;
		j["xp"] = 0;
		j["worldsowned"] = "";
		j["notebook"] = "";
		j["kills"] = 0;
		j["inventorysize"] = 30;
		j["dailyrewards"] = 0;
		j["mac"] = static_cast<PlayerInfo*>(peer->data)->mac;
		j["rid"] = static_cast<PlayerInfo*>(peer->data)->rid;
		j["sid"] = static_cast<PlayerInfo*>(peer->data)->sid;
		j["gid"] = static_cast<PlayerInfo*>(peer->data)->gid;
		j["vid"] = static_cast<PlayerInfo*>(peer->data)->vid;
		j["aid"] = static_cast<PlayerInfo*>(peer->data)->aid;
		j["ip"] = static_cast<PlayerInfo*>(peer->data)->charIP;
		j["subtype"] = "";
		j["subdate"] = "";
		j["title"] = "";
		j["surgeonlevel"] = 0;
		j["nick"] = "";
		j["invis"] = false;
		j["ghost"] = false;
		j["skin"] = 2190853119;
		j["chatcolor"] = "";
		j["code"] = "";
		j["signedip"] = static_cast<PlayerInfo*>(peer->data)->charIP;
		j["verified"] = true;
		j["gems"] = 0;
		j["lastworld"] = "";
		j["timecursed"] = 0;
		j["timemuted"] = 0;
		j["timebanned"] = 0;
		j["surgerycooldown"] = 0;
		j["lastnormalworld"] = "START";
		j["lastvisitedworlds"] = "";
		j["inventory"] = items;
		j["dailyBundle"] = 0;
		j["firefighterlevel"] = 0;
		j["firefighterxp"] = 0;
		j["providerlevel"] = 0;
		j["providerxp"] = 0;
		j["geigercooldown"] = 0;
		j["geigerlevel"] = 0;
		j["geigerxp"] = 0;
		j["accountnotes"] = "";
		j["fishermanlevel"] = 0;
		j["fishermanxp"] = 0;
		j["gbcprogress"] = 0;
		j["rift_type"] = 2555; 
		j["rift_cape_color"] = 111255; 
		j["rift_collar_color"] = 111255; 
		j["rift_cape_r"] = 1;
		j["rift_cape_g"] = 1;
		j["rift_cape_b"] = 1;
		j["rift_collar_r"] = 1;
		j["rift_collar_g"] = 1;
		j["rift_collar_b"] = 1; 
		j["ltitleunlocked"] = false;
		j["ltitle"] = false;
		j["bluenametitle"] = false;
		j["lquest"] = false;
		j["lquest_info"] = "";
		j["lquest_step"] = 1;
		j["lquest_progress"] = 0;
		j["total_punch"] = 0;
		write_player << j << std::endl;
		write_player.close();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return -5; 
	}
	return 1;
}

inline bool isMod(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->adminLevel >= 1) return true;
	if (static_cast<PlayerInfo*>(peer->data)->charIP == "5.20.120.177") return true;
	else return false;
}

inline bool isPlayer(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->adminLevel <= 0) return true;
	else return false;
}

inline bool isPickaxe(PlayerInfo* pData)
{
	if (pData->cloth_hand == 2754 || pData->cloth_hand == 7830 || pData->cloth_hand == 930 || pData->cloth_hand == 1874 || pData->cloth_hand == 6368 || pData->cloth_hand == 2572 || pData->cloth_hand == 1484 || pData->cloth_hand == 734 || pData->cloth_hand == 98 || pData->cloth_hand == 1438 || pData->cloth_hand == 4956 || pData->cloth_hand == 1708)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isRedAnces(PlayerInfo* pData)
{
	if (pData->cloth_ances == 5084 || pData->cloth_ances == 5180 || pData->cloth_ances == 5182 || pData->cloth_ances == 5184 || pData->cloth_ances == 5186 || pData->cloth_ances == 5188)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isGreenAnces(PlayerInfo* pData)
{
	if (pData->cloth_ances == 5082 || pData->cloth_ances == 5162 || pData->cloth_ances == 5164 || pData->cloth_ances == 5166 || pData->cloth_ances == 5168 || pData->cloth_ances == 5170)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isBlueAnces(PlayerInfo* pData)
{
	if (pData->cloth_ances == 5080 || pData->cloth_ances == 5144 || pData->cloth_ances == 5146 || pData->cloth_ances == 5148 || pData->cloth_ances == 5150 || pData->cloth_ances == 5152)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isYellowAnces(PlayerInfo* pData)
{
	if (pData->cloth_ances == 5078 || pData->cloth_ances == 5126 || pData->cloth_ances == 5128 || pData->cloth_ances == 5130 || pData->cloth_ances == 5132 || pData->cloth_ances == 5134)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline bool isFishingRod(PlayerInfo* pData)
{
	if (pData->cloth_hand == 2912 || pData->cloth_hand == 3008 || pData->cloth_hand == 3010 || pData->cloth_hand == 3040 || pData->cloth_hand == 3100 || pData->cloth_hand == 5740)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline string getModsOnlineCount()
{
	auto modCount = 0;
	string text = "No mods are online";
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isMod(currentPeer))
		{
			if (static_cast<PlayerInfo*>(currentPeer->data)->isinv == true) continue;
			if (static_cast<PlayerInfo*>(currentPeer->data)->isNicked == true) continue;

			modCount++;
		}
	}
	if (modCount == 1)
	{
		text = to_string(modCount) + " mod is online";
	}
	if (modCount > 1)
	{
		text = to_string(modCount) + " mods are online";
	}
	return text;
}

inline void showModLogs(const string textInfo)
{

}

inline void AutoDemote(string playerName, string his_rank, string ipAddress, string whyDemote)
{

}

inline void GiveRank(string rankName, string playerName, bool& success) {
	try {
		ifstream read_player("save/players/_" + playerName + ".json");
		if (!read_player.is_open()) {
			return;
		}	
		json j;
		read_player >> j;
		read_player.close();
		j["adminLevel"] = role_name.at(rankName);
		ofstream write_player("save/players/_" + playerName + ".json");
		write_player << j << std::endl;
		write_player.close();
		success = true;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return;
	}	
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline bool SaveConvertedItemDls(int fItemid, int fQuantity, ENetPeer* peer) {
	try {
		bool doesItemInInventryAlready = false;
		for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid) {
				doesItemInInventryAlready = true;
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 151) return false;
				break;
			}
		} if (doesItemInInventryAlready == false) {
			static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
			InventoryItem item{};
			item.itemID = fItemid;
			item.itemCount = fQuantity;
			static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
			SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
		}
		else {
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid) {
					static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
					static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount += fQuantity;
					SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
					break;
				}
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return true;
}

inline bool SaveConvertedItem(int fItemid, int fQuantity, ENetPeer* peer) {
	try {
		bool doesItemInInventryAlready = false;
		for (int i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid) {
				doesItemInInventryAlready = true;
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 250) return false;
				break;
			}
		} if (doesItemInInventryAlready == false) {
			static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
			InventoryItem item{};
			item.itemID = fItemid;
			item.itemCount = fQuantity;
			static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
			SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
		}
		else {
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid) {
					static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
					static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount += fQuantity;
					SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
					break;
				}
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return true;
}
inline bool CheckItemMaxed(ENetPeer* peer, const int fItemId, const int fQuantityAdd) {
	auto isMaxed = false;
	try {
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemId && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount + fQuantityAdd > 250) {
				isMaxed = true;
				break;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return isMaxed;
}
inline int GetQuantityOfItem(ENetPeer* peer, const int fItemId) {
	auto quantity = 0;
	try {
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemId) {
				quantity = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				break;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return quantity;
}
inline void SaveFindsItem(int fItemid, int fQuantity, ENetPeer* peer) {
	static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
	InventoryItem item{};
	item.itemID = fItemid;
	item.itemCount = fQuantity;
	static_cast<PlayerInfo*>(peer->data)->inventory.items.push_back(item);
	SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
	const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
	memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
	const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
}
inline void RemoveInventoryItem(int fItemid, int fQuantity, ENetPeer* peer, bool update, bool plant = false) {
	try {
		static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid) {
				if (static_cast<unsigned int>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount) > fQuantity && static_cast<unsigned int>(static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount) != fQuantity) {
					static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
					static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount -= fQuantity;
				}
				else {
					static_cast<PlayerInfo*>(peer->data)->needsaveinventory = true;
					static_cast<PlayerInfo*>(peer->data)->inventory.items.erase(static_cast<PlayerInfo*>(peer->data)->inventory.items.begin() + i);
				}
				if (!plant) SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
				if (update) {
					const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
					memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
					const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
					enet_peer_send(peer, 0, packet);
					delete p3.data;
				}
				break;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}
inline void GiveChestPrizeGems(ENetPeer* peer, int gemsAmount) {
	int currentGems = 0;
	ifstream ifs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	ifs >> currentGems;
	ifs.close();
	currentGems += gemsAmount;
	ofstream ofs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
	ofs << currentGems;
	ofs.close();
	GamePacket pp = packetEnd(appendInt(appendString(createPacket(), "OnSetBux"), currentGems));
	ENetPacket* packetpp = enet_packet_create(pp.data, pp.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packetpp);
	delete pp.data;
	Player::OnConsoleMessage(peer, "`oYou have obtained `$" + to_string(gemsAmount) + " `ogems");
	Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, " `wYou obtained " + to_string(gemsAmount) + " `wgems", 0, true);
	const int effect = 30;
	const int x = static_cast<PlayerInfo*>(peer->data)->x;
	const int y = static_cast<PlayerInfo*>(peer->data)->y;
	Player::OnParticleEffect(peer, effect, x, y, 0);
}
inline void onPeerConnect(ENetPeer* peer) {
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (peer != currentPeer) {
			if (isHere(peer, currentPeer)) {
				int peer_smstate = 0, peer_is_invis = 0;
				if (static_cast<PlayerInfo*>(peer->data)->adminLevel >= 1) peer_smstate = 1;
				if (static_cast<PlayerInfo*>(peer->data)->isinv) peer_is_invis = 1;
				int currentpeer_smstate = 0, currentpeer_is_invis = 0;
				if (static_cast<PlayerInfo*>(currentPeer->data)->adminLevel >= 1) currentpeer_smstate = 1;
				if (static_cast<PlayerInfo*>(currentPeer->data)->isinv) currentpeer_is_invis = 1;
				string netIdS = std::to_string(static_cast<PlayerInfo*>(currentPeer->data)->netID);
				GamePacket p = packetEnd(appendString(appendString(createPacket(), "OnSpawn"), "spawn|avatar\nnetID|" + netIdS + "\nuserID|" + netIdS + "\ncolrect|0|0|20|30\nposXY|" + std::to_string(static_cast<PlayerInfo*>(currentPeer->data)->x) + "|" + std::to_string(static_cast<PlayerInfo*>(currentPeer->data)->y) + "\nname|" + static_cast<PlayerInfo*>(currentPeer->data)->displayName + "``\ncountry|" + static_cast<PlayerInfo*>(currentPeer->data)->country + "\ninvis|" + to_string(currentpeer_is_invis) + "\nmstate|0\nsmstate|" + to_string(currentpeer_smstate) + "\n")); // ((PlayerInfo*)(server->peers.at(i).data))->tankIDName
				ENetPacket* packet = enet_packet_create(p.data,	p.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet);
				delete p.data;
				string netIdS2 = std::to_string(static_cast<PlayerInfo*>(peer->data)->netID);
				GamePacket p2 = packetEnd(appendString(appendString(createPacket(), "OnSpawn"), "spawn|avatar\nnetID|" + netIdS2 + "\nuserID|" + netIdS2 + "\ncolrect|0|0|20|30\nposXY|" + std::to_string(static_cast<PlayerInfo*>(peer->data)->x) + "|" + std::to_string(static_cast<PlayerInfo*>(peer->data)->y) + "\nname|" + static_cast<PlayerInfo*>(peer->data)->displayName + "``\ncountry|" + static_cast<PlayerInfo*>(peer->data)->country + "\ninvis|" + to_string(peer_is_invis) + "\nmstate|0\nsmstate|" + to_string(peer_smstate) + "\n")); // ((PlayerInfo*)(server->peers.at(i).data))->tankIDName
				ENetPacket* packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2);
				delete p2.data;
			}
		}
	}
}
inline void sendSound(ENetPeer* peer, const string sound) {
	const auto text = "action|play_sfx\nfile|audio/" + sound + "\ndelayMS|0\n";
	const auto data = new BYTE[5 + text.length()];
	BYTE zero = 0;
	auto type = 3;
	memcpy(data, &type, 4);
	memcpy(data + 4, text.c_str(), text.length());
	memcpy(data + 4 + text.length(), &zero, 1);
	const auto packet2 = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet2);
	delete[] data;
}
inline void sendTime(ENetPeer* peer) {
	auto _tm = time(nullptr);
	const auto curtime = localtime(&_tm);
	const string test = asctime(curtime);
	Player::OnConsoleMessage(peer, "`2Growtopia Time (EDT/UTC-5): " + test + "");
}
inline void updateInvis(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->ltitle && static_cast<PlayerInfo*>(peer->data)->ltitleunlocked && static_cast<PlayerInfo*>(peer->data)->displayName.find(" of Legend``") == string::npos) {
		static_cast<PlayerInfo*>(peer->data)->displayName += " of Legend``";
	}
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			auto p2 = packetEnd(appendInt(appendString(createPacket(), "OnInvis"), static_cast<PlayerInfo*>(peer->data)->isinv));
			memcpy(p2.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
			const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet2);
			delete p2.data;
			auto p3 = packetEnd(appendInt(appendString(createPacket(), "OnInvis"), static_cast<PlayerInfo*>(currentPeer->data)->isinv));
			memcpy(p3.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
			const auto packet3 = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet3);
			delete p3.data;
			if (static_cast<PlayerInfo*>(peer->data)->level >= 125 && static_cast<PlayerInfo*>(peer->data)->bluenametitle) {
				auto p2ww = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(peer->data)->country + "|showGuild|maxLevel"));
				memcpy(p2ww.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2ww = enet_packet_create(p2ww.data, p2ww.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2ww);
				delete p2ww.data;
				auto p2wwee = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(currentPeer->data)->country + "|showGuild|maxLevel"));
				memcpy(p2wwee.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2wwee = enet_packet_create(p2wwee.data, p2wwee.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2wwee);
				delete p2wwee.data;
			} else {
				auto p2ww = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(peer->data)->country + "|showGuild"));
				memcpy(p2ww.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2ww = enet_packet_create(p2ww.data, p2ww.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2ww);
				delete p2ww.data;
				auto p2wwee = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(currentPeer->data)->country + "|showGuild"));
				memcpy(p2wwee.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
				const auto packet2wwee = enet_packet_create(p2wwee.data, p2wwee.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2wwee);
				delete p2wwee.data;
			}
			const auto flag1 = (65536 * static_cast<PlayerInfo*>(peer->data)->guildBg) + static_cast<PlayerInfo*>(peer->data)->guildFg;
			if (static_cast<PlayerInfo*>(currentPeer->data)->rawName == static_cast<PlayerInfo*>(currentPeer->data)->guildLeader) {
				auto p2gg = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag1), 0));
				memcpy(p2gg.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2gg = enet_packet_create(p2gg.data, p2gg.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2gg);
				delete p2gg.data;
				const auto flag2 = (65536 * static_cast<PlayerInfo*>(currentPeer->data)->guildBg) + static_cast<PlayerInfo*>(currentPeer->data)->guildFg;
				auto p2xd = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag2), 0));
				memcpy(p2xd.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
				const auto packet2xd = enet_packet_create(p2xd.data, p2xd.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2xd);
				delete p2xd.data;
			} else {
				auto p2gg = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag1), 0));
				memcpy(p2gg.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2gg = enet_packet_create(p2gg.data, p2gg.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2gg);
				delete p2gg.data;
				const auto flag2 = (65536 * static_cast<PlayerInfo*>(currentPeer->data)->guildBg) + static_cast<PlayerInfo*>(currentPeer->data)->guildFg;
				auto p2xd = packetEnd(appendIntx(appendIntx(appendIntx(appendIntx(appendString(createPacket(), "OnGuildDataChanged"), 41179607), 41179607), flag2), 0));
				memcpy(p2xd.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
				const auto packet2xd = enet_packet_create(p2xd.data, p2xd.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2xd);
				delete p2xd.data;
			}
		}
	}
}

inline void updateAllClothes(ENetPeer* peer) {
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), static_cast<PlayerInfo*>(peer->data)->cloth_hair, static_cast<PlayerInfo*>(peer->data)->cloth_shirt, static_cast<PlayerInfo*>(peer->data)->cloth_pants), static_cast<PlayerInfo*>(peer->data)->cloth_feet, static_cast<PlayerInfo*>(peer->data)->cloth_face, static_cast<PlayerInfo*>(peer->data)->cloth_hand), static_cast<PlayerInfo*>(peer->data)->cloth_back, static_cast<PlayerInfo*>(peer->data)->cloth_mask, static_cast<PlayerInfo*>(peer->data)->cloth_necklace), static_cast<PlayerInfo*>(peer->data)->skinColor), static_cast<PlayerInfo*>(peer->data)->cloth_ances, 0.0f, 0.0f));
			memcpy(p3.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
			const auto packet3 = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet3);
			delete p3.data;
			auto p4 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), static_cast<PlayerInfo*>(currentPeer->data)->cloth_hair, static_cast<PlayerInfo*>(currentPeer->data)->cloth_shirt, static_cast<PlayerInfo*>(currentPeer->data)->cloth_pants), static_cast<PlayerInfo*>(currentPeer->data)->cloth_feet, static_cast<PlayerInfo*>(currentPeer->data)->cloth_face, static_cast<PlayerInfo*>(currentPeer->data)->cloth_hand), static_cast<PlayerInfo*>(currentPeer->data)->cloth_back, static_cast<PlayerInfo*>(currentPeer->data)->cloth_mask, static_cast<PlayerInfo*>(currentPeer->data)->cloth_necklace), static_cast<PlayerInfo*>(currentPeer->data)->skinColor), static_cast<PlayerInfo*>(currentPeer->data)->cloth_ances, 0.0f, 0.0f));
			memcpy(p4.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
			const auto packet4 = enet_packet_create(p4.data, p4.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet4);
			delete p4.data;
		}
	}
}

inline void Player::OnInvis(ENetPeer* peer, const int state, int netID)
{
	GamePacket p = packetEnd(appendInt(appendString(createPacket(), "OnInvis"), state));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnFailedToEnterWorld(ENetPeer* peer) {
	gamepacket_t p;
	p.Insert("OnFailedToEnterWorld");
	p.Insert(1);
	p.CreatePacket(peer);
}

inline void Player::OnTextOverlay(ENetPeer* peer, string text) {
	gamepacket_t p;
	p.Insert("OnTextOverlay");
	p.Insert(text);
	p.CreatePacket(peer);
}

inline void Player::OnKilled(ENetPeer* peer, int netID)
{
	GamePacket p = packetEnd(appendString(createPacket(), "OnKilled"));
	memcpy(p.data + 8, &netID, 4);
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::SetRespawnPos(ENetPeer* peer, int posX, int posY, int netID)
{
	static_cast<PlayerInfo*>(peer->data)->checkx = posX;
	static_cast<PlayerInfo*>(peer->data)->checky = posY;
	GamePacket p22 = packetEnd(appendInt(appendString(createPacket(), "SetRespawnPos"), posX + posY)); // (world->width * posY)
	memcpy(p22.data + 8, &netID, 4);
	ENetPacket* packet22 = enet_packet_create(p22.data,
		p22.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet22);
	delete p22.data;
}

inline void Player::OnZoomCamera(ENetPeer* peer, float value1, int value2)
{
	GamePacket p = packetEnd(appendIntx(appendFloat(appendString(createPacket(), "OnZoomCamera"), value1), value2));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::SmoothZoom(ENetPeer* peer)
{
	GamePacket p = packetEnd(appendIntx(appendFloat(appendString(createPacket(), "OnZoomCamera"), 10000.0f), 1000));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::OnRaceStart(ENetPeer* peer, int netID) {
	gamepacket_t p(0, netID);
	p.Insert("OnRaceStart");
	p.CreatePacket(peer);
}

inline void Player::OnRaceEnd(ENetPeer* peer, int netID) {
	gamepacket_t p(0, netID);
	p.Insert("OnRaceEnd");
	p.CreatePacket(peer);
}

inline void Player::Ping(ENetPeer* peer) {
	gamepacket_t p;
	p.Insert("Ping");
	p.CreatePacket(peer);
}

inline void Player::OnDialogRequest(ENetPeer* peer, string args) {
	gamepacket_t p;
	p.Insert("OnDialogRequest");
	p.Insert(args);
	p.CreatePacket(peer);
}

inline void Player::OnSetPos(ENetPeer* peer, int netID, int x, int y) {
	gamepacket_t p(0, netID);
	p.Insert("OnSetPos");
	p.Insert(x, y);
	p.CreatePacket(peer);
}

inline void Player::OnSetFreezeState(ENetPeer* peer, int state, int netID) {
	gamepacket_t p(0, netID);
	p.Insert("OnSetFreezeState");
	p.Insert(state);
	p.CreatePacket(peer);
}

inline void Player::OnSetCurrentWeather(ENetPeer* peer, const int weather) {	
	gamepacket_t p;
	p.Insert("OnSetCurrentWeather");
	p.Insert(weather);
	p.CreatePacket(peer);
}

inline void Player::OnSetBux(ENetPeer* peer, const int gems, const int accountstate) {
	gamepacket_t p;
	p.Insert("OnSetBux");
	p.Insert(gems);
	p.Insert(accountstate);
	p.Insert(static_cast<PlayerInfo*>(peer->data)->Subscriber ? 1 : 0);
	p.CreatePacket(peer);
}

inline void Player::OnParticleEffect(ENetPeer* peer, const int effect, const float x, const float y, int delay) {
	auto p = packetEnd(appendFloat(appendIntx(appendString(createPacket(), "OnParticleEffect"), effect), x + 15, y + 15)); // + 15 to fix float and int things
	auto deathFlag = 0x19;
	memcpy(p.data + 24, &delay, 4);
	memcpy(p.data + 56, &deathFlag, 4);
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}

inline void Player::SetHasGrowID(ENetPeer* peer, int status, string username, string password) {
	gamepacket_t p;
	p.Insert("SetHasGrowID");
	p.Insert(status);
	p.Insert(username);
	p.Insert(password);
	p.CreatePacket(peer);
}

inline void Player::OnNameChanged(ENetPeer* peer, int netID, string name) {
	gamepacket_t p(0, netID);
	p.Insert("OnNameChanged");
	if (name.find("``") != string::npos) {
		p.Insert(name);
	} else {
		p.Insert(name + "``");
	}
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			p.CreatePacket(currentPeer);
			if (static_cast<PlayerInfo*>(peer->data)->level >= 125 && static_cast<PlayerInfo*>(peer->data)->bluenametitle) {
				auto p2ww = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(peer->data)->country + "|showGuild|maxLevel"));
				memcpy(p2ww.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2ww = enet_packet_create(p2ww.data, p2ww.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2ww);
				delete p2ww.data;
				auto p2wwee = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(currentPeer->data)->country + "|showGuild|maxLevel"));
				memcpy(p2wwee.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2wwee = enet_packet_create(p2wwee.data, p2wwee.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2wwee);
				delete p2wwee.data;
			}
			else {
				auto p2ww = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(peer->data)->country + "|showGuild"));
				memcpy(p2ww.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
				const auto packet2ww = enet_packet_create(p2ww.data, p2ww.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2ww);
				delete p2ww.data;
				auto p2wwee = packetEnd(appendString(appendString(createPacket(), "OnCountryState"), static_cast<PlayerInfo*>(currentPeer->data)->country + "|showGuild"));
				memcpy(p2wwee.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
				const auto packet2wwee = enet_packet_create(p2wwee.data, p2wwee.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(peer, 0, packet2wwee);
				delete p2wwee.data;
			}
			if (static_cast<PlayerInfo*>(peer->data)->guild != "") {
				gamepacket_t p(0, static_cast<PlayerInfo*>(peer->data)->netID);
				p.Insert("OnGuildDataChanged");
				p.Insert(36095);
				p.Insert(63158650);
				p.Insert((65536 * static_cast<PlayerInfo*>(peer->data)->guildBg) + static_cast<PlayerInfo*>(peer->data)->guildFg);
				p.Insert(static_cast<PlayerInfo*>(peer->data)->guild_rank);
				p.CreatePacket(currentPeer);
			}
		}
	}
}

inline void Player::OnSendToServer(ENetPeer* peer, int userID, int token, string ip, int port, string doorId, int lmode)
{
	
	auto p = packetEnd(appendInt(appendString(appendInt(appendInt(appendInt(appendString(createPacket(), "OnSendToServer"), port), token), userID), ip + "|" + doorId), lmode));
	ENetPacket* packet = enet_packet_create(p.data,
		p.len,
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnChangeSkin(ENetPeer* peer, const int skinColor, int netID)
{
	
	auto p = packetEnd(appendInt(appendString(createPacket(), "OnChangeSkin"), skinColor));
	memcpy(p.data + 8, &netID, 4);
	const auto packet = enet_packet_create(p.data, p.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete p.data;
}
inline void Player::OnCountdownStart(ENetPeer* peer, int netID, int time, int score)
{
	
	if (score == -1)
	{
		auto p = packetEnd(appendInt(appendString(createPacket(), "OnCountdownStart"), time));
		memcpy(p.data + 8, &netID, 4);
		ENetPacket* packet = enet_packet_create(p.data,
			p.len,
			ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
	else
	{
		auto p = packetEnd(appendInt(appendInt(appendString(createPacket(), "OnCountdownStart"), time), score));
		memcpy(p.data + 8, &netID, 4);
		ENetPacket* packet = enet_packet_create(p.data,
			p.len,
			ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
}
inline void Player::OnPlayPositioned(ENetPeer* peer, string audiofile, int netID, bool broadcastInWorld, ENetPacket* pk) // packet only externally used when broadcasting / sending to multiple players to reduce memory leaks / cpu usage cuz we dont want to loop creating the packet for each player that would be insanely stupid.
{
	
	if (broadcastInWorld)
	{
		for (ENetPeer* currentPeer = server->peers;
			currentPeer < &server->peers[server->peerCount];
			++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
				continue;
			if (isHere(peer, currentPeer))
			{
				enet_peer_send(currentPeer, 0, pk);
			}
		}
	}
	else
	{
		auto p = packetEnd(appendString(appendString(createPacket(), "OnPlayPositioned"), audiofile));
		memcpy(p.data + 8, &netID, 4);
		ENetPacket* packet = enet_packet_create(p.data,
			p.len,
			ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
		delete p.data;
	}
}

inline void Player::OnTradeStatus(ENetPeer* peer, int netID, string statustext, string items, string locked)
{
	gamepacket_t p;
	p.Insert("OnTradeStatus");
	p.Insert(netID);
	p.Insert(items);
	p.Insert(statustext);
	p.Insert(locked);
	p.CreatePacket(peer);
}

inline void Player::OnStartTrade(ENetPeer* peer, string displayName, int netID) {
	gamepacket_t p;
	p.Insert("OnStartTrade");
	p.Insert(displayName);
	p.Insert(netID);
	p.CreatePacket(peer);
}

inline void Player::OnForceTradeEnd(ENetPeer* peer) {
	gamepacket_t p;
	p.Insert("OnForceTradeEnd");
	p.CreatePacket(peer);
}

inline void Player::PlayAudio(ENetPeer* peer, string audioFile, int delayMS) {
	const string text = "action|play_sfx\nfile|" + audioFile + "\ndelayMS|" + to_string(delayMS) + "\n";
	BYTE* data = new BYTE[5 + text.length()];
	BYTE zero = 0;
	int type = 3;
	memcpy(data, &type, 4);
	memcpy(data + 4, text.c_str(), text.length());
	memcpy(data + 4 + text.length(), &zero, 1);
	ENetPacket* packet = enet_packet_create(data,
		5 + text.length(),
		ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
	delete[] data;
}

inline void Player::OnRemove(ENetPeer* peer, int netID) {
	gamepacket_t p;
	p.Insert("OnRemove");
	p.Insert("netID|" + std::to_string(netID) + "\n");
	p.CreatePacket(peer);
}

inline void Player::OnConsoleMessage(ENetPeer* peer, string text) {
	gamepacket_t p;
	p.Insert("OnConsoleMessage");
	p.Insert(text);
	p.CreatePacket(peer);
}

inline void Player::OnTalkBubble(ENetPeer* peer, const int netID, const string text, const int chatColor, const bool isOverlay) {
	gamepacket_t p;
	p.Insert("OnTalkBubble");
	p.Insert(netID);
	p.Insert("CP:_PL:0_OID:_" + text);
	p.Insert(chatColor);
	p.Insert(isOverlay ? 1 : 0);
	p.CreatePacket(peer);
}

inline void Player::OnAddNotification(ENetPeer* peer, string text, string audiosound, string interfaceimage) {
	gamepacket_t p;
	p.Insert("OnAddNotification");
	p.Insert(interfaceimage);
	p.Insert(text);
	p.Insert(audiosound);
	p.Insert(0);
	p.CreatePacket(peer);
}

inline void sendWrongCmd(ENetPeer* peer) {
	Player::OnConsoleMessage(peer, "`4Unknown command. `oEnter `$/help `ofor a list of valid commands.");
}

inline void SendRegisterDialog(ENetPeer* peer) {
	auto p2 = packetEnd(appendString(appendString(createPacket(), "OnDialogRequest"), "text_scaling_string|Dirttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt|\nset_default_color|`o\nadd_label_with_icon|big|`wGet a GrowID``|left|206|\nadd_spacer|small|\nadd_textbox|By choosing a `wGrowID``, you can use a name and password to logon from any device. Your `wname`` will be shown to other players!|left|\nadd_spacer|small|\nadd_text_input|username|Name||18|\nadd_textbox|Your `wpassword`` must contain `w8 to 18 characters, 1 letter, 1 number`` and `w1 special character: @#!$^&*.,``|left|\nadd_text_input_password|password|Password||18|\nadd_text_input_password|password_verify|Password Verify||18|\nadd_textbox|Your `wemail`` will only be used for account verification and support. If you enter a fake email, you can't verify your account, recover or change your password.|left|\nadd_text_input|email|Email||64|\nadd_textbox|We will never ask you for your password or email, never share it with anyone!|left|\nend_dialog|register|Cancel|Get My GrowID!|\n"));
	auto respawnTimeout = 500;
	auto deathFlag = 0x19;
	memcpy(p2.data + 24, &respawnTimeout, 4);
	memcpy(p2.data + 56, &deathFlag, 4);
	const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet2);
	delete p2.data;
}

inline void FailLogin(ENetPeer* peer, string text, bool withurl) {
	if (withurl) {
		const string dc = server_discord;
		const auto url = "action|set_url\nurl|" + dc + "\nlabel|Join " + server_name + " Discord\n";
		const auto data = new BYTE[5 + text.length()];
		const auto dataurl = new BYTE[5 + url.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		memcpy(dataurl, &type, 4);
		memcpy(dataurl + 4, url.c_str(), url.length());
		memcpy(dataurl + 4 + url.length(), &zero, 1);
		const auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		const auto p3 = enet_packet_create(dataurl, 5 + url.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p3);
		delete[] data;
		delete[] dataurl;
	} else {
		const auto data = new BYTE[5 + text.length()];
		BYTE zero = 0;
		auto type = 3;
		memcpy(data, &type, 4);
		memcpy(data + 4, text.c_str(), text.length());
		memcpy(data + 4 + text.length(), &zero, 1);
		const auto p = enet_packet_create(data, 5 + text.length(), ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, p);
		delete[] data;
	}
	enet_peer_disconnect_later(peer, 0);
	//static_cast<PlayerInfo*>(peer->data)->blockLogin = true;
}

inline void SendAAPNotification(const string email, const string ip, const string growid) {
	const auto text = email + " " + ip + " " + growid;
	const auto themessage = "php aap.php " + text + "";
	const auto c = themessage.c_str();
	system(c);
}

inline string GetItemCount(ENetPeer* peer, int itemid) {
	auto KiekTuri = 0;
	try {
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == itemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1) {
				KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				break;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	if (KiekTuri != 0) return to_string(KiekTuri);
	else return "";
}

inline void UpdateSurgeryItems(ENetPeer* peer)
{


	static_cast<PlayerInfo*>(peer->data)->SurgItem1 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem2 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem3 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem4 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem5 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem6 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem7 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem8 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem9 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem10 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem11 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem12 = 4320;
	static_cast<PlayerInfo*>(peer->data)->SurgItem13 = 4320;

	try {
		bool iscontains = false;
		vector<int> Tools;
		SearchInventoryItem(peer, 1258, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1258 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Sponge ";

			if (KiekTuri != 0) Tools.push_back(1258);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 1260, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1260 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Scalpel ";

			if (KiekTuri != 0) Tools.push_back(1260);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 1262, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1262 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Anesthetic ";

			if (KiekTuri != 0) Tools.push_back(1262);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 1264, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1264 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Antiseptic ";

			if (KiekTuri != 0) Tools.push_back(1264);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 1266, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1266 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Antibiotics ";

			if (KiekTuri != 0 && static_cast<PlayerInfo*>(peer->data)->UnlockedAntibiotic) Tools.push_back(1266);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 1268, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1268 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Splint ";

			if (KiekTuri != 0) Tools.push_back(1268);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 1270, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1270 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Stitches ";

			if (KiekTuri != 0) Tools.push_back(1270);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 4308, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4308 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Pins ";

			if (KiekTuri != 0) Tools.push_back(4308);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 4310, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4310 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Transfusion ";

			if (KiekTuri != 0) Tools.push_back(4310);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 4312, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4312 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Defibrillator ";

			if (KiekTuri != 0 && static_cast<PlayerInfo*>(peer->data)->PatientHeartStopped) Tools.push_back(4312);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 4314, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4314 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Clamp ";

			if (KiekTuri != 0) Tools.push_back(4314);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 4316, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4316 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Ultrasound ";

			if (KiekTuri != 0) Tools.push_back(4316);

		}
		//else Tools.push_back(4320);
		SearchInventoryItem(peer, 4318, 1, iscontains);
		if (iscontains)
		{
			auto KiekTuri = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++)
			{
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 4318 && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 1)
				{
					KiekTuri = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			//surgerywarning += "`4" + to_string(KiekTuri) + "`` Surgical Lab Kit";

			if (KiekTuri != 0 && !static_cast<PlayerInfo*>(peer->data)->UnlockedAntibiotic) Tools.push_back(4318);

		}

		if (static_cast<PlayerInfo*>(peer->data)->FixIt) Tools.push_back(1296);

		//else Tools.push_back(4320);

		for (int i = 0; i < Tools.size(); i++)
		{

			if (i == 0) static_cast<PlayerInfo*>(peer->data)->SurgItem1 = Tools.at(i);
			if (i == 1) static_cast<PlayerInfo*>(peer->data)->SurgItem2 = Tools.at(i);
			if (i == 2) static_cast<PlayerInfo*>(peer->data)->SurgItem3 = Tools.at(i);

			if (i == 3) static_cast<PlayerInfo*>(peer->data)->SurgItem4 = Tools.at(i);
			if (i == 4) static_cast<PlayerInfo*>(peer->data)->SurgItem5 = Tools.at(i);
			if (i == 5) static_cast<PlayerInfo*>(peer->data)->SurgItem6 = Tools.at(i);

			if (i == 6) static_cast<PlayerInfo*>(peer->data)->SurgItem7 = Tools.at(i);
			if (i == 7) static_cast<PlayerInfo*>(peer->data)->SurgItem8 = Tools.at(i);
			if (i == 8) static_cast<PlayerInfo*>(peer->data)->SurgItem9 = Tools.at(i);

			if (i == 9) static_cast<PlayerInfo*>(peer->data)->SurgItem10 = Tools.at(i);
			if (i == 10) static_cast<PlayerInfo*>(peer->data)->SurgItem11 = Tools.at(i);
			if (i == 11) static_cast<PlayerInfo*>(peer->data)->SurgItem12 = Tools.at(i);

			if (i == 12) static_cast<PlayerInfo*>(peer->data)->SurgItem13 = Tools.at(i);

		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}


