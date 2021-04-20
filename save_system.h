#pragma once


inline void save_manager() {
	while (true) {
		Sleep(60000); 
		global_loop_tick++;
		if (global_loop_tick >= 6) {
			threads.push_back(std::thread(WorldEvents));
			global_loop_tick = 0;
		}
		LoadEvents();
		for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
			if (currentPeer->state != ENET_PEER_STATE_CONNECTED || currentPeer->data == NULL) continue;
			if (!static_cast<PlayerInfo*>(currentPeer->data)->haveGrowId || static_cast<PlayerInfo*>(currentPeer->data)->currentWorld == "EXIT" || !static_cast<PlayerInfo*>(currentPeer->data)->isIn) continue;
			if (static_cast<PlayerInfo*>(currentPeer->data)->isCursed) {
				auto cooldownleft = calcBanDuration(static_cast<PlayerInfo*>(currentPeer->data)->lastCursed);
				if (cooldownleft < 1) {
					Player::OnConsoleMessage(currentPeer, "You are no longer bound to the netherworld, you're free to go. (`$Curse ``mod removed)");
					static_cast<PlayerInfo*>(currentPeer->data)->skinColor = 0x8295C3FF;
					sendClothes(currentPeer);
					static_cast<PlayerInfo*>(currentPeer->data)->isCursed = false;
					send_state(currentPeer);
					static_cast<PlayerInfo*>(currentPeer->data)->lastCursed = 0;
				}
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->Fishing && !static_cast<PlayerInfo*>(currentPeer->data)->TriggerFish && static_cast<PlayerInfo*>(currentPeer->data)->FishPosX != 0 && static_cast<PlayerInfo*>(currentPeer->data)->FishPosY != 0) {
				if (rand() % 100 <= 50) {
					static_cast<PlayerInfo*>(currentPeer->data)->TriggerFish = true;
					for (auto currentPeers = server->peers; currentPeers < &server->peers[server->peerCount]; ++currentPeers) {
						if (currentPeers->state != ENET_PEER_STATE_CONNECTED) continue;
						if (isHere(currentPeer, currentPeers))  {
							Player::OnParticleEffect(currentPeers, 36, static_cast<PlayerInfo*>(currentPeer->data)->FishPosX, static_cast<PlayerInfo*>(currentPeer->data)->FishPosY, 0);
							Player::PlayAudio(currentPeers, "audio/splash.wav", 0);
						}
					}
				}
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->isDuctaped) {
				auto cooldownleft = calcBanDuration(static_cast<PlayerInfo*>(currentPeer->data)->lastMuted);
				if (cooldownleft < 1) {
					Player::OnConsoleMessage(currentPeer, "You've free to talk again! (`$Muted`` mod removed)");
					static_cast<PlayerInfo*>(currentPeer->data)->taped = false;
					static_cast<PlayerInfo*>(currentPeer->data)->isDuctaped = false;
					static_cast<PlayerInfo*>(currentPeer->data)->cantsay = false;
					static_cast<PlayerInfo*>(currentPeer->data)->lastMuted = 0;
					send_state(currentPeer);
					sendClothes(currentPeer);
				}
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->SurgeryCooldown) {
				auto cooldownleft = calcBanDuration(static_cast<PlayerInfo*>(currentPeer->data)->SurgeryTime);
				if (cooldownleft < 1) {
					Player::OnConsoleMessage(currentPeer, "You've paid your debt to society! (`$Malpractice`` mod removed)");
					sendSound(currentPeer, "audio/dialog_confirm.wav");
					static_cast<PlayerInfo*>(currentPeer->data)->SurgeryCooldown = false;
					static_cast<PlayerInfo*>(currentPeer->data)->SurgeryTime = 0;
				}
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->PunchPotion) {
				auto cooldownleft = calcBanDuration(static_cast<PlayerInfo*>(currentPeer->data)->usedPunchPotion);
				if (cooldownleft < 1) {
					Player::OnConsoleMessage(currentPeer, "You feel weak again. (`$One HIT `omod removed)");
					sendSound(currentPeer, "audio/dialog_confirm.wav");
					static_cast<PlayerInfo*>(currentPeer->data)->PunchPotion = false;
					static_cast<PlayerInfo*>(currentPeer->data)->usedPunchPotion = 0;
				}
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->PlacePotion) {
				auto cooldownleft = calcBanDuration(static_cast<PlayerInfo*>(currentPeer->data)->usedPlacePotion);
				if (cooldownleft < 1) {
					Player::OnConsoleMessage(currentPeer, "Your hands shrinks again. (`$Triple Place `omod removed)");
					sendSound(currentPeer, "audio/dialog_confirm.wav");
					static_cast<PlayerInfo*>(currentPeer->data)->PlacePotion = false;
					static_cast<PlayerInfo*>(currentPeer->data)->usedPlacePotion = 0;
				}
			}
			if (static_cast<PlayerInfo*>(currentPeer->data)->GeigerCooldown) {
				auto cooldownleft = calcBanDuration(static_cast<PlayerInfo*>(currentPeer->data)->GeigerTime);
				if (cooldownleft < 1) {
					Player::OnConsoleMessage(currentPeer, "You've no longer radioactive! (`$Irradiated`` mod removed)");
					sendSound(currentPeer, "audio/dialog_confirm.wav");
					if (static_cast<PlayerInfo*>(currentPeer->data)->cloth_necklace != 4656) {
						static_cast<PlayerInfo*>(currentPeer->data)->haveGeigerRadiation = false;
						send_state(currentPeer);
					}
					static_cast<PlayerInfo*>(currentPeer->data)->GeigerCooldown = false;
					static_cast<PlayerInfo*>(currentPeer->data)->GeigerTime = 0;
				}
			}
			save_playerinfo(static_cast<PlayerInfo*>(currentPeer->data));
		} try {
			for (int i = 0; i < worlds.size(); i++) {
				if (worlds.at(i).name != "EXIT" && worlds.at(i).name != "error") {
					try {
						WorldInfo info = worlds.at(i);
						if (info.saved) continue;
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
						info.saved = true;
					}
					catch (const std::out_of_range& e) {
						std::cout << e.what() << std::endl;
					}
					catch (std::exception& e) {
						cout << e.what() << endl;
					}
				}
			}
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what() << std::endl;
		} if (GlobalMaintenance) {
			SendConsole("Worlds are now saved! server shutted down as requested by one player", "INFO");
			system("PAUSE");
			exit(0);
		}
	}
}
