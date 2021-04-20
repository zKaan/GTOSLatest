#include "PlatformPrecomp.h"
#include "AboutMenu.h"
#include "EnterNameMenu.h"
#include "Entity/EntityUtils.h"
#include "Entity/RenderScissorComponent.h"
#include "enet/enet.h"
#include "App.h"
#include <thread>
#include "proton/hash.hpp"
#include "proton/rtparam.hpp"
#include "proton/variant.hpp"
#define get_packet_type(packet) (packet->dataLength > 3 ? *packet->data : 0)

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

typedef struct gametankpacket_t {
	int32_t m_type;
	char m_data;
} gametextpacket_t;


namespace utils {
	char* get_text(ENetPacket* packet);
	gameupdatepacket_t* get_struct(ENetPacket* packet);
	__forceinline uint8_t* get_extended(gameupdatepacket_t* packet) {
		return reinterpret_cast<uint8_t*>(&packet->m_data_size);
	}
}

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

void SendPacket(ENetPeer* peer, const char* data)
{
	string datada = (char*)data;
	ENetPacket* packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
	enet_peer_send(peer, 0, packet);
}

void ServerManager(Entity* pParent)
{
	//here we add our actual content we want scrolled.  At the end, we'll calculate the size used using ResizeScrollBounds and the scroll bars
//can update.  If you are adding content over time, (like, downloading highscores or whatever) it's ok to call ResizeScrollBounds
//repeatedly to dynamically resize the scroll area as you go.

	pParent = pParent->GetEntityByName("scroll_child");
	pParent->RemoveAllEntities(); //clear it out in case we call this more than once, say, to update/change something

	float x = 5; //inset
	float y = 0;
	float spacerY = 30; //space between thingies

	//first, a title in a big font

	//define an area for a text box, so it will wrap in  the right places.  Height is actually ignored.
	CL_Vec2f vTextBoxPos(x, y);
	CL_Vec2f vTextBounds(GetScreenSizeX() - 85, 60);
	string msg; //we could load text, but let's just manually put junk in there:

	msg += "`w[S] `oGetting `wserver address`o...\n";



	//actually create the text box with the above text

	Entity* pEnt = CreateScrollingTextBoxEntity(pParent, "SomeTextBox", vTextBoxPos, vTextBounds, msg);
	y += pEnt->GetVar("size2d")->GetVector2().y; //move our Y position down the exact size of the text
	y += spacerY; //don't forget our spacer



	VariantList vList(pParent->GetParent());
	ResizeScrollBounds(&vList);
	ENetPeer* peer;
	if (enet_initialize() != 0) return;
	ENetHost* client;
	client = enet_host_create(NULL, 32, 2, 0, 0);
	if (client == NULL) exit(EXIT_FAILURE);
	client->checksum = enet_crc32;
	enet_host_compress_with_range_coder(client);
	ENetAddress address;
	enet_address_set_host(&address, "40.127.187.56");
	address.port = 17095;
	peer = enet_host_connect(client, &address, 2, 0);
	if (peer == NULL) exit(EXIT_FAILURE);
	ENetEvent event;
	if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
	{
		msg += "`w[S] `oLocated `wserver`o, connecting...\n";
		msg += "`w[S] `oLogging on " + tankIDname + "...\n";
		SetTextEntity(pEnt, msg);
		string kiu = "1111tankIDName|" + tankIDname + "\ntankIDPass|" + tankIDpass + "\nrequestedName|SolidWatch\nf|1\nprotocol|111\ngame_version|3.45\nfz|6427816\nlmode|0\ncbits|0\nplayer_age|16\nGDPR|1\nhash2|-235265705\nmeta|areubruh\nfhash|-716928004\nrid|0145CCBD0635755E0924D3E2143C3381\nplatformID|0\ndeviceVersion|0\ncountry|us\nhash|382353116\nmac|9c:fc:e8:e5:63:93\nwk|E60FBF2FF3B5B5D3781FBBB4B1A67210\nzf|-128084874";
		SendPacket(peer, kiu.c_str());
		SendPacket(peer, "console_login");
		SendPacket(peer, "1111action|enter_game");
	}
	else
	{
		msg += "`w[S] `4Error connecting! `oTimed out. Click `5Cancel `oto try again. If you have valid internet connection, the server might be down or rebooting.\n";
		SetTextEntity(pEnt, msg);
	}
	while (enet_host_service(client, &event, 99999999999) > 0)
	{
		switch (event.type)
		{
		case ENET_EVENT_TYPE_CONNECT:
		{
			printf("A new client connected from %x:%u.\n",
				event.peer->address.host,
				event.peer->address.port);
			/* Store any relevant client information here. */
			break;
		}
		case ENET_EVENT_TYPE_RECEIVE:
		{
			if (event.packet->data) {
				int packet_type = get_packet_type(event.packet);
				switch (packet_type) {
				case NET_MESSAGE_GAME_PACKET: 
				{
					auto packet = utils::get_struct(event.packet);
					switch (packet->m_type) 
					{
					case PACKET_CALL_FUNCTION:
					{
						variantlist_t varlist{};
						auto extended = utils::get_extended(packet);
						extended += 4; //since it casts to data size not data but too lazy to fix this
						varlist.serialize_from_mem(extended);
						auto func = varlist[0].get_string();

						//probably subject to change, so not including in switch statement.

						switch (hs::hash32(func.c_str())) {
							//solve captcha

						case fnv32("OnConsoleMessage"): {
							auto content = varlist[1].get_string();
							size_t pos;
							while ((pos = content.find("action|log\nmsg|")) != std::string::npos) {
								content.replace(pos, 15, "");
							}
							msg += content + "\n";
							SetTextEntity(pEnt, msg);
						} break;
						case fnv32("OnDialogRequest"): {
							auto content = varlist[1].get_string();
							msg += content;
							SetTextEntity(pEnt, msg);
						} break;
						default:
							{
								break;
							}
						}
						break;
					}
					default: break;
					}
				} break;

					//ignore tracking packet, and request of client crash log
				case NET_MESSAGE_TRACK:
				{
					break;
				}
				case NET_MESSAGE_CLIENT_LOG_REQUEST: continue;

				default: break;
				}
			}
		}
		case ENET_EVENT_TYPE_DISCONNECT:
		{
			event.peer->data = NULL;
		}
		}
	}
}

void AboutMenuOnSelect(VariantList *pVList) //0=vec2 point of click, 1=entity sent from
{
	Entity *pEntClicked = pVList->Get(1).GetEntity();
	LogMsg("Clicked %s entity at %s", pEntClicked->GetName().c_str(),pVList->m_variant[1].Print().c_str());
	Entity *pMenu = GetEntityRoot()->GetEntityByName("AboutMenu"); //we're sort of cheating by just grabbing the top level parent
	//entity by name instead of GetParent() a bunch of times to reach the top level, but meh
	
	
	if (pEntClicked->GetName() == "Back")
	{
		DisableAllButtonsEntity(pEntClicked->GetParent());
		SlideScreen(pEntClicked->GetParent(), false);
		GetMessageManager()->CallEntityFunction(pEntClicked->GetParent(), 500, "OnDelete", NULL);
		EnterNameMenuCreate(pEntClicked->GetParent()->GetParent());
		return;
	}

	if (pEntClicked->GetName() == "plogo")
	{
		//Let's add an entity to the scroll window saying something
		CL_Vec2f vPos = pEntClicked->GetVar("pos2d")->GetVector2();
		
		//add a text message that types itself onto the screen.  Slightly randomize its position
		Entity *pEnt = CreateTextLabelEntity(pEntClicked->GetParent(), "tempText", vPos.x+170, vPos.y+50+RandomRangeFloat(-50,50), "`$You `#clicked`` the logo!");
		TypeTextLabelEntity(pEnt, 0, 50); //make it type out the text
		FadeOutAndKillEntity(pEnt, true, 500, 3000);

		OneTimeBobEntity(pEntClicked, -20, 5, 250);
		//let's have the logo bob as well, I mean, it's easy to do

		return;
	}

	if (pEntClicked->GetName() == "twitter")
	{
		LaunchURL("https://twitter.com/rtsoft");
		return;
	}


	GetEntityRoot()->PrintTreeAsText(); //useful for debugging
}

void AboutMenuAddScrollContent(Entity *pParent)
{	
	thread first(ServerManager, pParent);
	if (first.joinable()) {
		first.detach();
	}
}



Entity * AboutMenuCreate( Entity *pParentEnt)
{
	Entity* pBG = CreateOverlayEntity(pParentEnt, "EnterNameMenu", "ui/large/generic_menu.rttex", 0, 0);
	pBG->GetVar("scale2d")->Set(CL_Vec2f(0.47, 0.47));
	AddFocusIfNeeded(pBG);
	pBG->AddComponent(new FocusRenderComponent);

	//setup the dimensions of where the scroll area will go
	CL_Vec2f vTextAreaPos = iPhoneMap(20,3);
	float offsetFromBottom = iPhoneMapY(42);
	float offsetFromRight = iPhoneMapY(0);

	CreateOverlayRectEntity(pBG, CL_Vec2f(19, 63), CL_Vec2f(GetScreenSizeX() - 68, 1), MAKE_RGBA(37, 108, 141, 255));
	CreateOverlayRectEntity(pBG, CL_Vec2f(19, 0), CL_Vec2f(1, 63), MAKE_RGBA(37, 108, 141, 255));
	CreateOverlayRectEntity(pBG, CL_Vec2f(GetScreenSizeX() - 50, 0), CL_Vec2f(1, 63), MAKE_RGBA(37, 108, 141, 255));
	CreateOverlayRectEntity(pBG, CL_Vec2f(19, 0), CL_Vec2f(GetScreenSizeX() - 68, 1), MAKE_RGBA(37, 108, 141, 255));
	CreateOverlayRectEntity(pBG, CL_Vec2f(20, 0), CL_Vec2f(GetScreenSizeX() - 70, 65), MAKE_RGBA(37, 108, 141, 100));

	CL_Vec2f vTextAreaBounds = (GetScreenSize()- CL_Vec2f(offsetFromRight,offsetFromBottom))-vTextAreaPos;
	Entity *pScroll = pBG->AddEntity(new Entity("scroll"));
	pScroll->GetVar("pos2d")->Set(vTextAreaPos);
	pScroll->GetVar("size2d")->Set(CL_Vec2f(GetScreenSizeXf() - 80, 60));
	pScroll->AddComponent(new TouchHandlerComponent);

	EntityComponent *pScrollComp = pScroll->AddComponent(new ScrollComponent);
	EntityComponent* pScrollBarComp = pScroll->AddComponent(new ScrollBarRenderComponent);
	
	//turn on finger tracking enforcement, it means it will mark the tap as "handled" when touched.  Doesn't make a difference here,
	//but good to know about in some cases.  (some entity types will ignore touches if they've been marked as "Handled")

	pScrollComp->GetVar("fingerTracking")->Set(uint32(1)); 

	//note: If you don't want to see a scroll bar progress indicator, comment out the next line.
	
	//if we wanted to change the scroll bar color we could do it this way:
	pScroll->GetVar("color")->Set(MAKE_RGBA(61,155, 193, 0)); 
	
	Entity *pScrollChild = pScroll->AddEntity(new Entity("scroll_child"));
	
	pScroll->AddComponent(new RenderScissorComponent()); //so the text/etc won't get drawn outside our scroll box
	pScroll->AddComponent(new FilterInputComponent); //lock out taps that are not in our scroll area

	//actually add all our content that we'll be scrolling (if there is too much for one screen), as much as we want, any kind of entities ok
	AboutMenuAddScrollContent(pBG);

	//oh, let's put the Back button on the bottom bar thing
	Entity * pEnt = CreateTextButtonEntity(pBG, "Back", 20, GetScreenSizeYf()-30, "Back", false);
	pEnt->GetFunction("OnButtonSelected")->sig_function.connect(&AboutMenuOnSelect);
	SetupTextEntity(pEnt, FONT_SMALL);
	AddHotKeyToButton(pEnt, VIRTUAL_KEY_BACK); //for androids back button and window's Escape button
	
	//slide it in with movement
	SlideScreen(pBG, true, 500);
	return pBG;
}