#pragma once
#include "trade_system.h"

struct WorldItem
{
	__int16_t foreground = 0;
	__int16_t background = 0;
	int displayblock = 0;
	int breakLevel = 0;
	long long int breakTime = 0;
	string sign = "";
	bool water = false;
	bool rotatedLeft = false;
	bool fire = false;
	bool glue = false;
	bool red = false;
	bool green = false;
	bool flipped = false;
	bool blue = false;
	int intdata = 0;
	string label = "";
	string destWorld = "";
	string destId = "";
	string currId = "";
	string password = "";
	bool activated = false;
	int yellowGems = 0;
	int blueGems = 0;
	int redGems = 0;
	int greenGems = 0;
	int purpleGems = 0;

	int clothHair = 0;
	int clothHead = 0;
	int clothMask = 0;
	int clothHand = 0;
	int clothNeck = 0;
	int clothShirt = 0;
	int clothPants = 0;
	int clothFeet = 0;
	int clothBack = 0;

	/*magplant*/
	int mid = 0;
	int mc = 0;
	bool rm = false;

	/*vending*/
	bool destroy = false;
	int vdraw = 0;
	int vid = 0;
	int vprice = 0;
	int vcount = 0;
	int breakstate = 0;
	int breakbotstate = 0;

	/*hmonitor*/
	string monitorname = "";
	bool monitoronline = false;

	/*entrance*/
	bool opened = false;
	/*seedai*/
	bool spliced = false;
	int growtime = 0;
	int fruitcount = 0;
	/*rocks*/
	int evolvestage = 0;
	bool atnaujino = false;
	bool lock = false;

};

struct DroppedItem
{
	int id;
	int uid;
	int count;
	float x;
	float y;
};

struct WorldInfo
{
	int width = 100;
	int height = 60;
	int publicBlock = -1;
	int weather = 4;
	int droppedCount = 0;
	float rating = 1;
	int entrylevel = 1;
	bool silence = false;
	bool isNuked = false;
	bool isPublic = false;
	bool DisableDrop = false;
	bool rainbow = false;
	bool isEvent = true;
	bool worker = false;
	bool drop_gem = true;
	bool saved = false;
	string name = "TEST";
	string owner = "";
	string category = "None";
	vector<WorldItem> items{};
	vector<DroppedItem> droppedItems{};
	vector<string> accessed{};
	string notification = "";
};

struct AWorld
{
	WorldInfo* ptr{};
	WorldInfo info{};
	int id = -1;
};

struct TileExtra
{
	int packetType;
	int characterState;
	float objectSpeedX;
	int punchX;
	int punchY;
	int charStat;
	int blockid;
	int visual;
	int signs;
	int backgroundid;
	int displayblock;
	int time;
	int netID;
	int weatherspeed;
	int bpm;
};

struct BlockVisual
{
	int packetType;
	int characterState;
	int punchX;
	int punchY;
	float x;
	float y;
	int plantingTree;
	float XSpeed;
	float YSpeed;
	int charStat;
	int blockid;
	int visual;
	int signs;
	int backgroundid;
	int displayblock;
	int time;
	int netID;
};

inline void decodeName(char* src, const int len, const int itemID, char* dest)
{
	const char key[] = "PBG892FXX982ABC*";
	for (auto i = 0; i < len; i++)
	{
		dest[i] = src[i] ^ key[(i + itemID) % 16];
	}
}

struct itemDataStruct
{
	string name;
	string texturefile;
	string audiofile;
	int id;
	uint8_t editableType;
	uint8_t category;
	uint8_t type;
	uint8_t solid;
	uint16_t rarity;
	uint32_t color1;
	uint32_t color2;
	uint8_t textureX;
	uint8_t textureY;
	uint8_t textureType;
	uint8_t hardness;
	uint16_t audioVol;
	uint32_t texturehash;
	uint32_t audiohash;
	uint8_t seedBase;
	uint8_t seedOverlay;
	uint8_t treeBase;
	uint8_t treeOverlay;
	int punchEffect = 0;
};

enum BlockTypes
{
	FOREGROUND,
	BACKGROUND,
	CONSUMABLE,
	SEED,
	PAIN_BLOCK,
	BEDROCK,
	MAIN_DOOR,
	SIGN,
	DOOR,
	CLOTHING,
	FIST,
	WRENCH,
	CHECKPOINT,
	LOCK,
	GATEWAY,
	TREASURE,
	WEATHER,
	TRAMPOLINE,
	TOGGLE_FOREGROUND,
	CHEMICAL_COMBINER,
	SWITCH_BLOCK,
	SFX_FOREGROUND,
	RANDOM_BLOCK,
	PORTAL,
	PLATFORM,
	MAILBOX,
	MAGIC_EGG,
	CRYSTAL,
	GEMS,
	DEADLY,
	CHEST,
	FACTION,
	BULLETIN_BOARD,
	BOUNCY,
	ANIM_FOREGROUND,
	COMPONENT,
	SUCKER,
	FISH,
	STEAM,
	GROUND_BLOCK,
	DISPLAY,
	STORAGE,
	VENDING,
	DONATION,
	PHONE,
	SEWINGMACHINE,
	CRIME_VILLAIN,
	PROVIDER,
	UNKNOWN
};

vector<WorldInfo> worlds;

class WorldDB
{
public:
	WorldInfo get(string name) const;
	WorldInfo* get_pointer(string name) const;
	static AWorld get2(string name);
	WorldDB();
};

inline WorldDB::WorldDB()
{
}

inline void GenerateGrowaloneLikeWorld(WorldInfo* world, const bool cave, const int width, const int height, const int dirtType = 2, const int lavaType = 4, const int mainDoorType = 6, const int bedrockType = 8, const int rockType = 10, const int caveBackgroundType = 14, const int wmachineid = 0, const int deco1Id = 0, const int deco2Id = 0, const int id = 0) {
	try {
		world->weather = wmachineid;
		if (world->name == "GROWGANOTH") {
			world->weather = 9;
		}
		for (auto i = 0; i < world->width * world->height; i++) {
			WorldItem tiles{};
			tiles.foreground = 0;
			world->items.push_back(tiles);
		}
		if (cave) {
			const auto offset = new int[width];
			const auto offset2 = new int[width];
			offset[0] = (height - height < 0) ? -10 : height - height;
			offset2[0] = offset[0] < 0 ? -10 : offset[0];
			auto settile = [](WorldInfo* w, const int x, const int y, const int id) {
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					w->items.at(x + y * w->width).foreground = id;
			};
			auto settilebg = [](WorldInfo* w, const int x, const int y, const int id) {
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					w->items.at(x + y * w->width).background = id;
			};
			auto settileactive = [](WorldInfo* w, const int x, const int y, const int id) {
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					w->items.at(x + y * w->width).activated = true;
			};
			auto settiletext = [](WorldInfo* w, const int x, const int y, const string text) {
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					w->items.at(x + y * w->width).sign = text;
			};
			auto gettile = [](WorldInfo* w, const int x, const int y) {
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					return w->items.at(x + y * w->width).foreground;
				return static_cast<short>(0);
			};
			for (auto i = 1; i < width; i++) {
				offset[i] = offset[i - 1]; // no change
				offset2[i] = offset[i] < 0 ? -10 : offset[i];
			} for (auto j = 0; j < width; j++) {
				for (auto k = offset[j]; k < height; k++) {
					settilebg(world, j, k, 3556);
					//settilebg(world, j, k, 14);
					float chance = k / 2.5;
					if (rand() % 100 <= chance) {
						settile(world, j, k, 9380);
					} else {
						settile(world, j, k, 3564);
					}
					if ((rand() % 12) > 10)
						settile(world, j, k, rockType);
					if ((rand() % 100) <= 2)
						settile(world, j, k, 4); //lava
					if ((rand() % 300) <= 1)
						settile(world, j, k, 9148); //magma
					if ((rand() % 200) <= 1)
						settile(world, j, k, 8440); //coal
					if (k >= 0 && (rand() % 800) <= 1)
						settile(world, j, k, 8532); //iron
					if (k >= 0 && (rand() % 1000) <= 1)
						settile(world, j, k, 9146); //gold
					if (k >= 0 && (rand() % 1700) <= 1)
						settile(world, j, k, 8530); //diamond
					if (k >= 0 && (rand() % 2000) <= 1)
						settile(world, j, k, 4762); //amethyst
					if (k >= 0 && (rand() % 2000) <= 1)
						settile(world, j, k, 7382); //onyx
					if (k >= 0 && (rand() % 2000) <= 1)
						settile(world, j, k, 5136); //smaraged
					if (k >= 0 && (rand() % 2000) <= 1)
						settile(world, j, k, 5138); //dstone
					if (k >= 0 && (rand() % 2000) <= 1)
						settile(world, j, k, 5140); //pdiamond
					if (k >= 0 && (rand() % 2000) <= 1)
						settile(world, j, k, 5154); //citrine
					if (k >= 0 && (rand() % 2000) <= 1)
						settile(world, j, k, 9498); //hellstone
					if (k == 59)
						settile(world, j, k, 8); //bedrock
				}
			}
			const auto mainDoorX = (rand() % (width - 4)) + 2;
			auto f = 30 + offset[mainDoorX];
			settile(world, mainDoorX, f, mainDoorType); 
			settile(world, mainDoorX + 1, f, 20);
			settiletext(world, mainDoorX + 1, f, "Welcome to the mines!");
			settile(world, mainDoorX - 1, f, 0);
			settile(world, mainDoorX, f - 1, 696);
			settileactive(world, mainDoorX , f - 1, 696);
			settile(world, mainDoorX + 1, f - 1, 0);
			settile(world, mainDoorX - 1, f - 1, 0);
			settile(world, mainDoorX, f + 1, bedrockType);
			const auto minerX = (rand() % (width - 4)) + 2;
			f = 45 + offset[minerX];
			settile(world, minerX + 1, f, 20);
			settile(world, minerX, f, 9150);
			settiletext(world, minerX + 1, f, "Miner can trade your ores for gems, or craft items!");
			settile(world, minerX - 1, f, 0);
			settile(world, minerX, f - 1, 0);
			settile(world, minerX + 1, f - 1, 0);
			settile(world, minerX - 1, f - 1, 0);
			settile(world, minerX - 2, f - 1, 0);
			settile(world, minerX - 2, f + 1, 3584);
			settile(world, minerX + 2, f - 1, 0);
			settile(world, minerX + 2, f + 1, 0);
			settile(world, minerX - 2, f, 0);
			settile(world, minerX - 2, f, 0);
			settile(world, minerX + 2, f, 9148);
			settile(world, minerX + 3, f, 9148);
			settile(world, minerX, f - 2, 0);
			settile(world, minerX + 1, f - 2, 0);
			settile(world, minerX + 2, f - 2, 3584);
			settile(world, minerX - 1, f - 2, 0);
			settile(world, minerX - 2, f - 2, 3584);
			delete[] offset;
			delete[] offset2;
		} else {
			const auto offset = new int[width];
			const auto offset2 = new int[width];
			offset[0] = (height - 60 < 0) ? -10 : height - 60;
			offset2[0] = offset[0] < 0 ? -10 : offset[0];
			auto settile = [](WorldInfo* w, const int x, const int y, const int id)
			{
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					w->items.at(x + y * w->width).foreground = id;
			};
			auto settilebg = [](WorldInfo* w, const int x, const int y, const int id)
			{
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					w->items.at(x + y * w->width).background = id;
			};
			auto gettile = [](WorldInfo* w, const int x, const int y)
			{
				if (x < w->width && x >= 0 && y < w->height && y >= 0)
					return w->items.at(x + y * w->width).foreground;
				return static_cast<short>(0);
			};
			for (auto i = 1; i < width; i++)
			{
				offset[i] = (height - 60 < 0) ? -10 : height - 60;
				const auto rnd = rand() % 30 - 10;
				if (rnd < -2)
					offset[i] = offset[i - 1] - 1; // rise
				else if (rnd > 11)
					offset[i] = offset[i - 1] + 1; // fall
				else
					offset[i] = offset[i - 1]; // no change
				offset2[i] = offset[i] < 0 ? -10 : offset[i];
			}
			for (auto j = 0; j < width; j++)
			{
				for (auto k = 26 + offset[j]; k < height - 5; k++)
				{
					settile(world, j, k, dirtType);
					settilebg(world, j, k, caveBackgroundType);
					const auto renrnd = rand() % 12;
					if (renrnd > 10)
						settile(world, j, k, rockType);
				}
				settile(world, j, 26 + offset[j], dirtType);
				settilebg(world, j, 26 + offset[j], caveBackgroundType);
				settile(world, j, height - 6, bedrockType);
				settile(world, j, height - 5, bedrockType);
				settile(world, j, height - 4, bedrockType);
				settile(world, j, height - 3, bedrockType);
				settile(world, j, height - 2, bedrockType);
				settile(world, j, height - 1, bedrockType);
				settilebg(world, j, height - 6, caveBackgroundType);
				settilebg(world, j, height - 5, caveBackgroundType);
				settilebg(world, j, height - 4, caveBackgroundType);
				settilebg(world, j, height - 3, caveBackgroundType);
				settilebg(world, j, height - 2, caveBackgroundType);
				settilebg(world, j, height - 1, caveBackgroundType);
			}
			for (auto srg = height - 10; srg < height - 6; srg++)
			{
				for (auto dhk = 0; dhk < width; dhk++)
				{
					const auto djkf = rand() % 2;
					if (djkf == 1)
					{
						settile(world, dhk, srg, lavaType);
					}
				}
			}
			if (id & BlastProperties_WaterLevelD2)
			{
				for (auto i = 0; i < width; i++)
				{
					for (auto j = deco2Id; j < height; j++)
					{
						if (gettile(world, i, j) == 0)
						{
							if (i < world->width && i >= 0 && j < world->height && j >= 0)
								world->items.at(i + j * world->width).water = true;
						}
					}
				}
			}
			else if (id & BlastProperties_RandomDeco1)
			{
				const auto deco1Count = rand() % 25 + 3;
				for (auto i = 0; i < deco1Count; i++)
				{
					const auto a = rand() % width;
					settile(world, a, 25 + offset[a], deco1Id);
				}
			}
			else if (id & BlastProperties_RandomDeco2)
			{
				const auto deco2Count = rand() % 25 + 3;
				for (auto i = 0; i < deco2Count; i++)
				{
					const auto a = rand() % width;
					settile(world, a, 25 + offset[a], deco2Id);
				}
			}
		regenerate:
			const auto mainDoorX = (rand() % (width - 4)) + 2;
			auto f = 25 + offset[mainDoorX];
			while (gettile(world, mainDoorX, f) != 0)
			{
				f--;
				if (f < 0) goto regenerate;
			}
			settile(world, mainDoorX, f, mainDoorType);
			settile(world, mainDoorX, f + 1, bedrockType);
			delete[] offset;
			delete[] offset2;
		}
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
}

inline void GenerateRegularWorld(WorldInfo* world, const int width, const int height, const int dirtType = 2, const int lavaType = 4, const int mainDoorType = 6, const int bedrockType = 8, const int rockType = 10, const int caveBackgroundType = 14, const int machineId = 0)
{
	try {
		//SendConsole("Generating new world (GenerateRegularWorld) details: width(" + to_string(width) + ") height(" + to_string(height) + ") dirtType(" + to_string(dirtType) + ") lavaType(" + to_string(lavaType) + ") mainDoorType(" + to_string(mainDoorType) + ") bedrockType(" + to_string(bedrockType) + ") rockType(" + to_string(rockType) + ") caveBackgroundType(" + to_string(caveBackgroundType) + ") machineId(" + to_string(machineId) + ")", "INFO");
		world->weather = machineId;
		const auto mainDoorX = (rand() % (world->width - 4)) + 2;
		for (auto i = 0; i < world->width * world->height; i++)
		{
			world->items.at(i).foreground = 0;
		}
		for (auto i = 0; i < world->width * world->height; i++)
		{
			if (i >= 3800 && i < 5400 && !(rand() % 50))
			{
				world->items.at(i).foreground = rockType;
			}
			else if (i >= 3700 && i < 5400)
			{
				if (i > 5000)
				{
					const auto m = rand() % 8;
					if (m < 3)
					{
						world->items.at(i).foreground = lavaType;
					}
					else
					{
						world->items.at(i).foreground = dirtType;
					}
				}
				else
				{
					world->items.at(i).foreground = dirtType;
				}
			}
			else if (i >= 5400)
			{
				world->items.at(i).foreground = bedrockType;
			}
			if (i == 3600 + mainDoorX)
			{
				world->items.at(i).foreground = mainDoorType;
			}
			if (i == 3700 + mainDoorX)
			{
				world->items.at(i).foreground = bedrockType;
			}
			if (i >= 3700)
			{
				world->items.at(i).background = caveBackgroundType;
			}
		}
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
}

inline WorldInfo CreateWorld(const string name, int width, int height, const bool cave = false, const int dirtType = 2, const int lavaType = 4, const int mainDoorType = 6, const int bedrockType = 8, const int rockType = 10, const int caveBackgroundType = 14) {
	WorldInfo world;
	world.name = name;
	world.width = width;
	world.height = height;
	world.drop_gem = false;
	GenerateGrowaloneLikeWorld(&world, cave, width, height, dirtType, lavaType, mainDoorType, bedrockType, rockType, caveBackgroundType, 0, 0, 0, BlastProperties_RandomDeco1);
	return world;
}

inline int PlayerDB::guildRegister(ENetPeer* peer, string guildName, string guildStatement, string guildFlagfg, string guildFlagbg)
{
	SendConsole("Registering new guild (guildRegister) details: guildName(" + guildName + ") guildStatement(" + guildStatement + ") guildFlagfg(" + guildFlagfg + ") guildFlagbg(" + guildFlagbg + ")", "INFO");
	string uname = guildName;
	if (guildName.find(" ") != string::npos || guildName.find(".") != string::npos || guildName.find(",") != string::npos || guildName.find("?") != string::npos || guildName.find("@") != string::npos || guildName.find("[") != string::npos || guildName.find("]") != string::npos || guildName.find("#") != string::npos || guildName.find("<") != string::npos || guildName.find(">") != string::npos || guildName.find(":") != string::npos || guildName.find("{") != string::npos || guildName.find("}") != string::npos || guildName.find("|") != string::npos || guildName.find("+") != string::npos || guildName.find("_") != string::npos || guildName.find("~") != string::npos || guildName.find("-") != string::npos || guildName.find("!") != string::npos || guildName.find("$") != string::npos || guildName.find("%") != string::npos || guildName.find("^") != string::npos || guildName.find("&") != string::npos || guildName.find("`") != string::npos || guildName.find("*") != string::npos || guildName.find("(") != string::npos || guildName.find(")") != string::npos || guildName.find("=") != string::npos || guildName.find("'") != string::npos || guildName.find(";") != string::npos || guildName.find("/") != string::npos)
	{
		return -1;
	}
	/*if (guildName == "prn" || guildName == "con" || guildName == "aux" || guildName == "nul" || guildName == "com1" || guildName == "com2" || guildName == "com3" || guildName == "com4" || guildName == "com5" || guildName == "com6" || guildName == "com7" || guildName == "com8" || guildName == "com9" || guildName == "lpt1" || guildName == "lpt2" || guildName == "lpt3" || guildName == "lpt4" || guildName == "lpt5" || guildName == "lpt6" || guildName == "lpt7" || guildName == "lpt8" || guildName == "lpt9")
	{
		return -1;
	}*/
	toUpperCase(uname);
	if (guildName.length() < 3)
	{
		return -2;
	}
	if (guildName.length() > 15)
	{
		return -3;
	}
	if (guildFlagfg.size() > 5 || guildFlagfg.size() < 0 || guildFlagbg.size() > 5 || guildFlagbg.size() < 0)
	{
		autoBan(peer, true, 99999, "tried to crash with guild reg things");
		return -1;
	}
	int fg;
	int bg;
	try
	{
		fg = stoi(guildFlagfg);
	}
	catch (...)
	{
		return -6;
	}
	try
	{
		bg = stoi(guildFlagbg);
	}
	catch (...)
	{
		return -5;
	}
	if (fg > maxItems || bg > maxItems)
	{
		return -1;
	}
	auto fixedguildName = PlayerDB::getProperName(guildName);
	std::ifstream ifs("save/guilds/" + fixedguildName + ".json");
	if (ifs.is_open())
	{
		return -4;
	}
	return 1;
}

WorldDB worldDB;

inline string GetPlayerCountServer() {
	auto count = 0;
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->isinv || static_cast<PlayerInfo*>(currentPeer->data)->displayName == "" || static_cast<PlayerInfo*>(currentPeer->data)->rawName == "") continue;
		count++;
	}
	return to_string(count);
}

inline AWorld WorldDB::get2(string name) {
	AWorld ret;
	try {
		name = getStrUpper(name);
		const auto p = std::find_if(worlds.begin(), worlds.end(), [name](const WorldInfo& a) { return a.name == name; });
		if (p != worlds.end()) {
			ret.id = p - worlds.begin();
			ret.info = worlds.at(p - worlds.begin());
			ret.ptr = &worlds.at(p - worlds.begin());
			return ret;
		}
		/*int size_b4 = worlds.size();
		for (int i = 0; i < worlds.size(); i++) {
			if (loop_freeze) {
				AWorld ret;
				ret.id = -1;
				return ret;
			}
			if (i >= worlds.size() || size_b4 != worlds.size()) {
				SendConsole("worlds.size() was larger than loop size", "ERROR");
				AWorld ret;
				ret.id = -1;
				return ret;
			}
			if (worlds.at(i).name == name) {
				int tiketinas = worlds.at(i).height * worlds.at(i).width;
				if (worlds.at(i).items.size() != tiketinas) {
					AWorld ret;
					ret.id = -1;
					return ret;
				}
				ret.id = i;
				ret.info = worlds.at(i);
				if (loop_freeze) {
					AWorld ret;
					ret.id = -1;
					return ret;
				}
				ret.ptr = &worlds.at(i);
				return ret;
			}
		}*/
		try {
			ifstream read_world("save/worlds/_" + name + ".json");
			if (!read_world.is_open()) {
				if (usedtinyblast == true) {
					usedtinyblast = false;
					WorldInfo info = CreateWorld(name, 60, 30);
					worlds.push_back(info);
					ret.id = worlds.size() - 1;
					ret.info = info;
					ret.ptr = &worlds.at(worlds.size() - 1);
					return ret;
				} else if (usedlargeblast == true) {
					usedlargeblast = false;
					WorldInfo info = CreateWorld(name, 150, 100);
					worlds.push_back(info);
					ret.id = worlds.size() - 1;
					ret.info = info;
					ret.ptr = &worlds.at(worlds.size() - 1);
					return ret;
				} else if (usedthermoblast == true) {
					usedthermoblast = false;
					WorldInfo info = CreateWorld(name, 100, 60, false, 0, 0, 6, 8, 0, 0);
					worlds.push_back(info);
					ret.id = worlds.size() - 1;
					ret.info = info;
					ret.ptr = &worlds.at(worlds.size() - 1);
					return ret;
				} else if (usedcaveblast == true) {
					usedcaveblast = false;
					WorldInfo info = CreateWorld(name, 90, 60, true);
					worlds.push_back(info);
					ret.id = worlds.size() - 1;
					ret.info = info;
					ret.ptr = &worlds.at(worlds.size() - 1);
					return ret;
				} 
				WorldInfo info = CreateWorld(name, 100, 60);
				worlds.push_back(info);
				ret.id = worlds.size() - 1;
				ret.info = info;
				ret.ptr = &worlds.at(worlds.size() - 1);
				return ret;
			}	
			json j;
			read_world >> j;
			read_world.close();
			string w_name = j["name"];
			string owner = j["owner"];
			string admins = j["admins"];
			bool nuked = j["nuked"];
			bool is_public = j["public"];
			int weather = j["weather"];
			int publicBlock = j["publicBlock"];
			bool silence = j["silence"];
			int update_id = j["update_id"];
			bool disableDrop = j["disableDrop"];
			string category = j["category"];
			int rating = j["rating"]; 
			int entrylevel = j["entrylevel"];
			int width = j["width"];
			int height = j["height"];
			json w_tiles = j["tiles"];
			json dropped = j["dropped"];
			bool rainbow = j["rainbow"];
			WorldInfo info;
			info.name = w_name;
			info.owner = owner;
			info.isNuked = nuked;
			info.isPublic = is_public;
			info.silence = silence;
			info.DisableDrop = disableDrop;
			info.rainbow = rainbow;
			if (admins != "") {
				vector<string> infoDats = explode("|", admins);
				for (auto i = 0; i < infoDats.size(); i++) {
					if (infoDats.at(i) == "") continue;
					info.accessed.push_back(infoDats.at(i));
				}
			}
			info.weather = weather;
			if (info.name == "GROWGANOTH") info.weather = 9;
			info.category = category;
			info.rating = rating;
			if (rating == 1) {
				info.drop_gem = false;
			} else {
				info.drop_gem = true;
			}
			info.entrylevel = entrylevel;
			info.width = width;
			info.height = height;
			info.publicBlock = publicBlock;
			json droppedobjects = dropped;
			for (int i = 0; i < droppedobjects.size(); i++) {
				DroppedItem di{};
				di.count = droppedobjects.at(i)["c"].get<BYTE>();
				di.id = droppedobjects.at(i)["id"].get<short>();
				di.x = droppedobjects.at(i)["x"].get<int>();
				di.y = droppedobjects.at(i)["y"].get<int>();
				di.uid = droppedobjects.at(i)["uid"].get<int>();
				info.droppedCount = di.uid + 1;
				info.droppedItems.push_back(di);
			}
			json tiles = w_tiles;
			auto square = info.width * info.height;
			for (int i = 0; i < w_tiles.size(); i++) {
				WorldItem w_tiles{};
				w_tiles.foreground = tiles.at(i)["fg"].get<int>();
				w_tiles.background = tiles.at(i)["bg"].get<int>();
				w_tiles.flipped = tiles.at(i)["r"].get<bool>();
				w_tiles.sign = tiles.at(i)["s"].get<string>();
				w_tiles.intdata = tiles.at(i)["int"].get<int>();
				w_tiles.label = tiles.at(i)["l"].get<string>();
				w_tiles.destWorld = tiles.at(i)["d"].get<string>();
				w_tiles.destId = tiles.at(i)["did"].get<string>();
				w_tiles.currId = tiles.at(i)["crid"].get<string>();
				w_tiles.password = tiles.at(i)["p"].get<string>();
				w_tiles.mid = tiles.at(i)["mid"].get<int>();
				w_tiles.mc = tiles.at(i)["mc"].get<int>();
				w_tiles.rm = tiles.at(i)["rm"].get<bool>();
				w_tiles.opened = tiles.at(i)["open"].get<bool>();
				w_tiles.vcount = tiles.at(i)["vc"].get<int>();
				w_tiles.vdraw = tiles.at(i)["vd"].get<int>();
				w_tiles.vid = tiles.at(i)["vid"].get<int>();
				w_tiles.vprice = tiles.at(i)["vp"].get<int>();
				w_tiles.monitorname = tiles.at(i)["how"].get<string>();
				w_tiles.monitoronline = tiles.at(i)["mon"].get<bool>();
				w_tiles.spliced = tiles.at(i)["spl"].get<bool>();
				w_tiles.activated = tiles.at(i)["a"].get<bool>();
				w_tiles.growtime = tiles.at(i)["sgt"].get<int>();
				w_tiles.fruitcount = tiles.at(i)["sfc"].get<int>();
				w_tiles.water = tiles.at(i)["w"].get<bool>();
				w_tiles.fire = tiles.at(i)["f"].get<bool>();
				w_tiles.red = tiles.at(i)["red"].get<int>();
				w_tiles.green = tiles.at(i)["gre"].get<int>();
				w_tiles.blue = tiles.at(i)["blu"].get<int>();
				w_tiles.evolvestage = tiles.at(i)["es"].get<int>();
				info.items.push_back(w_tiles);
			}
			worlds.push_back(info);
			j.clear();
			droppedobjects.clear();
			tiles.clear();
			ret.id = worlds.size() - 1;
			ret.info = info;
			ret.ptr = &worlds.at(worlds.size() - 1);
			return ret;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			WorldInfo info = CreateWorld(name, 100, 60);
			worlds.push_back(info);
			ret.id = worlds.size() - 1;
			ret.info = info;
			ret.ptr = &worlds.at(worlds.size() - 1);
			return ret;
		}
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
		AWorld ret;
		ret.id = -1;
		return ret;
	}
	throw 1;
}

inline WorldInfo WorldDB::get(const string name) const
{
	AWorld worldas = this->get2(name);
	if (worldas.id == -1) {
		worldas.info.name = "error";
	}
	return worldas.info;
}

inline WorldInfo* WorldDB::get_pointer(const string name) const
{
	AWorld worldas = this->get2(name);
	if (worldas.id == -1) {
		return NULL;
	}
	return worldas.ptr;
}

inline int getPlayersCountInWorld(const string name)
{
	auto count = 0;
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->isinv == false)
		{
			if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == name)
			{
				count++;
			}
		}
	}
	return count;
}

inline int getPlayersCountInWorldVSave(const string name) {
	auto count = 0;
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == name) {
			count++;
		}
	}
	return count;
}

/*bool flush(WorldInfo info) {
	try {
		json j;
		json WorldTiles = json::array();
		int current_update_id = 0;
		const int square = info.width * info.height;
		json WorldDropped = json::array();
		for (int i = 0; i < square; i++) {
			json tile;
			tile["fg"] = info.items.at(i).foreground;
			tile["bg"] = info.items.at(i).background;
			tile["s"] = info.items.at(i).sign;
			tile["r"] = info.items.at(i).flipped;
			tile["int"] = info.items.at(i).intdata;
			tile["l"] = info.items.at(i).label;
			tile["d"] = info.items.at(i).destWorld;
			tile["did"] = info.items.at(i).destId;
			tile["crid"] = info.items.at(i).currId;
			tile["p"] = info.items.at(i).password;
			tile["mid"] = info.items.at(i).mid;
			tile["mc"] = info.items.at(i).mc;
			tile["rm"] = info.items.at(i).rm;
			tile["open"] = info.items.at(i).opened;
			tile["vc"] = info.items.at(i).vcount;
			tile["vd"] = info.items.at(i).vdraw;
			tile["vid"] = info.items.at(i).vid;
			tile["vp"] = info.items.at(i).vprice;
			tile["how"] = info.items.at(i).monitorname;
			tile["mon"] = info.items.at(i).monitoronline;
			tile["spl"] = info.items.at(i).spliced;
			tile["a"] = info.items.at(i).activated;
			tile["sgt"] = info.items.at(i).growtime;
			tile["sfc"] = info.items.at(i).fruitcount;
			tile["w"] = info.items.at(i).water;
			tile["f"] = info.items.at(i).fire;
			tile["red"] = info.items.at(i).red;
			tile["gre"] = info.items.at(i).green;
			tile["blu"] = info.items.at(i).blue;
			tile["es"] = info.items.at(i).evolvestage;
			WorldTiles.push_back(tile);
			tile.clear();
		} for (int i = 0; i < info.droppedItems.size(); i++) {
			json droppedJ;
			droppedJ["c"] = static_cast<BYTE>(info.droppedItems.at(i).count);
			droppedJ["id"] = static_cast<short>(info.droppedItems.at(i).id);
			droppedJ["x"] = info.droppedItems.at(i).x;
			droppedJ["y"] = info.droppedItems.at(i).y;
			droppedJ["uid"] = info.droppedItems.at(i).uid;
			WorldDropped.push_back(droppedJ);
			droppedJ.clear();
		}
		j["name"] = info.name;
		j["owner"] = info.owner;
		string world_admins = "";
		for (int i = 0; i < info.accessed.size(); i++) {
			world_admins += info.accessed.at(i) + "|";
		}
		j["admins"] = world_admins;
		j["nuked"] = info.isNuked;
		j["public"] = info.isPublic;
		j["weather"] = info.weather;
		j["publicBlock"] = info.publicBlock;
		j["silence"] = info.silence;
		j["update_id"] = 0; 
		j["disableDrop"] = info.DisableDrop;
		j["category"] = info.category;
		j["rating"] = info.rating;
		j["entrylevel"] = info.entrylevel;
		j["width"] = info.width;
		j["height"] = info.height;
		j["tiles"] = WorldTiles;
		j["dropped"] = WorldDropped;
		j["rainbow"] = info.rainbow;
		ofstream write_player("save/worlds/_" + info.name + ".json");
		write_player << j << std::endl;
		write_player.close();
		j.clear();
		WorldTiles.clear();
		WorldDropped.clear();
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
		return false;
	} catch (std::exception& e) {
		cout << e.what() << endl;
		return false;
	}
	return true;
}*/

inline int getPlayersCountInWorldEvent(WorldInfo* world, string name) {
	int count = 0;
	try {
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (currentPeer->data == nullptr) {
				SendConsole("currentPeer was nullptr", "ERROR");
				continue;
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == name && !static_cast<PlayerInfo*>(currentPeer->data)->isinv) count++;
		}
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
	return count;
}

inline int getPlayersCountInWorldEvent(WorldInfo world, string name) {
	int count = 0;
	try {
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (currentPeer->data == nullptr) {
				SendConsole("currentPeer was nullptr", "ERROR");
				continue;
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == name && !static_cast<PlayerInfo*>(currentPeer->data)->isinv) count++;
		}
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
	return count;
}

/*inline void saveAll() {
	try {
		for (int i = 0; i < worlds.size(); i++) { 
			if (worlds.at(i).name != "EXIT" && worlds.at(i).name != "error") {
				flush(worlds.at(i));
			}
		}
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
}*/

vector<WorldInfo*> getRandomWorldsPointer(int how_much, int min_peoples) {
	vector<WorldInfo*> ret;
	try {
		if (worlds.size() != 0) {
			int added = 0;
			for (int i = 0; i < worlds.size(); i++) {
				WorldInfo* world = worldDB.get_pointer(worlds.at(i).name);
				if (world == NULL || world->isNuked || world->name == "EXIT") continue;
				added++;
				if (added > how_much) {
					break;
				}
				if (getPlayersCountInWorld(world->name) < min_peoples) continue;
				ret.push_back(world);
			} 
		}
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
	return ret;
}

inline bool isHereSave(ENetPeer* peer, ENetPeer* peer2)
{
	return static_cast<PlayerInfo*>(peer->data)->currentWorld == static_cast<PlayerInfo*>(peer2->data)->currentWorld;
}

inline int getPlayersCountInWorldSave(const string name)
{
	auto count = 0;
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
			continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->isinv == false)
		{
			if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == name)
			{
				count++;
			}
		}
	}
	return count;
}

inline WorldInfo* getPlyersWorld(ENetPeer* peer) {
	WorldInfo* world = worldDB.get_pointer(static_cast<PlayerInfo*>(peer->data)->currentWorld);
	if (world == NULL) {
		return NULL;
	}
	return worldDB.get2(static_cast<PlayerInfo*>(peer->data)->currentWorld).ptr;
}

struct ItemDefinition
{
	int id = 0;
	string name = "";
	int rarity = 0;
	int breakHits = 0;
	int growTime = 0;
	ClothTypes clothType{};
	BlockTypes blockType{};
	string description = "This item has no description.";
	string MultiFacing = "This item can be placed in both directions.";
	int properties = 0;
};

vector<ItemDefinition> itemDefs;
vector<DroppedItem> droppedItems;

inline ItemDefinition getItemDef(const int id)
{
	try {
		if (id < itemDefs.size() && id > 0 && id <= maxItems) {
			if (id == 1259 || id == 1261 || id == 1263 || id == 1265 || id == 1267 || id == 1269 || id == 1271 || id == 4309 || id == 4311 || id == 4313 || id == 4315 || id == 4317 || id == 4319) {
				itemDefs.at(id).name = "Surgical Tool Tree";
			}
			return itemDefs.at(id);
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return itemDefs.at(0);
}

inline void craftItemDescriptions()
{
	try {
		ifstream infile("Descriptions.txt");
		for (string line; getline(infile, line);)
		{
			if (line.length() > 3 && line[0] != '/' && line[1] != '/')
			{
				auto ex = explode("|", line);
				if (atoi(ex.at(0).c_str()) + 1 < itemDefs.size())
				{
					itemDefs.at(atoi(ex[0].c_str())).description = ex[1];
					if (!(atoi(ex.at(0).c_str()) % 2))
					{
						itemDefs.at(atoi(ex.at(0).c_str()) + 1).description = "This is a tree.";
					}
				}
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void buildItemsDatabase() {
	auto current = -1;
	ifstream infile("CoreData.txt");
	for (string line; getline(infile, line);) {
		if (line.length() > 8 && line[0] != '/' && line[1] != '/') {
			auto ex = explode("|", line);
			ItemDefinition def;
			def.id = atoi(ex[0].c_str());
			def.name = ex[1];
			def.rarity = atoi(ex[2].c_str());
			def.breakHits = atoi(ex[7].c_str());
			auto properties = explode(",", ex[3]);
			def.properties = Property_Zero;
			for (auto& prop : properties) {
				if (prop == "NoSeed") {
					def.properties += Property_NoSeed;
				}
				if (prop == "NoBlock") {
					def.properties += Property_NoBlock;
				}
				if (prop == "Dropless") {
					def.properties += Property_Dropless;
				}
				if (prop == "Beta") {
					def.properties += Property_Beta;
				}
				if (prop == "Mod") {
					def.properties += Property_Mod;
				}
				if (prop == "Untradable") {
					def.properties += Property_Untradable;
				}
				if (prop == "Wrenchable") {
					def.properties += Property_Wrenchable;
				}
				if (prop == "MultiFacing") {
					def.properties += Property_MultiFacing;
				}
				if (prop == "Permanent") {
					def.properties += Property_Permanent;
				}
				if (prop == "AutoPickup") {
					def.properties += Property_AutoPickup;
				}
				if (prop == "WorldLock") {
					def.properties += Property_WorldLock;
				}
				if (prop == "NoSelf") {
					def.properties += Property_NoSelf;
				}
				if (prop == "RandomGrow") {
					def.properties += Property_RandomGrow;
				}
				if (prop == "Public") {
					def.properties += Property_Public;
				}
				if (prop == "Foreground") {
					def.properties += Property_Foreground;
				}
				if (prop == "OnlyCombiner") {
					def.properties += Property_Chemical;
				}
			}
			string bt = ex[4];
			if (bt == "Foreground_Block")
			{
				def.blockType = BlockTypes::FOREGROUND;
			}
			else if (bt == "Background_Block")
			{
				def.blockType = BlockTypes::BACKGROUND;
			}
			else if (bt == "Seed")
			{
				def.blockType = BlockTypes::SEED;
			}
			else if (bt == "Consummable")
			{
				def.blockType = BlockTypes::CONSUMABLE;
			}
			else if (bt == "Pain_Block")
			{
				def.blockType = BlockTypes::PAIN_BLOCK;
			}
			else if (bt == "Main_Door")
			{
				def.blockType = BlockTypes::MAIN_DOOR;
			}
			else if (bt == "Bedrock")
			{
				def.blockType = BlockTypes::BEDROCK;
			}
			else if (bt == "Door")
			{
				def.blockType = BlockTypes::DOOR;
			}
			else if (bt == "Fist")
			{
				def.blockType = BlockTypes::FIST;
			}
			else if (bt == "Sign")
			{
				def.blockType = BlockTypes::SIGN;
			}
			else if (bt == "Back")
			{
				def.blockType = BlockTypes::BACKGROUND;
			}
			else if (bt == "Sheet_Music")
			{
				def.blockType = BlockTypes::BACKGROUND;
			}
			else if (bt == "Wrench")
			{
				def.blockType = BlockTypes::WRENCH;
			}
			else if (bt == "Checkpoint")
			{
				def.blockType = BlockTypes::CHECKPOINT;
			}
			else if (bt == "Lock")
			{
				def.blockType = BlockTypes::LOCK;
			}
			else if (bt == "Gateway")
			{
				def.blockType = BlockTypes::GATEWAY;
			}
			else if (bt == "Clothing")
			{
				def.blockType = BlockTypes::CLOTHING;
			}
			else if (bt == "Platform")
			{
				def.blockType = BlockTypes::PLATFORM;
			}
			else if (bt == "SFX_Foreground")
			{
				def.blockType = BlockTypes::SFX_FOREGROUND;
			}
			else if (bt == "Gems")
			{
				def.blockType = BlockTypes::GEMS;
			}
			else if (bt == "Toggleable_Foreground")
			{
				def.blockType = BlockTypes::TOGGLE_FOREGROUND;
			}
			else if (bt == "Chemical_Combiner")
			{
				def.blockType = BlockTypes::CHEMICAL_COMBINER;
			}
			else if (bt == "Treasure")
			{
				def.blockType = BlockTypes::TREASURE;
			}
			else if (bt == "Deadly_Block")
			{
				def.blockType = BlockTypes::DEADLY;
			}
			else if (bt == "Trampoline_Block")
			{
				def.blockType = BlockTypes::TRAMPOLINE;
			}
			else if (bt == "Animated_Foreground_Block")
			{
				def.blockType = BlockTypes::ANIM_FOREGROUND;
			}
			else if (bt == "Portal")
			{
				def.blockType = BlockTypes::PORTAL;
			}
			else if (bt == "Random_Block")
			{
				def.blockType = BlockTypes::RANDOM_BLOCK;
			}
			else if (bt == "Bouncy")
			{
				def.blockType = BlockTypes::BOUNCY;
			}
			else if (bt == "Chest")
			{
				def.blockType = BlockTypes::CHEST;
			}
			else if (bt == "Switch_Block")
			{
				def.blockType = BlockTypes::SWITCH_BLOCK;
			}
			else if (bt == "Magic_Egg")
			{
				def.blockType = BlockTypes::MAGIC_EGG;
			}
			else if (bt == "Crystal")
			{
				def.blockType = BlockTypes::CRYSTAL;
			}
			else if (bt == "Mailbox")
			{
				def.blockType = BlockTypes::MAILBOX;
			}
			else if (bt == "Bulletin_Board")
			{
				def.blockType = BlockTypes::BULLETIN_BOARD;
			}
			else if (bt == "Faction")
			{
				def.blockType = BlockTypes::FACTION;
			}
			else if (bt == "Component")
			{
				def.blockType = BlockTypes::COMPONENT;
			}
			else if (bt == "Weather_Machine")
			{
				def.blockType = BlockTypes::WEATHER;
			}
			else if (bt == "ItemSucker")
			{
				def.blockType = BlockTypes::SUCKER;
			}
			else if (bt == "Fish_Tank_Port")
			{
				def.blockType = BlockTypes::FISH;
			}
			else if (bt == "Steam_Block")
			{
				def.blockType = BlockTypes::STEAM;
			}
			else if (bt == "ground_Block")
			{
				def.blockType = BlockTypes::GROUND_BLOCK;
			}
			else if (bt == "Display")
			{
				def.blockType = BlockTypes::DISPLAY;
			}
			else if (bt == "Untrade_A_Box" || bt == "Safe_Vault")
			{
				def.blockType = BlockTypes::STORAGE;
			}
			else if (bt == "Vending")
			{
				def.blockType = BlockTypes::VENDING;
			}
			else if (bt == "Donation_Box")
			{
				def.blockType = BlockTypes::DONATION;
			}
			else if (bt == "Phone_Booth")
			{
				def.blockType = BlockTypes::PHONE;
			}
			else if (bt == "Sewing_Machine")
			{
				def.blockType = BlockTypes::SEWINGMACHINE;
			}
			else if (bt == "Crime_Villain")
			{
				def.blockType = BlockTypes::CRIME_VILLAIN;
			}
			else if (bt == "Provider")
			{
				def.blockType = BlockTypes::PROVIDER;
			}
			else
			{
				def.blockType = BlockTypes::UNKNOWN;
			}
			def.breakHits = atoi(ex[7].c_str());
			def.growTime = atoi(ex[8].c_str());
			if (def.id == 866) {
				def.growTime = 86400;
			} else if (def.id == 872) {
				def.growTime = 86400;
			} else if (def.id == 928) {
				def.growTime = 43200;
			} else if (def.id == 1008) {
				def.growTime = 79200;
			} else if (def.id == 1044) {
				def.growTime = 86400;
			} else if (def.id == 1632) {
				def.growTime = 86400;
			} else if (def.id == 1636) {
				def.growTime = 604800;
			} else if (def.id == 2798) {
				def.growTime = 86400;
			} else if (def.id == 3044) {
				def.growTime = 172800;
			} else if (def.id == 3888) {
				def.growTime = 259200;
			} else if (def.id == 4858) {
				def.growTime = 4200;
			} else if (def.id == 5116) {
				def.growTime = 86400;
			} else if (def.id == 5318) {
				def.growTime = 86400;
			} else if (def.id == 6212) {
				def.growTime = 432000;
			} else if (def.id == 6414) {
				def.growTime = 432000;
			} else if (def.id == 7476) {
				def.growTime = 86400;
			} else if (def.id == 7766) {
				def.growTime = 172800;
			} else if (def.id == 7770) {
				def.growTime = 259200;
			} else if (def.id == 7774) {
				def.growTime = 259200;
			} else if (def.id == 7778) {
				def.growTime = 259200;
			} else if (def.id == 8050) {
				def.growTime = 172800;
			} else if (def.id == 8076) {
				def.growTime = 432000;
			} else if (def.id == 8088) {
				def.growTime = 432000;
			} else if (def.id == 8100) {
				def.growTime = 432000;
			} else if (def.id == 8112) {
				def.growTime = 432000;
			} else if (def.id == 8124) {
				def.growTime = 432000;
			} else if (def.id == 8136) {
				def.growTime = 432000;
			} else if (def.id == 8148) {
				def.growTime = 432000;
			} else if (def.id == 8160) {
				def.growTime = 432000;
			} else if (def.id == 8172) {
				def.growTime = 432000;
			} else if (def.id == 8196) {
				def.growTime = 86400;
			} else if (def.id == 9224) {
				def.growTime = 86400;
			} else if (def.id == 9302) {
				def.growTime = 259200;
			} else if (def.id == 10446) {
				def.growTime = 86400;
			} else if (def.id == 10450) {
				def.growTime = 86400;
			} else if (def.id == 10656) {
				def.growTime = 12000;
			} else if (def.id == 10656) {
				def.growTime = 12000;
			}
			string cl = ex[9];
			if (def.blockType == BlockTypes::CLOTHING)
			{
				if (cl == "None")
				{
					def.clothType = ClothTypes::NONE;
				}
				else if (cl == "Hat")
				{
					def.clothType = ClothTypes::HAIR;
				}
				else if (cl == "Shirt")
				{
					def.clothType = ClothTypes::SHIRT;
				}
				else if (cl == "Pants")
				{
					def.clothType = ClothTypes::PANTS;
				}
				else if (cl == "Feet")
				{
					def.clothType = ClothTypes::FEET;
				}
				else if (cl == "Face")
				{
					def.clothType = ClothTypes::FACE;
				}
				else if (cl == "Hand")
				{
					def.clothType = ClothTypes::HAND;
				}
				else if (cl == "Back")
				{
					def.clothType = ClothTypes::BACK;
				}
				else if (cl == "Hair")
				{
					def.clothType = ClothTypes::MASK;
				}
				else if (cl == "Chest")
				{
					def.clothType = ClothTypes::NECKLACE;
				}
				else
				{
					def.clothType = ClothTypes::NONE;
				}
			}
			else
			{
				def.clothType = ClothTypes::NONE;
			}
			if (++current != def.id)
			{
				SendConsole("Unordered database at item " + std::to_string(current) + "/" + std::to_string(def.id), "ERROR");
			}
			maxItems = def.id;
			itemDefs.push_back(def);
		} 
	}
	craftItemDescriptions();
}

inline BYTE* packBlockVisual(TileExtra* dataStruct)
{
	const auto data = new BYTE[104];
	for (auto i = 0; i < 100; i++)
	{
		data[i] = 0;
	}
	memcpy(data, &dataStruct->packetType, 4);
	memcpy(data + 8, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 16, &dataStruct->objectSpeedX, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	memcpy(data + 52, &dataStruct->charStat, 4);
	memcpy(data + 56, &dataStruct->blockid, 2);
	memcpy(data + 58, &dataStruct->backgroundid, 2);
	memcpy(data + 60, &dataStruct->visual, 4);
	memcpy(data + 64, &dataStruct->displayblock, 4);
	return data;
}

inline BYTE* packBlockVisual(BlockVisual* dataStruct)
{
	const auto data = new BYTE[72];
	for (auto i = 0; i < 72; i++)
	{
		data[i] = 0;
	}
	memcpy(data, &dataStruct->packetType, 4);
	memcpy(data + 8, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	memcpy(data + 52, &dataStruct->charStat, 4);
	memcpy(data + 56, &dataStruct->blockid, 4);
	memcpy(data + 60, &dataStruct->visual, 4);
	memcpy(data + 64, &dataStruct->displayblock, 4);
	return data;
}

inline BYTE* packStuffVisual(TileExtra* dataStruct, int options, int gravity)
{
	const auto data = new BYTE[102];
	for (auto i = 0; i < 102; i++)
	{
		data[i] = 0;
	}
	memcpy(data, &dataStruct->packetType, 4);
	memcpy(data + 8, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	memcpy(data + 52, &dataStruct->charStat, 4);
	memcpy(data + 56, &dataStruct->blockid, 2);
	memcpy(data + 58, &dataStruct->backgroundid, 2);
	memcpy(data + 60, &dataStruct->visual, 4);
	memcpy(data + 64, &dataStruct->displayblock, 4);
	memcpy(data + 68, &gravity, 4);
	memcpy(data + 70, &options, 4);
	return data;
}

inline BYTE* packStuffVisual333(TileExtra* dataStruct)
{
	const auto data = new BYTE[102];
	for (auto i = 0; i < 102; i++)
	{
		data[i] = 0;
	}
	memcpy(data, &dataStruct->packetType, 4);
	memcpy(data + 8, &dataStruct->netID, 4);
	memcpy(data + 12, &dataStruct->characterState, 4);
	memcpy(data + 44, &dataStruct->punchX, 4);
	memcpy(data + 48, &dataStruct->punchY, 4);
	memcpy(data + 52, &dataStruct->charStat, 4);
	memcpy(data + 56, &dataStruct->blockid, 2);
	memcpy(data + 58, &dataStruct->backgroundid, 2);
	memcpy(data + 60, &dataStruct->visual, 4);
	memcpy(data + 64, &dataStruct->displayblock, 4);
	return data;
}

inline void SendPacketRaw3(int a1, void* packetData, const size_t packetDataSize, void* a4, ENetPeer* peer, const int packetFlag)
{
	if (peer)
	{
		const auto p = enet_packet_create(nullptr, packetDataSize + 5, packetFlag);
		memcpy(p->data, &a1, 4);
		memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
		enet_peer_send(peer, 0, p);
	}
	delete static_cast<char*>(packetData);
}

inline void SendPacketRaw2(int a1, void* packetData, const size_t packetDataSize, void* a4, ENetPeer* peer, const int packetFlag)
{
	ENetPacket* p;
	if (peer)
	{
		if (a1 == 4 && *(static_cast<BYTE*>(packetData) + 12) & 8)
		{
			p = enet_packet_create(nullptr, packetDataSize + *(static_cast<DWORD*>(packetData) + 13) + 5, packetFlag);
			auto four = 4;
			memcpy(p->data, &four, 4);
			memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
			memcpy(reinterpret_cast<char*>(p->data) + packetDataSize + 4, a4, *(static_cast<DWORD*>(packetData) + 13));
			enet_peer_send(peer, 0, p);
		}
		else
		{
			if (a1 == 192)
			{
				a1 = 4;
				p = enet_packet_create(nullptr, packetDataSize + 5, packetFlag);
				memcpy(p->data, &a1, 4);
				memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
				enet_peer_send(peer, 0, p);
			}
			else
			{
				p = enet_packet_create(nullptr, packetDataSize + 5, packetFlag);
				memcpy(p->data, &a1, 4);
				memcpy(reinterpret_cast<char*>(p->data) + 4, packetData, packetDataSize);
				enet_peer_send(peer, 0, p);
			}
		}
	}
	// ReSharper disable once CppDeletingVoidPointer
	delete static_cast<char*>(packetData);
}

inline void updatetile(ENetPeer* peer, const int netID, const int x, const int y)
{
	BlockVisual data3{};
	data3.packetType = 0x5;
	data3.characterState = 8;
	data3.charStat = 8;
	data3.blockid = 2;
	data3.backgroundid = 2;
	data3.visual = 0x03000000;
	data3.punchX = x;
	data3.punchY = y;
	data3.netID = netID;
	SendPacketRaw2(192, packBlockVisual(&data3), 100, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
}

inline void update_entrance(ENetPeer* peer, int foreground, int x, int y, bool open, int bg) {
	BYTE* data = new BYTE[69];// memset(data, 0, 69);
	for (int i = 0; i < 69; i++) data[i] = 0;
	int four = 4; int five = 5; int eight = 8;
	// ReSharper disable once CppDeclaratorNeverUsed
	int huhed = (65536 * bg) + foreground; int loled = 128;

	memcpy(data, &four, 4);
	memcpy(data + 4, &five, 4);
	memcpy(data + 16, &eight, 4);
	memcpy(data + 48, &x, 4);
	memcpy(data + 52, &y, 4);
	memcpy(data + 56, &eight, 4);
	memcpy(data + 60, &foreground, 4);
	memcpy(data + 62, &bg, 4);

	if (open) {
		int state = 0;
		memcpy(data + 66, &loled, 4);
		memcpy(data + 68, &state, 4);
	}
	else {
		int state = 100;
		int yeetus = 25600;
		memcpy(data + 67, &yeetus, 5);
		memcpy(data + 68, &state, 4);
	}
	ENetPacket* p = enet_packet_create(data, 69, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, p);
	delete[] data;
}

inline void updatepeffect(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->haveGrowId)
	{
		sendPuncheffectpeer(peer, static_cast<PlayerInfo*>(peer->data)->effect);
	}
}

inline void changetile(ENetPeer* peer, const int x, const int y)
{
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer))
		{
			BlockVisual data3{};
			data3.packetType = 0x5;
			data3.characterState = 8;
			data3.charStat = 8;
			data3.blockid = 260;
			data3.backgroundid = 260;
			data3.visual = 0x00400000;
			data3.punchX = x;
			data3.punchY = y;
			data3.netID = static_cast<PlayerInfo*>(peer->data)->netID;
			SendPacketRaw2(192, packBlockVisual(&data3), 100, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
}

inline void sendPData(ENetPeer* peer, PlayerMoving* data)
{
	for (ENetPeer* currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (peer != currentPeer)
		{
			if (isHere(peer, currentPeer))
			{
				data->netID = static_cast<PlayerInfo*>(peer->data)->netID;
				SendPacketRaw(4, packPlayerMoving(data), 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
			}
		}
	}
}

inline void sendArrow(ENetPeer* peer, const uint16_t itemid, const bool droppeditem) {
    PlayerMoving pmov;
	memset(&pmov, 0, sizeof(PlayerMoving));
	*reinterpret_cast<uint32_t*>(&pmov) = 37 | (droppeditem << 8);
	pmov.netID = itemid;
	const auto pmovpacked = packPlayerMoving(&pmov);
	const auto packet = new uint8_t[4 + 56];
	memset(packet, 0, 4 + 56);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, sizeof(PlayerMoving));
	const auto epacket = enet_packet_create(packet, 4 + 56, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, epacket);
	delete pmovpacked;
	delete[] packet;
}

inline void initialize_packet_with_mannequin(BYTE* raw)
{
	int i = 0;
	raw[i] = 0x05; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x08; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x09; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x17; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x22; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x8c; i++;
	raw[i] = 0x05; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x01; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x0e; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00;
}
inline void updateMannequin(ENetPeer* peer, int foreground, int x, int y, int background, string text, int clothHair, int clothHead, int clothMask, int clothHand, int clothNeck, int clothShirt, int clothPants, int clothFeet, int clothBack, bool sendPacketToEveryone = true, int blockState = 0) {
	PlayerMoving sign{};
	sign.packetType = 0x3;
	sign.characterState = 0x0;
	sign.x = x;
	sign.y = y;
	sign.punchX = x;
	sign.punchY = y;
	sign.XSpeed = 0;
	sign.YSpeed = 0;
	sign.netID = -1;
	sign.plantingTree = foreground;
	SendPacketRaw(4, packPlayerMoving(&sign), 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	short textLen = text.size();
	const int plength = 95 + textLen;
	BYTE* raw = new BYTE[plength];
	memset(raw, 0, plength);
	initialize_packet_with_mannequin(raw);
	int negativeOne = -1;
	int adjhasdjk = 0xfdfdfdfd;
	memcpy(raw + 44, &x, sizeof(int));
	memcpy(raw + 48, &y, sizeof(int));
	memcpy(raw + 56, &foreground, sizeof(short));
	memcpy(raw + 58, &background, sizeof(short));
	memcpy(raw + 60, &blockState, sizeof(short));
	memcpy(raw + 65, &textLen, sizeof(short));
	memcpy(raw + 67, text.c_str(), textLen);
	memcpy(raw + 68 + textLen, &negativeOne, sizeof(int));
	memcpy(raw + 72 + textLen, &clothHead, sizeof(short));
	memcpy(raw + 74 + textLen, &clothShirt, sizeof(short));
	memcpy(raw + 76 + textLen, &clothPants, sizeof(short));
	memcpy(raw + 78 + textLen, &clothFeet, sizeof(short));
	memcpy(raw + 80 + textLen, &clothMask, sizeof(short));
	memcpy(raw + 82 + textLen, &clothHand, sizeof(short));
	memcpy(raw + 84 + textLen, &clothBack, sizeof(short));
	memcpy(raw + 86 + textLen, &clothHair, sizeof(short));
	memcpy(raw + 88 + textLen, &clothNeck, sizeof(short));
	memcpy(raw + 91 + textLen, &adjhasdjk, sizeof(short));
	const auto p = enet_packet_create(nullptr, plength + 4, ENET_PACKET_FLAG_RELIABLE);
	auto four = 4;
	memcpy(p->data, &four, sizeof(int));
	memcpy(reinterpret_cast<char*>(p->data) + 4, raw, plength);
	if (sendPacketToEveryone) {
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer)) {
				enet_peer_send(currentPeer, 0, p);
			}
		}
		delete[] raw;
	}
	else
	{
		enet_peer_send(peer, 0, p);
		delete[] raw;
	}
}

inline bool isWorldAdmin(ENetPeer* peer, WorldInfo* world) {
	try {
		for (int i = 0; i < world->accessed.size(); i++) {
			if (world->accessed.at(i) == "") continue;
			if (world->accessed.at(i) == static_cast<PlayerInfo*>(peer->data)->rawName) return true;
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return false;
}

inline bool isWorldAdmin(ENetPeer* peer, WorldInfo world) {
	try {
		for (int i = 0; i < world.accessed.size(); i++) {
			if (world.accessed.at(i) == "") continue;
			if (world.accessed.at(i) == static_cast<PlayerInfo*>(peer->data)->rawName) return true;
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return false;
}

inline bool isWorldAdmin(string name, WorldInfo* world) {
	try {
		for (int i = 0; i < world->accessed.size(); i++) {
			if (world->accessed.at(i) == "") continue;
			if (world->accessed.at(i) == name) return true;
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return false;
}

inline void restoreplayernick(ENetPeer* peer)
{
	if (serverIsFrozen || static_cast<PlayerInfo*>(peer->data)->currentWorld == "EXIT" || static_cast<PlayerInfo*>(peer->data)->isIn == false || static_cast<PlayerInfo*>(peer->data)->isNicked) return;
	WorldInfo* world = getPlyersWorld(peer);
	if (world == NULL) {
		SendConsole("restoreplayernick error", "ERROR");
		return;
	}
	try {
		if (static_cast<PlayerInfo*>(peer->data)->rawName == world->owner) {
			if (static_cast<PlayerInfo*>(peer->data)->NickPrefix != "") {
				static_cast<PlayerInfo*>(peer->data)->displayName = static_cast<PlayerInfo*>(peer->data)->NickPrefix + ". " + "`2" + role_prefix.at(static_cast<PlayerInfo*>(peer->data)->adminLevel) + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			}
			else {
				static_cast<PlayerInfo*>(peer->data)->displayName = "`2" + role_prefix.at(static_cast<PlayerInfo*>(peer->data)->adminLevel) + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			}
		}
		else if (isWorldAdmin(peer, world)) {
			if (static_cast<PlayerInfo*>(peer->data)->NickPrefix != "") {
				static_cast<PlayerInfo*>(peer->data)->displayName = static_cast<PlayerInfo*>(peer->data)->NickPrefix + ". " + "`^" + role_prefix.at(static_cast<PlayerInfo*>(peer->data)->adminLevel) + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			}
			else {
				static_cast<PlayerInfo*>(peer->data)->displayName = "`^" + role_prefix.at(static_cast<PlayerInfo*>(peer->data)->adminLevel) + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			}
		}
		else {
			if (static_cast<PlayerInfo*>(peer->data)->NickPrefix != "") {
				static_cast<PlayerInfo*>(peer->data)->displayName = static_cast<PlayerInfo*>(peer->data)->NickPrefix + ". " + role_prefix.at(static_cast<PlayerInfo*>(peer->data)->adminLevel) + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			}
			else {
				static_cast<PlayerInfo*>(peer->data)->displayName = role_prefix.at(static_cast<PlayerInfo*>(peer->data)->adminLevel) + static_cast<PlayerInfo*>(peer->data)->tankIDName;
			}
		} if (static_cast<PlayerInfo*>(peer->data)->ltitle && static_cast<PlayerInfo*>(peer->data)->ltitleunlocked && static_cast<PlayerInfo*>(peer->data)->displayName.find(" of Legend``") == string::npos) {
			static_cast<PlayerInfo*>(peer->data)->displayName += " of Legend``";
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void updateplayer(ENetPeer* peer) {
	const auto item = static_cast<PlayerInfo*>(peer->data)->cloth_back;
	if (item == 8552) {
		static_cast<PlayerInfo*>(peer->data)->isDr = true;
		static_cast<PlayerInfo*>(peer->data)->canDoubleJump = true;
	}
	else if (item == 10426 || item == 1784 || item == 1674 || item == 9434 || item == 9006 || item == 1958 || getItemDef(item).name.find("Aura") != string::npos || getItemDef(item).name.find("Wings") != string::npos || getItemDef(item).name.find("Cape") != string::npos || item == 8580 || item == 9410 || item == 9306 || item == 10020 || item == 10012 || item == 5158 || item == 9466 || item == 10016 || item == 5136 || item == 9760 || item == 10022 || item == 9478 || item == 9506 || item == 9476 || item == 1970 || item == 8286 || item == 156 || item == 9434 || item == 8552 || item == 362 || item == 678 || item == 736 || item == 7734 || item == 7762 || item == 818 || item == 1206 || item == 1460 || item == 1550 || item == 1574 || item == 1668 || item == 1672 || item == 1824 || item == 1936 || item == 1938 || item == 2254 || item == 2256 || item == 2258 || item == 2260 || item == 2262 || item == 2264 || item == 2390 || item == 2392 || item == 3120 || item == 3308 || item == 3512 || item == 4534 || item == 4986 || item == 5754 || item == 6144 || item == 6334 || item == 6694 || item == 6818 || item == 6842 || item == 1934 || item == 3134 || item == 6004 || item == 1780 || item == 2158 || item == 2160 || item == 2162 || item == 2164 || item == 2166 || item == 2168 || item == 2438 || item == 2538 || item == 2778 || item == 3858 || item == 350 || item == 998 || item == 1738 || item == 2642 || item == 2982 || item == 3104 || item == 3144 || item == 5738 || item == 3112 || item == 2722 || item == 3114 || item == 4970 || item == 4972 || item == 5020 || item == 6284 || item == 4184 || item == 4628 || item == 5322 || item == 4112 || item == 4114 || item == 3442 || item == 9466 || item == 5136 || item == 9416 || item == 9356)
	{
		static_cast<PlayerInfo*>(peer->data)->canDoubleJump = true;
	}
	updatepeffect(peer);
}

inline void send_rift_cape(ENetPeer* peer, PlayerInfo* pData) {
	GamePacket p7 = packetEnd(appendInt(appendInt(appendInt(appendInt(appendInt(appendInt(appendString(createPacket(), "OnRiftCape"), pData->rift_type), pData->rift_cape_color), 723421695), pData->rift_collar_color), 1059267327), 30));
	memcpy(p7.data + 8, &(pData->netID), 4);
	ENetPacket* packet7 = enet_packet_create(p7.data, p7.len, ENET_PACKET_FLAG_RELIABLE);
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			enet_peer_send(currentPeer, 0, packet7);
		}
	}
	delete p7.data;
}

inline void send_state(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->currentWorld == "EXIT") return;
	if (static_cast<PlayerInfo*>(peer->data)->cloth_necklace == 4656) static_cast<PlayerInfo*>(peer->data)->haveGeigerRadiation = true;
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			PlayerMoving data{};
			auto water = 125.0f;
			data.packetType = 0x14;
			data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
			data.x = 1000;
			if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 366) data.y = -400;
			else data.y = 400;
			data.punchX = 0;
			data.punchY = 0;
			data.XSpeed = 300;
			if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 9472) data.YSpeed = 600;
			else if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 5196 || static_cast<PlayerInfo*>(peer->data)->cloth_back == 7558) data.YSpeed = 250;
			else data.YSpeed = 1000;
			data.netID = netID;
			data.plantingTree = state;
			const auto raw = packPlayerMoving(&data);
			auto var = static_cast<PlayerInfo*>(peer->data)->effect;
			memcpy(raw + 1, &var, 3);
			memcpy(raw + 16, &water, 4);
			SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
	restoreplayernick(peer);
	Player::OnNameChanged(peer, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->displayName);
	updateplayer(peer);
	if (static_cast<PlayerInfo*>(peer->data)->isZombie == true || static_cast<PlayerInfo*>(peer->data)->cloth_feet == 898 || static_cast<PlayerInfo*>(peer->data)->cloth_feet == 1830 || static_cast<PlayerInfo*>(peer->data)->cloth_feet == 1966) playerconfig(peer, 1150, 130, 0x14);
	if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 9506) playerconfig(peer, 1150, 500, 0x14);
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			if (static_cast<PlayerInfo*>(currentPeer->data)->cloth_back == 10424) {
				send_rift_cape(peer, static_cast<PlayerInfo*>(currentPeer->data));
			}
			if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 10424) {
				send_rift_cape(currentPeer, static_cast<PlayerInfo*>(peer->data));
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->guild != "") {
				gamepacket_t p(0, static_cast<PlayerInfo*>(currentPeer->data)->netID);
				p.Insert("OnGuildDataChanged");
				p.Insert(36095);
				p.Insert(63158650);
				p.Insert((65536 * static_cast<PlayerInfo*>(currentPeer->data)->guildBg) + static_cast<PlayerInfo*>(currentPeer->data)->guildFg);
				p.Insert(static_cast<PlayerInfo*>(currentPeer->data)->guild_rank);
				p.CreatePacket(peer);
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
			if (peer != currentPeer) {
				PlayerMoving data{};
				data.packetType = 0x14;
				data.characterState = static_cast<PlayerInfo*>(currentPeer->data)->characterState;
				data.x = 1000;
				data.y = 400;
				data.punchX = 0;
				data.punchY = 0;
				data.XSpeed = 300;
				data.YSpeed = 1000;
				data.netID = static_cast<PlayerInfo*>(currentPeer->data)->netID;
				data.plantingTree = getState(static_cast<PlayerInfo*>(currentPeer->data));
				const auto raw = packPlayerMoving(&data);
				auto var = static_cast<PlayerInfo*>(currentPeer->data)->effect;
				memcpy(raw + 1, &var, 3);
				SendPacketRaw(4, raw, 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
			}	
			gamepacket_t p_name(0, static_cast<PlayerInfo*>(currentPeer->data)->netID);
			p_name.Insert("OnNameChanged");
			if (static_cast<PlayerInfo*>(currentPeer->data)->displayName.find("``") != string::npos) {
				p_name.Insert(static_cast<PlayerInfo*>(currentPeer->data)->displayName);
			}
			else {
				p_name.Insert(static_cast<PlayerInfo*>(currentPeer->data)->displayName + "``");
			}
			p_name.CreatePacket(peer);
		}
	}
}

inline void end_surgery(ENetPeer* peer, bool Fail) {
	if (Fail) {
		WorldInfo* world = getPlyersWorld(peer);
		if (world == NULL) {
			SendConsole("end_surgery error", "ERROR");
			return;
		}
		try {
			Player::OnConsoleMessage(peer, "You couldn't save them!");
			Player::OnConsoleMessage(peer, "You are not allowed to perform surgery for a while! (`$Malpractice`` mod added, `$1 hour`` left)");
			ENetPeer* currentPeer;
			for (currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
				if (isHere(peer, currentPeer)) {
					Player::PlayAudio(currentPeer, "audio/metal_destroy.wav", 0);
				}
			}
			if (static_cast<PlayerInfo*>(peer->data)->lastPunchX >= 0 && static_cast<PlayerInfo*>(peer->data)->lastPunchY >= 0) {
				world->items.at(static_cast<PlayerInfo*>(peer->data)->lastPunchX + (static_cast<PlayerInfo*>(peer->data)->lastPunchY * world->width)).foreground = 0;
				PlayerMoving data3{};
				data3.packetType = 0x3;
				data3.characterState = 0x0;
				data3.x = static_cast<PlayerInfo*>(peer->data)->lastPunchX;
				data3.y = static_cast<PlayerInfo*>(peer->data)->lastPunchY;
				data3.punchX = static_cast<PlayerInfo*>(peer->data)->lastPunchX;
				data3.punchY = static_cast<PlayerInfo*>(peer->data)->lastPunchY;
				data3.XSpeed = 0;
				data3.YSpeed = 0;
				data3.netID = -1;
				data3.plantingTree = 0;
				for (currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
					if (isHere(peer, currentPeer)) {
						const auto raw = packPlayerMoving(&data3);
						raw[2] = 0;
						raw[3] = 0;
						SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
						Player::OnParticleEffect(currentPeer, 57, static_cast<PlayerInfo*>(peer->data)->lastPunchX * 32, static_cast<PlayerInfo*>(peer->data)->lastPunchY * 32, 0);
					}
				}
			}
			static_cast<PlayerInfo*>(peer->data)->SurgeryTime = (GetCurrentTimeInternalSeconds() + (60 * 60));
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		}
	} else {
		if (SurgeryDay) {
			static_cast<PlayerInfo*>(peer->data)->SurgeryTime = (GetCurrentTimeInternalSeconds() + (30 * 60));
		} else {
			static_cast<PlayerInfo*>(peer->data)->SurgeryTime = (GetCurrentTimeInternalSeconds() + (20 * 60));
		}
	}
	static_cast<PlayerInfo*>(peer->data)->SurgeryCooldown = true;
	static_cast<PlayerInfo*>(peer->data)->PatientDiagnosis = "";
	static_cast<PlayerInfo*>(peer->data)->PatientPulse = "";
	static_cast<PlayerInfo*>(peer->data)->PatientStatus = "";
	static_cast<PlayerInfo*>(peer->data)->PatientTemperature = 0;
	static_cast<PlayerInfo*>(peer->data)->OperationSite = "";
	static_cast<PlayerInfo*>(peer->data)->PatientIncisions = 0;
	static_cast<PlayerInfo*>(peer->data)->PerformingSurgery = false;
	static_cast<PlayerInfo*>(peer->data)->HardToSee = false;
	static_cast<PlayerInfo*>(peer->data)->PatientLosingBlood = false;
	static_cast<PlayerInfo*>(peer->data)->TempColor = "";
	static_cast<PlayerInfo*>(peer->data)->UnlockedAntibiotic = false;
	static_cast<PlayerInfo*>(peer->data)->PatientHeartStopped = false;
	static_cast<PlayerInfo*>(peer->data)->SurgeryCooldown = true;
	static_cast<PlayerInfo*>(peer->data)->PatientTemperatureRise = 0;
	static_cast<PlayerInfo*>(peer->data)->IncisionsColor = "";
	static_cast<PlayerInfo*>(peer->data)->FixIt = false;
	static_cast<PlayerInfo*>(peer->data)->Ultrasound = 0;
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
}

string FormatTradeItemsForMessage(vector<TradeItem> tradeItems) {
	if (tradeItems.size() < 1) return "nothing";
	string fmt;
	for (auto& t : tradeItems) {
		if (fmt.size() > 0)
			fmt += ", " + to_string(t.count) + " " + getItemDef(t.id).name + "";
		else
			fmt += to_string(t.count) + " " + getItemDef(t.id).name + "";
	}
	return fmt;
}

string FormatTradeItemsForDialog(vector<TradeItem> tradeItems, bool getting) {
	if (tradeItems.size() == 0) {
		string a = "\nadd_textbox|`4Nothing!``|left|";
		return a;
	}
	string fmt;
	for (auto& t : tradeItems) {
		fmt += "\nadd_label_with_icon|small|(`w" + to_string(t.count) + "``) " + getItemDef(t.id).name + "|left|" + to_string(t.id) + "|";
	}
	return fmt;
}

inline void sendPlayerLeave(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->trade) end_trade(peer, false, true);
	if (static_cast<PlayerInfo*>(peer->data)->Fishing) {
		static_cast<PlayerInfo*>(peer->data)->TriggerFish = false;
		static_cast<PlayerInfo*>(peer->data)->FishPosX = 0;
		static_cast<PlayerInfo*>(peer->data)->FishPosY = 0;
		static_cast<PlayerInfo*>(peer->data)->Fishing = false;
		send_state(peer);
	}
	if (static_cast<PlayerInfo*>(peer->data)->PerformingSurgery) {
		end_surgery(peer, true);
	}
	static_cast<PlayerInfo*>(peer->data)->cpY = 0;
	static_cast<PlayerInfo*>(peer->data)->cpY = 0;
	static_cast<PlayerInfo*>(peer->data)->usedCP = false;
	if (find(static_cast<PlayerInfo*>(peer->data)->lastworlds.begin(), static_cast<PlayerInfo*>(peer->data)->lastworlds.end(), static_cast<PlayerInfo*>(peer->data)->currentWorld) != static_cast<PlayerInfo*>(peer->data)->lastworlds.end()) {
		static_cast<PlayerInfo*>(peer->data)->lastworlds.erase(std::remove(static_cast<PlayerInfo*>(peer->data)->lastworlds.begin(), static_cast<PlayerInfo*>(peer->data)->lastworlds.end(), static_cast<PlayerInfo*>(peer->data)->currentWorld), static_cast<PlayerInfo*>(peer->data)->lastworlds.end());
		static_cast<PlayerInfo*>(peer->data)->lastworlds.push_back(static_cast<PlayerInfo*>(peer->data)->currentWorld);
	} else {
		static_cast<PlayerInfo*>(peer->data)->lastworlds.push_back(static_cast<PlayerInfo*>(peer->data)->currentWorld);
	}
	static_cast<PlayerInfo*>(peer->data)->ischeck = false;
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == "EXIT") continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->isIn == false) continue;
		if (isHere(peer, currentPeer)) {
			Player::OnRemove(currentPeer, static_cast<PlayerInfo*>(peer->data)->netID);
			if (!static_cast<PlayerInfo*>(peer->data)->isinv) {
				Player::OnConsoleMessage(currentPeer, "`5<`w" + static_cast<PlayerInfo*>(peer->data)->displayName + "`` `5left, `w" + std::to_string(getPlayersCountInWorld(static_cast<PlayerInfo*>(peer->data)->currentWorld) - 1) + "`` `5others here>```w");
				Player::OnTalkBubble(currentPeer, static_cast<PlayerInfo*>(peer->data)->netID, "`5<`w" + static_cast<PlayerInfo*>(peer->data)->displayName + "`` `5left, `w" + std::to_string(getPlayersCountInWorld(static_cast<PlayerInfo*>(peer->data)->currentWorld) - 1) + "`` `5others here>```w", 0, true);
				Player::PlayAudio(currentPeer, "audio/door_shut.wav", 0);
			}
		}
	}
	static_cast<PlayerInfo*>(peer->data)->currentWorld = "EXIT";
	if (gem_multiplier != 0) Player::OnConsoleMessage(peer, "`9There is a `#" + to_string(gem_multiplier) + "x `9gem event going-on! Don't miss it.");
}

inline void sendRoulete(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->lastSPIN + 1500 < (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count())
	{
		static_cast<PlayerInfo*>(peer->data)->lastSPIN = (duration_cast<milliseconds>(system_clock::now().time_since_epoch())).count();
	}
	else
	{
		return;
	}
	const auto val = rand() % 36;
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer))
		{
			string name = static_cast<PlayerInfo*>(peer->data)->displayName;
			if (val == 1 || val == 3 || val == 5 || val == 7 || val == 9 || val == 12 || val == 14 || val == 16 || val == 18 || val == 19 || val == 21 || val == 23 || val == 25 || val == 27 || val == 30 || val == 32 || val == 34 || val == 36)
			{
				auto p2 = packetEnd(appendIntx(appendString(appendIntx(appendString(createPacket(), "OnTalkBubble"), static_cast<PlayerInfo*>(peer->data)->netID), "`w[" + name + " `wspun the wheel and got `4" + std::to_string(val) + "`w!]"), 0));
				auto respawnTimeout = 2000;
				auto deathFlag = 0x19;
				memcpy(p2.data + 24, &respawnTimeout, 4);
				memcpy(p2.data + 56, &deathFlag, 4);
				const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2);
				delete p2.data;
				auto p2s = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`7[`w" + name + " `ospun the wheel and got `4" + std::to_string(val) + "`o!`7]"));
				memcpy(p2s.data + 24, &respawnTimeout, 4);
				memcpy(p2s.data + 56, &deathFlag, 4);
				const auto packet2s = enet_packet_create(p2s.data, p2s.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2s);
				delete p2s.data;
			}
			else if (val == 2 || val == 4 || val == 6 || val == 8 || val == 10 || val == 11 || val == 13 || val == 15 || val == 17 || val == 20 || val == 22 || val == 24 || val == 26 || val == 28 || val == 29 || val == 31 || val == 33 || val == 35)
			{
				auto p2 = packetEnd(appendIntx(appendString(appendIntx(appendString(createPacket(), "OnTalkBubble"), static_cast<PlayerInfo*>(peer->data)->netID), "`w[" + name + " `wspun the wheel and got `b" + std::to_string(val) + "`w!]"), 0));
				auto respawnTimeout = 2000;
				auto deathFlag = 0x19;
				memcpy(p2.data + 24, &respawnTimeout, 4);
				memcpy(p2.data + 56, &deathFlag, 4);
				const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2);
				delete p2.data;
				auto p2s = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`7[`w" + name + " `ospun the wheel and got `b" + std::to_string(val) + "`o!`7]"));
				memcpy(p2s.data + 24, &respawnTimeout, 4);
				memcpy(p2s.data + 56, &deathFlag, 4);
				const auto packet2s = enet_packet_create(p2s.data, p2s.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2s);
				delete p2s.data;
			}
			else if (val == 0 || val == 37)
			{
				auto p2 = packetEnd(appendIntx(appendString(appendIntx(appendString(createPacket(), "OnTalkBubble"), static_cast<PlayerInfo*>(peer->data)->netID), "`w[" + name + " `wspun the wheel and got `20`w!]"), 0));
				auto respawnTimeout = 2000;
				auto deathFlag = 0x19;
				memcpy(p2.data + 24, &respawnTimeout, 4);
				memcpy(p2.data + 56, &deathFlag, 4);
				const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2);
				delete p2.data;
				auto p2s = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`7[`w" + name + " `ospun the wheel and got `20`o!`7]"));
				memcpy(p2s.data + 24, &respawnTimeout, 4);
				memcpy(p2s.data + 56, &deathFlag, 4);
				const auto packet2s = enet_packet_create(p2s.data, p2s.len, ENET_PACKET_FLAG_RELIABLE);
				enet_peer_send(currentPeer, 0, packet2s);
				delete p2s.data;
			}
		}
	}
}

inline void initialize_packet_with_display_block(BYTE* raw)
{
	int i = 0;
	raw[i] = 0x05; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x08; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x56; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x15; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x0d; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x82; i++;
	raw[i] = 0x0b; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x01; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x17; i++;
	raw[i] = 0x82; i++;
	raw[i] = 0x04; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x6c; i++;
	raw[i] = 0xfd; i++;
	raw[i] = 0xfd; i++;
	raw[i] = 0xfd;
}

inline void initialize_packet_with_unlocked_door(BYTE* raw)
{
	int i = 0;
	raw[i] = 0x05; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x08; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x56; i++; // x - 4 bytes
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x15; i++; // y - 4 bytes
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x0d; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x0c; i++; // door ID / background ID - 4 bytes
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x01; i++;
	raw[i] = 0x00; i++;
	raw[i] = 0x01;
	//raw[i] = 0x61; i++; // text??
	//raw[i] = 0x08; i++;
	//raw[i] = 0xeb; i++; // or 98 if locked
	//raw[i] = 0xfd; i++;
	//raw[i] = 0xfd; i++;
	//raw[i] = 0xfd; i++;
}

inline void updateDoor(ENetPeer* peer, int foreground, int x, int y, int background, string text, bool locked, bool sendPacketToEveryone = true, int visuals = 0) {
	PlayerMoving sign{};
	sign.packetType = 0x3;
	sign.characterState = 0x0;
	sign.x = 0x56;
	sign.y = 0x15;
	sign.punchX = 0x56;
	sign.punchY = 0x15;
	sign.XSpeed = 0;
	sign.YSpeed = 0;
	sign.netID = -1;
	sign.plantingTree = 0x0b82;
	SendPacketRaw(4, packPlayerMoving(&sign), 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	BYTE a;
	BYTE b;
	if (!locked) a = 0x00; // 0x08 for locked
	else a = 0x08;
	if (!locked) b = 0xeb; // 0x98 for locked
	else b = 0x98;
	uint32_t c = 0xfdfdfdfd;
	short textLen = static_cast<short>(text.size());
	const int plength = 73 + textLen;
	BYTE* raw = new BYTE[plength];
	memset(raw, 0, plength);
	initialize_packet_with_unlocked_door(raw);
	memcpy(raw + 44, &x, sizeof(int));
	memcpy(raw + 48, &y, sizeof(int));
	memcpy(raw + 56, &foreground, sizeof(short));
	memcpy(raw + 58, &background, sizeof(short));
	memcpy(raw + 60, &visuals, sizeof(int));
	memcpy(raw + 65, &textLen, sizeof(short));
	memcpy(raw + 67, text.c_str(), textLen);
	memcpy(raw + 67 + textLen, &a, 1);
	memcpy(raw + 68 + textLen, &b, 1);
	memcpy(raw + 69 + textLen, &c, 4);
	ENetPacket* p = enet_packet_create(nullptr, plength + 4, ENET_PACKET_FLAG_RELIABLE);
	int four = 4;
	memcpy(p->data, &four, sizeof(int));
	memcpy(reinterpret_cast<char*>(p->data) + 4, raw, plength);
	if (sendPacketToEveryone) {
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer)) {
				enet_peer_send(currentPeer, 0, p);
			}
		}
		delete[] raw;
	}
	else {
		enet_peer_send(peer, 0, p);
		delete[] raw;
	}
}



inline void UpdateDisplayVisuals(ENetPeer* peer, int foreground, int x, int y, int background, int itemid, bool sendPacketToEveryone = true)
{
	PlayerMoving sign{};
	sign.packetType = 0x3;
	sign.characterState = 0x0;
	sign.x = 0x56;
	sign.y = 0x15;
	sign.punchX = 0x56;
	sign.punchY = 0x15;
	sign.XSpeed = 0;
	sign.YSpeed = 0;
	sign.netID = -1;
	sign.plantingTree = 0x0b82;
	SendPacketRaw(4, packPlayerMoving(&sign), 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	const auto plength = 73;
	const auto raw = new BYTE[plength];
	memset(raw, 0, plength);
	initialize_packet_with_display_block(raw);
	memcpy(raw + 44, &x, sizeof(int));
	memcpy(raw + 48, &y, sizeof(int));
	memcpy(raw + 56, &foreground, sizeof(short));
	memcpy(raw + 58, &background, sizeof(short));
	memcpy(raw + 65, &itemid, sizeof(int));
	const auto p = enet_packet_create(nullptr, plength + 4, ENET_PACKET_FLAG_RELIABLE);
	auto four = 4;
	memcpy(p->data, &four, sizeof(int));
	memcpy(reinterpret_cast<char*>(p->data) + 4, raw, plength);
	if (sendPacketToEveryone)
	{
		for (auto currentPeer = server->peers;
			currentPeer < &server->peers[server->peerCount];
			++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer))
			{
				enet_peer_send(currentPeer, 0, p);
			}
		}
		delete[] raw;
	}
	else
	{
		enet_peer_send(peer, 0, p);
		delete[] raw;
	}
}

inline void UpdateTreeVisuals(ENetPeer* peer, int foreground, int x, int y, int background, int fruitCount, int timeIntoGrowth, bool forEveryone, int blockStateFlags)
{
	auto hmm = 8;
	auto packetType = 5;
	const auto yeh = hmm + 3 + 1;
	auto idk = 15 + 4;
	auto blockState = blockStateFlags;
	auto bubble_type = 4;
	const auto ok = 52 + idk;
	const auto packetSize = ok + 4;
	const auto yup = ok - 8 - idk;
	auto four = 4;
	const auto magic = 56;
	const auto wew = ok + 5 + 4;
	auto fc = static_cast<short>(fruitCount);
	auto time = static_cast<int>(timeIntoGrowth);
	blockState |= 0x100000;
	const auto data = new BYTE[packetSize];
	const auto p = enet_packet_create(nullptr, wew, ENET_PACKET_FLAG_RELIABLE);
	memset(data, 0, packetSize);
	memcpy(data, &packetType, sizeof(int));
	memcpy(data + yeh, &hmm, sizeof(int));
	memcpy(data + yup, &x, sizeof(int));
	memcpy(data + yup + 4, &y, sizeof(int));
	memcpy(data + 4 + yup + 4, &idk, sizeof(int));
	memcpy(data + magic, &foreground, sizeof(short));
	memcpy(data + magic + 2, &background, sizeof(short));
	memcpy(data + magic + 4, &blockState, sizeof(int));
	memcpy(data + magic + 8, &bubble_type, sizeof(BYTE));
	memcpy(data + magic + 9 + 0, &time, 4);
	memcpy(data + magic + 9 + 4, &fc, 1);
	memcpy(data + ok, &blockState, sizeof(int));
	memcpy(p->data, &four, four);
	memcpy(reinterpret_cast<char*>(p->data) + four, data, packetSize);
	if (forEveryone)
	{
		for (auto currentPeer = server->peers;
			currentPeer < &server->peers[server->peerCount];
			++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer))
			{
				enet_peer_send(currentPeer, 0, p);
			}
		}
		delete[] data;
	}
	else
	{
		enet_peer_send(peer, 0, p);
		delete[] data;
	}
}

inline void UpdateMessageVisuals(ENetPeer* peer, int foreground, int x, int y, const string text, int background, const int bubbleType_ = 2, const bool sendPacketToEveryone = true, int blockState = 0)
{
	if (text.size() > 100) return;
	PlayerMoving sign{};
	sign.packetType = 0x3;
	sign.characterState = 0x0;
	sign.x = x;
	sign.y = y;
	sign.punchX = x;
	sign.punchY = y;
	sign.XSpeed = 0;
	sign.YSpeed = 0;
	sign.netID = -1;
	sign.plantingTree = foreground;
	SendPacketRaw(4, packPlayerMoving(&sign), 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	int hmm = 8, textLen = text.size(), PacketType = 5;
	const auto yeh = hmm + 3 + 1, idk = 15 + textLen, endMarker = -1, sizeofshort = 2;
	auto bubbleType = bubbleType_;
	const auto ok = 52 + idk;
	const auto kek = ok + 4, yup = ok - 8 - idk;
	const auto sizeofint = 4, magic = 56, wew = ok + 5 + 4;
	const auto wow = magic + 4 + 5;
	const auto data = new BYTE[kek];
	const auto p = enet_packet_create(nullptr, wew, ENET_PACKET_FLAG_RELIABLE);
	for (auto i = 0; i < kek; i++) data[i] = 0;
	memcpy(data, &PacketType, sizeof(int));
	memcpy(data + yeh, &hmm, sizeof(int));
	memcpy(data + yup, &x, sizeof(int));
	memcpy(data + yup + 4, &y, sizeof(int));
	memcpy(data + 4 + yup + 4, &idk, sizeof(int));
	memcpy(data + magic, &foreground, sizeof(short));
	memcpy(data + magic + 2, &background, sizeof(short));
	memcpy(data + sizeofint + magic, &blockState, sizeof(int));
	memcpy(data + magic + 4 + sizeofint, &bubbleType, sizeof(BYTE));
	memcpy(data + wow, &textLen, sizeof(short));
	memcpy(data + sizeofshort + wow, text.c_str(), textLen);
	memcpy(data + ok, &endMarker, sizeof(int));
	memcpy(p->data, &sizeofint, sizeof(int));
	memcpy(reinterpret_cast<char*>(p->data) + sizeofint, data, kek);
	if (sendPacketToEveryone)
	{
		for (auto currentPeer = server->peers;
			currentPeer < &server->peers[server->peerCount];
			++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer))
			{
				enet_peer_send(currentPeer, 0, p);
			}
		}
		delete[] data;
	}
	else
	{
		enet_peer_send(peer, 0, p);
		delete[] data;
	}
}

inline void sendblockstate(ENetPeer* peer, int x, int y, int state)
{
	BlockVisual data{};
	data.packetType = 0x5;
	data.characterState = 8;
	data.charStat = 8;
	data.blockid = 0;
	data.backgroundid = 0;
	data.visual = state;
	data.punchX = x;
	data.punchY = y;
	data.netID = static_cast<PlayerInfo*>(peer->data)->netID;
	SendPacketRaw2(192, packBlockVisual(&data), 100, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
}

inline void UpdateVisualsForBlock(ENetPeer* peer, const bool forEveryone, const int x, const int y, WorldInfo* worldInfo, bool useLockId = true)
{
	if (!worldInfo) return;
	try {
		const auto i = y * worldInfo->width + x;
		auto blockStateFlags = 0;
		if (worldInfo->items.at(i).flipped) blockStateFlags |= 0x00200000;
		if (worldInfo->items.at(i).water) blockStateFlags |= 0x04000000;
		if (worldInfo->items.at(i).glue) blockStateFlags |= 0x08000000;
		if (worldInfo->items.at(i).fire) blockStateFlags |= 0x10000000;
		if (worldInfo->items.at(i).red) blockStateFlags |= 0x20000000;
		if (worldInfo->items.at(i).green) blockStateFlags |= 0x40000000;
		if (worldInfo->items.at(i).blue) blockStateFlags |= 0x80000000;
		if (getItemDef(worldInfo->items.at(i).foreground).blockType == BlockTypes::MAIN_DOOR)
		{
			updateDoor(peer, worldInfo->items.at(i).foreground, x, y, worldInfo->items.at(i).background, "EXIT", false, forEveryone, blockStateFlags);
		}
		else if (worldInfo->items.at(i).foreground == 2946)
		{
			UpdateDisplayVisuals(peer, worldInfo->items.at(i).foreground, x, y, worldInfo->items.at(i).background, worldInfo->items.at(i).intdata);
		}
		else if (worldInfo->items.at(i).foreground % 2 == 1)
		{
			UpdateTreeVisuals(peer, worldInfo->items.at(i).foreground, x, y, worldInfo->items.at(i).background, 3, 59, true, 0);
		}
		else
		{
			UpdateMessageVisuals(peer, worldInfo->items.at(i).foreground, x, y, "", worldInfo->items.at(i).background, 0, forEveryone, blockStateFlags);
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void UpdateBlockState(ENetPeer* peer, const int x, const int y, bool forEveryone, WorldInfo* worldInfo)
{
	if (!worldInfo) return;
	try {
		const auto i = y * worldInfo->width + x;
		auto blockStateFlags = 0;
		if (worldInfo->items.at(i).flipped)
			blockStateFlags |= 0x00200000;
		if (worldInfo->items.at(i).water)
			blockStateFlags |= 0x04000000;
		if (worldInfo->items.at(i).glue)
			blockStateFlags |= 0x08000000;
		if (worldInfo->items.at(i).fire)
			blockStateFlags |= 0x10000000;
		if (worldInfo->items.at(i).red)
			blockStateFlags |= 0x20000000;
		if (worldInfo->items.at(i).green)
			blockStateFlags |= 0x40000000;
		if (worldInfo->items.at(i).blue)
			blockStateFlags |= 0x80000000;
		if (worldInfo->items.at(i).activated)
			blockStateFlags |= 0x00400000;
		if (blockStateFlags != 0)
		{
			TileExtra data{};
			data.packetType = 0x5;
			data.characterState = 8;
			data.charStat = 8;
			data.blockid = worldInfo->items.at(i).foreground;
			data.backgroundid = worldInfo->items.at(i).background;
			data.visual = blockStateFlags;
			data.punchX = x;
			data.punchY = y;
			for (auto currentPeer = server->peers;
				currentPeer < &server->peers[server->peerCount];
				++currentPeer)
			{
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
				if (isHere(peer, currentPeer))
				{
					SendPacketRaw2(192, packBlockVisual(&data), 100, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
				}
			}
		}
		else
		{
			TileExtra data{};
			data.packetType = 0x5;
			data.characterState = 8;
			data.charStat = 8;
			data.blockid = worldInfo->items.at(i).foreground;
			data.backgroundid = worldInfo->items.at(i).background;
			data.visual = blockStateFlags;
			data.punchX = x;
			data.punchY = y;
			for (auto currentPeer = server->peers;
				currentPeer < &server->peers[server->peerCount];
				++currentPeer)
			{
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
				if (isHere(peer, currentPeer))
				{
					SendPacketRaw2(192, packBlockVisual(&data), 100, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
				}
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline uint8_t* SuckerTileData(const uint16_t itemid, const uint16_t itemamount, const uint8_t magnet_on, const uint8_t remote_on)
{
	const auto data = new uint8_t[15];
	memset(data, 0, 15);
	data[0] = 0x3E;
	*reinterpret_cast<uint16_t*>(data + 1) = itemid;
	*reinterpret_cast<uint16_t*>(data + 5) = itemamount;
	*static_cast<uint8_t*>(data + 9) = magnet_on;
	*static_cast<uint8_t*>(data + 10) = remote_on;
	*static_cast<uint8_t*>(data + 12) = 1;
	return data;
}

inline void send_item_sucker(ENetPeer* peer, const int blockid, const int x, const int y, const uint16_t itemid, const uint16_t itemamount, const uint8_t magneton, const uint8_t remoteon, const int background)
{
	PlayerMoving pmov{};
	pmov.packetType = 5;
	pmov.characterState = 8;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = -1;
	const auto pmovpacked = packPlayerMoving(&pmov);
	*reinterpret_cast<uint32_t*>(pmovpacked + 52) = 15 + 8;
	const auto packet = new uint8_t[4 + 56 + 15 + 8];
	memset(packet, 0, 4 + 56 + 15 + 8);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, 56);
	*reinterpret_cast<uint16_t*>(packet + 4 + 56) = blockid;
	*reinterpret_cast<uint16_t*>(packet + 6 + 56) = background;
	const auto tiledata = SuckerTileData(itemid, itemamount, magneton, remoteon);
	memcpy(packet + 4 + 56 + 8, tiledata, 15);
	const auto epacket = enet_packet_create(packet, 4 + 56 + 8 + 15, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, epacket);
	delete pmovpacked;
	delete[] packet;
	delete tiledata;
}

inline void SendDonateData(ENetPeer* peer, short fg, short bg, const int x, const int y, int item)
{
	/*const auto ExtendedData = new BYTE[15];
	auto extendedLen = 15;
	PlayerMoving pmov{};
	pmov.packetType = 0x5;
	pmov.characterState = 0x8;
	pmov.punchX = x;
	pmov.punchY = y;
	const auto raw = new BYTE[56 + 15];
	memcpy(raw, packPlayerMoving(&pmov), 56);
	memcpy(raw + 52, &extendedLen, 4);
	memcpy(ExtendedData, &fg, 2);
	memcpy(ExtendedData + 2, &bg, 2);
	ExtendedData[4] = 0;
	ExtendedData[5] = 0;
	ExtendedData[6] = 65;
	ExtendedData[7] = 0;
	memcpy(raw + 56, ExtendedData, extendedLen);
	SendPacketRaw3(4, raw, 56 + 15, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);*/
}

inline void RemoveItemPacket(ENetPeer* peer, short fg, short bg, const int x, const int y, int item)
{
	/*const auto ExtendedData = new BYTE[15];
	//auto state = 0x0010000;
	//auto zero = 0;
	auto extendedLen = 15;
	//auto stt = 65;
	PlayerMoving pmov{};
	pmov.packetType = 0x5;
	pmov.characterState = 0x8;
	pmov.punchX = x;
	pmov.punchY = y;
	const auto raw = new BYTE[56 + 15];
	memcpy(raw, packPlayerMoving(&pmov), 56);
	memcpy(raw + 52, &extendedLen, 4);
	memcpy(ExtendedData, &fg, 2);
	memcpy(ExtendedData + 2, &bg, 2);
	ExtendedData[4] = 0;
	ExtendedData[5] = 0;
	ExtendedData[6] = 0;
	ExtendedData[7] = 0;
	memcpy(raw + 56, ExtendedData, extendedLen);
	SendPacketRaw3(4, raw, 56 + 15, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);*/
}

inline void SendItemPacket(ENetPeer* peer, short fg, short bg, const int x, const int y, int item)
{
	/*const auto ExtendedData = new BYTE[15];
	auto extendedLen = 15;
	PlayerMoving pmov{};
	pmov.packetType = 0x5;
	pmov.characterState = 0x8;
	pmov.punchX = x;
	pmov.punchY = y;
	const auto raw = new BYTE[56 + 15];
	memcpy(raw, packPlayerMoving(&pmov), 56);
	memcpy(raw + 52, &extendedLen, 4);
	memcpy(ExtendedData, &fg, 2);
	memcpy(ExtendedData + 2, &bg, 2);
	ExtendedData[4] = 0;
	ExtendedData[5] = 0;
	ExtendedData[6] = 65;
	ExtendedData[7] = 0;
	memcpy(raw + 56, ExtendedData, extendedLen);
	SendPacketRaw3(4, raw, 56 + 15, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);*/
}

inline void sendHMonitor(ENetPeer* peer, int x, int y, string name, bool online, const int background) {
	size_t pos;
	while ((pos = name.find("`2")) != string::npos) {
		name.replace(pos, 2, "");
	}
	PlayerMoving pmov{};
	pmov.packetType = 5;
	pmov.characterState = 8;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = -1;
	const int len = 7 + name.length();
	uint8_t* pmovpacked = packPlayerMoving(&pmov);
	*reinterpret_cast<uint32_t*>(pmovpacked + 52) = 8 + len;
	uint8_t* packet = new uint8_t[4 + 56 + 8 + len];
	memset(packet, 0, 4 + 56 + 8 + len);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, 56);
	*reinterpret_cast<uint16_t*>(packet + 4 + 56) = 0x4D8; 
	*reinterpret_cast<uint16_t*>(packet + 4 + 56 + 6) = 1 | (online ? 0x40 : 0);
	*reinterpret_cast<uint16_t*>(packet + 6 + 56) = background;
	*static_cast<uint8_t*>(packet + 4 + 56 + 8) = 0x0B;
	*reinterpret_cast<uint16_t*>(packet + 4 + 56 + 13) = name.length();
	memcpy(packet + 4 + 56 + 15, name.data(), name.length());
	ENetPacket* epacket = enet_packet_create(packet, 4 + 56 + 8 + len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, epacket);
	delete pmovpacked;
	delete[] packet;
}
inline void UpdateVend(ENetPeer* peer, int x, int y, int id, bool locks, int price, int background, bool isPer = false) {
	if (price == 0) id = 0;
	auto options321 = 0;
	if (price >= 256 && price < 512) options321 = 1;
	else if (price >= 512 && price < 768) options321 = 2;
	else if (price >= 768 && price < 1024) options321 = 3;
	else if (price >= 1024 && price < 1280) options321 = 4;
	else if (price >= 1280 && price < 1536) options321 = 5;
	else if (price >= 1536 && price < 1792) options321 = 6;
	else if (price >= 1792 && price < 2048) options321 = 7;
	else if (price >= 2048 && price < 2304) options321 = 8;
	else if (price >= 2304 && price < 2560) options321 = 9;
	else if (price >= 2560 && price < 2816) options321 = 10;
	else if (price >= 2816 && price < 3072) options321 = 11;
	else if (price >= 3072 && price < 3328) options321 = 12;
	else if (price >= 3328 && price < 3584) options321 = 13;
	else if (price >= 3584 && price < 3840) options321 = 14;
	else if (price >= 3840 && price < 4096) options321 = 15;
	else if (price >= 4096 && price < 4352) options321 = 16;
	else if (price >= 4352 && price < 4608) options321 = 17;
	else if (price >= 4608 && price < 4864) options321 = 18;
	else if (price >= 4864 && price < 5120) options321 = 19;
	else if (price >= 5120 && price < 5376) options321 = 20;
	else if (price >= 5376 && price < 5632) options321 = 21;
	else if (price >= 5632 && price < 5888) options321 = 22;
	else if (price >= 5888 && price < 6144) options321 = 23;
	else if (price >= 6144 && price < 6400) options321 = 24;
	else if (price >= 6400 && price < 6656) options321 = 25;
	else if (price >= 6656 && price < 6912) options321 = 26;
	else if (price >= 6912 && price < 7168) options321 = 27;
	else if (price >= 7168 && price < 7424) options321 = 28;
	else if (price >= 7424 && price < 7680) options321 = 29;
	else if (price >= 7680 && price < 7936) options321 = 30;
	else if (price >= 7936 && price < 8192) options321 = 31;
	else if (price >= 8192 && price < 8448) options321 = 32;
	else if (price >= 8448 && price < 8704) options321 = 33;
	else if (price >= 8704 && price < 8960) options321 = 34;
	else if (price >= 8960 && price < 9216) options321 = 35;
	else if (price >= 9216 && price < 9472) options321 = 36;
	else if (price >= 9472 && price < 9728) options321 = 37;
	else if (price >= 9728 && price < 9984) options321 = 38;
	else if (price >= 9984 && price < 10240) options321 = 39;
	else if (price >= 10240 && price < 10496) options321 = 40;
	else if (price >= 10496 && price < 10752) options321 = 41;
	else if (price >= 10752 && price < 11008) options321 = 42;
	else if (price >= 11008 && price < 11264) options321 = 43;
	else if (price >= 11264 && price < 11520) options321 = 44;
	else if (price >= 11520 && price < 11776) options321 = 45;
	else if (price >= 11776 && price < 12032) options321 = 46;
	else if (price >= 12032 && price < 12288) options321 = 47;
	else if (price >= 12288 && price < 12544) options321 = 48;
	else if (price >= 12544 && price < 12800) options321 = 49;
	else if (price >= 12800 && price < 13056) options321 = 50;
	else if (price >= 13056 && price < 13312) options321 = 51;
	else if (price >= 13312 && price < 13568) options321 = 52;
	else if (price >= 13568 && price < 13824) options321 = 53;
	else if (price >= 13824 && price < 14080) options321 = 54;
	else if (price >= 14080 && price < 14336) options321 = 55;
	else if (price >= 14336 && price < 14592) options321 = 56;
	else if (price >= 14592 && price < 14848) options321 = 57;
	else if (price >= 14848 && price < 15104) options321 = 58;
	else if (price >= 15104 && price < 15360) options321 = 59;
	else if (price >= 15360 && price < 15616) options321 = 60;
	else if (price >= 15616 && price < 15872) options321 = 61;
	else if (price >= 15872 && price < 16128) options321 = 62;
	else if (price >= 16128 && price < 16384) options321 = 63;
	else if (price >= 16384 && price < 16640) options321 = 64;
	else if (price >= 16640 && price < 16896) options321 = 65;
	else if (price >= 16896 && price < 17152) options321 = 66;
	else if (price >= 17152 && price < 17408) options321 = 67;
	else if (price >= 17408 && price < 17664) options321 = 68;
	else if (price >= 17664 && price < 17920) options321 = 69;
	else if (price >= 17920 && price < 18176) options321 = 70;
	else if (price >= 18176 && price < 18432) options321 = 71;
	else if (price >= 18432 && price < 18688) options321 = 72;
	else if (price >= 18688 && price < 18944) options321 = 73;
	else if (price >= 18944 && price < 19200) options321 = 74;
	else if (price >= 19200 && price < 19456) options321 = 75;
	else if (price >= 19456 && price < 19712) options321 = 76;
	else if (price >= 19712 && price < 19968) options321 = 77;
	else if (price >= 19968 && price <= 20000) options321 = 78;
	price -= 256 * options321;
	TileExtra data{};
	data.packetType = 0x5;
	data.characterState = 8;
	data.punchX = x;
	data.punchY = y;
	data.charStat = 13;
	data.blockid = 2978;
	data.backgroundid = background;
	data.visual = 0x00410000;
	if (locks == true) data.visual = 0x02410000;
	auto n = id;
	string hex = "";
	{
		std::stringstream ss;
		ss << std::hex << n;
		string res(ss.str());
		hex = res + "18";
	}
	int xx;
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> xx;
	data.displayblock = xx;
	int xes; 
	{
		int wl = price;
		string basic_string = "";
		{
			std::stringstream stringstream;
			stringstream << std::hex << wl;
			string res(stringstream.str());
			basic_string = res + "00";
		}
		int i;
		std::stringstream basic_stringstream;
		basic_stringstream << std::hex << basic_string;
		basic_stringstream >> i;
		xes = i;
	}
	BYTE* raw = nullptr;
	if (isPer) {
		raw = packStuffVisual(&data, 16777215, -xes);
	} else {
		raw = packStuffVisual(&data, options321, xes);
	}
	SendPacketRaw2(192, raw, 102, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	raw = nullptr;
}

inline string lock_tile_datas(int visual, uint32_t owner, uint32_t adminLength, uint32_t* admins, bool isPublic = false, uint8_t bpm = 0) {
	string data;
	data.resize(4 + 2 + 4 + 4 + adminLength * 4 + 8);
	if (bpm) data.resize(data.length() + 4);
	data[2] = 0x01;
	if (isPublic) data[2] |= 0x80;
	data[4] = 3;
	data[5] = visual; 
	STRINT(data, 6) = owner;
	STRINT(data, 10) = adminLength;
	for (uint32_t i = 0; i < adminLength; i++) {
		STRINT(data, 14 + i * 4) = admins[i];
	}
	if (bpm) {
		STRINT(data, 10)++;
		STRINT(data, 14 + adminLength * 4) = -bpm;
	}
	return data;
}

inline void send_tile_data(ENetPeer* peer, int x, int y, int visual, uint16_t fgblock, uint16_t bgblock, string tiledata) {
	if (fgblock == 202 || fgblock == 204 || fgblock == 206 || fgblock == 4994) return;
	PlayerMoving pmov{};
	pmov.packetType = 5;
	pmov.characterState = 0;
	pmov.x = 0;
	pmov.y = 0;
	pmov.XSpeed = 0;
	pmov.YSpeed = 0;
	pmov.plantingTree = 0;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = 0;
	string packetstr;
	packetstr.resize(4);
	packetstr[0] = 4;
	packetstr += packPlayerMoving2(&pmov);
	packetstr[16] = 8;
	packetstr.resize(packetstr.size() + 4);
	STRINT(packetstr, 52 + 4) = tiledata.size() + 4;
	STR16(packetstr, 56 + 4) = fgblock;
	STR16(packetstr, 58 + 4) = bgblock;
	packetstr += tiledata;
	ENetPacket* packet = enet_packet_create(&packetstr[0], packetstr.length(), ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
}
inline bool isWorldOwner(ENetPeer* peer, WorldInfo* world) {
	return static_cast<PlayerInfo*>(peer->data)->rawName == world->owner;
}

inline void send_canvas_data(ENetPeer* peer, short fg, short bg, int x, int y, int item, string text) {
	byte* ExtendedData = new byte[15 + item + text.length()];
	int state = 0x0010000;
	int extendedLen = 15 + item + text.length();
	int TextLen = text.length();
	PlayerMoving pmov{};
	pmov.packetType = 0x5;
	pmov.characterState = 0x8;
	pmov.punchX = x;
	pmov.punchY = y;
	byte* raw = new byte[56 + 15 + item + TextLen];
	memcpy(raw, packPlayerMoving(&pmov), 56);
	memcpy(raw + 52, &extendedLen, 4);
	memcpy(ExtendedData, &fg, 2);
	memcpy(ExtendedData + 2, &bg, 2);
	memcpy(ExtendedData + 4, &state, 4);
	ExtendedData[8] = 0x23;
	memcpy(ExtendedData + 9, &item, 4);
	memcpy(ExtendedData + 13, &TextLen, 2);
	memcpy(ExtendedData + 15, text.data(), TextLen);
	memcpy(raw + 56, ExtendedData, extendedLen);
	SendPacketRaw3(4, raw, 56 + 15 + item + TextLen, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	delete[] ExtendedData; 
}

inline void sendDrop(ENetPeer* peer, int netID, int x, int y, int item, int count, BYTE specialEffect) {
	if (item > maxItems || item < 0) return;
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer)) {
			PlayerMoving data{};
			data.packetType = 14;
			data.x = x;
			data.y = y;
			data.netID = netID;
			data.plantingTree = item;
			float val = count;
			auto val2 = specialEffect;
			const auto raw = packPlayerMoving(&data);
			memcpy(raw + 16, &val, 4);
			memcpy(raw + 1, &val2, 1);
			SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
}

inline void RemoveDroppedItem(ENetPeer* peer, const int obj_id) {
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			const auto b = new BYTE[56];
			memset(b, 0, 56);
			*reinterpret_cast<int*>(&b[0]) = 0xe;
			*reinterpret_cast<int*>(&b[4]) = -2;
			*reinterpret_cast<int*>(&b[8]) = -1;
			*reinterpret_cast<int*>(&b[20]) = obj_id + 1;
			SendPacketRaw(4, b, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
}
inline int processTakeServer(WorldInfo* world, ENetPeer* peer, const int itemIdx) {
	//WorldInfo* world = getPlyersWorld(peer);
	if (world == NULL) {
		SendConsole("processTakeServer error", "ERROR");
		return -1;
	}
	if (!world) return -1;
	try {
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		auto legit = true;
		auto atik = -1;
		for (auto i = 0; i < world->droppedItems.size(); i++) {
			if (world->droppedItems.at(i).uid == itemIdx) {
				atik = i;
				break;
			}
		}
		legit = atik != -1;
		if (legit) {
			try {
				world->droppedItems.erase(world->droppedItems.begin() + atik);
			}
			catch (...) {
				return -1;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

inline void SendThrowEffect(ENetPeer* peer, int id, int netIDsrc, int netIDdst, int timeMs, BYTE type, int x, int y) {
	PlayerMoving data{};
	data.packetType = 0x13;
	data.punchX = id;
	data.punchY = id;
	data.x = x;
	data.y = y;
	const auto raw = packPlayerMoving(&data);
	auto netIdSrc = netIDsrc;
	auto netIdDst = netIDdst;
	auto n1 = timeMs;
	memcpy(raw + 3, &type, 1);
	memcpy(raw + 4, &netIdDst, 4);
	memcpy(raw + 8, &netIdSrc, 4);
	memcpy(raw + 20, &n1, 4);
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			const auto raw2 = new BYTE[56];
			memcpy(raw2, raw, 56);
			SendPacketRaw(4, raw2, 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
	delete raw;
}

inline void DropItem(WorldInfo* world, ENetPeer* peer, int netID, int x, int y, int item, int count, BYTE specialEffect, string history = "", bool mageffect = true) {
	if (serverIsFrozen) return;
	if (!world) return;
	if (item < 0) return;
	if (x == 0 || y == 0) return;
	if (static_cast<PlayerInfo*>(peer->data)->currentWorld == "EXIT") return;
	const auto blockX = x / 32;
	const auto blockY = y / 32;
	if (blockX < 0 || blockY < 0 || blockX > world->width || blockY > world->height) return;
	auto hasmag = false;
	for (auto i = 0; i < world->width * world->height; i++) {
		if (world->items.at(i).foreground == 5638 || world->items.at(i).foreground == 6946 || world->items.at(i).foreground == 6948) {
			if (world->items.at(i).mid != 0) {
				if (item == world->items.at(i).mid) {
					if (world->items.at(i).mc <= 5000 || world->items.at(i).mid == 112) {
						const auto xx = i % world->width, yy = i / world->width;
						hasmag = true;
						world->items.at(i).mc += count;
						for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
							if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
							if (isHere(peer, currentPeer)) {
								if (mageffect) SendThrowEffect(currentPeer, item, static_cast<PlayerInfo*>(peer->data)->netID, -1, 200, 0, xx * 32 + 16, yy * 32 + 16);
								if (world->items.at(i).mc <= 0) {
									send_item_sucker(currentPeer, world->items.at(i).foreground, xx, yy, world->items.at(i).mid, 0, true, true, world->items.at(i).background);
								} else if (world->items.at(i).mc >= 5000 && world->items.at(i).mid != 112) {
									send_item_sucker(currentPeer, world->items.at(i).foreground, xx, yy, world->items.at(i).mid, -1, true, true, world->items.at(i).background);
								} else {
									send_item_sucker(currentPeer, world->items.at(i).foreground, xx, yy, world->items.at(i).mid, 1, true, true, world->items.at(i).background);
								}
							}
						}
						break;
					}
				}
			}
		}
	}
	if (hasmag == true) return;
	try {
		if (item == 112) {
			if (count == 1) world->items.at(blockX + (blockY * world->width)).yellowGems++;
			if (count == 5) world->items.at(blockX + (blockY * world->width)).blueGems++;
			if (count == 10) world->items.at(blockX + (blockY * world->width)).redGems++;
			if (count == 50) world->items.at(blockX + (blockY * world->width)).greenGems++;
			if (count == 100) world->items.at(blockX + (blockY * world->width)).purpleGems++;
			vector<int> idstoremove;
			if (world->items.at(blockX + (blockY * world->width)).yellowGems > 4) {
				for (auto i = 0; i < world->droppedItems.size(); i++) {
					if (blockX == static_cast<int>(world->droppedItems.at(i).x / 32) && blockY == static_cast<int>(world->droppedItems.at(i).y / 32)) {
						if (world->droppedItems.at(i).count == 1 && world->droppedItems.at(i).id == 112) {
							RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
							idstoremove.push_back(world->droppedItems.at(i).uid);
						}
					}
				}
				world->items.at(blockX + (blockY * world->width)).yellowGems = 0;
				world->items.at(blockX + (blockY * world->width)).blueGems++;
				count = 5;
			} if (world->items.at(blockX + (blockY * world->width)).blueGems > 1) {
				for (auto i = 0; i < world->droppedItems.size(); i++) {
					if (blockX == static_cast<int>(world->droppedItems.at(i).x / 32) && blockY == static_cast<int>(world->droppedItems.at(i).y / 32)) {
						if (world->droppedItems.at(i).count == 5 && world->droppedItems.at(i).id == 112) {
							RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
							idstoremove.push_back(world->droppedItems.at(i).uid);
						}
					}
				}
				world->items.at(blockX + (blockY * world->width)).blueGems = 0;
				world->items.at(blockX + (blockY * world->width)).redGems++;
				count = 10;
			} if (world->items.at(blockX + (blockY * world->width)).redGems > 4) {
				for (auto i = 0; i < world->droppedItems.size(); i++) {
					if (blockX == static_cast<int>(world->droppedItems.at(i).x / 32) && blockY == static_cast<int>(world->droppedItems.at(i).y / 32)) {
						if (world->droppedItems.at(i).count == 10 && world->droppedItems.at(i).id == 112) {
							RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
							idstoremove.push_back(world->droppedItems.at(i).uid);
						}
					}
				}
				world->items.at(blockX + (blockY * world->width)).redGems = 0;
				world->items.at(blockX + (blockY * world->width)).greenGems++;
				count = 50;
			} if (world->items.at(blockX + (blockY * world->width)).greenGems > 1) {
				for (auto i = 0; i < world->droppedItems.size(); i++) {
					if (blockX == static_cast<int>(world->droppedItems.at(i).x / 32) && blockY == static_cast<int>(world->droppedItems.at(i).y / 32)) {
						if (world->droppedItems.at(i).count == 50 && world->droppedItems.at(i).id == 112) {
							RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
							idstoremove.push_back(world->droppedItems.at(i).uid);
						}
					}
				}
				world->items.at(blockX + (blockY * world->width)).greenGems = 0;
				world->items.at(blockX + (blockY * world->width)).purpleGems++;
				count = 100;
			}
			for (auto i = 0; i < idstoremove.size(); i++) processTakeServer(world, peer, idstoremove.at(i));
		} else {
			vector<int> idstoremove;
			for (auto i = 0; i < world->droppedItems.size(); i++) {
				if (blockX == static_cast<int>(world->droppedItems.at(i).x / 32) && blockY == static_cast<int>(world->droppedItems.at(i).y / 32)) {
					if (world->droppedItems.at(i).count < 250 && world->droppedItems.at(i).id == item && world->droppedItems.at(i).count + count <= 250) {
						count = world->droppedItems.at(i).count + count;
						x = world->droppedItems.at(i).x;
						y = world->droppedItems.at(i).y;
						RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
						idstoremove.push_back(world->droppedItems.at(i).uid);
					}
				}
			}
			for (auto i = 0; i < idstoremove.size(); i++) processTakeServer(world, peer, idstoremove.at(i));
		}
		DroppedItem item_dropped{};
		item_dropped.id = item;
		item_dropped.count = count;
		item_dropped.x = x;
		item_dropped.y = y;
		item_dropped.uid = world->droppedCount++;
		world->droppedItems.push_back(item_dropped);
		sendDrop(peer, netID, x, y, item, count, specialEffect);
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}
inline void SaveDroppedItem(int fItemid, int fQuantity, ENetPeer* peer, bool& success) {
	try {
		const size_t invsizee = static_cast<PlayerInfo*>(peer->data)->currentInventorySize;
		auto alreadyhave = false;
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == invsizee && CheckItemExists(peer, fItemid) == false) alreadyhave = true;
		auto isFullStock = false;
		auto isInInv = false;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount + fQuantity > 250) isFullStock = true;
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount <= 250) isInInv = true;
		}
		if (isFullStock == true || alreadyhave == true) {
			success = false;
		}
		else {
			success = true;
			if (isInInv == false) {
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
		const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
		memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
		const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet);
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}
inline void SaveItemMoreTimes(int fItemid, int fQuantity, ENetPeer* peer, bool& success, string madeby = "") {
	if (fQuantity == 0) {
		return;
	}
	try {
		const size_t invsizee = static_cast<PlayerInfo*>(peer->data)->currentInventorySize;
		auto alreadyhave = false;
		if (static_cast<PlayerInfo*>(peer->data)->inventory.items.size() == invsizee && CheckItemExists(peer, fItemid) == false) {
			//DropItem(world, peer, -1, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y + rand() % 16, fItemid, fQuantity, 0);
			alreadyhave = true;
		}
		auto isFullStock = false;
		auto isInInv = false;
		for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount >= 250) {
				Player::OnDialogRequest(peer, "add_label_with_icon|big|`4Whoops!|left|1048|\nadd_spacer|small|\nadd_textbox|`oSoory! You already have full stock of this item!|\nadd_spacer|small|\nadd_button|close|`5Close|0|0|");
				isFullStock = true;
			}
			if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == fItemid && static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount < 250) isInInv = true;
		}
		if (isFullStock == true || alreadyhave == true) {
			success = false;
		}
		else {
			success = true;
			if (fItemid == 1486) {
				if (static_cast<PlayerInfo*>(peer->data)->quest_active && static_cast<PlayerInfo*>(peer->data)->lastquest == "honor" && static_cast<PlayerInfo*>(peer->data)->quest_step == 6 && static_cast<PlayerInfo*>(peer->data)->quest_progress < 50) {
					static_cast<PlayerInfo*>(peer->data)->quest_progress += fQuantity;
					if (static_cast<PlayerInfo*>(peer->data)->quest_progress >= 50) {
						static_cast<PlayerInfo*>(peer->data)->quest_progress = 50;
						Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`9Legendary Quest step complete! I'm off to see a Wizard!", 0, false);
					}
				}
			}
			if (isInInv == false) {
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
			const auto p3 = packetEnd(appendFloat(appendIntx(appendFloat(appendFloat(appendFloat(appendString(createPacket(), "OnSetClothing"), (static_cast<PlayerInfo*>(peer->data))->cloth_hair, (static_cast<PlayerInfo*>(peer->data))->cloth_shirt, (static_cast<PlayerInfo*>(peer->data))->cloth_pants), (static_cast<PlayerInfo*>(peer->data))->cloth_feet, (static_cast<PlayerInfo*>(peer->data))->cloth_face, (static_cast<PlayerInfo*>(peer->data))->cloth_hand), (static_cast<PlayerInfo*>(peer->data))->cloth_back, (static_cast<PlayerInfo*>(peer->data))->cloth_mask, (static_cast<PlayerInfo*>(peer->data))->cloth_necklace), (static_cast<PlayerInfo*>(peer->data))->skinColor), (static_cast<PlayerInfo*>(peer->data))->cloth_ances, 0.0f, 0.0f));
			memcpy(p3.data + 8, &((static_cast<PlayerInfo*>(peer->data))->netID), 4);
			const auto packet = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet);
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline int getGemCount(const int item)
{
	// ReSharper disable once CppInitializedValueIsAlwaysRewritten
	auto count = 0;
	try {
		const auto rarity = getItemDef(item).rarity;
		if (rarity == 0) return 0;
		if (rarity > 13) {
			count = rarity / 3;
		} else {
			const auto ran = rand() % 2;
			switch (ran)
			{
			case 1:
				count = 1;
				break;
			case 2:
				count = 2;
				break;
			default:
				count = 0;
				break;
			}
		}
	}
	catch (...)
	{
		return 0;
	}
	return count;
}

inline void send_item(ENetPeer* peer, const int itemid, const int item_amount, const int kindofchest)
{
	auto success = false;
	SaveItemMoreTimes(itemid, item_amount, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from " + getItemDef(kindofchest).name + "");
	Player::OnConsoleMessage(peer, "`oYou have obtained `$" + getItemDef(itemid).name + "`o");
}

inline void DailyRewardCheck(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->lastdailyGems <= GetCurrentTimeInternalSeconds() / 60) {
		static_cast<PlayerInfo*>(peer->data)->lastdailyGems = (GetCurrentTimeInternalSeconds() / 60) + 1440;
		//bool success = true;
		/*if (static_cast<PlayerInfo*>(peer->data)->Subscriber && static_cast<PlayerInfo*>(peer->data)->SubscribtionEndDay - 1 >= 1)  { 
			SaveItemMoreTimes(1360, 2, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from daily reward");
		} else {
			SaveItemMoreTimes(1360, 1, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from daily reward");
		}*/
		if (static_cast<PlayerInfo*>(peer->data)->Subscriber) {
			static_cast<PlayerInfo*>(peer->data)->SubscribtionEndDay -= 1;
		}
		try {
			ifstream read_player("save/players/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			if (!read_player.is_open()) {
				return;
			}	
			json j;
			read_player >> j;
			read_player.close();
			j["dailyrewards"] = static_cast<PlayerInfo*>(peer->data)->lastdailyGems;
			if (static_cast<PlayerInfo*>(peer->data)->SubscribtionEndDay <= 0) {
				j["subtype"] = "";
				j["subdate"] = "";
			} else {
				j["subdate"] = to_string(static_cast<PlayerInfo*>(peer->data)->SubscribtionEndDay);
			}
			ofstream write_player("save/players/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".json");
			write_player << j << std::endl;
			write_player.close();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			return;
		}
		if (static_cast<PlayerInfo*>(peer->data)->SubscribtionEndDay == 0) {
			static_cast<PlayerInfo*>(peer->data)->Subscriber = false;
			static_cast<PlayerInfo*>(peer->data)->haveSuperSupporterName = false;
			static_cast<PlayerInfo*>(peer->data)->chatcolor = "";
			static_cast<PlayerInfo*>(peer->data)->NickPrefix = "";
			static_cast<PlayerInfo*>(peer->data)->SubscribtionEndDay = 0;
			auto iscontains = false;
			SearchInventoryItem(peer, 6260, 1, iscontains);
			if (iscontains) {
				RemoveInventoryItem(6260, 1, peer, true);
			}
			if (static_cast<PlayerInfo*>(peer->data)->isinv) {
				static_cast<PlayerInfo*>(peer->data)->isinv = false;
				Player::OnInvis(peer, 0, static_cast<PlayerInfo*>(peer->data)->netID);
			}
			send_state(peer);
			if (static_cast<PlayerInfo*>(peer->data)->cloth_necklace == 6260) {
				static_cast<PlayerInfo*>(peer->data)->cloth_necklace = 0;
				static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
				sendPuncheffect(peer, static_cast<PlayerInfo*>(peer->data)->effect);
			}
			sendClothes(peer);
		}
	}
}

inline void send_break_packet(ENetPeer* peer, const int x, const int y) {
	PlayerMoving data{};
	// ReSharper disable once CppAssignedValueIsNeverUsed
	data.netID = static_cast<PlayerInfo*>(peer->data)->netID;
	data.packetType = 0x8;
	data.plantingTree = 0;
	data.netID = -1;
	data.x = x;
	data.y = y;
	data.punchX = x;
	data.punchY = y;
	SendPacketRaw(4, packPlayerMoving(&data), 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
}



inline void sendFrozenState(ENetPeer* peer)
{
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer))
		{
			PlayerMoving data{};
			data.packetType = 0x14;
			data.characterState = 0;
			data.x = 1000;
			data.y = 100;
			data.punchX = 0;
			data.punchY = 0;
			data.XSpeed = 300;
			data.YSpeed = 600;
			data.netID = netID;
			data.plantingTree = 2048;
			const auto raw = packPlayerMoving(&data);
			auto var = info->effect;
			memcpy(raw + 1, &var, 3);
			SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
}

inline void sendWorldOffers(ENetPeer* peer) { 
	try {
		vector<WorldInfo*> local_worlds = getRandomWorldsPointer(worldthreading, 2);
		string worldOffers = "default|";
		if (static_cast<PlayerInfo*>(peer->data)->isIn && static_cast<PlayerInfo*>(peer->data)->haveGrowId) {
			const string lastworld = static_cast<PlayerInfo*>(peer->data)->lastnormalworld;
			if (lastworld != "EXIT" && lastworld != "") worldOffers += lastworld;
			else worldOffers += "START";
		}
		worldOffers += "\nadd_button|Showing: `wRandom Worlds``|_catselect_|0.6|3529161471|\n";
		int added_worlds = 0;
		for (int i = 0; i < local_worlds.size(); i++) {
			if (jammers) {
				bool Jammed = false;
				for (auto jss = 0; jss < local_worlds.at(i)->width * local_worlds.at(i)->height; jss++) {
					if (local_worlds.at(i)->items.at(jss).foreground == 226 && local_worlds.at(i)->items.at(jss).activated) {
						Jammed = true;
						break;
					}
				}
				if (Jammed) continue;
			}
			float size = 0.40;
			size += 0.03 * getPlayersCountInWorld(local_worlds.at(i)->name);
			if (size > 0.75) size = 0.75;
			added_worlds++;
			worldOffers += "add_floater|" + local_worlds.at(i)->name + "|" + std::to_string(getPlayersCountInWorld(local_worlds.at(i)->name)) + "|" + to_string(size) + "|3529161471\n";
		}
		if (static_cast<PlayerInfo*>(peer->data)->lastworlds.size() > 7) {
			int kiek_erase = static_cast<PlayerInfo*>(peer->data)->lastworlds.size() - 7;
			static_cast<PlayerInfo*>(peer->data)->lastworlds.erase(static_cast<PlayerInfo*>(peer->data)->lastworlds.begin(),static_cast<PlayerInfo*>(peer->data)->lastworlds.begin()+kiek_erase);
		}
		for (int i = static_cast<PlayerInfo*>(peer->data)->lastworlds.size() - 1; i >= 0; --i) {
			if (static_cast<PlayerInfo*>(peer->data)->lastworlds.at(i) == "" || static_cast<PlayerInfo*>(peer->data)->lastworlds.at(i) == "EXIT") continue;
			worldOffers += "\nadd_floater|" + static_cast<PlayerInfo*>(peer->data)->lastworlds.at(i) + "|0|0.5|3417414143|\n";
		}
		auto p3 = packetEnd(appendString(appendString(createPacket(), "OnRequestWorldSelectMenu"), worldOffers));
		const auto packet3 = enet_packet_create(p3.data, p3.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet3);
		delete p3.data;
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
}



inline void SendGamePacketEveryoneInWorld(ENetPeer* peer, GamePacket* p) {
	const auto packet1 = enet_packet_create(p->data, p->len, ENET_PACKET_FLAG_RELIABLE);
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			enet_peer_send(currentPeer, 0, packet1);
		}
	}
	delete p->data;
}

inline void sendWho(ENetPeer* peer) {
	string whoisinworld = "";
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (static_cast<PlayerInfo*>(currentPeer->data)->isinv) continue;
		if (isHere(peer, currentPeer)) {
			auto p2 = packetEnd(appendIntx(appendString(appendIntx(appendString(createPacket(), "OnTalkBubble"), static_cast<PlayerInfo*>(currentPeer->data)->netID), static_cast<PlayerInfo*>(currentPeer->data)->displayName), 1));
			const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet2);
			delete p2.data;
			whoisinworld += static_cast<PlayerInfo*>(currentPeer->data)->displayName + ", ";

		}
	} if (whoisinworld != "") {
		Player::OnConsoleMessage(peer, "`wWho's in `9" + static_cast<PlayerInfo*>(peer->data)->currentWorld + "`w: " + whoisinworld);
	}
}

inline void sendAction(ENetPeer* peer, int netID, string action)
{
	auto p2 = packetEnd(appendString(appendString(createPacket(), "OnAction"), action));
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer))
		{
			memcpy(p2.data + 8, &netID, 4);
			const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(currentPeer, 0, packet2);
		}
	}
	delete p2.data;
}

inline void SendTake(ENetPeer* peer, const int netID, const int x, const int y, const int item) {
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			PlayerMoving data{};
			data.packetType = 14;
			data.x = x;
			data.y = y;
			data.netID = netID;
			data.plantingTree = item;
			auto raw = packPlayerMoving(&data);
			SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_EVENT_TYPE_RECEIVE);
			raw = nullptr;
		}
	}
	SendInventory(peer, static_cast<PlayerInfo*>(peer->data)->inventory);
}

inline void sendResetState(ENetPeer* peer)
{
	if (static_cast<PlayerInfo*>(peer->data)->isCursed)
	{
		const auto info = static_cast<PlayerInfo*>(peer->data);
		const auto netID = info->netID;
		for (auto currentPeer = server->peers;
			currentPeer < &server->peers[server->peerCount];
			++currentPeer)
		{
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer))
			{
				PlayerMoving data{};
				data.packetType = 0x14;
				data.characterState = 0;
				data.x = 1000;
				data.y = 100;
				data.punchX = 0;
				data.punchY = 0;
				data.XSpeed = 300;
				data.YSpeed = 600;
				data.netID = netID;
				data.plantingTree = 4096;
				const auto raw = packPlayerMoving(&data);
				auto var = info->effect;
				memcpy(raw + 1, &var, 3);
				SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
			}
			else
			{
				if (static_cast<PlayerInfo*>(peer->data)->isDuctaped)
				{
					const auto player_info = static_cast<PlayerInfo*>(peer->data);
					const auto net_id = player_info->netID;
					for (auto peer2 = server->peers;
						peer2 < &server->peers[server->peerCount];
						++peer2)
					{
						if (peer2->state != ENET_PEER_STATE_CONNECTED) continue;
						if (isHere(peer, peer2))
						{
							PlayerMoving data{};
							data.packetType = 0x14;
							data.characterState = 0;
							data.x = 1000;
							data.y = 100;
							data.punchX = 0;
							data.punchY = 0;
							data.XSpeed = 300;
							data.YSpeed = 600;
							data.netID = net_id;
							data.plantingTree = 8192;
							const auto raw = packPlayerMoving(&data);
							auto var = player_info->effect;
							memcpy(raw + 1, &var, 3);
							SendPacketRaw(4, raw, 56, nullptr, peer2, ENET_PACKET_FLAG_RELIABLE);
						}
						else
						{
							PlayerMoving data{};
							data.packetType = 0x14;
							data.characterState = 0;
							data.x = 1000;
							data.y = 100;
							data.punchX = 0;
							data.punchY = 0;
							data.XSpeed = 300;
							data.YSpeed = 600;
							data.netID = net_id;
							data.plantingTree = 2;
							const auto raw = packPlayerMoving(&data);
							auto var = player_info->effect;
							memcpy(raw + 1, &var, 3);
							SendPacketRaw(4, raw, 56, nullptr, peer2, ENET_PACKET_FLAG_RELIABLE);
						}
					}
				}
			}
		}
	}
}



inline void SendGamePacket(ENetPeer* peer, GamePacket* p)
{
	const auto packet1 = enet_packet_create(p->data, p->len, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet1);
}

inline void DoCancelTransitionAndTeleport(ENetPeer* peer, const int x, const int y, bool entered, bool animations) {
	if (animations) {
		auto respawnTimeout = 200;
		auto deathFlag = 0x19;
		if (!entered) {
			auto p2 = packetEnd(appendFloat(appendString(createPacket(), "OnSetPos"), x * 32, y * 32));
			memcpy(p2.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
			memcpy(p2.data + 24, &respawnTimeout, 4);
			memcpy(p2.data + 56, &deathFlag, 4);
			const auto packet2 = enet_packet_create(p2.data, p2.len, ENET_PACKET_FLAG_RELIABLE);
			enet_peer_send(peer, 0, packet2);
			delete p2.data;
		}
		auto p23 = packetEnd(appendIntx(appendFloat(appendString(createPacket(), "OnZoomCamera"), 10000.000000), 1000));
		memcpy(p23.data + 24, &respawnTimeout, 4);
		memcpy(p23.data + 56, &deathFlag, 4);
		const auto packet2 = enet_packet_create(p23.data, p23.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet2);
		delete p23.data;

		auto p234 = packetEnd(appendIntx(appendString(createPacket(), "OnSetFreezeState"), 0));
		memcpy(p234.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
		memcpy(p234.data + 24, &respawnTimeout, 4);
		memcpy(p234.data + 56, &deathFlag, 4);
		const auto packet23 = enet_packet_create(p234.data, p234.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet23);
		delete p234.data;

		auto p2346 = packetEnd(appendString(appendString(createPacket(), "OnPlayPositioned"), "audio/door_open.wav"));
		memcpy(p2346.data + 24, &respawnTimeout, 4);
		memcpy(p2346.data + 56, &deathFlag, 4);
		const auto packet249 = enet_packet_create(p2346.data, p2346.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packet249);
		delete p2346.data;
	} else {
		if (!entered) {
			GamePacket p4 = packetEnd(appendFloat(appendString(createPacket(), "OnSetPos"), x * 32, y * 32));
			memcpy(p4.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
			SendGamePacket(peer, &p4);
		}
		Player::OnZoomCamera(peer, 10000.000000, 1000);
		auto p2 = packetEnd(appendIntx(appendString(createPacket(), "OnSetFreezeState"), 0));
		memcpy(p2.data + 8, &(static_cast<PlayerInfo*>(peer->data)->netID), 4);
		SendGamePacket(peer, &p2);
		auto psp = packetEnd(appendString(appendString(createPacket(), "OnPlayPositioned"), "audio/door_open.wav"));
		const auto packetd = enet_packet_create(psp.data, psp.len, ENET_PACKET_FLAG_RELIABLE);
		enet_peer_send(peer, 0, packetd);
		delete psp.data;
	}
}

inline void SendParticleEffect(ENetPeer* peer, int x, int y, int size, int id, int delay)
{
	PlayerMoving datx{};
	datx.packetType = 0x11;
	datx.x = x;
	datx.y = y;
	datx.YSpeed = id;
	datx.XSpeed = size;
	datx.plantingTree = delay;
	SendPacketRaw(4, packPlayerMoving(&datx), 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
}

inline void SyncPlayerRoles(ENetPeer* peer, int level, string type) {
	if (type == "firefighter") {
		Player::PlayAudio(peer, "audio/levelup.wav", 0);
		Player::OnParticleEffect(peer, 46, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
		Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wFirefighter role is now level " + to_string(level) + "!", 0, true);
		if (level == 1) {
			auto success = true;
			SaveItemMoreTimes(1486, 1, peer, success, "");
		} else if (level == 2) {

		} else if (level == 3) {
			
		} else if (level == 4) {
			
		} else if (level == 5) {
			auto success = true;
			SaveItemMoreTimes(4996, 1, peer, success, "");
		} else if (level == 6) {
			
		} else if (level == 7) {
			
		} else if (level == 8) {
			auto success = true;
			SaveItemMoreTimes(6860, 1, peer, success, "");
		} else if (level == 9) {
			auto success = true;
			SaveItemMoreTimes(1486, 10, peer, success, "");
		} else if (level == 10) {
			auto success = true;
			SaveItemMoreTimes(6008, 1, peer, success, "");
		}
	} else if (type == "provider") {
		Player::PlayAudio(peer, "audio/levelup.wav", 0);
		Player::OnParticleEffect(peer, 46, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
		Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wProvider role is now level " + to_string(level) + "!", 0, true);
		if (level == 1) {
			auto success = true;
			SaveItemMoreTimes(1636, 1, peer, success, "");
		} else if (level == 2) {

		} else if (level == 3) {
			auto success = true;
			SaveItemMoreTimes(1486, 3, peer, success, "");
		} else if (level == 4) {
			
		} else if (level == 5) {
			auto success = true;
			SaveItemMoreTimes(5082, 1, peer, success, "");
		} else if (level == 6) {
			
		} else if (level == 7) {
			
		} else if (level == 8) {
			auto success = true;
			SaveItemMoreTimes(6860, 1, peer, success, "");
		} else if (level == 9) {
			auto success = true;
			SaveItemMoreTimes(1486, 10, peer, success, "");
		} else if (level == 10) {
			auto success = true;
			SaveItemMoreTimes(7558, 1, peer, success, "");
		}
	} else if (type == "geiger") {
		Player::PlayAudio(peer, "audio/levelup.wav", 0);
		Player::OnParticleEffect(peer, 46, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
		Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wGeiger Hunter role is now level " + to_string(level) + "!", 0, true);
		if (level == 1) {
			auto success = true;
			SaveItemMoreTimes(4656, 1, peer, success);
		} else if (level == 2) {

		} else if (level == 3) {

		} else if (level == 4) {
			
		} else if (level == 5) {

		} else if (level == 6) {
			
		} else if (level == 7) {
			
		} else if (level == 8) {
			auto success = true;
			SaveItemMoreTimes(10424, 1, peer, success);
		} else if (level == 9) {
			auto success = true;
			SaveItemMoreTimes(5084, 1, peer, success);
		} else if (level == 10) {
			auto success = true;
			SaveItemMoreTimes(8480, 1, peer, success);
		}
	} else if (type == "fisherman") {
		Player::PlayAudio(peer, "audio/levelup.wav", 0);
		Player::OnParticleEffect(peer, 46, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
		Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wFisherman role is now level " + to_string(level) + "!", 0, true);
		if (level == 1) {
			auto success = true;
			SaveItemMoreTimes(3010, 1, peer, success);
		} else if (level == 2) {

		} else if (level == 3) {

		} else if (level == 4) {
			auto success = true;
			SaveItemMoreTimes(3074, 1, peer, success);
		} else if (level == 5) {
			auto success = true;
			SaveItemMoreTimes(5740, 1, peer, success);
		} else if (level == 6) {
			
		} else if (level == 7) {
			auto success = true;
			SaveItemMoreTimes(1550, 1, peer, success);
		} else if (level == 8) {
			auto success = true;
			SaveItemMoreTimes(3100, 1, peer, success);
		} else if (level == 9) {
			auto success = true;
			SaveItemMoreTimes(5080, 1, peer, success);
		} else if (level == 10) {
			auto success = true;
			SaveItemMoreTimes(3040, 1, peer, success);
		}
	} else if (type == "regular") {
		for (ENetPeer* net_peer = server->peers; net_peer < &server->peers[server->peerCount]; ++net_peer) {
			if (net_peer->state != ENET_PEER_STATE_CONNECTED) continue;
			if (isHere(peer, net_peer)) {
				Player::PlayAudio(net_peer, "audio/levelup2.wav", 0);
			}
		}
		if (level == 1) {

		} else if (level == 2) {
			auto success = true;
			SaveItemMoreTimes(340, 75, peer, success, "");
		} else if (level == 3) {
			auto success = true;
			SaveItemMoreTimes(1486, 1, peer, success, "");
		} else if (level == 4) {
			auto success = true;
			SaveItemMoreTimes(1938, 1, peer, success, "");
		} else if (level == 5) {
			auto success = true;
			SaveItemMoreTimes(1486, 5, peer, success, "");
		} else if (level == 6) {
			
		} else if (level == 7) {
			auto success = true;
			SaveItemMoreTimes(6918, 1, peer, success, "");
		} else if (level == 8) {

		} else if (level == 9) {
			std::ifstream ifsz("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
			std::string content((std::istreambuf_iterator<char>(ifsz)), (std::istreambuf_iterator<char>()));
			auto gembux = atoi(content.c_str());
			auto fingembux = gembux + 5000;
			ofstream myfile;
			myfile.open("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
			myfile << fingembux;
			myfile.close();
			auto gemcalc = gembux + 5000;
			Player::OnSetBux(peer, gemcalc, 0);
		} else if (level == 10) {
			auto success = true;
			SaveItemMoreTimes(1740, 1, peer, success, "");
		} else if (level == 11) {

		} else if (level == 12) {
			std::ifstream ifsz("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
			std::string content((std::istreambuf_iterator<char>(ifsz)), (std::istreambuf_iterator<char>()));
			auto gembux = atoi(content.c_str());
			auto fingembux = gembux + 15000;
			ofstream myfile;
			myfile.open("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
			myfile << fingembux;
			myfile.close();
			auto gemcalc = gembux + 15000;
			Player::OnSetBux(peer, gemcalc, 0);
		} else if (level == 13) {
			auto success = true;
			SaveItemMoreTimes(8452, 1, peer, success, "");
		} else if (level == 14) {
			auto success = true;
			SaveItemMoreTimes(1486, 5, peer, success, "");
		} else if (level == 15) {
			
		}
	}
}

inline void SendXP(ENetPeer* peer, int amount) {
	if (GrowganothEvent) {
		if ((rand() % 3000) <= 1) {
			Player::OnConsoleMessage(peer, "`4Growganoth `olikes your work and rewards with `2Gift Of Growganoth`o!");
			Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`4Growganoth `wlikes your work and rewards with `2Gift Of Growganoth`w!", 0, false);
			auto success = true;
			SaveItemMoreTimes(10386, 1, peer, success);
		}
	}
	if (static_cast<PlayerInfo*>(peer->data)->cloth_necklace == 9168) {
		amount *= 2;
	} 
	if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 9152) {
		amount *= 2;
	} 
	if (static_cast<PlayerInfo*>(peer->data)->cloth_back == 9506) {
		amount *= 2;
	} 
	if (isYellowAnces(GetPeerData(peer)) || FarmingEvent) {
		if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5078 || FarmingEvent) {
			const auto chance = (rand() % 100) + 1;
			if (chance <= 5) {
				amount *= 2;
				Player::OnParticleEffect(peer, 49, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
			}
		} else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5126) /*lvl2*/ {
			const auto chance = (rand() % 100) + 1;
			if (chance <= 10)
			{
				amount *= 2;
				Player::OnParticleEffect(peer, 49, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
			}
		}
		else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5128) /*lvl3*/
		{
			const auto chance = (rand() % 100) + 1;
			if (chance <= 15)
			{
				amount *= 2;
				Player::OnParticleEffect(peer, 49, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
			}
		}
		else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5130) /*lvl4*/
		{
			const auto chance = (rand() % 100) + 1;
			if (chance <= 20)
			{
				amount *= 2;
				Player::OnParticleEffect(peer, 49, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
			}
		}
		else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5132) /*lvl5*/
		{
			const auto chance = (rand() % 100) + 1;
			if (chance <= 25)
			{
				amount *= 2;
				Player::OnParticleEffect(peer, 49, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
			}
		}
		else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5134) /*lvl6*/
		{
			const auto chance = (rand() % 100) + 1;
			if (chance <= 30)
			{
				amount *= 2;
				Player::OnParticleEffect(peer, 49, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
			}
		}
	}
	if (static_cast<PlayerInfo*>(peer->data)->quest_active && static_cast<PlayerInfo*>(peer->data)->lastquest == "honor" && static_cast<PlayerInfo*>(peer->data)->quest_step == 8 && static_cast<PlayerInfo*>(peer->data)->quest_progress < 10000) {
		static_cast<PlayerInfo*>(peer->data)->quest_progress += amount;
		if (static_cast<PlayerInfo*>(peer->data)->quest_progress >= 10000) {
			static_cast<PlayerInfo*>(peer->data)->quest_progress = 10000;
			Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`9Legendary Quest step complete! I'm off to see a Wizard!", 0, false);
		}
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 125) return;
	static_cast<PlayerInfo*>(peer->data)->xp += amount;
	if (static_cast<PlayerInfo*>(peer->data)->xp >= (static_cast<PlayerInfo*>(peer->data)->level * 1500) && static_cast<PlayerInfo*>(peer->data)->level < 125) {
		static_cast<PlayerInfo*>(peer->data)->xp = 0;
		static_cast<PlayerInfo*>(peer->data)->level = static_cast<PlayerInfo*>(peer->data)->level + 1;
		SyncPlayerRoles(peer, static_cast<PlayerInfo*>(peer->data)->level, "regular");
		for (ENetPeer* net_peer = server->peers; net_peer < &server->peers[server->peerCount]; ++net_peer) {
			if (net_peer->state != ENET_PEER_STATE_CONNECTED) continue;
			if (isHere(peer, net_peer)) {
				Player::OnParticleEffect(net_peer, 46, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, 0);
				Player::OnConsoleMessage(net_peer, static_cast<PlayerInfo*>(peer->data)->displayName + " `wis now level " + std::to_string(static_cast<PlayerInfo*>(peer->data)->level) + "!");
				Player::OnTalkBubble(net_peer, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->displayName + " `wis now level " + std::to_string(static_cast<PlayerInfo*>(peer->data)->level) + "!", 0, true);
			}
		}
	}
}

inline void find_geiger(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->GeigerCooldown) return;
	if (static_cast<PlayerInfo*>(peer->data)->geigerx == 0 && static_cast<PlayerInfo*>(peer->data)->geigery == 0) {
		const auto geigercounterx = rand() % 3000;
		const auto geigercountery = rand() % 1500;
		static_cast<PlayerInfo*>(peer->data)->geigerx = geigercounterx;
		static_cast<PlayerInfo*>(peer->data)->geigery = geigercountery;
	}
	if (static_cast<PlayerInfo*>(peer->data)->x >= static_cast<PlayerInfo*>(peer->data)->geigerx - 30 && static_cast<PlayerInfo*>(peer->data)->x <= static_cast<PlayerInfo*>(peer->data)->geigerx + 30 && static_cast<PlayerInfo*>(peer->data)->y >= static_cast<PlayerInfo*>(peer->data)->geigery - 30 && static_cast<PlayerInfo*>(peer->data)->y <= static_cast<PlayerInfo*>(peer->data)->geigery + 30) {
		SendParticleEffect(peer, static_cast<PlayerInfo*>(peer->data)->x + 10, static_cast<PlayerInfo*>(peer->data)->y + 10, 3, 114, 0);
		std::vector<int> list{ 6416, 2206, 3792, 3196, 4654, 3306, 1498, 1500, 2804, 2806, 8270, 8272, 8274, 2242, 2244, 2246, 2248, 2250 };
		if (ValentineEvent) list.push_back(4426);
		if (GeigerDay) {
			list.push_back(4676);
			list.push_back(4678);
			list.push_back(4680);
			list.push_back(4682);
			list.push_back(4652);
			list.push_back(4646);
			list.push_back(4648);
			list.push_back(4652);
			list.push_back(4650);
			list.push_back(10084);
			list.push_back(10086);
		}
		const int index = rand() % list.size();
		const auto value = list[index];
		Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wI found a `2" + getItemDef(value).name + "`w!", 0, true);
		auto success = true;
		SaveItemMoreTimes(value, 1, peer, success);
		const auto geigercounterx = rand() % 3000;
		const auto geigercountery = rand() % 1500;
		static_cast<PlayerInfo*>(peer->data)->geigerx = geigercounterx;
		static_cast<PlayerInfo*>(peer->data)->geigery = geigercountery;
		int chanceofbonus = 1;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 4) chanceofbonus = 2;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 6) chanceofbonus = 3;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 8) chanceofbonus = 4;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 10) chanceofbonus = 5;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 2 && rand() % 100 <= chanceofbonus) {
			Player::OnConsoleMessage(peer, "Infused bonus not gained irradiated mod");
		} else {
			if (GeigerDay) {
				Player::OnConsoleMessage(peer, "`oYou are aglow with radiation!. (`$Irradiated `omod added, `$15 mins `oleft)``");
				static_cast<PlayerInfo*>(peer->data)->GeigerTime = (GetCurrentTimeInternalSeconds() + (15 * 60));
			} else {
				Player::OnConsoleMessage(peer, "`oYou are aglow with radiation!. (`$Irradiated `omod added, `$30 mins `oleft)``");
				static_cast<PlayerInfo*>(peer->data)->GeigerTime = (GetCurrentTimeInternalSeconds() + (30 * 60));
			}
			static_cast<PlayerInfo*>(peer->data)->GeigerCooldown = true;
			static_cast<PlayerInfo*>(peer->data)->haveGeigerRadiation = true;
			send_state(peer);
		}

		int chanceofextrabonus = 1;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 7) chanceofextrabonus = 2;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 4 && rand() % 100 <= chanceofextrabonus) {
			std::vector<int> lists{ 6416, 2206, 3792, 3196, 4654, 3306, 1498, 1500, 2804, 2806, 8270, 8272, 8274, 2242, 2244, 2246, 2248, 2250 };
			if (ValentineEvent) lists.push_back(4426);
			if (GeigerDay) {
				lists.push_back(4676);
				lists.push_back(4678);
				lists.push_back(4680);
				lists.push_back(4682);
				lists.push_back(4652);
				lists.push_back(4646);
				lists.push_back(4648);
				lists.push_back(4652);
				lists.push_back(4650);
				lists.push_back(10084);
				lists.push_back(10086);
			}
			const int indexas = rand() % lists.size();
			const auto values = lists[indexas];
			Player::OnConsoleMessage(peer, "Weil Magic bonus gained " + getItemDef(values).name + "");
			auto success1 = true;
			SaveItemMoreTimes(values, 1, peer, success1);
		}

		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 3 && rand() % 100 <= 1) {
			Player::OnConsoleMessage(peer, "Obtained Uranium Block");
			auto success1 = true;
			SaveItemMoreTimes(4658, 1, peer, success1);
		}

		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 5 && rand() % 100 <= 1) {
			Player::OnConsoleMessage(peer, "Obtained Electrical Power Cube");
			auto success1 = true;
			SaveItemMoreTimes(6976, 1, peer, success1);
		}

		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel >= 10 && rand() % 100 <= 1) {
			Player::OnConsoleMessage(peer, "Obtained Growtoken");
			auto success1 = true;
			SaveItemMoreTimes(1486, 1, peer, success1);
		}

		int targetgeigerlevel = 600;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel > 0) targetgeigerlevel = targetgeigerlevel * static_cast<PlayerInfo*>(peer->data)->geigerlevel;
		if (static_cast<PlayerInfo*>(peer->data)->geigerlevel == 0) targetgeigerlevel = 350;
		if (static_cast<PlayerInfo*>(peer->data)->geigerxp >= targetgeigerlevel && static_cast<PlayerInfo*>(peer->data)->geigerlevel < 10) {
			static_cast<PlayerInfo*>(peer->data)->geigerlevel++;
			static_cast<PlayerInfo*>(peer->data)->geigerxp = 0;
			SyncPlayerRoles(peer, static_cast<PlayerInfo*>(peer->data)->geigerlevel, "geiger");
		} else {
			static_cast<PlayerInfo*>(peer->data)->geigerxp += 10;
		}
		SendXP(peer, 15);
	} else {
		const auto checkx = static_cast<PlayerInfo*>(peer->data)->geigerx - static_cast<PlayerInfo*>(peer->data)->x;
		const auto checky = static_cast<PlayerInfo*>(peer->data)->y - static_cast<PlayerInfo*>(peer->data)->geigery;
		if (checkx > 200 || checkx < -200) {
			SendParticleEffect(peer, static_cast<PlayerInfo*>(peer->data)->x + 10, static_cast<PlayerInfo*>(peer->data)->y + 10, 0, 114, 0);
		} else if (checky > 200 || checky < -200) {
			SendParticleEffect(peer, static_cast<PlayerInfo*>(peer->data)->x + 10, static_cast<PlayerInfo*>(peer->data)->y + 10, 1, 114, 0);
		} else {
			SendParticleEffect(peer, static_cast<PlayerInfo*>(peer->data)->x + 10, static_cast<PlayerInfo*>(peer->data)->y + 10, 2, 114, 0);
		}
	}
}

inline void updateworldremove(ENetPeer* peer) {
	size_t pos;
	while ((pos = static_cast<PlayerInfo*>(peer->data)->displayName.find("`2")) != std::string::npos) {
		static_cast<PlayerInfo*>(peer->data)->displayName.replace(pos, 2, "");
	}
	Player::OnNameChanged(peer, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->displayName);
}

inline void treeModify(ENetPeer* peer, const int x, const int y, const int NetID)
{
	PlayerMoving data_{};
	data_.packetType = 0xC;
	data_.x = 0;
	data_.y = 0;
	data_.punchX = x;
	data_.punchY = y;
	data_.XSpeed = 0;
	data_.YSpeed = 0;
	data_.netID = NetID;
	data_.plantingTree = 0;
	const auto raw = packPlayerMoving(&data_);
	memset(raw + 8, 0xFF, 4);
	SendPacketRaw(4, raw, 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
}

inline bool isSeed(const int block)
{
	return block % 2 == 1;
}

inline void accessPlayer(ENetPeer* peer, const string name, WorldInfo* world) {
	if (world == NULL) return;
	try {
		if (static_cast<PlayerInfo*>(peer->data)->haveGrowId == false || world->owner != static_cast<PlayerInfo*>(peer->data)->rawName) return;
		string access_name = "";
		int x = static_cast<PlayerInfo*>(peer->data)->wrenchedBlockLocation % world->width;
		int y = static_cast<PlayerInfo*>(peer->data)->wrenchedBlockLocation / world->width;
		for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer)) {
				if (static_cast<PlayerInfo*>(currentPeer->data)->rawName == name) {
					if (isWorldOwner(currentPeer, world) || isWorldAdmin(currentPeer, world)) {
						Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`w" + static_cast<PlayerInfo*>(currentPeer->data)->displayName + "`` already has access to the lock.", 0, false);
						break;
					}
					access_name = static_cast<PlayerInfo*>(currentPeer->data)->displayName;
					world->accessed.push_back(static_cast<PlayerInfo*>(currentPeer->data)->rawName);
					Player::PlayAudio(currentPeer, "audio/secret.wav", 0);
					static_cast<PlayerInfo*>(currentPeer->data)->displayName = "`^" + static_cast<PlayerInfo*>(currentPeer->data)->displayName;
					auto p7 = packetEnd(appendString(appendString(createPacket(), "OnNameChanged"), static_cast<PlayerInfo*>(currentPeer->data)->displayName));
					memcpy(p7.data + 8, &(static_cast<PlayerInfo*>(currentPeer->data)->netID), 4);
					auto packet7 = enet_packet_create(p7.data, p7.len, ENET_PACKET_FLAG_RELIABLE);
					delete p7.data;
					for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
						if (isHere(peer, currentPeer)) {
							enet_peer_send(currentPeer, 0, packet7);
						}
					}
					send_tile_data(currentPeer, x, y, 0x10, world->items.at(static_cast<PlayerInfo*>(peer->data)->wrenchedBlockLocation).foreground, world->items.at(static_cast<PlayerInfo*>(peer->data)->wrenchedBlockLocation).background, lock_tile_datas(0x20, static_cast<PlayerInfo*>(currentPeer->data)->netID, 0, 0, true, 100));
					break;
				}
			}
		}
		if (access_name != "") {
			for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
				if (isHere(peer, currentPeer)) {
					Player::OnConsoleMessage(currentPeer, access_name + " `owas given access to a World Lock.");
				}
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void DropBlock(WorldInfo* world, ENetPeer* peer, const int x, const int y, const int foreground) {
	if (getItemDef(foreground).properties & Property_Dropless || getItemDef(foreground).properties & Property_Mod || getItemDef(foreground).properties & Property_NoBlock) return;
	if (foreground == 4762 || foreground == 7382 || foreground == 5136 || foreground == 5138 || foreground == 5154 || foreground == 5140) return;
	DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), foreground, 1, 0);
}

inline void SendDropSeed(WorldInfo* world, ENetPeer* peer, const int x, const int y, const int foreground)
{
	if (getItemDef(foreground).properties & Property_NoSeed || getItemDef(foreground).properties & Property_Mod || getItemDef(foreground).properties & Property_Dropless) return;
	if (specialdrop != 0)
	{
		if ((rand() % 1200) <= 6)
		{
			DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), specialdrop, 1, 0);
		}
	}
	if ((rand() % 180000) <= 3)
	{
		DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 5018, 1, 0);
	}
	/*fire chi*/
	if (getItemDef(foreground).blockType == BlockTypes::PAIN_BLOCK)
	{
		if ((rand() % 1800) <= 6)
		{
			DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 5024, 1, 0);
		}
	}
	/*water chi*/
	if (foreground == 5034 || foreground == 5048 || foreground == 7520 || foreground == 7522 || foreground == 7772 || foreground == 7774 || foreground == 8240 || foreground == 3506 || foreground == 3584)
	{
		if ((rand() % 1800) <= 6)
		{
			DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 5026, 1, 0);
		}
	}
	/*earth chi*/
	if (getItemDef(foreground).blockType == BlockTypes::FOREGROUND && foreground != 5034 && foreground != 5048 && foreground != 7520 && foreground != 7522 && foreground != 7772 && foreground != 7774 && foreground != 2794 || foreground != 2796 || foreground != 2810 && foreground != 8240 && foreground != 3506 && foreground != 3584)
	{
		if ((rand() % 1800) <= 6)
		{
			DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 5028, 1, 0);
		}
	}
	/*wind chi*/
	if (foreground == 2794 || foreground == 2796 || foreground == 2810)
	{
		if ((rand() % 1800) <= 6)
		{
			DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 5030, 1, 0);
		}
	}
	int chance = 0;
	if (isSeed(foreground)) {
		SendXP(peer, 1);
		chance = (rand() % 350) + 1;
	}
	else if (getItemDef(foreground).rarity < 25) {
		SendXP(peer, 1);
		chance = (rand() % 110) + 1;
	}
	else if (getItemDef(foreground).rarity >= 25 && getItemDef(foreground).rarity < 40) {
		SendXP(peer, 2);
		chance = (rand() % 115) + 1;
	}
	else if (getItemDef(foreground).rarity >= 40 && getItemDef(foreground).rarity < 60) {
		SendXP(peer, 3);
		chance = (rand() % 120) + 1;
	}
	else if (getItemDef(foreground).rarity >= 60 && getItemDef(foreground).rarity < 80) {
		SendXP(peer, 4);
		chance = (rand() % 125) + 1;
	}
	else if (getItemDef(foreground).rarity >= 80 && getItemDef(foreground).rarity < 100) {
		SendXP(peer, 5);
		chance = (rand() % 130) + 1;
	}
	else if (getItemDef(foreground).rarity >= 100) {
		SendXP(peer, 6);
		chance = (rand() % 135) + 1;
	}
	int target_v = 20;
	if (foreground == 9508) target_v = 40;
	if (chance <= target_v) {
		if (isSeed(foreground)) {
			DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), foreground, 1, 0);
		} else {
			DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), foreground + 1, 1, 0);
		}
	}
}

inline void SendTradeEffect(ENetPeer* peer, const int id, const int netIDsrc, const int netIDdst, const int timeMs)
{
	PlayerMoving data{};
	data.packetType = 0x13;
	data.punchX = id;
	data.punchY = id;
	const auto raw = packPlayerMoving(&data);
	auto netIdSrc = netIDsrc;
	auto netIdDst = netIDdst;
	auto three = 3;
	auto n1 = timeMs;
	memcpy(raw + 3, &three, 1);
	memcpy(raw + 4, &netIdDst, 4);
	memcpy(raw + 8, &netIdSrc, 4);
	memcpy(raw + 20, &n1, 4);
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer))
		{
			const auto raw2 = new BYTE[56];
			memcpy(raw2, raw, 56);
			SendPacketRaw(4, raw2, 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
	delete raw;
}

inline void DropGem(ENetPeer* peer, const int x, const int y, WorldInfo* world, int kiek = 0) {
	try {
		auto b = getGemCount(world->items.at(x + (y * world->width)).foreground) + rand() % 3;
		if (b == 0 && static_cast<PlayerInfo*>(peer->data)->GemBuffDrop) b += 1;
		if (kiek != 0) b = kiek;
		if (item_multiplier.find(static_cast<PlayerInfo*>(peer->data)->cloth_hand) != item_multiplier.end()) {
			b *= item_multiplier.at(static_cast<PlayerInfo*>(peer->data)->cloth_hand);
		} if (item_multiplier.find(static_cast<PlayerInfo*>(peer->data)->cloth_back) != item_multiplier.end()) {
			b *= item_multiplier.at(static_cast<PlayerInfo*>(peer->data)->cloth_back);
		} if (item_multiplier.find(static_cast<PlayerInfo*>(peer->data)->cloth_necklace) != item_multiplier.end()) {
			b *= item_multiplier.at(static_cast<PlayerInfo*>(peer->data)->cloth_necklace);
		}
		if (gem_multiplier != 0) b *= gem_multiplier;
		if (!world->drop_gem && b != 0) {
			try {
				Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`^You found `9" + std::to_string(b) + " `2Gems`w!", 0, 0);
				int currentgems = 0;
				ifstream fs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				if (!fs.is_open()) {
					SendConsole("TXT Exception #1 Failed to open TXT for reading " + static_cast<PlayerInfo*>(peer->data)->rawName, "ERROR");
					return;
				}
				fs >> currentgems;
				fs.close();
				currentgems += b;
				ofstream of("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				of << currentgems;
				of.close();
				Player::OnSetBux(peer, currentgems, 0);
			}
			catch (std::exception&) {
				SendConsole("TXT Exception #4 Failed to save gems " + static_cast<PlayerInfo*>(peer->data)->rawName, "ERROR");
			}
			return;
		}
		while (b > 0) {
			if (b >= 100) {
				DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 100, 0);
				b -= 100;
				for (auto i = 0; i < rand() % 1; i++) DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 10, 0);
				for (auto i = 0; i < rand() % 4; i++) DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 1, 0);
				continue;
			}
			if (b >= 50) {
				DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 50, 0);
				b -= 50;
				for (auto i = 0; i < rand() % 1; i++) DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 5, 0);
				for (auto i = 0; i < rand() % 3; i++) DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 1, 0);
				continue;
			}
			if (b >= 10) {
				DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 10, 0);
				b -= 10;
				for (auto i = 0; i < rand() % 4; i++) DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 1, 0);
				continue;
			}
			if (b >= 7) {
				DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 10, 0);
				b -= 5;
				for (auto i = 0; i < rand() % 2; i++) DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 1, 0);
				continue;
			}
			if (b >= 5) {
				DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 5, 0);
				b -= 5;
				for (auto i = 0; i < rand() % 2; i++) DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 1, 0);
				continue;
			}
			if (b >= 1) {
				DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), 112, 1, 0);
				b -= 1;
				for (auto i = 0; i < rand() % 1; i++) DropItem(world, peer, -1, x * 32 + (rand() % 8), y * 32 + (rand() % 16), 112, 1, 0);
				continue;
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void SendTileData(WorldInfo* world, ENetPeer* peer, const int x, const int y, const int punchX, const int punchY, int kiek_gem = 0)
{
	try {
		if (getItemDef(world->items.at(x + (y * world->width)).foreground).properties & Property_Dropless) return;
		/*The Basic Everything*/
		if (static_cast<PlayerInfo*>(peer->data)->quest_active && static_cast<PlayerInfo*>(peer->data)->lastquest == "honor" && static_cast<PlayerInfo*>(peer->data)->quest_step == 11 && static_cast<PlayerInfo*>(peer->data)->quest_progress < 100000) {
			static_cast<PlayerInfo*>(peer->data)->quest_progress += getItemDef(world->items.at(x + (y * world->width)).foreground).rarity;
			if (static_cast<PlayerInfo*>(peer->data)->quest_progress >= 100000) {
				static_cast<PlayerInfo*>(peer->data)->quest_progress = 100000;
				Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`9Legendary Quest step complete! I'm off to see a Wizard!", 0, false);
			}
		}
		if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 9454 || static_cast<PlayerInfo*>(peer->data)->cloth_hand == 9456 || static_cast<PlayerInfo*>(peer->data)->cloth_hand == 9458) return;
		if (!isSeed(world->items.at(x + (y * world->width)).foreground)) {
			DropGem(peer, x, y, world, kiek_gem);
			if ((rand() % 300) <= 3) {
				DropBlock(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
			}
			if (isRedAnces(GetPeerData(peer)) || FarmingEvent)
			{
				if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5084 || FarmingEvent)
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 5)
					{
						static_cast<PlayerInfo*>(peer->data)->GemBuffDrop = true;
						Player::OnParticleEffect(peer, 29, punchX * 32, punchY * 32, 0);
						DropGem(peer, x, y, world, kiek_gem);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5180) /*lvl2*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 10)
					{
						static_cast<PlayerInfo*>(peer->data)->GemBuffDrop = true;
						Player::OnParticleEffect(peer, 29, punchX * 32, punchY * 32, 0);
						DropGem(peer, x, y, world, kiek_gem);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5182) /*lvl3*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 15)
					{
						static_cast<PlayerInfo*>(peer->data)->GemBuffDrop = true;
						Player::OnParticleEffect(peer, 29, punchX * 32, punchY * 32, 0);
						DropGem(peer, x, y, world, kiek_gem);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5184) /*lvl4*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 20)
					{
						static_cast<PlayerInfo*>(peer->data)->GemBuffDrop = true;
						Player::OnParticleEffect(peer, 29, punchX * 32, punchY * 32, 0);
						DropGem(peer, x, y, world, kiek_gem);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5186) /*lvl5*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 25)
					{
						static_cast<PlayerInfo*>(peer->data)->GemBuffDrop = true;
						Player::OnParticleEffect(peer, 29, punchX * 32, punchY * 32, 0);
						DropGem(peer, x, y, world, kiek_gem);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5188) /*lvl6*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 30)
					{
						static_cast<PlayerInfo*>(peer->data)->GemBuffDrop = true;
						Player::OnParticleEffect(peer, 29, punchX * 32, punchY * 32, 0);
						DropGem(peer, x, y, world, kiek_gem);
					}
				}
			}
			else if (isBlueAnces(GetPeerData(peer)) || FarmingEvent)
			{
				if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5080 || FarmingEvent) /*lvl1*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 3)
					{
						Player::OnParticleEffect(peer, 374, punchX * 32 + 20, punchY * 32 + 30, 0);
						DropBlock(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5144) /*lvl2*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 6)
					{
						Player::OnParticleEffect(peer, 374, punchX * 32 + 20, punchY * 32 + 30, 0);
						DropBlock(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5146) /*lvl3*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 9)
					{
						Player::OnParticleEffect(peer, 374, punchX * 32 + 20, punchY * 32 + 30, 0);
						DropBlock(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5148) /*lvl4*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 12)
					{
						Player::OnParticleEffect(peer, 374, punchX * 32 + 20, punchY * 32 + 30, 0);
						DropBlock(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5150) /*lvl5*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 15)
					{
						Player::OnParticleEffect(peer, 374, punchX * 32 + 20, punchY * 32 + 30, 0);
						DropBlock(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
					}
				}
				else if (static_cast<PlayerInfo*>(peer->data)->cloth_ances == 5152) /*lvl6*/
				{
					const auto chance = (rand() % 125) + 1;
					if (chance <= 18)
					{
						Player::OnParticleEffect(peer, 374, punchX * 32 + 20, punchY * 32 + 30, 0);
						DropBlock(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
					}
				}
			}
		}
		SendDropSeed(world, peer, x, y, world->items.at(x + (y * world->width)).foreground);
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void SendGuildPoints(ENetPeer* peer, int amount)
{
	if (static_cast<PlayerInfo*>(peer->data)->haveGrowId == false) return;
	if (static_cast<PlayerInfo*>(peer->data)->guild != "")
	{
		try
		{
			auto currentgpoints = 0;
			ifstream guildstream1("save/guildrewards/guildpoints/" + static_cast<PlayerInfo*>(peer->data)->guild + ".txt");
			guildstream1 >> currentgpoints;
			guildstream1.close();
			if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 9508)
			{
				amount *= 2;
				auto newgpoints = currentgpoints + amount;
				ofstream guildstream3("save/guildrewards/guildpoints/" + static_cast<PlayerInfo*>(peer->data)->guild + ".txt");
				guildstream3 << newgpoints;
				guildstream3.close();
			}
			else
			{
				auto newgpoints = currentgpoints + amount;
				ofstream guildstream3("save/guildrewards/guildpoints/" + static_cast<PlayerInfo*>(peer->data)->guild + ".txt");
				guildstream3 << newgpoints;
				guildstream3.close();
			}
			// M CONTRIBUTION
			auto currentplayercontribution = 0;
			namespace fs = std::experimental::filesystem;
			if (!fs::is_directory("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild) || !fs::exists("save/guildrewards / contribution / " + static_cast<PlayerInfo*>(peer->data)->guild))
			{
				fs::create_directory("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild);
				ifstream mcontr("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild + "/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				mcontr >> currentplayercontribution;
				mcontr.close();
				if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 9508)
				{
					amount *= 2;
					auto newcontr = currentplayercontribution + amount;
					ofstream savecon("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild + "/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
					savecon << newcontr;
					savecon.close();
				}
				else
				{
					auto newcontr = currentplayercontribution + amount;
					ofstream savecon("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild + "/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
					savecon << newcontr;
					savecon.close();
				}
			}
			else
			{
				ifstream mcontr("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild + "/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				mcontr >> currentplayercontribution;
				mcontr.close();
				if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 9508)
				{
					amount *= 2;
					auto newcontr = currentplayercontribution + amount;
					ofstream savecon("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild + "/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
					savecon << newcontr;
					savecon.close();
				}
				else
				{
					auto newcontr = currentplayercontribution + amount;
					ofstream savecon("save/guildrewards/contribution/" + static_cast<PlayerInfo*>(peer->data)->guild + "/" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
					savecon << newcontr;
					savecon.close();
				}
			}
		}
		catch (...)
		{
			cout << "SendGuildPoints Function Failed" << endl;
		}
	}
}

inline void SendFarmableDrop(ENetPeer* peer, int chance, int x, int y, WorldInfo* world) {
	int valgem = rand() % chance + 1;
	DropGem(peer, x, y, world, valgem);
}
inline void SendPlacingEffect(ENetPeer* peer, const int punchX, const int punchY, const int effect)
{
	const float hi = punchX * 32;
	const float hi2 = punchY * 32;
	for (auto currentPeer = server->peers;
		currentPeer < &server->peers[server->peerCount];
		++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer))
		{
			Player::OnParticleEffect(currentPeer, effect, hi, hi2, 0);
		}
	}
}

inline void SendHarvestFestivalDrop(WorldInfo* world, ENetPeer* peer, const int x, const int y, const int rarity)
{
	auto TargetChance = 0;
	if (rarity <= 15) TargetChance = 6;
	else if (rarity <= 25) TargetChance = 10;
	else if (rarity <= 35) TargetChance = 12;
	else if (rarity <= 45) TargetChance = 14;
	else if (rarity <= 55) TargetChance = 18;
	else if (rarity <= 65) TargetChance = 20;
	else if (rarity <= 75) TargetChance = 23;
	else if (rarity <= 85) TargetChance = 25;
	else if (rarity <= 95) TargetChance = 28;
	else if (rarity <= 115) TargetChance = 30;
	else TargetChance = 30;
	const auto chance = (rand() % 100) + 1;
	if (chance <= TargetChance) {
		vector<int> CakeBase{ 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 3870, 7058, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 7058, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1828, 3870, 3870, 7058, 1058, 1094, 1096, 1098, 1058, 1828, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 5156, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1094, 1096, 1098, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1094, 1096, 1098, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1094, 1096, 1098, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098, 1058, 1094, 1096, 1098 };
		const int Index = rand() % CakeBase.size();
		const auto ItemID = CakeBase[Index];
		DropItem(world, peer, -1, x * 32, y * 32, ItemID, 1, 0);
		for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (isHere(peer, currentPeer)) {
				Player::OnParticleEffect(currentPeer, 50, x * 32, y * 32, 0);
			}
		}
	}
}

inline void SendCombiner(ENetPeer* peer, WorldInfo* world, const int x, const int y) {
	try {
		vector<int> items_at_pos{};
		for (auto i = 0; i < world->droppedItems.size(); i++) {
			int x_p = world->droppedItems.at(i).x / 32;
			int y_p = world->droppedItems.at(i).y / 32;
			if (x_p == x && y_p == y) {
				items_at_pos.push_back(world->droppedItems.at(i).id);
			}
		}
		ifstream infile("binary.txt");
		for (string line; getline(infile, line);) {
			if (line.length() > 3 && line.at(0) != '/' && line.at(1) != '/') {
				auto ex = explode("|", line);
				int id1 = atoi(ex.at(0).c_str());
				int id2 = atoi(ex.at(1).c_str());
				int id3 = atoi(ex.at(2).c_str());
				if (std::find(items_at_pos.begin(), items_at_pos.end(), id1) != items_at_pos.end() && std::find(items_at_pos.begin(), items_at_pos.end(), id2) != items_at_pos.end() && std::find(items_at_pos.begin(), items_at_pos.end(), id3) != items_at_pos.end()) {
					int id1count = 0, id2count = 0, id3count = 0;
					for (auto i = 0; i < world->droppedItems.size(); i++) {
						int x_p = world->droppedItems.at(i).x / 32;
						int y_p = world->droppedItems.at(i).y / 32;
						if (x_p == x && y_p == y && world->droppedItems.at(i).id == id1) {
							id1count = world->droppedItems.at(i).count;
						} else if (x_p == x && y_p == y && world->droppedItems.at(i).id == id2) {
							id2count = world->droppedItems.at(i).count;
						} else if (x_p == x && y_p == y && world->droppedItems.at(i).id == id3) {
							id3count = world->droppedItems.at(i).count;
						}
						if (id1count != 0 && id2count != 0 && id3count != 0) break;
					}
					bool changed_something = false;
					while (id1count >= atoi(ex.at(3).c_str()) && id2count >= atoi(ex.at(4).c_str()) && id3count >= atoi(ex.at(5).c_str())) {
						for (auto i = 0; i < world->droppedItems.size(); i++) {
							int x_p = world->droppedItems.at(i).x / 32;
							int y_p = world->droppedItems.at(i).y / 32;
							if (x_p == x && y_p == y && world->droppedItems.at(i).id == id1) {
								world->droppedItems.at(i).count -= atoi(ex.at(3).c_str());
								id1count = world->droppedItems.at(i).count;
								if (world->droppedItems.at(i).count <= 0) {
									RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
									world->droppedItems.erase(world->droppedItems.begin() + i);
									i--;
								} else {
									RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
									world->droppedItems.at(i).uid = world->droppedCount++;
									sendDrop(peer, -1, world->droppedItems.at(i).x + 1, world->droppedItems.at(i).y + 1, world->droppedItems.at(i).id, world->droppedItems.at(i).count, 0);
								}
							} else if (x_p == x && y_p == y && world->droppedItems.at(i).id == id2) {
								world->droppedItems.at(i).count -= atoi(ex.at(4).c_str());
								id2count = world->droppedItems.at(i).count;
								if (world->droppedItems.at(i).count <= 0) {
									RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
									world->droppedItems.erase(world->droppedItems.begin() + i);
									i--;
								} else {
									RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
									world->droppedItems.at(i).uid = world->droppedCount++;
									sendDrop(peer, -1, world->droppedItems.at(i).x + 1, world->droppedItems.at(i).y + 1, world->droppedItems.at(i).id, world->droppedItems.at(i).count, 0);
								}
							} else if (x_p == x && y_p == y && world->droppedItems.at(i).id == id3) {
								world->droppedItems.at(i).count -= atoi(ex.at(5).c_str());
								id3count = world->droppedItems.at(i).count;
								if (world->droppedItems.at(i).count <= 0) {
									RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
									world->droppedItems.erase(world->droppedItems.begin() + i);
									i--;
								} else {
									RemoveDroppedItem(peer, world->droppedItems.at(i).uid);
									world->droppedItems.at(i).uid = world->droppedCount++;
									sendDrop(peer, -1, world->droppedItems.at(i).x + 1, world->droppedItems.at(i).y + 1, world->droppedItems.at(i).id, world->droppedItems.at(i).count, 0);
								}
							}
						}
						changed_something = true;
						DropItem(world, peer, -1, x * 32 + (rand() % 16), y * 32 + (rand() % 16), atoi(ex.at(6).c_str()), atoi(ex.at(7).c_str()), 0);
					}
					if (changed_something) Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "Science!", 0, true);
					break;
				}
			}
		}
		infile.close();
	}
	catch (const std::out_of_range& e) {
		cout << e.what() << endl;
	}
}

inline void SendFishing(ENetPeer* peer, const int netID, const int x, const int y)
{
	PlayerMoving p{};
	p.packetType = 0x1F;
	p.netID = netID;
	p.punchX = x;
	p.punchY = y;
	SendPacketRaw(4, packPlayerMoving(&p), 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
}

inline void SendGhost(ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->canWalkInBlocks == false) {
		if (static_cast<PlayerInfo*>(peer->data)->skinColor == 0x8295C3FF || static_cast<PlayerInfo*>(peer->data)->skinColor == 2190853119 || static_cast<PlayerInfo*>(peer->data)->skinColor == 2527912447 || static_cast<PlayerInfo*>(peer->data)->skinColor == 2864971775 || static_cast<PlayerInfo*>(peer->data)->skinColor == 3033464831 || static_cast<PlayerInfo*>(peer->data)->skinColor == 3370516479) {
			static_cast<PlayerInfo*>(peer->data)->skinColor = -2450;
			sendClothes(peer);
		}
		static_cast<PlayerInfo*>(peer->data)->canWalkInBlocks = true;
		send_state(peer);
		sendClothes(peer);
		Player::OnConsoleMessage(peer, "`oYour atoms are suddenly aware of quantum tunneling. (`$Ghost in the Shell `omod added)``");
		Player::PlayAudio(peer, "audio/dialog_confirm.wav", 0);
	} else {
		if (static_cast<PlayerInfo*>(peer->data)->skinColor == -2450) {
			static_cast<PlayerInfo*>(peer->data)->skinColor = 0x8295C3FF;
			sendClothes(peer);
		}
		static_cast<PlayerInfo*>(peer->data)->canWalkInBlocks = false;
		send_state(peer);
		Player::OnConsoleMessage(peer, "`oYour body stops shimmering and returns to normal. (`$Ghost in the Shell `omod removed)``");
		Player::PlayAudio(peer, "audio/dialog_confirm.wav", 0);
	}
}

inline void SendVendDialog(ENetPeer* peer, WorldInfo* world) {
	try {
		const auto x = static_cast<PlayerInfo*>(peer->data)->lastPunchX;
		const auto y = static_cast<PlayerInfo*>(peer->data)->lastPunchY;
		const auto squaresign = x + (y * world->width);
		string type = "";
		if (world->items.at(x + (y * world->width)).rm) {
			type = "\nadd_checkbox|chk_peritem|World Locks per Item|1\nadd_checkbox|chk_perlock|Items per World Lock|0";
		}
		if (world->items.at(x + (y * world->width)).opened) {
			type = "\nadd_checkbox|chk_peritem|World Locks per Item|0\nadd_checkbox|chk_perlock|Items per World Lock|1";
		}
		if (world->items.at(x + (y * world->width)).rm && world->items.at(x + (y * world->width)).opened) {
			type = "\nadd_checkbox|chk_peritem|World Locks per Item|1\nadd_checkbox|chk_perlock|Items per World Lock|1";
		}
		auto currentworld = static_cast<PlayerInfo*>(peer->data)->currentWorld + "X" + std::to_string(squaresign);
		string withdrawdialog = "";
		if (world->items.at(x + (y * world->width)).vdraw > 0) withdrawdialog = "\nadd_smalltext|`oYou have earned " + to_string(world->items.at(x + (y * world->width)).vdraw) + " World Locks.``|left|\nadd_button|withdraw|Withdraw World Locks|";
		if (world->items.at(x + (y * world->width)).vid == 0 || world->items.at(x + (y * world->width)).vcount == 0) {
			Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_textbox|This machine is empty.|left|\nadd_item_picker|stockitem|`wPut an item in``|Choose an item to put in the machine!|" + withdrawdialog + "|\nend_dialog|vending|Close||");
		}
		else if (world->items.at(x + (y * world->width)).vcount != 0) {
			string addthemdialog = "";
			auto mtitems = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == world->items.at(x + (y * world->width)).vid) {
					mtitems = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
					break;
				}
			}
			if (mtitems != 0) {
				addthemdialog = "\nadd_smalltext|`oYou have " + to_string(mtitems) + " " + getItemDef(world->items.at(x + (y * world->width)).vid).name + " in your backpack.``|left|\nadd_button|addvend|Add them to the machine|";
			}
			string saledialog = "\nadd_textbox|Not currently for sale!|left|";
			if (world->items.at(x + (y * world->width)).vprice != 0) {
				if (world->items.at(x + (y * world->width)).opened) saledialog = "\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|1 x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|";
				else saledialog = "\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|1 x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|";
			}
			Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_label_with_icon|sml|The machine contains a total of " + to_string(world->items.at(x + (y * world->width)).vcount) + " `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``.|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|" + saledialog + "|" + addthemdialog + "|\nadd_button|pullstock|Empty the machine|noflags|0|0|\nadd_smalltext|`5(Vending Machine will not function when price is set to 0)``|left|\nadd_text_input|setprice|Price|" + to_string(world->items.at(x + (y * world->width)).vprice) + "|5|" + type + "|" + withdrawdialog + "|\nend_dialog|vending|Close|Update|");
		}
		else if (world->items.at(x + (y * world->width)).vcount != 0 && world->items.at(x + (y * world->width)).vprice != 0) {
			if (world->items.at(x + (y * world->width)).opened) Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_label_with_icon|sml|The machine contains a total of " + to_string(world->items.at(x + (y * world->width)).vcount) + " `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``.|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|1 x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_button|pullstock|Empty the machine|noflags|0|0|\nadd_smalltext|`5(Vending Machine will not function when price is set to 0)``|left|\nadd_text_input|setprice|Price|" + to_string(world->items.at(x + (y * world->width)).vprice) + "|5|" + type + "|" + withdrawdialog + "|\nend_dialog|vending|Close|Update|");
			else Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_label_with_icon|sml|The machine contains a total of " + to_string(world->items.at(x + (y * world->width)).vcount) + " `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``.|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|1 x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_button|pullstock|Empty the machine|noflags|0|0|\nadd_smalltext|`5(Vending Machine will not function when price is set to 0)``|left|\nadd_text_input|setprice|Price|" + to_string(world->items.at(x + (y * world->width)).vprice) + "|5|" + type + "|" + withdrawdialog + "|\nend_dialog|vending|Close|Update|");
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void SendBuyerVendDialog(ENetPeer* peer, WorldInfo* world) {
	try {
		const int x = static_cast<PlayerInfo*>(peer->data)->lastPunchX;
		const int y = static_cast<PlayerInfo*>(peer->data)->lastPunchY;
		const auto squaresign = x + (y * world->width);
		auto currentworld = static_cast<PlayerInfo*>(peer->data)->currentWorld + "X" + std::to_string(squaresign);
		if (world->items.at(x + (y * world->width)).vid == 0 || world->items.at(x + (y * world->width)).vcount == 0 || world->items.at(x + (y * world->width)).vprice == 0 || world->items.at(x + (y * world->width)).vcount < world->items.at(x + (y * world->width)).vprice && world->items.at(x + (y * world->width)).opened) {
			Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_textbox|This machine is out of order.|left|\nend_dialog|vending|Close||");
		}
		else if (world->items.at(x + (y * world->width)).vcount != 0 && world->items.at(x + (y * world->width)).vprice == 0) {
			if (world->items.at(x + (y * world->width)).opened) Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_label_with_icon|sml|The machine contains a total of " + to_string(world->items.at(x + (y * world->width)).vcount) + " `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``.|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|1 x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|You'll need to wait for the owner to stock up to at least 1 World Lock's worth before you can buy.|left|\nend_dialog|vending|Close||");
			else Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_label_with_icon|sml|The machine contains a total of " + to_string(world->items.at(x + (y * world->width)).vcount) + " `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``.|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|1 x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|You'll need to wait for the owner to stock up to at least 1 World Lock's worth before you can buy.|left|\nend_dialog|vending|Close||");
		}
		else if (world->items.at(x + (y * world->width)).vcount != 0) {
			auto worldlocks = 0;
			auto diamondlocks = 0;
			auto locks = 0;
			for (auto i = 0; i < static_cast<PlayerInfo*>(peer->data)->inventory.items.size(); i++) {
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 242) {
					worldlocks = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
				if (static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemID == 1796) {
					diamondlocks = static_cast<PlayerInfo*>(peer->data)->inventory.items.at(i).itemCount;
				}
			}
			if (diamondlocks > 0) {
				locks = diamondlocks * 100;
			}
			locks += worldlocks;
			if (world->items.at(x + (y * world->width)).opened) Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_label_with_icon|sml|The machine contains a total of " + to_string(world->items.at(x + (y * world->width)).vcount) + " `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``.|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|1 x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|You have " + to_string(locks) + " World Locks.|left|\nadd_text_input|buycount|How many would you like to buy?|0|3|\nend_dialog|vending|Close|Buy|");
			else Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wVending Machine``|left|2978|\nadd_spacer|small|\nadd_label_with_icon|sml|The machine contains a total of " + to_string(world->items.at(x + (y * world->width)).vcount) + " `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``.|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|For a cost of:|left|\nadd_label_with_icon|small|" + to_string(world->items.at(x + (y * world->width)).vprice) + " x `8World Lock``|left|242|\nadd_spacer|small|\nadd_textbox|You will get:|left|\nadd_label_with_icon|small|1 x `2" + getItemDef(world->items.at(x + (y * world->width)).vid).name + "``|left|" + to_string(world->items.at(x + (y * world->width)).vid) + "|\nadd_spacer|small|\nadd_textbox|You have " + to_string(locks) + " World Locks.|left|\nadd_text_input|buycount|How many would you like to buy?|0|3|\nend_dialog|vending|Close|Buy|");
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void SendWeather(ENetPeer* peer, int tile, WorldInfo* world, int x, int y)
{
	try {
		if (tile == 18)
		{
			if (world->items.at(x + (y * world->width)).foreground == 1490)
			{
				if (world->weather == 10)
				{
					world->weather = 0;
					world->items.at(x + (y * world->width)).activated = false;
				}
				else
				{
					world->weather = 10;
					world->items.at(x + (y * world->width)).activated = true;
				}
				ENetPeer* currentPeer;
				for (currentPeer = server->peers;
					currentPeer < &server->peers[server->peerCount];
					++currentPeer)
				{
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
						continue;
					if (isHere(peer, currentPeer))
					{
						GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
						ENetPacket* packet2 = enet_packet_create(p2.data,
							p2.len,
							ENET_PACKET_FLAG_RELIABLE);
						enet_peer_send(currentPeer, 0, packet2);
						delete p2.data;
						continue;
					}
				}
			}
		}
		if (tile == 18)
		{
			if (world->items.at(x + (y * world->width)).foreground == 934)
			{
				if (world->weather == 2)
				{
					world->weather = 0;
					world->items.at(x + (y * world->width)).activated = false;
				}
				else
				{
					world->weather = 2;
					world->items.at(x + (y * world->width)).activated = true;
				}
				ENetPeer* currentPeer;
				for (currentPeer = server->peers;
					currentPeer < &server->peers[server->peerCount];
					++currentPeer)
				{
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
						continue;
					if (isHere(peer, currentPeer))
					{
						GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
						ENetPacket* packet2 = enet_packet_create(p2.data,
							p2.len,
							ENET_PACKET_FLAG_RELIABLE);
						enet_peer_send(currentPeer, 0, packet2);
						delete p2.data;
						continue;
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 946)
				{
					if (world->weather == 3)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 3;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 1490)
				{
					if (world->weather == 10)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 10;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 932)
				{
					if (world->weather == 4)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 4;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 984)
				{
					if (world->weather == 5)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 5;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 1210)
				{
					if (world->weather == 8)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 8;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 1364)
				{
					if (world->weather == 11)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 11;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 1750)
				{
					if (world->weather == 15)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 15;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 2046)
				{
					if (world->weather == 17)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 17;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 2284)
				{
					if (world->weather == 18)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 18;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 2744)
				{
					if (world->weather == 19)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 19;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 3252)
				{
					if (world->weather == 20)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 20;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 3446)
				{
					if (world->weather == 21)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 21;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 3534)
				{
					if (world->weather == 22)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 22;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 1490)
				{
					if (world->weather == 10)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 10;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 4242)
				{
					if (world->weather == 30)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 30;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 4486)
				{
					if (world->weather == 31)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 31;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 4776)
				{
					if (world->weather == 32)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 32;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 4892)
				{
					if (world->weather == 33)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 33;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 5112)
				{
					if (world->weather == 35)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 35;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 5654)
				{
					if (world->weather == 36)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 36;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 5716)
				{
					if (world->weather == 37)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 37;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 5958)
				{
					if (world->weather == 38)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 38;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 6854)
				{
					if (world->weather == 42)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 42;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
		{
			if (tile == 18)
			{
				if (world->items.at(x + (y * world->width)).foreground == 7644)
				{
					if (world->weather == 44)
					{
						world->weather = 0;
						world->items.at(x + (y * world->width)).activated = false;
					}
					else
					{
						world->weather = 44;
						world->items.at(x + (y * world->width)).activated = true;
					}
					ENetPeer* currentPeer;
					for (currentPeer = server->peers;
						currentPeer < &server->peers[server->peerCount];
						++currentPeer)
					{
						if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL)
							continue;
						if (isHere(peer, currentPeer))
						{
							GamePacket p2 = packetEnd(appendInt(appendString(createPacket(), "OnSetCurrentWeather"), world->weather));
							ENetPacket* packet2 = enet_packet_create(p2.data,
								p2.len,
								ENET_PACKET_FLAG_RELIABLE);
							enet_peer_send(currentPeer, 0, packet2);
							delete p2.data;
							continue;
						}
					}
				}
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}



inline void complete_surgery(ENetPeer* peer)
{

	if (static_cast<PlayerInfo*>(peer->data)->SurgerySkill < 100) static_cast<PlayerInfo*>(peer->data)->SurgerySkill++;
	vector<int> surg_rewards{ 3172, 1258, 1260, 1262, 1264, 1266, 1268, 1270, 4308, 4310, 4312, 4314, 4316, 4318, 3172, 1258, 1260, 1262, 1264, 1266, 1268, 1270, 4308, 4310, 4312, 4314, 4316, 4318, 4296, 1242, 1244, 1246, 1248, 1282, 1284, 1286, 1290, 1288, 1292, 1294, 1256, 2586, 782, 3536, 764, 4176, 4322, 4080, 2992, 2976, 3790, 4990, 1506, 1274, 9000, 1252, 8284, 8954, 8534, 8478, 8480, 8486, 8484, 8482, 8468, 8494, 8466, 8490, 8456, 8458, 8496, 8472, 6398, 6426, 6340, 6342, 6350, 6818, 8244, 8242, 8240, 8452, 8454, 8488, 8498, 8474, 8476, 8492 };


	
	if (static_cast<PlayerInfo*>(peer->data)->cloth_face == 312) 
	{
		surg_rewards.push_back(5482);
	}
	if (WinterfestEvent)
	{
		surg_rewards.push_back(2240);
		surg_rewards.push_back(3204);
	}
	if (SuperpineappleEvent)
	{
		surg_rewards.push_back(6114);
	}
	if (SurgeryDay)
	{
		surg_rewards.push_back(4328);
		surg_rewards.push_back(4326);
		surg_rewards.push_back(4330);
		surg_rewards.push_back(4324);
		surg_rewards.push_back(4334);
	}

	auto reward_id = surg_rewards[rand() % surg_rewards.size()];

	auto count = 1;

	if (reward_id == 1290) count = 10;
	if (reward_id == 1288) count = 5;
	if (reward_id == 1292) count = 5;
	if (reward_id == 1294) count = 5;

	if (reward_id == 1258) count = 5;
	if (reward_id == 1260) count = 5;
	if (reward_id == 1262) count = 5;
	if (reward_id == 1264) count = 5;
	if (reward_id == 1266) count = 5;
	if (reward_id == 1268) count = 5;
	if (reward_id == 1270) count = 5;
	if (reward_id == 4308) count = 5;
	if (reward_id == 4310) count = 5;
	if (reward_id == 4312) count = 5;
	if (reward_id == 4314) count = 5;
	if (reward_id == 4316) count = 5;
	if (reward_id == 4318) count = 5;
	if (reward_id == 4296) count = 5;



	if (reward_id == 8284)
	{
		if ((rand() % 1000) <= 5) {}
		else reward_id = 1244;
	}
	if (reward_id == 1506)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 1242;
	}
	if (reward_id == 8452)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 1246;
	}
	if (reward_id == 8488)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 1248;
	}
	if (reward_id == 8492)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 1242;
	}
	if (reward_id == 8494)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 1244;
	}
	if (reward_id == 8496)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 1246;
	}
	if (reward_id == 1252)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 1248;
	}
	if (reward_id == 8954)
	{
		if ((rand() % 50) <= 5) {}
		else reward_id = 2586;
	}

	if (static_cast<PlayerInfo*>(peer->data)->quest_active && static_cast<PlayerInfo*>(peer->data)->lastquest == "honor" && static_cast<PlayerInfo*>(peer->data)->quest_step == 12 && static_cast<PlayerInfo*>(peer->data)->quest_progress < 100) {
		static_cast<PlayerInfo*>(peer->data)->quest_progress++;
		if (static_cast<PlayerInfo*>(peer->data)->quest_progress >= 100) {
			static_cast<PlayerInfo*>(peer->data)->quest_progress = 100;
			Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`9Legendary Quest step complete! I'm off to see a Wizard!", 0, false);
		}
	}
	auto success = true;
	SaveItemMoreTimes(reward_id, count, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from surgery");
	SaveItemMoreTimes(4298, 1, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from surgery");
	Player::PlayAudio(peer, "audio/double_chance.wav", 0);
	Player::OnConsoleMessage(peer, "`oYou got " + to_string(count) + " `2" + getItemDef(reward_id).name + " `oand a `3Caduceus`o!");
	Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wAfter a surgery like that, you decide you deserve `w" + to_string(count) + " " + getItemDef(reward_id).name + "`w.", 0, true);
	if (SurgeryDay) Player::OnConsoleMessage(peer, "Congratulations on your successful surgery! (`$Recovery`` mod added, `$30 min`` left)");
	else Player::OnConsoleMessage(peer, "Congratulations on your successful surgery! (`$Recovery`` mod added, `$20 min`` left)");
	ENetPeer* currentPeer;
	for (currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
	{
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer))
		{
			Player::PlayAudio(currentPeer, "audio/metal_destroy.wav", 0);
		}
	}
	WorldInfo* world = getPlyersWorld(peer);
	if (world == NULL) {
		SendConsole("complete_surgery error", "ERROR");
		return;
	}
	try {
		if (static_cast<PlayerInfo*>(peer->data)->lastPunchX >= 0 && static_cast<PlayerInfo*>(peer->data)->lastPunchY >= 0)
		{
			world->items.at(static_cast<PlayerInfo*>(peer->data)->lastPunchX + (static_cast<PlayerInfo*>(peer->data)->lastPunchY * world->width)).foreground = 0;
			PlayerMoving data3{};
			data3.packetType = 0x3;
			data3.characterState = 0x0;
			data3.x = static_cast<PlayerInfo*>(peer->data)->lastPunchX;
			data3.y = static_cast<PlayerInfo*>(peer->data)->lastPunchY;
			data3.punchX = static_cast<PlayerInfo*>(peer->data)->lastPunchX;
			data3.punchY = static_cast<PlayerInfo*>(peer->data)->lastPunchY;
			data3.XSpeed = 0;
			data3.YSpeed = 0;
			data3.netID = -1;
			data3.plantingTree = 0;
			for (currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer)
			{
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
				if (isHere(peer, currentPeer))
				{
					const auto raw = packPlayerMoving(&data3);
					raw[2] = 0;
					raw[3] = 0;
					SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
					Player::OnParticleEffect(currentPeer, 57, static_cast<PlayerInfo*>(peer->data)->lastPunchX * 32, static_cast<PlayerInfo*>(peer->data)->lastPunchY * 32, 0);
				}
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	end_surgery(peer, false);

}

inline bool surgery_skill_fail(ENetPeer* peer) {
	const auto chance = 85 + static_cast<PlayerInfo*>(peer->data)->SurgerySkill;
	if (rand() % 200 < chance) return false; /*nera*/
	else return true;
}

inline void restore_prices() {
	try {
		char oldname[] = "price_data.txt";
		char newname[] = "price_data1.txt";
		char oldname1[] = "price_data1.txt";
		char newname1[] = "price_data2.txt";
		char oldname2[] = "price_data2.txt";
		char newname2[] = "price_data3.txt";
		auto itemid = 0;
		auto kaina = 0;
		string append = "";
		int drop_k = 0;
		int rise_k = 0;
		srand(time(nullptr)); /*reset the seed*/
		for (int i = 0; i <= maxItems; i++) {
			itemid++;
			kaina = -1;
			if (getItemDef(itemid).blockType == BlockTypes::SIGN && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::DEADLY && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::GATEWAY && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::DOOR && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::PAIN_BLOCK && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::PLATFORM && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::BACKGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::FOREGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::SFX_FOREGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::ANIM_FOREGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::TOGGLE_FOREGROUND && getItemDef(itemid).rarity != 999) {
				/*per world lock*/
				int past_price = 0;
				ifstream infile("price_data.txt");
				for (string line; getline(infile, line);) {
					if (line.length() > 3 && line[0] != '/' && line[1] != '/') {
						auto ex = explode("|", line);
						if (ex[0] == to_string(itemid)) {
							past_price = atoi(ex[1].c_str());
							break;
						}
					}
				}
				infile.close();
				vector<float>rise{1.01,1.02,1.03,1.04,1.05,1.06,1.07,1.08,1.09};
				vector<float>fall{0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99};
				bool r_rise = (rand() % 2) != 0;
				if (r_rise) { /*rise*/
					float rise_num = rise.at(rand() % rise.size());
					past_price *= rise_num;
					rise_k++;
				} else { /*fall*/
					float fall_num = fall.at(rand() % fall.size());
					past_price *= fall_num;
					drop_k++;
				}	
				kaina = past_price;
				if (kaina > 250 && itemid != 9498 && itemid != 5154 && itemid != 5140 && itemid != 5138 && itemid != 5136 && itemid != 7382 && itemid != 4762) kaina = 250;
				if (kaina < 1) kaina = 1;
				if (itemid == 7188) kaina = 100;
			} else {
				int past_price = 0;
				ifstream infile("price_data.txt");
				for (string line; getline(infile, line);) {
					if (line.length() > 3 && line[0] != '/' && line[1] != '/') {
						auto ex = explode("|", line);
						if (ex[0] == to_string(itemid)) {
							past_price = atoi(ex[1].c_str());
							break;
						}
					}
				}
				infile.close();
				vector<float>rise{1.01,1.02,1.03,1.04,1.05,1.06,1.07,1.08,1.09};
				vector<float>fall{0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99};
				bool r_rise = (rand() % 2) != 0;
				if (r_rise) { /*rise*/
					float rise_num = rise.at(rand() % rise.size());
					past_price *= rise_num;
					rise_k++;
				} else { /*fall*/
					float fall_num = fall.at(rand() % fall.size());
					past_price *= fall_num;
					drop_k++;
				}	
				kaina = past_price;
				if (kaina > 25000) kaina = 25000;
				if (kaina < 1) kaina = 1;
				if (itemid == 7188) kaina = 100;
			}
			append += to_string(itemid) + "|" + to_string(kaina) + "|0\n";
		} 
		remove("price_data3.txt");
		if (rename(oldname2, newname2) != 0) {
			SendConsole("Filesystem Exception #3 Failed to rename file", "ERROR");
		}
		remove("price_data2.txt");
		if (rename(oldname1, newname1) != 0) {
			SendConsole("Filesystem Exception #2 Failed to rename file", "ERROR");
		}
		remove("price_data1.txt");
		if (rename(oldname, newname) != 0) {
			SendConsole("Filesystem Exception #1 Failed to rename file", "ERROR");
		}
		remove("price_data.txt");
		ofstream breaklogs("price_data.txt", ios::app);
		breaklogs << append;
		breaklogs.close();
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (drop_k > rise_k) Player::OnConsoleMessage(currentPeer, "`oGrowtech shows that item prices averagely started to `4drop`o!");
			else  Player::OnConsoleMessage(currentPeer, "`oGrowtech shows that item prices averagely started to `2rise`o!");
			Player::PlayAudio(currentPeer, "audio/bell.wav", 0);
		}
		SendConsole("Item prices were refreshed", "WARN");
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
}

inline void LoadEvents(bool ignore = false)
{
	
	string test = lastday;
	time_t t = time(nullptr);
	// ReSharper disable once CppDeprecatedEntity
	tm* timePtr = localtime(&t);
	timePtr->tm_wday;
	switch (timePtr->tm_wday)
	{
	case 1:
	{
		lastday = "1";
		DailyItem = 5040;
		DailyItemCount = 200;
		//GrowganothEvent = true;
		specialdrop = 5040;
		break;
	}
	case 2:
	{
		lastday = "2";
		DailyItem = 5042;
		DailyItemCount = 200;
		//HarvestEvent = true;
		specialdrop = 5042;
		break;
	}
	case 3:
	{
		lastday = "3";
		DailyItem = 5044;
		DailyItemCount = 200;
		//FarmingEvent = true;
		specialdrop = 5044;
		break;
	}
	case 4:
	{
		lastday = "4";
		DailyItem = 5044;
		DailyItemCount = 200;
		//ValentineEvent = true;
		specialdrop = 5044;
		break;
	}
	case 5:
	{
		lastday = "5";
		DailyItem = 5034;
		DailyItemCount = 200;
		//SurgeryDay = true;
		specialdrop = 5034;
		break;
	}
	case 6:
	{
		lastday = "6";
		DailyItem = 5036;
		DailyItemCount = 200;
		//GeigerDay = true;
		specialdrop = 5036;
		break;
	}
	case 0:
	{
		lastday = "0";
		DailyItem = 5038;
		DailyItemCount = 200;
		//LunarEvent = true;
		specialdrop = 5038;
		break;
	}
	default: break;
	}
	if (test != lastday && !ignore) { /*reiskia nauja diena*/
		threads.push_back(std::thread(restore_prices));
	}


}

inline void apply_lock_packet(WorldInfo* world, ENetPeer* peer, int x, int y, int id, int lockowner) {
	if (lockowner == -3) {
		lockowner = static_cast<PlayerInfo*>(peer->data)->netID;
	}
	int locksize = 0;
	if (id == 202) locksize = 25;
	PlayerMoving pmov{};
	pmov.packetType = 0xf;
	pmov.characterState = 0;
	pmov.x = 0;
	pmov.y = 0;
	pmov.XSpeed = 0;
	pmov.YSpeed = 0;
	pmov.plantingTree = id;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = lockowner;
	byte* pmovp = packPlayerMoving(&pmov);
	byte* packet = new byte[64 + locksize * 2];
	memset(packet, 0, 64 + locksize * 2);
	packet[0] = 4;
	memcpy(packet + 4, pmovp, 56);
	delete pmovp;
	packet[12] = locksize;
	packet[16] = 8;
	int locksz = locksize * 2;
	memcpy(packet + 56, &locksz, 4);
	bool lock_above = false;
	bool mid_lock = false;
	bool mid_low = false;
	bool mid_lowest = false;
	int vidur_ten = 2;
	int vidur = 2;
	int vidur_cia = 2;
	int lock_above_lock = 2;
	int lock_lowers_lock = 2;
	for (int i = 0; i < locksize; i++) {
		if (!lock_above) {
			int fml = y * world->width - 200 + x - 4 + lock_above_lock;
			memcpy(packet + world->height + i * 2, &fml, 2);
			lock_above_lock++;
			if (lock_above_lock >= 7) lock_above = true;
			continue;
		}
		if (mid_lowest) {
			int fml = y * world->width + 200 + x - 4 + lock_lowers_lock;
			memcpy(packet + world->height + i * 2, &fml, 2);
			lock_lowers_lock++;
		}
		else if (mid_low) {
			int fml = y * world->width + 100 + x - 4 + vidur_cia;
			memcpy(packet + world->height + i * 2, &fml, 2);
			vidur_cia++;
			if (vidur_cia >= 7) mid_lowest = true;
		}
		else if (mid_lock) {
			int fml = y * world->width + x - 4 + vidur;
			memcpy(packet + world->height + i * 2, &fml, 2);
			vidur++;
			if (vidur >= 7) mid_low = true;
		}
		else if (lock_above) {
			int fml = y * world->width - 100 + x - 4 + vidur_ten;
			memcpy(packet + world->height + i * 2, &fml, 2);
			vidur_ten++;
			if (vidur_ten >= 7) mid_lock = true;
		}
	}
	ENetPacket* packetenet = enet_packet_create(packet, 64 + locksize * 2, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packetenet);
	delete[] packet;
}

inline void SendPunishView(ENetPeer* peer, string PlayerName) {
	if (!isMod(peer)) return;
	static_cast<PlayerInfo*>(peer->data)->lastInfo = PlayerName;
	std::ifstream ifs7("save/gemdb/_" + PlayerName + ".txt");
	std::string contentp((std::istreambuf_iterator<char>(ifs7)), (std::istreambuf_iterator<char>()));
	ifs7.close();
	try {
		ifstream read_player("save/players/_" + PlayerName + ".json");
		if (!read_player.is_open()) {
			Player::OnConsoleMessage(peer, PlayerName + " does not exist");
			return;
		}	
		json j;
		read_player >> j;
		read_player.close();
		string username = j["username"];
		int playerid = j["playerid"];
		string email = j["email"];
		string ipID = j["ipID"];
		int receivedwarns = j["receivedwarns"];
		string mac = j["mac"];
		string rid = j["rid"];
		string sid = j["sid"];
		string gid = j["gid"];
		string vid = j["vid"];
		string aid = j["aid"];
		string ip = j["ip"];
		string nick = j["nick"];
		string accountnotes = j["accountnotes"];
		if (nick == "") nick = username;
		string accounts;
		if (ipID == "8421376") ipID = "-1";
		if (ip == "5.20.120.177") {
			Player::OnConsoleMessage(peer, PlayerName + " does not exist");
			return;
		}
		GTDialog allinfo;
		allinfo.addCustom("add_label|mid|`wEditing " + username + " `w(" + nick + "`w) - #" + to_string(playerid) + "|right\n");
		allinfo.addSpacer(SPACER_SMALL);
		bool HaveOnlineAccounts = false;
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (static_cast<PlayerInfo*>(currentPeer->data)->rawName == username || static_cast<PlayerInfo*>(currentPeer->data)->charIP == ip || static_cast<PlayerInfo*>(currentPeer->data)->email == email) {
				if (static_cast<PlayerInfo*>(currentPeer->data)->rawName == "") continue;
				allinfo.addLabelWithIconButton("`oON: `5" + static_cast<PlayerInfo*>(currentPeer->data)->rawName + " `w(" + static_cast<PlayerInfo*>(currentPeer->data)->displayName + "`w) #" + to_string(static_cast<PlayerInfo*>(currentPeer->data)->playerid) + " `oHrs: `w" + to_string(rand() % 3000) + " `oIP: `w" + static_cast<PlayerInfo*>(currentPeer->data)->charIP + "", 658, "viewinfo_" + static_cast<PlayerInfo*>(currentPeer->data)->rawName + "");
				allinfo.addButton("warpto_" + static_cast<PlayerInfo*>(currentPeer->data)->currentWorld + "", "`oWarp To User (in `5" + static_cast<PlayerInfo*>(currentPeer->data)->currentWorld + "`o)");
				HaveOnlineAccounts = true;
			}
		}
		if (HaveOnlineAccounts) allinfo.addSpacer(SPACER_SMALL);
		if (accountnotes != "") {
			allinfo.addTextBox("`oAccount notes/activity:");
			vector<string> info_dat = explode("|", accountnotes);
			for (int i = 0; i < info_dat.size(); i++) {
				if (info_dat.at(i) == "") continue;
				allinfo.addTextBox(info_dat.at(i));
			}
			allinfo.addSpacer(SPACER_SMALL);
		}
		if (accountnotes != "" && std::find(creators.begin(), creators.end(), static_cast<PlayerInfo*>(peer->data)->rawName) != creators.end()) allinfo.addLabelWithIconButton("`o<-- Clear account notes", 32, "clearaccountnotes_" + username + "");
		allinfo.addLabelWithIconButton("`o<-- View inventory", 6128, "showuserinventoryoffline_" + username + "");
		allinfo.addLabelWithIconButton("`o<-- ban panel", 732, "banpanel");
		allinfo.addLabelWithIconButton("`o<-- mute panel", 408, "mutepanel");
		allinfo.addLabelWithIconButton("`o<-- curse panel", 278, "cursepanel");
		/*allinfo.addLabelWithIconButton("`o<-- 4 week DGH", 732, "suspend4w");
		allinfo.addLabelWithIconButton("`o<-- 8 week DGH", 732, "suspend8w");
		allinfo.addLabelWithIconButton("`o<-- Perma ban DGH", 732, "suspend");*/
		//allinfo.addLabelWithIconButton("`o<-- Perma ban for bad stuff on alt(s)", 732, "suspendalts");
		//allinfo.addLabelWithIconButton("`o<-- Perma ban for hacker", 732, "suspend");
		allinfo.addLabelWithIconButton("`o<-- IP ban (online only)", 732, "ipbanwrench");
		allinfo.addSpacer(SPACER_SMALL);
		allinfo.addLabelWithIconButton("`o<-- Fake auto-ban (use for hackers, confuses them, online only)", 546, "fakeautoban");
		allinfo.addSpacer(SPACER_SMALL);
		/*if (accounts != "") {
			vector<string> info_dat = explode("|", accounts);
			for (int i = 0; i < info_dat.size(); i++) {
				if (info_dat[i] == "") continue;
				string aplayerid = "";
				string aip = "";
				string ausername = "";
				string anickname = "";
				MYSQL_ROW mysql_row;
				string cs = "SELECT * FROM PlayerDatnabase WHERE username = '" + info_dat[i] + "' LIMIT 1";
				if (mysql_query(conn, cs.c_str())) {
					cout << mysql_error(conn) << endl;
					continue;
				}
				res = mysql_store_result(conn);
				while ((mysql_row = mysql_fetch_row(res))) {
					aplayerid = mysql_row[0];
					ausername = mysql_row[1];
					aip = mysql_row[38];
					anickname = mysql_row[44];	
				}
				if (anickname == "") anickname = info_dat[i];
				allinfo.addLabelWithIconButton("`5" + info_dat[i] + " `w(" + anickname + "`w) #" + aplayerid + " `oHrs: `w" + to_string(rand() % 3000) + " `oIP: `w" + aip + "", 658, "viewinfo_" + info_dat[i] + "");
			}
			allinfo.addSpacer(SPACER_SMALL);
		}*/
		allinfo.endDialog("Close", "", "Close");
		Player::OnDialogRequest(peer, allinfo.finishDialog());	
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}	
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void SendGrowpedia(ENetPeer* peer) {
	string level1 = "", level2 = "", level3 = "", level4 = "", level5 = "", level6 = "", level7 = "", level8 = "", level9 = "", level10 = "", level11 = "", level12 = "", level13 = "", level14 = "", level15 = "", level16 = "", level17 = "", level18 = "", level19 = "", level20 = "";
	if (static_cast<PlayerInfo*>(peer->data)->level >= 1) {
		level1 = "`oUnlocked: 1000 Gems``";
	} else {
		level1 = "`a(Locked) 1000 Gems``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 2) {
		level2 = "`oUnlocked: 75 Chandelier``";
	} else {
		level2 = "`a(Locked) 75 Chandelier``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 3) {
		level3 = "`oUnlocked: Growtoken``";
	} else {
		level3 = "`a(Locked) Growtoken``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 4) {
		level4 = "`oUnlocked: Earth Mastery: 1% chance to break dirt in a single hit``|left|5050|\nadd_label_with_icon|sml|`oUnlocked: Diamond Wings``";
	} else {
		level4 = "`a(Locked) Earth Mastery: 1% chance to break dirt in a single hit``|left|5050|\nadd_label_with_icon|sml|`a(Locked) Diamond Wings``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 5) {
		level5 = "`oUnlocked: 5 Growtokens``";
	} else {
		level5 = "`a(Locked) 5 Growtokens``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 6) {
		level6 = "`oUnlocked: Earth Mastery (level 2) - Chance increase to 2%``";
	} else {
		level6 = "`a(Locked) Earth Mastery (level 2) - Chance increase to 2%``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 7) {
		level7 = "`oUnlocked: Punch Potion``";
	} else {
		level7 = "`a(Locked) Punch Potion``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 8) {
		level8 = "`oUnlocked: Flawless: 1% chance to decrease seed grow time when planting``|left|7186|\nadd_label_with_icon|sml|`oUnlocked: Earth Mastery (level 3) - Chance increase to 3%``";
	} else {
		level8 = "`a(Locked) Flawless: 1% chance to decrease seed grow time when planting``|left|7186|\nadd_label_with_icon|sml|`a(Locked) Earth Mastery (level 3) - Chance increase to 3%``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 9) {
		level9 = "`oUnlocked: 5000 Gems``";
	} else {
		level9 = "`a(Locked) 5000 Gems``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 10) {
		level10 = "`oUnlocked: Harvester: 1% chance to obtain extra block drop when harvesting trees``|left|1966|\nadd_label_with_icon|sml|`oUnlocked: Unique Prize``";
	} else {
		level10 = "`a(Locked) Harvester: 1% chance to obtain extra block drop when harvesting trees``|left|1966|\nadd_label_with_icon|sml|`a(Locked) Unique Prize``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 11) {
		level11 = "`oUnlocked: Flawless (level 2) - Chance increase to 2%``";
	} else {
		level11 = "`a(Locked) Flawless (level 2) - Chance increase to 2%``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 12) {
		level12 = "`oUnlocked: 15000 Gems``";
	} else {
		level12 = "`a(Locked) 15000 Gems``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 13) {
		level13 = "`oUnlocked: Harvester (level 2) - Chance increase to 2%``|left|1966|\nadd_label_with_icon|sml|`oUnlocked: Hands of the Void``";
	} else {
		level13 = "`a(Locked) Harvester (level 2) - Chance increase to 2%``|left|1966|\nadd_label_with_icon|sml|`a(Locked) Hands of the Void``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 14) {
		level14 = "`oUnlocked: 5 Growtokens``";
	} else {
		level14 = "`a(Locked) 5 Growtokens``";
	}
	if (static_cast<PlayerInfo*>(peer->data)->level >= 15) {
		level15 = "`oUnlocked: Ultimate Seediary Ability: Randomize all seed recipes into higher tier``";
	} else {
		level15 = "`a(Locked) Ultimate Seediary Ability: Randomize all seed recipes into higher tier``";
	}
	Player::OnDialogRequest(peer, "add_label_with_icon|big|`wLevel up Rewards``|left|18|\nadd_spacer|small|\nadd_textbox|`9Here are all the Level up rewards that you have earned so far!``|left|\nadd_spacer|small|\nadd_spacer|small|\nadd_smalltext|Level 1 rewards:|left|\nadd_label_with_icon|sml|" + level1 + "|left|112|\nadd_spacer|small|\nadd_smalltext|Level 2 rewards:|left|\nadd_label_with_icon|sml|" + level2 + "|left|340|\nadd_spacer|small|\nadd_smalltext|Level 3 rewards:|left|\nadd_label_with_icon|sml|" + level3 + "|left|1486|\nadd_spacer|small|\nadd_smalltext|Level 4 rewards:|left|\nadd_label_with_icon|sml|" + level4 + "|left|1938|\nadd_spacer|small|\nadd_smalltext|Level 5 rewards:|left|\nadd_label_with_icon|sml|" + level5 + "|left|1486|\nadd_spacer|small|\nadd_smalltext|Level 6 rewards:|left|\nadd_label_with_icon|sml|" + level6 + "|left|5050|\nadd_spacer|small|\nadd_smalltext|Level 7 rewards:|left|\nadd_label_with_icon|sml|" + level7 + "|left|6918|\nadd_spacer|small|\nadd_smalltext|Level 8 rewards:|left|\nadd_label_with_icon|sml|" + level8 + "|left|5050|\nadd_spacer|small|\nadd_smalltext|Level 9 rewards:|left|\nadd_label_with_icon|sml|" + level9 + "|left|112|\nadd_spacer|small|\nadd_smalltext|Level 10 rewards:|left|\nadd_label_with_icon|sml|" + level10 + "|left|2478|\nadd_spacer|small|\nadd_smalltext|Level 11 rewards:|left|\nadd_label_with_icon|sml|" + level11 + "|left|7186|\nadd_spacer|small|\nadd_smalltext|Level 12 rewards:|left|\nadd_label_with_icon|sml|" + level12 + "|left|112|\nadd_smalltext|Level 13 rewards:|left|\nadd_label_with_icon|sml|" + level13 + "|left|8452|\nadd_spacer|small|\nadd_smalltext|Level 14 rewards:|left|\nadd_label_with_icon|sml|" + level14 + "|left|1486|\nadd_spacer|small|\nadd_smalltext|Level 15 rewards:|left|\nadd_label_with_icon|sml|" + level15 + "|left|6128|\nadd_spacer|small|\nadd_button|back|Close|noflags|0|0||\nadd_quick_exit|");
}

inline void SendFishingState(ENetPeer* peer) {
	const auto info = static_cast<PlayerInfo*>(peer->data);
	const auto netID = info->netID;
	const auto state = getState(info);
	for (auto currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
		if (isHere(peer, currentPeer)) {
			PlayerMoving data{};
			data.packetType = 0x14;
			data.characterState = static_cast<PlayerInfo*>(peer->data)->characterState;
			data.x = 0;
			data.y = 9999999999;
			data.punchX = 0;
			data.punchY = 0;
			data.XSpeed = 0;
			data.YSpeed = 9999999999;
			data.netID = netID;
			data.plantingTree = state;
			const auto raw = packPlayerMoving(&data);
			auto var = info->effect;
			memcpy(raw + 1, &var, 3);
			SendPacketRaw(4, raw, 56, nullptr, currentPeer, ENET_PACKET_FLAG_RELIABLE);
		}
	}
}

inline void SyncFish(WorldInfo* world, ENetPeer* peer) {
	if (static_cast<PlayerInfo*>(peer->data)->Fishing && static_cast<PlayerInfo*>(peer->data)->TriggerFish) {
		static_cast<PlayerInfo*>(peer->data)->FishPosX = 0;
		static_cast<PlayerInfo*>(peer->data)->FishPosY = 0;
		static_cast<PlayerInfo*>(peer->data)->Fishing = false;
		send_state(peer);
		if (static_cast<PlayerInfo*>(peer->data)->TriggerFish) {
			static_cast<PlayerInfo*>(peer->data)->TriggerFish = false;
			vector<int> FishBase{ 3000, 3024, 3026, 3030, 3032, 3034, 3036, 3038, 3092, 3094, 3096, 3220, 3222, 3224, 3226, 3434, 3436, 3438, 3440, 3450, 3452, 3454, 3456, 3458, 3460, 3544, 3550, 3620, 3746, 3814, 3820, 4958, 5100, 5448, 5450, 5538, 5542, 5548, 5552, 5574, 5580, 7744, 8460 };
			const int Index = rand() % FishBase.size();
			const auto ItemID = FishBase[Index];
			vector<int> GearBase{ 344, 242, 3042, 3016, 5158, 5232, 5604, 5606, 5608, 6902, 6996, 9746 };
			const int GearIndex = rand() % GearBase.size();
			const auto GearID = GearBase[GearIndex];
			vector<int> BlockBase{ 444, 242, 1522, 3016, 3810, 4658, 5530, 5602, 5614, 5624, 6328, 7002, 8964, 8966 };
			const int BlockIndex = rand() % BlockBase.size();
			const auto BlockID = BlockBase[BlockIndex];
			auto count = 1;
			int ChanceOfGear = 0;
			int HowMuchLbs;
			int ChanceOfBlock = 0;
			if (static_cast<PlayerInfo*>(peer->data)->LastBait == "Fishing Fly")
			{
				ChanceOfBlock = (rand() % 400) + 1;
			}
			if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 2912) /*regular*/
			{
				HowMuchLbs = (rand() % 25) + 1;
			}
			else if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3008) /*ezrod*/
			{
				HowMuchLbs = (rand() % 40) + 1;
			}
			else if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3010) /*licorice*/
			{
				HowMuchLbs = (rand() % 60) + 1;
				ChanceOfGear = (rand() % 450) + 1;
			}
			else if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3100) /*cursed*/
			{
				HowMuchLbs = (rand() % 150) + 1;
				ChanceOfGear = (rand() % 250) + 1;
			}
			else if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 3040) /*golden*/
			{
				HowMuchLbs = (rand() % 200) + 1;
				ChanceOfGear = (rand() % 200) + 1;
			}
			else if (static_cast<PlayerInfo*>(peer->data)->cloth_hand == 5740) /*magical*/
			{
				HowMuchLbs = (rand() % 90) + 1;
				ChanceOfGear = (rand() % 350) + 1;
			} else {
				return;
			}

			int chanceofbonus = 1;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel >= 4) chanceofbonus = 2;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel >= 6) chanceofbonus = 3;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel >= 8) chanceofbonus = 4;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel >= 10) chanceofbonus = 5;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel >= 2 && rand() % 100 <= chanceofbonus) {
				vector<int> newGearBase{ 344, 242, 3042, 3016, 5158, 5232, 5604, 5606, 5608, 6902, 6996, 9746 };
				const int newGearIndex = rand() % newGearBase.size();
				const auto newGearID = newGearBase[newGearIndex];
				Player::OnConsoleMessage(peer, "Quantum bonus obtained " + getItemDef(newGearID).name + "");
				auto success = true;
				SaveItemMoreTimes(newGearID, 1, peer, success);
				auto Gems = (rand() % 600) + 1;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel == 10 && rand() % 100 <= 1) {
					Gems *= 2;
					Player::OnConsoleMessage(peer, "Obtained double gems");
				}
				auto currentGems = 0;
				ifstream ifs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				ifs >> currentGems;
				ifs.close();
				currentGems += Gems;
				ofstream ofs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				ofs << currentGems;
				ofs.close();
				SendXP(peer, 5);
				Player::OnSetBux(peer, currentGems, 0);
				for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
					if (isHere(peer, currentPeer)) {
						Player::OnConsoleMessage(currentPeer, "`$" + static_cast<PlayerInfo*>(peer->data)->displayName + " `oCaught `$" + getItemDef(newGearID).name + " `oand got `$" + to_string(Gems) + " `ogems");
						Player::PlayAudio(currentPeer, "audio/getpoint.wav", 0);
						SendTradeEffect(peer, BlockID, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->netID, 150);
					}
				}
			} 
			else if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel >= 3 && rand() % 100 <= 1) {
				bool success = true;
				SaveItemMoreTimes(260, 1, peer, success, "");
				Player::OnConsoleMessage(peer, "Obtained Golden Block");
			}

			count = HowMuchLbs;
			if (ChanceOfBlock <= 30 && ChanceOfBlock != 0) {
				auto success = true;
				SaveItemMoreTimes(BlockID, 1, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from fishing");
				Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wYou caught a `2" + getItemDef(BlockID).name + "`2!", 0, false);
				auto Gems = (rand() % 500) + 1;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel == 10 && rand() % 100 <= 1) {
					Gems *= 2;
					Player::OnConsoleMessage(peer, "Obtained double gems");
				}
				auto currentGems = 0;
				ifstream ifs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				ifs >> currentGems;
				ifs.close();
				currentGems += Gems;
				ofstream ofs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				ofs << currentGems;
				ofs.close();
				SendXP(peer, 3);
				Player::OnSetBux(peer, currentGems, 0);
				for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
					if (isHere(peer, currentPeer)) {
						Player::OnConsoleMessage(currentPeer, "`$" + static_cast<PlayerInfo*>(peer->data)->displayName + " `oCaught `$" + getItemDef(BlockID).name + " `oand got `$" + to_string(Gems) + " `ogems");
						Player::PlayAudio(currentPeer, "audio/getpoint.wav", 0);
						SendTradeEffect(peer, BlockID, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->netID, 150);
					}
				}
				Player::OnSetPos(peer, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y);
				int targetfishlevel = 1600;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel > 0) targetfishlevel = targetfishlevel * static_cast<PlayerInfo*>(peer->data)->fishermanlevel;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel == 0) targetfishlevel = 900;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanxp >= targetfishlevel && static_cast<PlayerInfo*>(peer->data)->fishermanlevel < 10) {
					static_cast<PlayerInfo*>(peer->data)->fishermanlevel++;
					static_cast<PlayerInfo*>(peer->data)->fishermanxp = 0;
					SyncPlayerRoles(peer, static_cast<PlayerInfo*>(peer->data)->fishermanlevel, "fisherman");
				} else {
					static_cast<PlayerInfo*>(peer->data)->fishermanxp += 3;
				}
				return;
			}
			if (ChanceOfGear <= 10 && ChanceOfGear != 0)
			{
				auto success = true;
				SaveItemMoreTimes(GearID, 1, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from fishing");
				Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wYou caught a `2" + getItemDef(GearID).name + "`2!", 0, false);
				auto Gems = (rand() % 600) + 1;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel == 10 && rand() % 100 <= 1) {
					Gems *= 2;
					Player::OnConsoleMessage(peer, "Obtained double gems");
				}
				auto currentGems = 0;
				ifstream ifs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				ifs >> currentGems;
				ifs.close();
				currentGems += Gems;
				ofstream ofs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
				ofs << currentGems;
				ofs.close();
				SendXP(peer, 5);
				Player::OnSetBux(peer, currentGems, 0);
				for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
					if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
					if (isHere(peer, currentPeer)) {
						Player::OnConsoleMessage(currentPeer, "`$" + static_cast<PlayerInfo*>(peer->data)->displayName + " `oCaught `$" + getItemDef(GearID).name + " `oand got `$" + to_string(Gems) + " `ogems");
						Player::PlayAudio(currentPeer, "audio/getpoint.wav", 0);
						SendTradeEffect(currentPeer, GearID, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->netID, 150);
					}	
				}
				Player::OnSetPos(peer, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y);
				int targetfishlevel = 1600;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel > 0) targetfishlevel = targetfishlevel * static_cast<PlayerInfo*>(peer->data)->fishermanlevel;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel == 0) targetfishlevel = 900;
				if (static_cast<PlayerInfo*>(peer->data)->fishermanxp >= targetfishlevel && static_cast<PlayerInfo*>(peer->data)->fishermanlevel < 10) {
					static_cast<PlayerInfo*>(peer->data)->fishermanlevel++;
					static_cast<PlayerInfo*>(peer->data)->fishermanxp = 0;
					SyncPlayerRoles(peer, static_cast<PlayerInfo*>(peer->data)->fishermanlevel, "fisherman");
				} else {
					static_cast<PlayerInfo*>(peer->data)->fishermanxp += 5;
				}
				return;
			}
			auto iscontains = false;
			SearchInventoryItem(peer, ItemID, 1, iscontains);
			if (!iscontains) {
				auto success = true;
				SaveItemMoreTimes(ItemID, count, peer, success, static_cast<PlayerInfo*>(peer->data)->rawName + " from fishing");
			} else {
				DropItem(world, peer, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y, ItemID, count, 0);
			}
			if (getItemDef(ItemID).blockType == BlockTypes::FISH) {
				Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wYou caught a `2" + to_string(count) + " lb. " + getItemDef(ItemID).name + "`2!", 0, false);
			} else {
				Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wYou caught a `2" + getItemDef(ItemID).name + "`2!", 0, false);
			}
			auto Gems = 0;
			if (count >= 1 && count < 30)
			{
				Gems = (rand() % 150) + 1;
			}
			else if (count >= 30 && count < 60)
			{
				Gems = (rand() % 250) + 1;
			}
			else if (count >= 60 && count < 90)
			{
				Gems = (rand() % 400) + 1;
			}
			else if (count >= 90 && count < 120)
			{
				Gems = (rand() % 450) + 1;
			}
			else if (count >= 120 && count < 150)
			{
				Gems = (rand() % 500) + 1;
			}
			else if (count >= 150 && count < 199)
			{
				Gems = (rand() % 550) + 1;
			}
			else if (count >= 200)
			{
				Gems = (rand() % 900) + 1;
			}
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel == 10 && rand() % 100 <= 1) {
				Gems *= 2;
				Player::OnConsoleMessage(peer, "Obtained double gems");
			}
			auto currentGems = 0;
			ifstream ifs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
			ifs >> currentGems;
			ifs.close();
			currentGems += Gems;
			ofstream ofs("save/gemdb/_" + static_cast<PlayerInfo*>(peer->data)->rawName + ".txt");
			ofs << currentGems;
			ofs.close();
			SendXP(peer, 2);
			Player::OnSetBux(peer, currentGems, 0);
			for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
				if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
				if (isHere(peer, currentPeer)) {
					Player::OnConsoleMessage(currentPeer, "`$" + static_cast<PlayerInfo*>(peer->data)->displayName + " `oCaught `$" + to_string(count) + " lb. " + getItemDef(ItemID).name + " `oand got `$" + to_string(Gems) + " `ogems");
					Player::PlayAudio(currentPeer, "audio/getpoint.wav", 0);
					SendTradeEffect(currentPeer, ItemID, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->netID, 150);
				}
			}
			int targetfishlevel = 1600;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel > 0) targetfishlevel = targetfishlevel * static_cast<PlayerInfo*>(peer->data)->fishermanlevel;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanlevel == 0) targetfishlevel = 900;
			if (static_cast<PlayerInfo*>(peer->data)->fishermanxp >= targetfishlevel && static_cast<PlayerInfo*>(peer->data)->fishermanlevel < 10) {
				static_cast<PlayerInfo*>(peer->data)->fishermanlevel++;
				static_cast<PlayerInfo*>(peer->data)->fishermanxp = 0;
				SyncPlayerRoles(peer, static_cast<PlayerInfo*>(peer->data)->fishermanlevel, "fisherman");
			} else {
				static_cast<PlayerInfo*>(peer->data)->fishermanxp += 2;
			}
		} 
		Player::OnSetPos(peer, static_cast<PlayerInfo*>(peer->data)->netID, static_cast<PlayerInfo*>(peer->data)->x, static_cast<PlayerInfo*>(peer->data)->y);
		return;
	} else if (static_cast<PlayerInfo*>(peer->data)->Fishing && !static_cast<PlayerInfo*>(peer->data)->TriggerFish) {
		static_cast<PlayerInfo*>(peer->data)->FishPosX = 0;
		static_cast<PlayerInfo*>(peer->data)->FishPosY = 0;
		static_cast<PlayerInfo*>(peer->data)->Fishing = false;
		Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`wSit perfectly while fishing`w!", 0, true);
	}
}

inline void SendGScan(ENetPeer* peer, WorldInfo* world, int x, int y) {
	try {
		string EditableDialog = "";
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		string button_dialog = "";
		string allowFloat = "0";
		string allowDrop = "0";
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		string endDialog = "";
		if (world->items.at(x + (y * world->width)).rm) allowFloat = "1";
		if (world->items.at(x + (y * world->width)).opened) allowDrop = "1";
		if (isWorldOwner(peer, world) || isMod(peer)) {
			endDialog = "\nend_dialog|statsblock|Cancel|Apply|";
			button_dialog = "\nadd_textbox|`wWhich stats would you like to view?|left\nadd_button|worldBlocks|World Blocks|noflags|0|0|\nadd_button|floatingItems|Floating Items|noflags|0|0|";
			EditableDialog = "\nadd_textbox|`wYou can set the stats to be usable by the public.|left\nadd_checkbox|isStatsWorldBlockUsableByPublic|World blocks is usable by public|" + allowDrop + "\nadd_checkbox|isStatsFloatingItemsUsableByPublic|Floating items is usable by public|" + allowFloat + "\nadd_spacer|small|";
		}
		else if (world->items.at(x + (y * world->width)).rm && world->items.at(x + (y * world->width)).opened) {
			endDialog = "\nend_dialog|statsblock|Cancel||";
			button_dialog = "\nadd_textbox|`wWhich stats would you like to view?|left\nadd_button|worldBlocks|World Blocks|noflags|0|0|\nadd_button|floatingItems|Floating Items|noflags|0|0|";
		}
		else if (world->items.at(x + (y * world->width)).rm) {
			endDialog = "\nend_dialog|statsblock|Cancel||";
			button_dialog = "\nadd_textbox|`wWhich stats would you like to view?|left\nadd_button|floatingItems|Floating Items|noflags|0|0|";
		}
		else if (world->items.at(x + (y * world->width)).opened) {
			endDialog = "\nend_dialog|statsblock|Cancel||";
			button_dialog = "\nadd_textbox|`wWhich stats would you like to view?|left\nadd_button|worldBlocks|World Blocks|noflags|0|0|";
		}
		else {
			endDialog = "\nend_dialog|statsblock|Cancel||";
			button_dialog = "\nadd_textbox|`wThis growscan options are set to private!|left";
		}
		Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`wWorld Stats``|left|6016|\nadd_spacer|small|\nadd_textbox|`wThis amazing block can show the stats for the whole world!|left\nadd_spacer|small|" + button_dialog + "\nadd_spacer|small|" + EditableDialog + "" + endDialog + "");
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline bool restricted_area_check(WorldInfo* world, const int x, const int y) {
	try {
		bool scan_area = false;
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		int where_lock_x = -1;
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		int where_lock_y = -1;
		bool can_interact = false;
		for (int i = 0; i < world->width * world->height; i++) {
			if (world->items.at(i).foreground == 202 || world->items.at(i).foreground == 204 || world->items.at(i).foreground == 206 || world->items.at(i).foreground == 4994) {
				where_lock_x = i % world->width;
				where_lock_y = i / world->width;
				scan_area = true;
				if (x == where_lock_x + 1 && where_lock_y == y) can_interact = true;
				if (x == where_lock_x + 2 && where_lock_y == y) can_interact = true;
				if (x == where_lock_x - 1 && where_lock_y == y) can_interact = true;
				if (x == where_lock_x - 2 && where_lock_y == y) can_interact = true;
				if (y == where_lock_y + 1 && where_lock_x == x) can_interact = true;
				if (y == where_lock_y + 2 && where_lock_x == x) can_interact = true;
				if (y == where_lock_y - 1 && where_lock_x == x) can_interact = true;
				if (y == where_lock_y - 2 && where_lock_x == x) can_interact = true;
				if (x == where_lock_x + 1 && where_lock_y + 1 == y) can_interact = true;
				if (x == where_lock_x + 2 && where_lock_y + 2 == y) can_interact = true;
				if (x == where_lock_x - 1 && where_lock_y - 1 == y) can_interact = true;
				if (x == where_lock_x - 2 && where_lock_y - 2 == y) can_interact = true;
				if (y == where_lock_y + 1 && where_lock_x + 1 == x) can_interact = true;
				if (y == where_lock_y + 2 && where_lock_x + 2 == x) can_interact = true;
				if (y == where_lock_y - 1 && where_lock_x - 1 == x) can_interact = true;
				if (y == where_lock_y - 2 && where_lock_x - 2 == x) can_interact = true;
				if (x == where_lock_x + 1 && where_lock_y - 1 == y) can_interact = true;
				if (x == where_lock_x + 2 && where_lock_y - 2 == y) can_interact = true;
				if (x == where_lock_x - 1 && where_lock_y + 1 == y) can_interact = true;
				if (x == where_lock_x - 2 && where_lock_y + 2 == y) can_interact = true;
				if (y == where_lock_y + 1 && where_lock_x - 1 == x) can_interact = true;
				if (y == where_lock_y + 2 && where_lock_x - 2 == x) can_interact = true;
				if (y == where_lock_y - 1 && where_lock_x + 1 == x) can_interact = true;
				if (y == where_lock_y - 2 && where_lock_x + 2 == x) can_interact = true;
				if (x == where_lock_x + 2 && where_lock_y + 1 == y) can_interact = true;
				if (x == where_lock_x - 2 && where_lock_y - 1 == y) can_interact = true;
				if (x == where_lock_x + 1 && where_lock_y + 2 == y) can_interact = true;
				if (x == where_lock_x - 1 && where_lock_y - 2 == y) can_interact = true;
				if (x == where_lock_x - 1 && where_lock_y + 2 == y) can_interact = true;
				if (x == where_lock_x + 1 && where_lock_y - 2 == y) can_interact = true;
				if (x == where_lock_x + 2 && where_lock_y - 1 == y) can_interact = true;
				if (x == where_lock_x + 2 && where_lock_y + 1 == y) can_interact = true;
				if (x == where_lock_x - 2 && where_lock_y + 1 == y) can_interact = true;
			}
		}
		if (!scan_area) return true;
		if (!can_interact) return true;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return false;
}

inline bool restricted_area(ENetPeer* peer, WorldInfo* world, const int x, const int y) {
	try {
		bool scan_area = false;
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		int where_lock_x = 0;
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		int where_lock_y = 0;
		// ReSharper disable once CppInitializedValueIsAlwaysRewritten
		bool can_interact = false;
		bool bound_area = false;
		for (int i = 0; i < world->width * world->height; i++) {
			if (world->items.at(i).foreground == 202 || world->items.at(i).foreground == 204 || world->items.at(i).foreground == 206 || world->items.at(i).foreground == 4994) {
				scan_area = true;
				if (world->items.at(i).opened || world->items.at(i).monitorname == static_cast<PlayerInfo*>(peer->data)->rawName) {
					where_lock_x = i % world->width;
					where_lock_y = i / world->width;
					if (x == where_lock_x + 1 && where_lock_y == y) can_interact = true;
					if (x == where_lock_x + 2 && where_lock_y == y) can_interact = true;
					if (x == where_lock_x - 1 && where_lock_y == y) can_interact = true;
					if (x == where_lock_x - 2 && where_lock_y == y) can_interact = true;
					if (y == where_lock_y + 1 && where_lock_x == x) can_interact = true;
					if (y == where_lock_y + 2 && where_lock_x == x) can_interact = true;
					if (y == where_lock_y - 1 && where_lock_x == x) can_interact = true;
					if (y == where_lock_y - 2 && where_lock_x == x) can_interact = true;
					if (x == where_lock_x + 1 && where_lock_y + 1 == y) can_interact = true;
					if (x == where_lock_x + 2 && where_lock_y + 2 == y) can_interact = true;
					if (x == where_lock_x - 1 && where_lock_y - 1 == y) can_interact = true;
					if (x == where_lock_x - 2 && where_lock_y - 2 == y) can_interact = true;
					if (y == where_lock_y + 1 && where_lock_x + 1 == x) can_interact = true;
					if (y == where_lock_y + 2 && where_lock_x + 2 == x) can_interact = true;
					if (y == where_lock_y - 1 && where_lock_x - 1 == x) can_interact = true;
					if (y == where_lock_y - 2 && where_lock_x - 2 == x) can_interact = true;
					if (x == where_lock_x + 1 && where_lock_y - 1 == y) can_interact = true;
					if (x == where_lock_x + 2 && where_lock_y - 2 == y) can_interact = true;
					if (x == where_lock_x - 1 && where_lock_y + 1 == y) can_interact = true;
					if (x == where_lock_x - 2 && where_lock_y + 2 == y) can_interact = true;
					if (y == where_lock_y + 1 && where_lock_x - 1 == x) can_interact = true;
					if (y == where_lock_y + 2 && where_lock_x - 2 == x) can_interact = true;
					if (y == where_lock_y - 1 && where_lock_x + 1 == x) can_interact = true;
					if (y == where_lock_y - 2 && where_lock_x + 2 == x) can_interact = true;
					if (x == where_lock_x + 2 && where_lock_y + 1 == y) can_interact = true;
					if (x == where_lock_x - 2 && where_lock_y - 1 == y) can_interact = true;
					if (x == where_lock_x + 1 && where_lock_y + 2 == y) can_interact = true;
					if (x == where_lock_x - 1 && where_lock_y - 2 == y) can_interact = true;
					if (x == where_lock_x - 1 && where_lock_y + 2 == y) can_interact = true;
					if (x == where_lock_x + 1 && where_lock_y - 2 == y) can_interact = true;
					if (x == where_lock_x + 2 && where_lock_y - 1 == y) can_interact = true;
					if (x == where_lock_x + 2 && where_lock_y + 1 == y) can_interact = true;
					if (x == where_lock_x - 2 && where_lock_y + 1 == y) can_interact = true;
				}
				else if (world->owner == "") {
					where_lock_x = i % world->width;
					where_lock_y = i / world->width;
					if (x == where_lock_x + 1 && where_lock_y == y) bound_area = true;
					if (x == where_lock_x + 2 && where_lock_y == y) bound_area = true;
					if (x == where_lock_x - 1 && where_lock_y == y) bound_area = true;
					if (x == where_lock_x - 2 && where_lock_y == y) bound_area = true;
					if (y == where_lock_y + 1 && where_lock_x == x) bound_area = true;
					if (y == where_lock_y + 2 && where_lock_x == x) bound_area = true;
					if (y == where_lock_y - 1 && where_lock_x == x) bound_area = true;
					if (y == where_lock_y - 2 && where_lock_x == x) bound_area = true;
					if (x == where_lock_x + 1 && where_lock_y + 1 == y) bound_area = true;
					if (x == where_lock_x + 2 && where_lock_y + 2 == y) bound_area = true;
					if (x == where_lock_x - 1 && where_lock_y - 1 == y) bound_area = true;
					if (x == where_lock_x - 2 && where_lock_y - 2 == y) bound_area = true;
					if (y == where_lock_y + 1 && where_lock_x + 1 == x) bound_area = true;
					if (y == where_lock_y + 2 && where_lock_x + 2 == x) bound_area = true;
					if (y == where_lock_y - 1 && where_lock_x - 1 == x) bound_area = true;
					if (y == where_lock_y - 2 && where_lock_x - 2 == x) bound_area = true;
					if (x == where_lock_x + 1 && where_lock_y - 1 == y) bound_area = true;
					if (x == where_lock_x + 2 && where_lock_y - 2 == y) bound_area = true;
					if (x == where_lock_x - 1 && where_lock_y + 1 == y) bound_area = true;
					if (x == where_lock_x - 2 && where_lock_y + 2 == y) bound_area = true;
					if (y == where_lock_y + 1 && where_lock_x - 1 == x) bound_area = true;
					if (y == where_lock_y + 2 && where_lock_x - 2 == x) bound_area = true;
					if (y == where_lock_y - 1 && where_lock_x + 1 == x) bound_area = true;
					if (y == where_lock_y - 2 && where_lock_x + 2 == x) bound_area = true;
					if (x == where_lock_x + 2 && where_lock_y + 1 == y) bound_area = true;
					if (x == where_lock_x - 2 && where_lock_y - 1 == y) bound_area = true;
					if (x == where_lock_x + 1 && where_lock_y + 2 == y) bound_area = true;
					if (x == where_lock_x - 1 && where_lock_y - 2 == y) bound_area = true;
					if (x == where_lock_x - 1 && where_lock_y + 2 == y) bound_area = true;
					if (x == where_lock_x + 1 && where_lock_y - 2 == y) bound_area = true;
					if (x == where_lock_x + 2 && where_lock_y - 1 == y) bound_area = true;
					if (x == where_lock_x + 2 && where_lock_y + 1 == y) bound_area = true;
					if (x == where_lock_x - 2 && where_lock_y + 1 == y) bound_area = true;
				}
			}
		}
		if (!can_interact && world->owner == "" && !bound_area || isWorldOwner(peer, world)) return false;
		else if (!scan_area) return true;
		else if (!can_interact) return true;
		else if (can_interact) return false;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return true;
}

inline void send_rainbow_shit_data(ENetPeer* peer, short fg, short bg, int x, int y, bool rainbow, int netid) {
	byte* ExtendedData = new byte[26];
	int state = 0x0010000;
	int extendedLen = 26;
	PlayerMoving pmov{};
	pmov.packetType = 0x5;
	pmov.characterState = 0x8;
	pmov.punchX = x;
	pmov.punchY = y;
	int NetID = netid;
	byte* raw = new byte[56 + 26];
	memcpy(raw, packPlayerMoving(&pmov), 56);
	memcpy(raw + 52, &extendedLen, 4);
	memcpy(ExtendedData, &fg, 2);
	memcpy(ExtendedData + 2, &bg, 2);
	memcpy(ExtendedData + 4, &state, 4);
	ExtendedData[8] = 0x3;
	// ReSharper disable once CppInitializedValueIsAlwaysRewritten
	int flags = 0;
	if (rainbow) {
		flags = 128;
	} else {
		flags = 0;
	}
	ExtendedData[9] = flags; 
	memcpy(ExtendedData + 10, &NetID, 4);
	ExtendedData[15] = 0;
	ExtendedData[16] = 0;
	ExtendedData[17] = 0;
	ExtendedData[18] = 0;
	ExtendedData[19] = 1;
	ExtendedData[20] = 0;
	ExtendedData[21] = 0;
	ExtendedData[22] = 0;
	ExtendedData[23] = 0;
	ExtendedData[24] = 0;
	ExtendedData[25] = 0;
	ExtendedData[26] = 0;
	memcpy(raw + 56, ExtendedData, extendedLen);
	SendPacketRaw3(4, raw, 56 + 26, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
	delete[] ExtendedData; 

}

inline void send_npc(ENetPeer* peer, float fromX, float fromY, float toX, float toY, float speed, uint8_t npc_id, uint8_t npc_type, uint8_t command) {
	PlayerMoving pmov;
	memset(&pmov, 0, sizeof(PlayerMoving));
	*reinterpret_cast<uint32_t*>(&pmov) = 34 | (npc_type << 8) | (npc_id << 16) | (command << 24);
	*reinterpret_cast<float*>(&pmov + 40) = speed; 
	pmov.x = fromX;
	pmov.y = fromY;
	pmov.XSpeed = toX;
	pmov.YSpeed = toY;
	uint8_t* pmovpacked = packPlayerMoving(&pmov);
	uint8_t* packet = new uint8_t[4 + 56];
	memset(packet, 0, 4 + 56);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, sizeof(PlayerMoving));
	ENetPacket* epacket = enet_packet_create(packet, 4 + 56, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, epacket);
	delete pmovpacked;
	delete[] packet;
}

inline void send_dice(ENetPeer* peer, int number, int x, int y) {
	PlayerMoving data;
	BYTE* raw = packPlayerMoving(&data);
	memcpy(raw + 1, &number, 3);
	data.netID = static_cast<PlayerInfo*>(peer->data)->netID;
	data.packetType = 0x8;
	data.plantingTree = 0;
	data.netID = -1;
	data.x = x;
	data.y = y;
	data.punchX = x;
	data.punchY = y;
	SendPacketRaw(4, raw, 56, nullptr, peer, ENET_PACKET_FLAG_RELIABLE);
}

inline void equip_item(ENetPeer* peer, int id, const int type) {
	bool has_item = false;
	SearchInventoryItem(peer, id, 1, has_item);
	if (!has_item) return;
	Player::PlayAudio(peer, "audio/change_clothes.wav", 0);
	bool silent_equip = false;
	bool overhaul_update = false;
	if (static_cast<PlayerInfo*>(peer->data)->cloth9 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth9 = 0;
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth8 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth8 = 0;
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth7 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth7 = 0;
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth6 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth6 = 0;
		static_cast<PlayerInfo*>(peer->data)->canDoubleJump = false;
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth5 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth5 = 0;
		if (static_cast<PlayerInfo*>(peer->data)->cloth4 != 0) {
			id = static_cast<PlayerInfo*>(peer->data)->cloth4;
			silent_equip = true;
			goto equip;
		} else {
			static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
		}
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth4 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth4 = 0;
		if (static_cast<PlayerInfo*>(peer->data)->cloth5 != 0) {
			id = static_cast<PlayerInfo*>(peer->data)->cloth5;
			silent_equip = true;
			goto equip;
		} else {
			static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
		}
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth3 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth3 = 0;
		if (static_cast<PlayerInfo*>(peer->data)->cloth5 != 0 || static_cast<PlayerInfo*>(peer->data)->cloth4 != 0) {
			overhaul_update = true;
			goto equip;
		} else {
			static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
		}
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth2 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth2 = 0;
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth1 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth1 = 0;
	} else if (static_cast<PlayerInfo*>(peer->data)->cloth0 == id) {
		static_cast<PlayerInfo*>(peer->data)->cloth0 = 0;
	} else {
		switch (type) {
			case 0:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth0 = id;
				break;
			}
			case 1:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth1 = id;
				break;
			}
			case 2:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth2 = id;
				break;
			}
			case 3:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth3 = id;
				break;
			}
			case 4:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth4 = id;
				break;
			}
			case 5:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth5 = id;
				break;
			}
			case 6:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth6 = id;   
				break;
			}
			case 7:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth7 = id;
				break;
			}
			case 8:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth8 = id;
				break;
			}
			case 10:
			{
				static_cast<PlayerInfo*>(peer->data)->cloth9 = id;
				break;
			}
			default:
			{
				break;
			}
		}
	equip:
		int x = 1;
		if (overhaul_update) {
			x = 10;
		}
		for (int i = 0; i < x; i++) {
			if (x != 1) {
				switch (i) {
					case 1:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth0;
						break;
					}
					case 2:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth1;
						break;
					}
					case 3:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth2;
						break;
					}
					case 4:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth3;
						break;
					}
					case 5:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth4;
						break;
					}
					case 6:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth5;
						break;
					}
					case 7:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth6;
						break;
					}
					case 8:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth7;
						break;
					}
					case 9:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth8;
						break;
					}
					case 10:
					{
						id = static_cast<PlayerInfo*>(peer->data)->cloth9;
						break;
					}
					default:
					{
						break;
					}
				}
			}
			switch (id) {
				case 3172:
				{
					if (static_cast<PlayerInfo*>(peer->data)->SurgeryCooldown) {
						Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`2Your briefs have stunned the judge!", 0, true);
						RemoveInventoryItem(3172, 1, peer, true);
						if (!silent_equip) Player::OnConsoleMessage(peer, "You've paid your debt to society! (`$Malpractice`` mod removed)");
						sendSound(peer, "audio/dialog_confirm.wav");
						static_cast<PlayerInfo*>(peer->data)->SurgeryCooldown = false;
						static_cast<PlayerInfo*>(peer->data)->SurgeryTime = 0;
					}
					bool contains = false;
					SearchInventoryItem(peer, 3172, 1, contains);
					if (!contains) return;
					break;
				}
				case 898: case 1830: case 1966:
				{
					playerconfig(peer, 1150, 130, 0x14);
					break;
				}
				case 9506: 
				{
					playerconfig(peer, 1150, 500, 0x14);
					break;
				}
				case 1946:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421401;
					break;
				}
				case 1874:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421400;
					break;
				}
				case 1204:
				{
					if (!silent_equip) Player::OnConsoleMessage(peer, "`oGive people the evil eye. (`oFocused eyes mod added`o)");
					static_cast<PlayerInfo*>(peer->data)->effect = 8421398;
					break;
				}
				case 1780:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421396;
					break;
				}
				case 2204:
				{
					static_cast<PlayerInfo*>(peer->data)->geigerx = rand() % 3000;
					static_cast<PlayerInfo*>(peer->data)->geigery = rand() % 1500;
					break;
				}
				case 1676:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421393;
					break;
				}
				case 1576:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421392;
					break;
				}
				case 1542:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421391;
					break;
				}
				case 2910:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421432;
					break;
				}
				case 2890:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421431;
					break;
				}
				case 2906:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421429;
					break;
				}
				case 2876:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421427;
					break;
				}
				case 1512:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421390;
					break;
				}
				case 2866:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421426;
					break;
				}
				case 594:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421380;
					break;
				}
				case 6312:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421529;
					break;
				}
				case 2212:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421408;
					break;
				}
				case 3466:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421405;
					break;
				}
				case 138:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421377;
					break;
				}
				case 2476:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421415;
					break;
				}
				case 2450:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421414;
					break;
				}
				case 2266:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421411;
					break;
				}
				case 2388:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421413;
					break;
				}
				case 366:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421378;
					break;
				}
				case 472:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421379;
					break;
				}
				case 2220:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421410;
					break;
				}
				case 1484:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421389;
					break;
				}
				case 2756:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421423;
					break;
				}
				case 2754:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421422;
					break;
				}
				case 2720:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421420;
					break;
				}
				case 2592:
				{
					if (!silent_equip) Player::OnConsoleMessage(peer, "`oNone can stand against you! (`oLegendary Swordsmaster mod added`o)");
					static_cast<PlayerInfo*>(peer->data)->effect = 8421419;
					break;
				}
				case 6782:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421509;
					break;
				}
				case 8452:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421412;
					break;
				}
				case 5480:
				{
					if (!silent_equip) Player::OnConsoleMessage(peer, "`oWho needs arms when you have these? (`oRayman fist! mod added`o)");
					static_cast<PlayerInfo*>(peer->data)->effect = 8421456;
					break;
				}
				case 1782:
				{
					if (!silent_equip) Player::OnConsoleMessage(peer, "`oYou should be very very nice to your pet. (`oLegendary! mod added`o)");
					static_cast<PlayerInfo*>(peer->data)->effect = 8421397;
					break;
				}
				case 1868:
				{
					if (!silent_equip) Player::OnConsoleMessage(peer, "`oYou command a mighty (violent) dragon! (`oDrakeborn mod added`o)");
					static_cast<PlayerInfo*>(peer->data)->effect = 8421399;
					break;
				}
				case 10618:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421563;
					break;
				}
				case 1804:
				{
					if (!silent_equip) Player::OnConsoleMessage(peer, "`oYou electrocute things. (`oFistful Of Thunder mod added`o)");
					static_cast<PlayerInfo*>(peer->data)->effect = 8421398;
					break;
				}
				case 9058:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421512;
					break;
				}
				case 9484:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421512;
					break;
				}
				case 9486:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421512;
					break;
				}
				case 7912:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421398;
					break;
				}
				case 6026:
				{
					if (!silent_equip) Player::OnConsoleMessage(peer, "`oThe truth is yours! (`oWhip of Truth mod added`o)");
					static_cast<PlayerInfo*>(peer->data)->effect = 8421452;
					break;
				}
				case 9164:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421452;
					break;
				}
				case 2572:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421418;
					break;
				}
				case 2872:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8424243;
					break;
				}
				case 2952: case 9510: case 9512: case 9520: case 9514: case 9496: case 9492: case 9494: case 9488: case 3932: case 9448: case 9452: case 9508: case 9454: case 9456: case 9458: case 9430:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421406;
					break;
				}
				case 4778:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421452;
					break;
				}
				case 4474:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421448;
					break;
				}
				case 3686:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421444;
					break;
				}
				case 3418:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421441;
					break;
				}
				case 8910:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421505;
					break;
				}
				case 7586:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421480;
					break;
				}
				case 7488:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421479;
					break;
				}
				case 7196:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421471;
					break;
				}
				case 10128:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421547;
					break;
				}
				case 10652:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421564;
					break;
				}
				case 10426:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421559;
					break;
				}
				case 7136:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421468;
					break;
				}
				case 7044:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421462;
					break;
				}
				case 6308:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421458;
					break;
				}
				case 3300:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421440;
					break;
				}
				case 4996:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421453;
					break;
				}
				case 3214:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421436;
					break;
				}
				case 3168:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421435;
					break;
				}
				case 3124:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421434;
					break;
				}
				case 3066:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421433;
					break;
				}
				case 9502:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421512;
					break;
				}
				case 9236:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421521;
					break;
				}
				case 9376:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421525;
					break;
				}
				case 9006:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = 8421511;
					break;
				}
				case 1956:
				{
					static_cast<PlayerInfo*>(peer->data)->effect = -997;
					break;
				}
				default:
				{
					if (type == 6) {
						if (id == 10426 || id == 156 || id == 9006 || id == 1958 || getItemDef(id).name.find("Aura") != string::npos || id == 9476 || id == 9434 || getItemDef(id).name.find("Wings") != string::npos || getItemDef(id).name.find("Cape") != string::npos || id == 8580 || id == 5158 || id == 9410 || id == 9306 || id == 10022 || id == 8308 || id == 7834 || id == 10020 || id == 9760 || id == 10016 || id == 10012 || id == 1674 || id == 9478 || id == 9506 || id == 9476 || id == 1970 || id == 8286 || id == 9506 || id == 9478 || id == 8552 || id == 362 || id == 678 || id == 736 || id == 7734 || id == 7762 || id == 818 || id == 1206 || id == 1460 || id == 1550 || id == 1574 || id == 1668 || id == 1672 || id == 1674 || id == 1784 || id == 1824 || id == 1936 || id == 1938 || id == 1970 || id == 2254 || id == 2256 || id == 2258 || id == 2260 || id == 2262 || id == 2264 || id == 2390 || id == 2392 || id == 3120 || id == 3308 || id == 3512 || id == 4534 || id == 4986 || id == 5754 || id == 6144 || id == 6334 || id == 6694 || id == 6818 || id == 6842 || id == 1934 || id == 3134 || id == 6004 || id == 1780 || id == 2158 || id == 2160 || id == 2162 || id == 2164 || id == 2166 || id == 2168 || id == 2438 || id == 2538 || id == 2778 || id == 3858 || id == 350 || id == 998 || id == 1738 || id == 2642 || id == 2982 || id == 3104 || id == 3144 || id == 5738 || id == 3112 || id == 2722 || id == 3114 || id == 4970 || id == 4972 || id == 5020 || id == 6284 || id == 4184 || id == 4628 || id == 5322 || id == 4112 || id == 4114 || id == 3442 || id == 9466 || id == 8286 || id == 5136 || id == 9416 || id == 9356) {
							if (id == 5196 || id == 7558) {
								if (!silent_equip) Player::OnConsoleMessage(peer, "`oYou can fly in air! It's like double jumping, but more. (`oFlying mod added`o)");
							} else {
								if (!silent_equip) Player::OnConsoleMessage(peer, "`oYou can jump in mid-air! It's like flying, but less. (`oDouble jump mod added`o)");
							}
							static_cast<PlayerInfo*>(peer->data)->canDoubleJump = true;
						} else {
							static_cast<PlayerInfo*>(peer->data)->canDoubleJump = false;
						}		
					} else if (type == 4 || type == 5) {
						static_cast<PlayerInfo*>(peer->data)->effect = 8421376;
					} 
					break;
				}
			}
		}
	}
	sendPuncheffect(peer, static_cast<PlayerInfo*>(peer->data)->effect);
	send_state(peer); 
	sendClothes(peer);	
}

inline void restore_player_name(WorldInfo* world, ENetPeer* peer) {
	try {
		string name2 = "";
		string namemsg = static_cast<PlayerInfo*>(peer->data)->rawName;
		static_cast<PlayerInfo*>(peer->data)->isNicked = false;
		static_cast<PlayerInfo*>(peer->data)->OriName = name2;
		if (static_cast<PlayerInfo*>(peer->data)->rawName == world->owner && !isMod(peer))
		{
			name2 = "`2" + static_cast<PlayerInfo*>(peer->data)->rawName;
			static_cast<PlayerInfo*>(peer->data)->country = "us";
		}
		else if (static_cast<PlayerInfo*>(peer->data)->adminLevel == 0)
		{
			name2 = "`w" + static_cast<PlayerInfo*>(peer->data)->rawName;
			static_cast<PlayerInfo*>(peer->data)->country = "us";
		}
		else
		{
			name2 = role_prefix.at(static_cast<PlayerInfo*>(peer->data)->adminLevel) + static_cast<PlayerInfo*>(peer->data)->rawName;
			static_cast<PlayerInfo*>(peer->data)->country = "us";
		}
		if (static_cast<PlayerInfo*>(peer->data)->NickPrefix != "")
		{
			name2 = static_cast<PlayerInfo*>(peer->data)->NickPrefix + ". " + static_cast<PlayerInfo*>(peer->data)->rawName;
		}
		if (static_cast<PlayerInfo*>(peer->data)->ltitle && static_cast<PlayerInfo*>(peer->data)->ltitleunlocked && name2.find(" of Legend``") == string::npos) {
			name2 += " of Legend``";
		}
		static_cast<PlayerInfo*>(peer->data)->displayName = name2;
		static_cast<PlayerInfo*>(peer->data)->msgName = namemsg;
		Player::OnNameChanged(peer, static_cast<PlayerInfo*>(peer->data)->netID, name2);
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void spray_tree(ENetPeer* peer, WorldInfo* world, const int x, const int y, const int tile, const bool reduce = false) {
	try {
		if (calcBanDuration(world->items.at(x + (static_cast<long long>(y) * world->width)).growtime) == 0 || tile == 5764 && world->items.at(x + (y * world->width)).foreground == 9287) {
			if (!reduce) Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "This tree has already bloomed, don't waste your spray on it!", 0, true);
			return;
		}
		int NewGrowTime = 0;
		int InternalGrowTime = 0;
		if (tile == 5764 && world->items.at(x + (y * world->width)).foreground != 5751) {
			Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "It would be a shame to waste this special Oriental Spice Spray on an ordinary tree!", 0, true);
			return;
		}
		else if (tile == 5764) {
			world->items.at(x + (y * world->width)).foreground = 9287;
			NewGrowTime = 0;
			world->items.at(x + (y * world->width)).fruitcount = 1;
			RemoveInventoryItem(5764, 1, peer, true);
		}
		else if (tile == 228) {
			NewGrowTime = calcBanDuration(world->items.at(x + (y * world->width)).growtime) - 3600;
			RemoveInventoryItem(228, 1, peer, true);
		}
		else if (tile == 1778) {
			NewGrowTime = calcBanDuration(world->items.at(x + (y * world->width)).growtime) - 86400;
			RemoveInventoryItem(1778, 1, peer, true);
		}
		else if (tile == 18 && reduce) {
			if (isDev(peer)) {
				NewGrowTime = calcBanDuration(world->items.at(x + (y * world->width)).growtime) / 24;
			}
			else if (isMod(peer) || static_cast<PlayerInfo*>(peer->data)->Subscriber) {
				NewGrowTime = calcBanDuration(world->items.at(x + (y * world->width)).growtime) / 20;
			}
			else {
				NewGrowTime = calcBanDuration(world->items.at(x + (y * world->width)).growtime) / 16;
			}
		}
		if (NewGrowTime < 0) NewGrowTime = 0;
		world->items.at(x + (y * world->width)).growtime = (GetCurrentTimeInternalSeconds() + NewGrowTime);
		int growTimeSeed = getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity * getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity * getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity;
		growTimeSeed += 30 * getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity;
		InternalGrowTime = growTimeSeed - calcBanDuration(world->items.at(x + (y * world->width)).growtime);
		UpdateTreeVisuals(peer, world->items.at(x + (y * world->width)).foreground, x, y, world->items.at(x + (y * world->width)).background, world->items.at(x + (y * world->width)).fruitcount, InternalGrowTime, true, 0);
		string age_message = getItemDef(world->items.at(x + (y * world->width)).foreground).name;
		if (world->items.at(x + (y * world->width)).foreground == 1259 || world->items.at(x + (y * world->width)).foreground == 1261 || world->items.at(x + (y * world->width)).foreground == 1263 || world->items.at(x + (y * world->width)).foreground == 1265 || world->items.at(x + (y * world->width)).foreground == 1267 || world->items.at(x + (y * world->width)).foreground == 1269 || world->items.at(x + (y * world->width)).foreground == 1271 || world->items.at(x + (y * world->width)).foreground == 4309 || world->items.at(x + (y * world->width)).foreground == 4311 || world->items.at(x + (y * world->width)).foreground == 4313 || world->items.at(x + (y * world->width)).foreground == 4315 || world->items.at(x + (y * world->width)).foreground == 4317 || world->items.at(x + (y * world->width)).foreground == 4319) {
			age_message = "Surgical Tool Tree";
		}
		if (calcBanDuration(world->items.at(x + (y * world->width)).growtime) == 0) {
			if (!reduce) Player::OnTextOverlay(peer, "" + age_message + " grew to full size!");
		}
		else if (tile == 228) {
			if (!reduce) Player::OnTextOverlay(peer, "" + age_message + " aged `$1`` hours");
		}
		else if (tile == 1778) {
			if (!reduce) Player::OnTextOverlay(peer, "" + age_message + " aged `$1`` day");
		}
		if (!reduce) Player::PlayAudio(peer, "audio/spray.wav", 0);
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void restore_prices_full() {
	try {
		remove("price_data3.txt");
		remove("price_data2.txt");
		remove("price_data1.txt");
		remove("price_data.txt");
		auto itemid = 0;
		auto kaina = 0;
		string append = "";
		for (int i = 0; i <= maxItems; i++) {
			itemid++;
			kaina = -1;
			if (getItemDef(itemid).blockType == BlockTypes::SIGN && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::DEADLY && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::GATEWAY && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::DOOR && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::PAIN_BLOCK && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::PLATFORM && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::BACKGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::FOREGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::SFX_FOREGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::ANIM_FOREGROUND && getItemDef(itemid).rarity != 999 || getItemDef(itemid).blockType == BlockTypes::TOGGLE_FOREGROUND && getItemDef(itemid).rarity != 999) {
				if (getItemDef(itemid).rarity <= 10) kaina = rand() % 150 + 100;
				else if (getItemDef(itemid).rarity <= 20) kaina = rand() % 50 + 50;
				else if (getItemDef(itemid).rarity <= 30) kaina = rand() % 55 + 40;
				else if (getItemDef(itemid).rarity <= 40) kaina = rand() % 50 + 30;
				else if (getItemDef(itemid).rarity <= 50) kaina = rand() % 30 + 30;
				else if (getItemDef(itemid).rarity <= 60) kaina = rand() % 15 + 20;
				else if (getItemDef(itemid).rarity <= 70) kaina = rand() % 25 + 1;
				else if (getItemDef(itemid).rarity <= 80) kaina = rand() % 15 + 1;
				else if (getItemDef(itemid).rarity < 100) kaina = rand() % 10 + 1;
				else kaina = rand() % 1 + 1;
				if (kaina == 0) kaina = 10;
				if (itemid == 1966) kaina = 660;
				if (itemid == 1830) kaina = 520;
				if (itemid == 5022) kaina = 760;
				if (itemid == 6300) kaina = 960;
				if (itemid == 2912) kaina = 5;
				if (itemid == 3008) kaina = 75;
				if (itemid == 3010) kaina = 180;
				if (itemid == 5740) kaina = 390;

				if (itemid == 4762) kaina = 15;
				if (itemid == 7382) kaina = 30;
				if (itemid == 5136) kaina = 50;
				if (itemid == 5138) kaina = 90;
				if (itemid == 5140) kaina = 200;
				if (itemid == 5154) kaina = 300;
				if (itemid == 9498) kaina = 500;
				if (itemid == 7188) kaina = 100;
				if (itemid == 5142) kaina = rand() % 3000 + 2500;
			} else {
				if (getItemDef(itemid).rarity <= 6) kaina = 1;
				else if (getItemDef(itemid).rarity <= 10) kaina = rand() % 2 + 1;
				else if (getItemDef(itemid).rarity <= 20) kaina = rand() % 3 + 1;
				else if (getItemDef(itemid).rarity <= 30) kaina = rand() % 4 + 1;
				else if (getItemDef(itemid).rarity <= 40) kaina = rand() % 5 + 1;
				else if (getItemDef(itemid).rarity <= 50) kaina = rand() % 8 + 1;
				else if (getItemDef(itemid).rarity <= 60) kaina = rand() % 10 + 1;
				else if (getItemDef(itemid).rarity <= 70) kaina = rand() % 15 + 1;
				else if (getItemDef(itemid).rarity <= 80) kaina = rand() % 20 + 1;
				else if (getItemDef(itemid).rarity <= 600) kaina = rand() % 100 + 1;
				else kaina = rand() % 1800 + 1;
				if (getItemDef(itemid).properties & Property_Untradable && getItemDef(itemid).rarity == 999) kaina = rand() % 1500 + 500;
				else if (getItemDef(itemid).clothType == ClothTypes::BACK && getItemDef(itemid).rarity == 999) kaina = rand() % 3000 + 900;
				else if (getItemDef(itemid).clothType == ClothTypes::SHIRT && getItemDef(itemid).rarity == 999) kaina = rand() % 160 + 100;
				else if (getItemDef(itemid).clothType == ClothTypes::HAIR && getItemDef(itemid).rarity == 999) kaina = rand() % 420 + 300;
				else if (getItemDef(itemid).clothType == ClothTypes::PANTS && getItemDef(itemid).rarity == 999) kaina = rand() % 320 + 200;
				else if (getItemDef(itemid).clothType == ClothTypes::FEET && getItemDef(itemid).rarity == 999) kaina = rand() % 230 + 100;
				else if (getItemDef(itemid).clothType == ClothTypes::FACE && getItemDef(itemid).rarity == 999) kaina = rand() % 590 + 200;
				else if (getItemDef(itemid).clothType == ClothTypes::HAND && getItemDef(itemid).rarity == 999) kaina = rand() % 1500 + 500;
				else if (getItemDef(itemid).clothType == ClothTypes::NECKLACE && getItemDef(itemid).rarity == 999) kaina = rand() % 530 + 300;
				else if (getItemDef(itemid).clothType == ClothTypes::MASK && getItemDef(itemid).rarity == 999) kaina = rand() % 580 + 200;
				if (getItemDef(itemid).name.find("Cape") != string::npos && getItemDef(itemid).rarity == 999 && getItemDef(itemid).blockType == BlockTypes::CLOTHING) kaina = rand() % 370 + 100;
				if (getItemDef(itemid).name.find("Riding") != string::npos && getItemDef(itemid).rarity == 999 && getItemDef(itemid).blockType == BlockTypes::CLOTHING) kaina = rand() % 1400 + 1000;
				if (getItemDef(itemid).name.find("Golden") != string::npos && getItemDef(itemid).rarity == 999 && getItemDef(itemid).blockType == BlockTypes::CLOTHING) kaina = rand() % 11000 + 1000;
				if (getItemDef(itemid).name.find("Nightmare") != string::npos && getItemDef(itemid).rarity == 999 && getItemDef(itemid).blockType == BlockTypes::CLOTHING) kaina = rand() % 8000 + 1000;
				if (getItemDef(itemid).name.find("Phoenix") != string::npos && getItemDef(itemid).rarity == 999 && getItemDef(itemid).blockType == BlockTypes::CLOTHING) kaina = rand() % 19000 + 1000;
				if (getItemDef(itemid).name.find("Diamond") != string::npos && getItemDef(itemid).rarity == 999 && getItemDef(itemid).blockType == BlockTypes::CLOTHING) kaina = rand() % 4000 + 1000;
				if (kaina == 0) kaina = 10;
				if (itemid == 1966) kaina = 660;
				if (itemid == 1830) kaina = 520;
				if (itemid == 5022) kaina = 760;
				if (itemid == 6300) kaina = 960;
				if (itemid == 2912) kaina = 5;
				if (itemid == 3008) kaina = 75;
				if (itemid == 3010) kaina = 180;
				if (itemid == 5740) kaina = 390;

				if (itemid == 4762) kaina = 15;
				if (itemid == 7382) kaina = 30;
				if (itemid == 5136) kaina = 50;
				if (itemid == 5138) kaina = 90;
				if (itemid == 5140) kaina = 200;
				if (itemid == 5154) kaina = 300;
				if (itemid == 9498) kaina = 500;
				if (itemid == 7188) kaina = 100;
				if (itemid == 5142) kaina = rand() % 3000 + 2500;
			}
			append += to_string(itemid) + "|" + to_string(kaina) + "|0\n";
		} 
		ofstream breaklogs("price_data.txt", ios::app);
		breaklogs << append;
		breaklogs.close();
	} catch(const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	} 
}

string get_player_buffs(PlayerInfo* pData) {
	string buffs = "";
	if (isPickaxe(pData))
	{
		buffs += "|\nadd_label_with_icon|small|`wEnchanced Digging``|left|" + to_string(pData->cloth_hand) + "|";
	}
	if (pData->GeigerCooldown)
	{
		buffs += "|\nadd_label_with_icon|small|`wIrradiated`` (`w" + OutputBanTime(calcBanDuration(pData->GeigerTime)) + " left`o)|left|2204|";
	}
	if (pData->SurgeryCooldown)
	{
		buffs += "|\nadd_label_with_icon|small|`wMalpractice`` (`w" + OutputBanTime(calcBanDuration(pData->SurgeryTime)) + " left`o)|left|1260|";
	}
	if (pData->Subscriber)
	{
		buffs += "|\nadd_label_with_icon|small|`wPremium Benefits `o(`w" + to_string(pData->SubscribtionEndDay) + " days `oleft)``|left|6862|";
	}
	if (pData->cantsay)
	{
		buffs += "|\nadd_label_with_icon|small|`wDuct tape covered your mouth!``|left|408|";
	}
	if (isRedAnces(pData) || FarmingEvent)
	{
		buffs += "|\nadd_label_with_icon|small|`wExtra Gem Drop``|left|528|";
	}
	if (isBlueAnces(pData) || FarmingEvent)
	{
		buffs += "|\nadd_label_with_icon|small|`wExtra Block Drop``|left|2|";
	}
	if (isYellowAnces(pData) || FarmingEvent)
	{
		buffs += "|\nadd_label_with_icon|small|`wExtra XP Buff``|left|1488|";
	}
	if (gem_multiplier != 0 || item_multiplier.find(pData->cloth_hand) != item_multiplier.end() || item_multiplier.find(pData->cloth_back) != item_multiplier.end() || item_multiplier.find(pData->cloth_necklace) != item_multiplier.end()) {
		string info = "";
		int gem_multi = gem_multiplier;
		if (item_multiplier.find(pData->cloth_hand) != item_multiplier.end()) {
			gem_multi += item_multiplier.at(pData->cloth_hand);
		} if (item_multiplier.find(pData->cloth_back) != item_multiplier.end()) {
			gem_multi += item_multiplier.at(pData->cloth_back);
		} if (item_multiplier.find(pData->cloth_necklace) != item_multiplier.end()) {
			gem_multi += item_multiplier.at(pData->cloth_necklace);
		} switch (gem_multi) {
			case 2:
			{
				info = "Double";
				break;
			}
			case 3:
			{
				info = "Triple";
				break;
			}
			case 4:
			{
				info = "Quadruple";
				break;
			}
			case 5:
			{
				info = "Quintuple";
				break;
			}
			case 6:
			{
				info = "Sextuple";
				break;
			}
			case 7:
			{
				info = "Septuple";
				break;
			}
			case 8:
			{
				info = "Octuple";
				break;
			}
			default:
			{
				info = to_string(gem_multi) + "x";
				break;
			}
		}
		buffs += "|\nadd_label_with_icon|small|`w" + info + " Gems``|left|112|";
	}
	if (pData->cloth_back == 9152 || pData->cloth_necklace == 9168 || pData->cloth_back == 9506) {
		if (pData->cloth_necklace == 9168 && pData->cloth_back == 9506) {
			buffs += "|\nadd_label_with_icon|small|`wQuadruple XP``|left|528|";
		}
		else {
			buffs += "|\nadd_label_with_icon|small|`wDouble XP``|left|528|";
		}
	}

	if (pData->cloth_hand == 9494 || pData->cloth_hand == 9510) {
		buffs += "|\nadd_label_with_icon|small|`w3x3 One HIT!``|left|" + to_string(pData->cloth_hand) + "|";
	} 
	if (pData->cloth_hand == 5480 || pData->cloth_hand == 9492) {
		buffs += "|\nadd_label_with_icon|small|`wRayman's 3 far hit!``|left|" + to_string(pData->cloth_hand) + "|";
	}
	if (pData->PunchPotion || pData->cloth_hand == 9520 || pData->cloth_hand == 9512 || pData->cloth_hand == 9496 || pData->cloth_necklace == 6260 || pData->cloth_hand == 2952 || pData->cloth_hand == 9164 || pData->cloth_hand == 9488)
	{
		int display_id = 6918;
		if (pData->cloth_necklace == 6260 && !pData->PunchPotion) display_id = 6260;
		if (pData->cloth_hand == 2952 && !pData->PunchPotion) display_id = 2952;
		if (pData->cloth_hand == 9164 && !pData->PunchPotion) display_id = 9164;
		if (pData->cloth_hand == 9488 && !pData->PunchPotion) display_id = 9488;
		if (pData->cloth_hand == 9496 && !pData->PunchPotion) display_id = 9496;
		if (pData->cloth_hand == 9512 && !pData->PunchPotion) display_id = 9512;
		if (pData->cloth_hand == 9520 && !pData->PunchPotion) display_id = 9520;
		if (pData->PunchPotion) {
			buffs += "|\nadd_label_with_icon|small|`wOne HIT! (`w" + OutputBanTime(calcBanDuration(pData->usedPunchPotion)) + " left`o)``|left|" + to_string(display_id) + "|";
		} else {
			buffs += "|\nadd_label_with_icon|small|`wOne HIT!``|left|" + to_string(display_id) + "|";
		}
	}
	if (pData->PlacePotion || pData->cloth_hair == 4748 || pData->cloth_hair == 4750 || pData->cloth_hair == 4746 || pData->cloth_necklace == 6260 || pData->cloth_hand == 9164)
	{
		int display_id = 6924;
		if (pData->cloth_necklace == 6260 && !pData->PlacePotion) display_id = 6260;
		if (pData->cloth_hand == 9164 && !pData->PlacePotion) display_id = 9164;
		if (pData->cloth_hair == 4746 || pData->cloth_hair == 4748 || pData->cloth_hair == 4750) display_id = pData->cloth_hair;
		if (pData->PlacePotion) {
			buffs += "|\nadd_label_with_icon|small|`wTriple Place! (`w" + OutputBanTime(calcBanDuration(pData->usedPlacePotion)) + " left`o)``|left|" + to_string(display_id) + "|";
		} else {
			buffs += "|\nadd_label_with_icon|small|`wTriple Place!``|left|" + to_string(display_id) + "|";
		}
	}
	if (pData->cloth_hand == 9520 || pData->cloth_necklace == 6260 || pData->cloth_hand == 9496) {
		int display_id = 0;
		if (pData->cloth_necklace == 6260) display_id = 6260;
		if (pData->cloth_hand == 9520) display_id = 9520;
		if (pData->cloth_hand == 9496) display_id = 9496;
		buffs += "|\nadd_label_with_icon|small|`wTriple Break!``|left|" + to_string(display_id) + "|";
	}
	if (pData->cloth_hand == 6840)
	{
		buffs += "|\nadd_label_with_icon|small|`wHarvester!``|left|" + to_string(pData->cloth_hand) + "|";
	}
	if (pData->cloth_back == 5196 || pData->cloth_back == 7558) {
		buffs += "|\nadd_label_with_icon|small|`wFlying and Double jump``|left|" + to_string(pData->cloth_back) + "|";
	}
	else if (pData->canDoubleJump)
	{
		buffs += "|\nadd_label_with_icon|small|`wDouble jump``|left|" + to_string(pData->cloth_back) + "|";
	}
	if (pData->canWalkInBlocks)
	{
		buffs += "|\nadd_label_with_icon|small|`wI can walk in blocks. (Ghost)``|left|3106|";
	}
	if (pData->isinv)
	{
		buffs += "|\nadd_label_with_icon|small|`wNinja, invisible to all!``|left|290|";
	}
	if (buffs == "")
	{
		buffs += "|\nadd_label_with_icon|small|`wYou don't have any active effects!``|left|18|";
	}
	return buffs;
}

inline void splice_seed(ENetPeer* peer, PlayerInfo* pData, WorldInfo* world, const int tile, const int x, const int y, int id) {
	try {
		string splice_message = getItemDef(id).name;
		if (id == 1259) {
			vector<int> random_surg{ 1258, 1260, 1262, 1264, 1266, 1268, 1270, 4308, 4310, 4312, 4314, 4316, 4318 };
			id = random_surg.at(rand() % random_surg.size()) + 1;
			splice_message = "Surgical Tool Tree";
		}
		world->items.at(x + (y * world->width)).spliced = true;
		if (id == 1791) world->items.at(x + (y * world->width)).fruitcount = 1;
		Player::OnTalkBubble(peer, pData->netID, "`w" + getItemDef(world->items.at(x + (y * world->width)).foreground).name + "`` and `w" + getItemDef(tile).name + "`` have been spliced to make a `$" + splice_message + "``!", 0, true);
		Player::PlayAudio(peer, "audio/success.wav", 0);
		world->items.at(x + (y * world->width)).foreground = id;
		int growTimeSeed = getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity * getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity * getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity;
		growTimeSeed += 30 * getItemDef(world->items.at(x + (y * world->width)).foreground - 1).rarity;
		world->items.at(x + (y * world->width)).growtime = (GetCurrentTimeInternalSeconds() + growTimeSeed);
		if (getItemDef(world->items.at(x + (y * world->width)).foreground).rarity == 999) {
			world->items.at(x + (y * world->width)).fruitcount = (rand() % 1) + 1;
		}
		else {
			world->items.at(x + (y * world->width)).fruitcount = (rand() % 3) + 1;
		}
		if (getItemDef(world->items.at(x + (y * world->width)).foreground - 1).blockType == BlockTypes::CLOTHING) world->items.at(x + (y * world->width)).fruitcount = 1;
		UpdateTreeVisuals(peer, world->items.at(x + (y * world->width)).foreground, x, y, world->items.at(x + (y * world->width)).background, world->items.at(x + (y * world->width)).fruitcount, 0, true, 0);
		spray_tree(peer, world, x, y, 18, true);
		RemoveInventoryItem(tile, 1, peer, true);
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

void sendStuffweather(ENetPeer* peer, int x, int y, uint16_t itemid, uint16_t gravity, bool spin, bool invert)
{
	PlayerMoving pmov;
	pmov.packetType = 5;
	pmov.characterState = 8;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = -1;
	uint8_t* pmovpacked = packPlayerMoving(&pmov);
	*(uint32_t*)(pmovpacked + 52) = 10 + 8;
	uint8_t* packet = new uint8_t[4 + 56 + 10 + 8];
	memset(packet, 0, 4 + 56 + 10 + 8);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, 56);
	*(uint16_t*)(packet + 4 + 56) = 3832; // bg machine id
	*(uint16_t*)(packet + 4 + 56 + 6) = 1;
	*(uint8_t*)(packet + 4 + 56 + 8) = 0x31;
	*(uint32_t*)(packet + 4 + 56 + 9) = itemid;
	*(uint32_t*)(packet + 4 + 56 + 13) = gravity;
	*(uint8_t*)(packet + 4 + 56 + 17) = spin | (invert << 1);
	ENetPacket* epacket = enet_packet_create(packet, 4 + 56 + 8 + 10, ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(peer, 0, epacket);

	delete pmovpacked;
	delete[] packet;
}

void sendBackground(ENetPeer* peer, int x, int y, uint16_t itemid)
{
	PlayerMoving pmov;
	pmov.packetType = 5;
	pmov.characterState = 8;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = -1;
	uint8_t* pmovpacked = packPlayerMoving(&pmov);
	*(uint32_t*)(pmovpacked + 52) = 5 + 8;
	uint8_t* packet = new uint8_t[4 + 56 + 5 + 8];
	memset(packet, 0, 4 + 56 + 5 + 8);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, 56);
	*(uint16_t*)(packet + 4 + 56) = 5000; // bg machine id
	*(uint16_t*)(packet + 4 + 56 + 6) = 1;
	*(uint8_t*)(packet + 4 + 56 + 8) = 0x28;
	*(uint16_t*)(packet + 4 + 56 + 9) = itemid;
	ENetPacket* epacket = enet_packet_create(packet, 4 + 56 + 8 + 5, ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(peer, 0, epacket);

	delete pmovpacked;
	delete[] packet;
}

void sendHeatwave(ENetPeer* peer, int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
	PlayerMoving pmov;
	pmov.packetType = 5;
	pmov.characterState = 8;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = -1;
	uint8_t* pmovpacked = packPlayerMoving(&pmov);
	*(uint32_t*)(pmovpacked + 52) = 5 + 8;
	uint8_t* packet = new uint8_t[4 + 56 + 5 + 8];
	memset(packet, 0, 4 + 56 + 5 + 8);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, 56);
	*(uint16_t*)(packet + 4 + 56) = 3694; // heatwave id
	*(uint16_t*)(packet + 4 + 56 + 6) = 1;
	*(uint8_t*)(packet + 4 + 56 + 8) = 0x28;
	*(uint32_t*)(packet + 4 + 56 + 9) = (blue << 24) | (green << 16) | (red << 8);
	ENetPacket* epacket = enet_packet_create(packet, 4 + 56 + 8 + 5, ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(peer, 0, epacket);

	delete pmovpacked;
	delete[] packet;

}

inline void LoadPlayerData(ENetPeer* peer) {
	PlayerInfo* pData = GetPeerData(peer);
	if (pData->haveGrowId && pData->rawName != "") {
		try {
			std::ifstream read_player("save/players/_" + pData->rawName + ".json");
			if (!read_player.is_open()) {
				return;
			}
			json j;
			read_player >> j;
			string email = j["email"];
			int playerid = j["playerid"];
			int ClothBack = j["ClothBack"];
			int ClothHand = j["ClothHand"];
			int ClothFace = j["ClothFace"];
			int ClothShirt = j["ClothShirt"];
			int ClothPants = j["ClothPants"];
			int ClothNeck = j["ClothNeck"];
			int ClothHair = j["ClothHair"];
			int ClothFeet = j["ClothFeet"];
			int ClothMask = j["ClothMask"];
			int ClothAnces = j["ClothAnces"];
			int effect = j["effect"];
			string friends = j["friends"];
			int adminLevel = j["adminLevel"];
			string guild = j["guild"];
			int level = j["level"];
			int xp = j["xp"];
			string worldsowned = j["worldsowned"];
			string notebook = j["notebook"];
			int kills = j["kills"];
			int inventorysize = j["inventorysize"];
			string mac = j["mac"];
			string rid = j["rid"];
			string sid = j["sid"];
			string gid = j["gid"];
			string vid = j["vid"];
			string aid = j["aid"];
			string ip = j["ip"];
			string subtype = j["subtype"];
			string subdate = j["subdate"];
			string title = j["title"];
			int surgeonlevel = j["surgeonlevel"];
			string nick = j["nick"];
			bool invis = j["invis"];
			bool ghost = j["ghost"];
			int skin = j["skin"];
			string chatcolor = j["chatcolor"];
			string lastworld = j["lastworld"];
			int timecursed = j["timecursed"];
			int timemuted = j["timemuted"];
			int surgerycooldown = j["surgerycooldown"];
			string lastnormalworld = j["lastnormalworld"];
			string lastvisitedworlds = j["lastvisitedworlds"];
			json inventory = j["inventory"];
			int firefighterlevel = j["firefighterlevel"];
			int firefighterxp = j["firefighterxp"];
			int providerlevel = j["providerlevel"];
			int providerxp = j["providerxp"];
			int geigercooldown = j["geigercooldown"];
			int geigerlevel = j["geigerlevel"];
			int geigerxp = j["geigerxp"];
			int fishermanlevel = j["fishermanlevel"];
			int fishermanxp = j["fishermanxp"];
			int gbcprogress = j["gbcprogress"];
			int rift_type = j["rift_type"];
			int rift_cape_color = j["rift_cape_color"];
			int rift_cape_r = j["rift_cape_r"];
			int rift_cape_g = j["rift_cape_g"];
			int rift_cape_b = j["rift_cape_b"];
			int rift_collar_color = j["rift_collar_color"];
			int rift_collar_r = j["rift_collar_r"];
			int rift_collar_g = j["rift_collar_g"];
			int rift_collar_b = j["rift_collar_b"];
			bool ltitleunlocked = j["ltitleunlocked"];
			bool ltitle = j["ltitle"];
			bool bluenametitle = j["bluenametitle"];
			string lastquest = j["lquest_info"];
			bool quest_active = j["lquest"];
			int quest_step = j["lquest_step"];
			int quest_progress = j["lquest_progress"];
			int total_punch = j["total_punch"];
			if (subtype != "" && subdate != "" && subtype != "0" && subdate != "0") {
				pData->haveSuperSupporterName = true;
				pData->Subscriber = true;
				pData->SubscribtionEndDay = atoi(subdate.c_str());
			}
			if (timecursed != 0) {
				pData->isCursed = true;
				pData->lastCursed = timecursed;
			}
			if (timemuted != 0) {
				pData->taped = true;
				pData->isDuctaped = true;
				pData->cantsay = true;
				pData->lastMuted = timemuted;
			}
			if (surgerycooldown != 0) {
				pData->SurgeryCooldown = true;
				pData->SurgeryTime = surgerycooldown;
			}
			if (geigercooldown != 0) {
				pData->haveGeigerRadiation = true;
				pData->GeigerCooldown = true;
				pData->GeigerTime = geigercooldown;
			}
			if (mac != pData->mac || rid != pData->rid || sid != pData->sid || gid != pData->gid || vid != pData->vid || aid != pData->aid || ip != pData->charIP) {
				ifstream read_entry("save/players/_" + pData->rawName + ".json");
				json j;
				read_entry >> j;
				read_entry.close();
				j["mac"] = pData->mac;
				j["rid"] = pData->rid;
				j["sid"] = pData->sid;
				j["gid"] = pData->gid;
				j["vid"] = pData->vid;
				j["aid"] = pData->aid;
				j["ip"] = pData->charIP;
				ofstream write_entry("save/players/_" + pData->rawName + ".json");
				write_entry << j << std::endl;
				write_entry.close();
			}
			pData->adminLevel = adminLevel;
			pData->displayName = role_prefix.at(pData->adminLevel) + pData->tankIDName;
			pData->displayNamebackup = role_prefix.at(pData->adminLevel) + pData->tankIDName;
			if (subdate == "\u000e") {
				Player::OnConsoleMessage(peer, "Your subscription time was corrupted, so it was removed to recover message Sebia#1234 details such as how long was your subscription and in game nickname");
				sendSound(peer, "audio/dialog_confirm.wav");
				pData->subdate = "0";
				subdate = "";
				subtype = "";
				enet_peer_disconnect_later(peer, 0);
			}
			else {
				pData->subdate = subdate;
			}
			pData->subtype = subtype;
			if (title != "" && subtype != "" && subdate != "" && subtype != "0" && subdate != "0") {
				pData->NickPrefix = title;
				pData->displayName = title + ". " + pData->tankIDName;
			}
			pData->cloth_back = ClothBack;
			pData->cloth_hand = ClothHand;
			pData->cloth_face = ClothFace;
			pData->cloth_hair = ClothHair;
			pData->cloth_feet = ClothFeet;
			pData->cloth_pants = ClothPants;
			pData->cloth_necklace = ClothNeck;
			pData->cloth_shirt = ClothShirt;
			pData->cloth_mask = ClothMask;
			pData->cloth_ances = ClothAnces;
			pData->guild = guild;
			pData->level = level;
			pData->xp = xp;
			pData->notebook = notebook;
			pData->TotalKills = kills;
			pData->SurgerySkill = surgeonlevel;
			pData->effect = effect;
			pData->lastworld = lastworld;
			pData->lastnormalworld = lastnormalworld;
			pData->email = email;
			pData->firefighterlevel = firefighterlevel;
			pData->firefighterxp = firefighterxp;
			pData->providerlevel = providerlevel;
			pData->providerxp = providerxp;
			pData->geigerlevel = geigerlevel;
			pData->geigerxp = geigerxp;
			pData->playerid = playerid;
			pData->fishermanlevel = fishermanlevel;
			pData->fishermanxp = fishermanxp;
			pData->bootybreaken = gbcprogress;
			pData->registermac = mac;
			pData->registerrid = rid;
			pData->registersid = sid;
			pData->registergid = gid;
			pData->registervid = vid;
			pData->registeraid = aid;
			pData->registerIP = ip;
			pData->ltitleunlocked = ltitleunlocked;
			pData->ltitle = ltitle;
			pData->bluenametitle = bluenametitle;
			pData->lastquest = lastquest;
			pData->quest_active = quest_active;
			pData->quest_step = quest_step;
			pData->quest_progress = quest_progress;
			pData->totalpunch = total_punch;
			pData->rift_type = rift_type;
			pData->rift_cape_color = rift_cape_color;
			pData->rift_collar_color = rift_collar_color;
			pData->rift_cape_r = rift_cape_r;
			pData->rift_cape_g = rift_cape_g;
			pData->rift_cape_b = rift_cape_b;
			pData->rift_collar_r = rift_collar_r;
			pData->rift_collar_g = rift_collar_g;
			pData->rift_collar_b = rift_collar_b;
			if (guild != "") {
				ifstream read_guild("save/guilds/_" + guild + ".json");
				if (!read_guild.is_open()) {
					goto skipguild;
				}
				json js;
				read_guild >> js;
				read_guild.close();
				string guild_leader = js["leader"];
				int guild_foreground = js["foreground"];
				int guild_background = js["background"];
				string read_member = js["members"];
				string guild_name = js["guild_name"];
				pData->guildFg = guild_foreground;
				pData->guildBg = guild_background;
				toUpperCase(guild_leader);
				string player_nick = pData->rawName;
				toUpperCase(player_nick);
				if (guild_leader == player_nick) {
					pData->guild_rank = 3; // leader
				}
				else {
					vector<string> member_array = explode("|", read_member);
					bool found_member = false;
					for (int i = 0; i < member_array.size(); i++) {
						toUpperCase(member_array.at(i));
						if (member_array.at(i) == player_nick) {
							pData->guild_rank = atoi(member_array.at(i + 1).c_str()); /*big hope that it will work*/
							found_member = true;
							break;
						}
					} if (!found_member) {
						pData->guild = "";
						pData->guild_rank = 0;
						pData->guildFg = 0;
						pData->guildBg = 0;
						Player::OnConsoleMessage(peer, "`oWhile you was offline, someone kicked you out of " + guild_name + " guild");
						sendSound(peer, "audio/dialog_confirm.wav");
					}
				}
			}
		skipguild:
			if (pData->cloth_back == 8552) pData->NickPrefix = "`4Dr";
			stringstream ssf(friends);
			while (ssf.good()) {
				string substr;
				getline(ssf, substr, ',');
				if (substr.size() == 0) continue;
				pData->friendinfo.push_back(substr);
			}
			stringstream ssfs(worldsowned);
			while (ssfs.good()) {
				string substr;
				getline(ssfs, substr, ',');
				if (substr.size() == 0) continue;
				pData->worldsowned.push_back(substr);
			}
			if (lastvisitedworlds != "") {
				vector<string> infoDats = explode("|", lastvisitedworlds);
				for (auto i = 0; i < infoDats.size(); i++) {
					if (find(pData->lastworlds.begin(), pData->lastworlds.end(), infoDats.at(i)) == pData->lastworlds.end()) {
						pData->lastworlds.push_back(infoDats.at(i));
					}
				}
			}
			if (skin != 2190853119) pData->skinColor = skin;
			if (isMod(peer) || pData->Subscriber) {
				pData->isinv = invis;
				if (chatcolor != "" && pData->Subscriber) {
					pData->chatcolor = chatcolor;
				}
			}
			if (nick != "") {
				pData->isNicked = true;
				if (pData->NickPrefix != "") {
					pData->displayName = pData->NickPrefix + ". " + nick;
				}
				else {
					pData->displayName = nick;
				}
				pData->OriName = nick;
			}
			pData->canWalkInBlocks = ghost;
			pData->currentInventorySize = inventorysize;
			updateAllClothes(peer);
			PlayerInventory inventory_data;
			{
				InventoryItem item{};
				for (int i = 0; i < pData->currentInventorySize; i++) {
					int itemid = inventory["items"].at(i)["itemid"];
					int quantity = inventory["items"].at(i)["quantity"];
					if (itemid != 0 && quantity != 0) {
						item.itemCount = quantity;
						item.itemID = itemid;
						inventory_data.items.push_back(item);
					}
				}
			}
			SendInventory(peer, inventory_data);
			pData->inventory = inventory_data;
			if (pData->isDuctaped) sendClothes(peer);
			if (!isMod(peer) && pData->isinv) pData->isinv = false;
			if (!isMod(peer) && !pData->Subscriber && pData->canWalkInBlocks) pData->canWalkInBlocks = false;
			DailyRewardCheck(peer);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			enet_peer_disconnect_now(peer, 0);
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what() << std::endl;
			enet_peer_disconnect_now(peer, 0);
		}
	}
}

inline void send_quest_view(ENetPeer* peer, PlayerInfo* pData, WorldInfo* world) {
	if (!pData->quest_active) return;
	try {
		int x = pData->lastPunchX;
		int y = pData->lastPunchY;
		pData->choosing_quest = "";
		if (isWorldOwner(peer, world) || isWorldAdmin(peer, world) || isDev(peer) || world->owner == "" || !restricted_area(peer, world, x, y) || world->items.at(x + (y * world->width)).foreground == 1790) {
			if (pData->lastquest == "honor") {
				string step = to_string(pData->quest_step);
				string quest_info = "";
				string current_progress = "";
				string deliver = "";
				string extra = "";
				switch (pData->quest_step) {
					case 1:
					{
						quest_info = "I challenge you to bring me 2,000 of those Sand thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/2,000)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 442 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 2000) KiekTuri = 2000 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Sand";
						}
						break;
					}
					case 2:
					{
						quest_info = "Prove your might by defeating 100 Growtopians in single combat! You can battle them in Games or in Deathmatch events.";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/100)";
						deliver = "You have not proven your might!";
						if (pData->quest_progress >= 100) {
							deliver = "I am the champion!";
						}
						break;
					}
					case 3:
					{
						quest_info = "You must defeat 5,000 blocks in battle!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/5,000)";
						deliver = "You are not yet worthy!";
						if (pData->quest_progress >= 5000) {
							deliver = "I have slain them all!";
						}
						break;
					}
					case 4:
					{
						quest_info = "I challenge you to bring me 600 of those Display Box thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/600)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1422 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 600) KiekTuri = 600 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Display Box";
						}
						break;
					}
					case 5:
					{
						quest_info = "You must plant 50,000 rarity worth of trees! Bring life to this land!";
						extra = "\nadd_label|small|`o(For example, if you plant a tree of rarity 50, you get 50 points. A Dirt Tree is 1 point because it is rarity 1)|left|";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/50,000)";
						deliver = "I will go plant more!";
						if (pData->quest_progress >= 50000) {
							deliver = "I have planted them all!";
						}
						break;
					}
					case 6:
					{
						quest_info = "Prove your skill! Earn 50 Growtokens in whatever way you want! You can keep the Growtokens, I'm not a greedy wizard.";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/50)";
						deliver = "I will quest onward!";
						if (pData->quest_progress >= 50) {
							deliver = "I am talented!";
						}
						break;
					}
					case 7:
					{
						quest_info = "I challenge you to bring me 3 of those Golden Diaper thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/3)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1462 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 3) KiekTuri = 3 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Golden Diaper";
						}
						break;
					}
					case 8:
					{
						quest_info = "Here's a freeform quest for you - I don't care what you do, just earn 10,000 XP doing it!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/10,000)";
						deliver = "I'm on my way!";
						if (pData->quest_progress >= 10000) {
							deliver = "I have learned!";
						}
						break;
					}
					case 9:
					{
						quest_info = "I challenge you to bring me 800 of those Tombstone thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/800)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 784 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 800) KiekTuri = 800 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Tombstone";
						}
						break;
					}
					case 10:
					{
						quest_info = "Look, it's not cheap being a Legendary Wizard. These aren't just purple robes, they're `9Legendary Purple Robes`o! So if you could just spot me like 100,000 Gems, I swear I'll think about paying you back. I'll think hard. Whaddya say?";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/100,000)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						std::ifstream ifsz("save/gemdb/_" + pData->rawName + ".txt");
						std::string content((std::istreambuf_iterator<char>(ifsz)), (std::istreambuf_iterator<char>()));
						KiekTuri = atoi(content.c_str());
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 100000) KiekTuri = 100000 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Gems";
						}
						break;
					}
					case 11:
					{
						quest_info = "You must crush 100,000 rarity worth of blocks! Destroy!";
						extra = "\nadd_label|small|`o(For example, if you smash a block of rarity 50, you get 50 points. A dirt block is 1 point because it is rarity 1)|left|";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/100,000)";
						deliver = "I will go smash more!";
						if (pData->quest_progress >= 100000) {
							deliver = "No block can beat me!";
						}
						break;
					}
					case 12:
					{
						quest_info = "Do some good for the world. Save 100 ailing Growtopians by performing surgery!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/100)";
						deliver = "You haven't helped enough!";
						if (pData->quest_progress >= 100) {
							deliver = "Saving lives is what I do";
						}
						break;
					}
					case 13:
					{
						quest_info = "I need you to pick up some groceries for me. Collect 1,000 items from Providers.";
						extra = "\nadd_label|small|`o(Providers are items like Science Stations and Cows, that give you an item on a regular basis)|left|";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/1,000)";
						deliver = "I'm on my way!";
						if (pData->quest_progress >= 1000) {
							deliver = "I'm a cow-puncher!";
						}
						break;
					}
					case 14:
					{
						quest_info = "I challenge you to bring me 3 of those Golden Heart Crystal thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/3)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1458 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 3) KiekTuri = 3 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Golden Heart Crystal";
						}
						break;
					}
					case 15:
					{
						quest_info = "You must pluck 100,000 rarity worth of delicious fruit from any tree! I don't want the fruit, I'm just mad that it's up there!";
						extra = "\nadd_label|small|`o(For example, if you smash a rarity 50 tree and get 3 fruit from it, you will get 150 points)|left|";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/100,000)";
						deliver = "I will go pick fruit!";
						if (pData->quest_progress >= 100000) {
							deliver = "The fruit is no more!";
						}
						break;
					}
					case 16:
					{
						quest_info = "I challenge you to bring me 1 of those Growie Award thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/1)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1614 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 1) KiekTuri = 1 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Growie Award";
						}
						break;
					}
					case 17:
					{
						quest_info = "I challenge you to bring me 3 of those Super Firework thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/3)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1680 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 3) KiekTuri = 3 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Super Firework";
						}
						break;
					}
					case 18:
					{
						quest_info = "I challenge you to bring me 3 of those Rainbow Wings thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/3)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1672 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 3) KiekTuri = 3 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Rainbow Wings";
						}
						break;
					}
					case 19:
					{
						quest_info = "I challenge you to bring me 3 of those Birth Certificate thingies!";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/3)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1280 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 3) KiekTuri = 3 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Birth Certificate";
						}
						break;
					}
					case 20:
					{
						quest_info = "And finally, i dare you to ascend to the peak of LEGENDARYMOUNTAIN and collect a Legendary Orb. This is the final challenge in any truly legendary quest.";
						current_progress = "(Current progress " + to_string(pData->quest_progress) + "/1)";
						deliver = "You have none to deliver!";
						auto KiekTuri = 0;
						for (auto i = 0; i < pData->inventory.items.size(); i++) {
							if (pData->inventory.items.at(i).itemID == 1794 && pData->inventory.items.at(i).itemCount > 0) {
								KiekTuri = pData->inventory.items.at(i).itemCount;
								break;
							}
						}
						if (KiekTuri != 0) {
							if (pData->quest_progress + KiekTuri > 1) KiekTuri = 1 - pData->quest_progress;
							deliver = "Deliver " + to_string(KiekTuri) + " Legendary Orb";
						}
						break;
					}
				}
				Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`9Quest For Honor``|left|1790|\nadd_textbox|`o(Step " + step + "/20)``|\nadd_spacer|small|\nadd_textbox|`o" + quest_info + "``|" + extra + "\nadd_spacer|small|\nadd_textbox|`o" + current_progress + "``|\nadd_button|deliver|`o" + deliver + "|noflags|0|0|\nadd_button|give_up|`oGive up this quest|noflags|0|0|\nend_dialog|legendary_wizard|Goodbye!||");
			}
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

inline void send_info(ENetPeer* peer, PlayerInfo* pData) {
	string buffs = get_player_buffs(pData);
	int levels = pData->level;
	int xp = pData->xp;
	string currentworld = pData->currentWorld;
	int xxx = pData->x / 32;
	int yyy = pData->y / 32;
	string joinguilddialog = "";
	string rift_cape = "";
	if (pData->isinvited == true) {
		joinguilddialog = "\nadd_button|joinguild|`2Join Guild " + pData->guildlast + "!|";
	}
	if (pData->cloth_back == 10424) {
		rift_cape += "\nadd_button|rift_cape_edit|`$Rift Cape``|noflags|0|0|";
	}
	Player::OnDialogRequest(peer, "set_default_color|`o\n\nadd_player_info|" + pData->displayName + "|" + std::to_string(levels) + "|" + std::to_string(xp) + "|" + to_string(pData->level * 1500) + "|\nadd_spacer|small|" + joinguilddialog + "|" + rift_cape + "\nadd_button|view_guide|`$Guide``|\nadd_button|change_password|`$Change password``|\nadd_button|manage_title|`$Title``|\nadd_button|manage_audio|`$Audio``|\nadd_button|notebook_edit|`$Notebook``|\nadd_button|goals|`$Goals & Quests``|noflags|0|0|\nadd_button|worlds_view|`$My Worlds``|\nadd_spacer|small|\nadd_textbox|`wActive effects:``|left|" + buffs + "|\nadd_spacer|small|\nadd_textbox|`oYou have `w" + to_string(pData->currentInventorySize) + "`` `obackpack slots.``|left|\nadd_textbox|`oYou have `w" + to_string(pData->TotalKills) + "`` `ototal kills.``|left|\nadd_spacer|small|\nadd_textbox|`oCurrent world: `w" + currentworld + " `o(`w" + std::to_string(xxx) + "`o, `w" + std::to_string(yyy) + "`o)|left|\nadd_spacer|small|\nadd_button|chc0|`wContinue|noflags|0|0|\n\nadd_quick_exit|\nnend_dialog|gazette||OK|");
}

bool has_permission(int adminLevel, string str, bool subscriber) {
	try {
		string cmd = explode(" ", str).at(0);
		size_t pos;
		while ((pos = cmd.find("/")) != std::string::npos) {
			cmd.replace(pos, 1, "");
		}
		if (std::find(role_commands.at(adminLevel).begin(), role_commands.at(adminLevel).end(), cmd) != role_commands.at(adminLevel).end()) {
			return true;
		}
		if (subscriber && std::find(sub_commands.begin(), sub_commands.end(), cmd) != sub_commands.end()) {
			return true;
		}
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	return false;
}

void sendDShelf(ENetPeer* peer, int x, int y, int item1, int item2, int item3, int item4)
{
	PlayerMoving pmov;
	pmov.packetType = 5;
	pmov.characterState = 8;
	pmov.punchX = x;
	pmov.punchY = y;
	pmov.netID = -1;
	uint8_t* pmovpacked = packPlayerMoving(&pmov);
	*(uint32_t*)(pmovpacked + 52) = 8 + 16;
	uint8_t* packet = new uint8_t[4 + 56 + 8 + 16];
	memset(packet, 0, 4 + 56 + 8 + 16);
	packet[0] = 4;
	memcpy(packet + 4, pmovpacked, 56);
	*(uint16_t*)(packet + 4 + 56) = 3794; // display shelf id
	*(uint16_t*)(packet + 4 + 56 + 6) = 1;
	*(uint8_t*)(packet + 4 + 56 + 8) = 0x2B;
	*(int*)(packet + 4 + 56 + 9 + 0 * 4) = item1;
	*(int*)(packet + 4 + 56 + 9 + 1 * 4) = item2;
	*(int*)(packet + 4 + 56 + 9 + 2 * 4) = item3;
	*(int*)(packet + 4 + 56 + 9 + 3 * 4) = item4;
	ENetPacket* epacket = enet_packet_create(packet, 4 + 56 + 8 + 16, ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(peer, 0, epacket);

	delete pmovpacked;
	delete packet;
}

inline void send_ban_panel(ENetPeer* peer, string extra) {
	PlayerInfo* pData = GetPeerData(peer);
	if (extra != "") extra += "<CR>";
	Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`!Banning Panel``|left|32|\nadd_textbox|`!User: " + pData->lastInfo + "<CR>" + extra + "`rKeep in mind! Applying a ban more or equal to 730 days equals as a suspension (permanent ban) for user slowlyrise.<CR>`!Choose the ban amount and write the reason.|\nadd_text_input|days|`oDays:|" + to_string(pData->last_ban_days) + "|9|\nadd_text_input|hours|`oHours:|" + to_string(pData->last_ban_hours) + "|9|\nadd_text_input|minutes|`oMinutes:|" + to_string(pData->last_ban_minutes) + "|9|\nadd_spacer|small|\nadd_text_input|reason|`!Reason:|" + pData->last_ban_reason + "|30|\nend_dialog|ban_panel|Cancel|`4BAN|");
}

inline void send_mute_panel(ENetPeer* peer, string extra) {
	PlayerInfo* pData = GetPeerData(peer);
	if (extra != "") extra += "<CR>";
	Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`!Muting Panel``|left|32|\nadd_textbox|`!User: " + pData->lastInfo + "<CR>" + extra + "`r<CR>`!Choose the mute amount and write the reason.|\nadd_text_input|days|`oDays:|" + to_string(pData->last_ban_days) + "|9|\nadd_text_input|hours|`oHours:|" + to_string(pData->last_ban_hours) + "|9|\nadd_text_input|minutes|`oMinutes:|" + to_string(pData->last_ban_minutes) + "|9|\nadd_spacer|small|\nadd_text_input|reason|`!Reason:|" + pData->last_ban_reason + "|30|\nend_dialog|mute_panel|Cancel|`4MUTE|");
}

inline void send_curse_panel(ENetPeer* peer, string extra) {
	PlayerInfo* pData = GetPeerData(peer);
	if (extra != "") extra += "<CR>";
	Player::OnDialogRequest(peer, "set_default_color|`o\nadd_label_with_icon|big|`!Cursing Panel``|left|32|\nadd_textbox|`!User: " + pData->lastInfo + "<CR>" + extra + "`r<CR>`!Choose the curse amount and write the reason.|\nadd_text_input|days|`oDays:|" + to_string(pData->last_ban_days) + "|9|\nadd_text_input|hours|`oHours:|" + to_string(pData->last_ban_hours) + "|9|\nadd_text_input|minutes|`oMinutes:|" + to_string(pData->last_ban_minutes) + "|9|\nadd_spacer|small|\nadd_text_input|reason|`!Reason:|" + pData->last_ban_reason + "|30|\nend_dialog|curse_panel|Cancel|`4CURSE|");
}
