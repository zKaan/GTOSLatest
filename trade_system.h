#pragma once

string FormatTradeItems(vector<TradeItem> tradeItems)
{
	string fmt = "";
	for (auto& t : tradeItems)
	{
		fmt += "add_slot|" + to_string(t.id) + "|" + to_string(t.count) + "\n";
	}
	return fmt;
}

void update_trade(ENetPeer* peer, int userID, bool silent = false) {
	PlayerInfo* pData = GetPeerData(peer);
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer)) {
			if (pData->trade_netid == static_cast<PlayerInfo*>(currentPeer->data)->netID || pData->netID == static_cast<PlayerInfo*>(currentPeer->data)->trade_netid) {
				Player::OnTradeStatus(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->netID, "`oSelect an item from the inventory.``", "", FormatTradeItems(static_cast<PlayerInfo*>(currentPeer->data)->tradeItems) + "\nlocked|0\nreset_locks|1\naccepted|0\n");
				Player::OnTradeStatus(currentPeer, pData->netID, "`o" + pData->displayName + "`o's offer.``", "", FormatTradeItems(pData->tradeItems) + "\nlocked|0\nreset_locks|1\naccepted|0\n");
				if (!silent) if (static_cast<PlayerInfo*>(currentPeer->data)->trade) Player::OnTextOverlay(currentPeer, "The deal has changed");
				Player::OnTradeStatus(peer, pData->netID, "`o" + pData->displayName + "`oSelect an item from the inventory.``", "", FormatTradeItems(pData->tradeItems) + "\nlocked|0\nreset_locks|1\naccepted|0\n");
				Player::OnTradeStatus(peer, static_cast<PlayerInfo*>(currentPeer->data)->netID, "`o" + static_cast<PlayerInfo*>(currentPeer->data)->displayName + "`o's offer.``", "", FormatTradeItems(static_cast<PlayerInfo*>(currentPeer->data)->tradeItems) + "\nlocked|0\nreset_locks|1\naccepted|0\n");
				if (!silent) {
					Player::OnTextOverlay(peer, "The deal has changed");
					Player::PlayAudio(currentPeer, "audio/tile_removed.wav", 0);
					Player::PlayAudio(peer, "audio/tile_removed.wav", 0);
				}
				pData->trade_accept = false;
				static_cast<PlayerInfo*>(currentPeer->data)->trade_accept = false;
				//break;
			}
		}
	}
}

void UpdateTradeAcceptedStatus(ENetPeer* peer, int showOverlay = 0, bool self = false) {
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (static_cast<PlayerInfo*>(peer->data)->trade_netid == static_cast<PlayerInfo*>(currentPeer->data)->netID) {
			Player::OnTradeStatus(currentPeer, static_cast<PlayerInfo*>(peer->data)->netID, "`o" + static_cast<PlayerInfo*>(peer->data)->displayName + "`o's offer.``", "", FormatTradeItems(static_cast<PlayerInfo*>(peer->data)->tradeItems) + "\nlocked|1\naccepted|" + to_string(static_cast<PlayerInfo*>(peer->data)->trade_accept) + "\n");
			Player::OnTradeStatus(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->netID, "`o" + static_cast<PlayerInfo*>(currentPeer->data)->displayName + "`o's offer.``", "", FormatTradeItems(static_cast<PlayerInfo*>(currentPeer->data)->tradeItems) + "\nlocked|1\naccepted|" + to_string(static_cast<PlayerInfo*>(currentPeer->data)->trade_accept) + "\n");
			if (self) {
				Player::OnTradeStatus(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`o" + static_cast<PlayerInfo*>(peer->data)->displayName + "`o's offer.``", "", FormatTradeItems(static_cast<PlayerInfo*>(peer->data)->tradeItems) + "\nlocked|1\naccepted|" + to_string(static_cast<PlayerInfo*>(peer->data)->trade_accept) + "\n");
				Player::OnTradeStatus(peer, static_cast<PlayerInfo*>(currentPeer->data)->netID, "`o" + static_cast<PlayerInfo*>(currentPeer->data)->displayName + "`o's offer.``", "", FormatTradeItems(static_cast<PlayerInfo*>(currentPeer->data)->tradeItems) + "\nlocked|1\naccepted|" + to_string(static_cast<PlayerInfo*>(currentPeer->data)->trade_accept) + "\n");
			}
			break;
		}
	}
}

inline void end_trade(ENetPeer* peer, bool cancelled = false, bool cancel = false) {
	for (ENetPeer* currentPeer = server->peers; currentPeer < &server->peers[server->peerCount]; ++currentPeer) {
		if (currentPeer->state != ENET_PEER_STATE_CONNECTED) continue;
		if (isHere(peer, currentPeer)) {
			if (static_cast<PlayerInfo*>(currentPeer->data)->netID == static_cast<PlayerInfo*>(peer->data)->trade_netid) {
				if (cancel) {
					Player::OnTextOverlay(currentPeer, static_cast<PlayerInfo*>(peer->data)->displayName + " `whas canceled the trade");
				}
				else if (cancelled) {
					Player::OnTalkBubble(currentPeer, static_cast<PlayerInfo*>(currentPeer->data)->netID, "`6[```4Trade canceled by " + static_cast<PlayerInfo*>(peer->data)->displayName + "`4!```6]``", 0, false);
					Player::OnConsoleMessage(currentPeer, "`6[```4Trade canceled by " + static_cast<PlayerInfo*>(peer->data)->displayName + "`4!```6]``");
					Player::OnTextOverlay(currentPeer, "`6[```4Trade canceled by " + static_cast<PlayerInfo*>(peer->data)->displayName + "`4!```6]``");
				} else {
					Player::OnConsoleMessage(currentPeer, static_cast<PlayerInfo*>(peer->data)->displayName + " `ois too busy to trade!");
					Player::OnTextOverlay(currentPeer, static_cast<PlayerInfo*>(peer->data)->displayName + " `wis too busy to trade!");
				}
				Player::OnForceTradeEnd(currentPeer);
				static_cast<PlayerInfo*>(currentPeer->data)->trade_netid = -1;
				static_cast<PlayerInfo*>(currentPeer->data)->trade = false;
				static_cast<PlayerInfo*>(currentPeer->data)->trade_accept = false;
				static_cast<PlayerInfo*>(currentPeer->data)->trade_confirmed = false;
				static_cast<PlayerInfo*>(currentPeer->data)->tradeItems.clear();
				break;
			}
		}
	}
	if (cancel) {
		Player::OnTextOverlay(peer, static_cast<PlayerInfo*>(peer->data)->displayName + " `whas canceled the trade");
	}
	else if (cancelled) {
		Player::OnTalkBubble(peer, static_cast<PlayerInfo*>(peer->data)->netID, "`6[```4Trade canceled by " + static_cast<PlayerInfo*>(peer->data)->displayName + "`4!```6]``", 0, false);
		Player::OnConsoleMessage(peer, "`6[```4Trade canceled by " + static_cast<PlayerInfo*>(peer->data)->displayName + "`4!```6]``");
		Player::OnTextOverlay(peer, "`6[```4Trade canceled by " + static_cast<PlayerInfo*>(peer->data)->displayName + "`4!```6]``");
	} else {
		Player::OnConsoleMessage(peer, static_cast<PlayerInfo*>(peer->data)->displayName + " `ois too busy to trade!");
		Player::OnTextOverlay(peer, static_cast<PlayerInfo*>(peer->data)->displayName + " `wis too busy to trade!");
	}
	Player::OnForceTradeEnd(peer);
	static_cast<PlayerInfo*>(peer->data)->trade_netid = -1;
	static_cast<PlayerInfo*>(peer->data)->trade = false;
	static_cast<PlayerInfo*>(peer->data)->tradeItems.clear();
	static_cast<PlayerInfo*>(peer->data)->trade_accept = false;
	static_cast<PlayerInfo*>(peer->data)->trade_confirmed = false;
}

inline void start_trade(ENetPeer* peer1, ENetPeer* peer2) {
	PlayerInfo* pinfo = (PlayerInfo*)peer1->data;
	PlayerInfo* pinfo2 = (PlayerInfo*)peer2->data;
	bool illegal_trade = false;
	for (auto& f : pinfo->tradeItems) {
		auto contains = false;
		SearchInventoryItem(peer1, f.id, f.count, contains);
		if (!contains) {
			illegal_trade = true;
			break;
		}
	} if (illegal_trade) {
		pinfo->tradeItems.clear();
	} for (auto& f : pinfo2->tradeItems) {
		auto contains = false;
		SearchInventoryItem(peer2, f.id, f.count, contains);
		if (!contains) {
			illegal_trade = true;
			break;
		}
	} if (illegal_trade) {
		pinfo2->tradeItems.clear();
	}
	pinfo->trade = true;
	pinfo2->trade = true;
	pinfo->trade_confirmed = false;
	pinfo2->trade_confirmed = false;
	Player::OnTradeStatus(peer1, pinfo->netID, "`oSelect an item from the inventory.``", "", FormatTradeItems(pinfo->tradeItems) + "\nlocked|0\nreset_locks|1\naccepted|" + to_string(pinfo->trade_accept) + "\n");
	Player::OnTradeStatus(peer1, pinfo2->netID, "`w" + pinfo2->displayName + "`o's offer.``", "", FormatTradeItems(pinfo2->tradeItems) + "\nlocked|0\naccepted|" + to_string(pinfo2->trade_accept) + "\n");
	Player::OnTradeStatus(peer2, pinfo2->netID, "`oSelect an item from the inventory.``", "", FormatTradeItems(pinfo2->tradeItems) + "\nlocked|0\naccepted|" + to_string(pinfo2->trade_accept) + "\n");
	Player::OnTradeStatus(peer2, pinfo->netID, "`w" + pinfo->displayName + "`o's offer.``", "", FormatTradeItems(pinfo->tradeItems) + "\nlocked|0\nreset_locks|1\naccepted|" + to_string(pinfo->trade_accept) + "\n");
	update_trade(peer1, static_cast<PlayerInfo*>(peer1->data)->trade_netid, true);
}