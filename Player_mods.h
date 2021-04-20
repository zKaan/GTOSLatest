#pragma once
#include "stdafx.h"
#include "enet/enet.h"
#ifdef _WIN32
typedef __int8 __int8_t;
typedef __int16 __int16_t;
#elif __APPLE__ || __linux__
typedef unsigned int DWORD;
#endif
typedef unsigned char BYTE;

inline void PlayerBuff(ENetPeer* peer, int x, int y)
{
	auto* const pinfo = static_cast<PlayerInfo*>(peer->data);
#pragma region BlueBerry
	long long blueberry = (pinfo->usedBerry);
	blueberry += (pinfo->lastBerry);
	if (pinfo->blueBerry)
	{
		if (blueberry <= GetCurrentTimeInternalSeconds())
		{
			sendSound(peer, "audio/dialog_confirm.wav");
			pinfo->skinColor = 0x8295C3FF;
			sendClothes(peer);
			Player::OnConsoleMessage(peer, "The effects of the `1blueberry`o have worn off. (`$Feelin' Blue `omod removed)");
			pinfo->blueBerry = false;
		}
	}
#pragma endregion BlueBerry
#pragma region LuckyClover
	long long LuckyClover = (pinfo->usedClover);
	LuckyClover += (pinfo->lastClover);
	if (pinfo->LuckyClover)
	{
		if (LuckyClover <= GetCurrentTimeInternalSeconds())
		{
			sendSound(peer, "audio/dialog_confirm.wav");
			Player::OnConsoleMessage(peer, "The effects of the `^Lucky Clover`o have worn off. (`$Lucky `omod removed)");
			pinfo->LuckyClover = false;
		}
	}
#pragma endregion LuckyClover
#pragma region SpikeJuice
	long long SpikeJuice = (pinfo->usedSpike);
	SpikeJuice += (pinfo->lastSpike);
	if (pinfo->SpikeJuice)
	{
		if (SpikeJuice <= GetCurrentTimeInternalSeconds())
		{
			sendSound(peer, "audio/dialog_confirm.wav");
			Player::OnConsoleMessage(peer, "You feel vulnerable again. (`$Spikeproof `omod removed)");
			pinfo->SpikeJuice = false;
		}
	}
#pragma endregion SpikeJuice
#pragma region PunchPotion
	long long PunchPotion = (pinfo->usedPunchPotion);
	PunchPotion += (pinfo->lastPunchPotion);
	if (pinfo->PunchPotion)
	{
		if (PunchPotion <= GetCurrentTimeInternalSeconds())
		{
			sendSound(peer, "audio/dialog_confirm.wav");
			Player::OnConsoleMessage(peer, "You feel weak again. (`$One HIT `omod removed)");
			pinfo->PunchPotion = false;
		}
	}
#pragma endregion PunchPotion
#pragma region PlacePotion
	long long PlacePotion = (pinfo->usedPlacePotion);
	PlacePotion += (pinfo->lastPlacePotion);
	if (pinfo->PlacePotion)
	{
		if (PlacePotion <= GetCurrentTimeInternalSeconds())
		{
			sendSound(peer, "audio/dialog_confirm.wav");
			Player::OnConsoleMessage(peer, "Your hands shrinks again. (`$Triple Place `omod removed)");
			pinfo->PlacePotion = false;
		}
	}
#pragma endregion PlacePotion
}
