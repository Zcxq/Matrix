#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <detours.h>
#include "main.h"
#include <fstream>
#include <detours.h>
#include "main.h"
#include "unlockall.h"
#include "tpOptions.h"
#include "bot.h"
#include "misc.h"

#define RegisterHook(original, hook) (DetourTransactionBegin(), DetourUpdateThread(GetCurrentThread()), DetourAttach(reinterpret_cast<LPVOID*>(&original), reinterpret_cast<LPVOID>(hook)), DetourTransactionCommit())
#define RemoveHook(original, hook) (DetourTransactionBegin(), DetourUpdateThread(GetCurrentThread()), DetourDetach(reinterpret_cast<LPVOID*>(&original), reinterpret_cast<LPVOID>(hook)), DetourTransactionCommit())


using namespace std;
const char* (*Live_GetLocalClientName_Stub)(int A) = (const char* (*)(int))0x005C7610;
const char* Live_GetLocalClientName_Hook(int A) {
	return customName;
}
void(*VM_Notify_Stub)(unsigned int, unsigned int, int) = (void(*)(unsigned int, unsigned int, int))0x0057FBB0;
void VM_Notify_Hook(unsigned int notifyListOwnerId, unsigned int stringValue, int top) {

	const char* notify = SL_ConvertToString(stringValue);
	int player = Scr_GetSelf(notifyListOwnerId);

	if (Scr_LocalPlayer() == player) {
		if (!strcmp(notify, "connected")) {
			Cmd_RegisterNotification(player, "+actionslot 1", "DPAD_UP");
			Cmd_RegisterNotification(player, "+actionslot 2", "DPAD_DOWN");
		}
		if (!strcmp(notify, "weapon_fired")) {
			if (hToggleAimbot != false) {
				Vector3 M;
				G_Damage(GEntity(NearestClient(GetLocalClient())), GEntity(GetLocalClient()), GEntity(GetLocalClient()), (float*)&M, (float*)&M, 9999, 0, 2, GetCurrentWeapon(GetLocalClient()), 7, 0, 0, 0);
			}
			if (AC130105mm != false) {
				GScr_MagicBullet("ac130_105mm_mp", PlayerAnglesToForward(GetLocalClient(), 25), PlayerAnglesToForward(GetLocalClient(), 9999), GEntity(GetLocalClient()));
			}
			if (AC13035mm != false) {
				GScr_MagicBullet("ac130_40mm_mp", PlayerAnglesToForward(GetLocalClient(), 25), PlayerAnglesToForward(GetLocalClient(), 9999), GEntity(GetLocalClient()));
			}
			if (AC13025mm != false) {
				GScr_MagicBullet("ac130_25mm_mp", PlayerAnglesToForward(GetLocalClient(), 25), PlayerAnglesToForward(GetLocalClient(), 9999), GEntity(GetLocalClient()));
			}
			if (RPGBullets != false) {
				GScr_MagicBullet("rpg_mp", PlayerAnglesToForward(GetLocalClient(), 25), PlayerAnglesToForward(GetLocalClient(), 9999), GEntity(GetLocalClient()));
			}
			if (unlimitedAmmo != false) {
				Add_Ammo(GEntity(GetLocalClientNumber()), GetCurrentWeapon(GetLocalClientNumber()), 0, 999, 1);
				Add_Ammo(GEntity(GetLocalClientNumber()), GetCurrentOffhand(GetLocalClientNumber()), 0, 999, 1);
			}

		}
	}
	VM_Notify_Stub(notifyListOwnerId, stringValue, top);
}

void(*R_EndFrame_Stub)(void) = (void(*)())0x00412130;
void R_EndFrame_Hook(void) {


	RunMenu();

	Drawtext("Thanks For Buying OG Gazza Build Version 1.3! F8 = Open.", 50, 690, 0.55, color_s(r, g, b, 255), "fonts/bigfont");
	R_EndFrame_Stub();
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	string name;
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();


		freopen("CONOUT$", "w", stdout);
		printf("::::    ::::      ::: ::::::::::: :::::::::  ::: :::    :::  \n", 0);
		printf("+:+:+: :+:+:+   :+: :+:   :+:     :+:    :+: :+: :+:    :+:  \n", 0);
		printf("+:+ +:+:+ +:+  +:+   +:+  +:+     +:+    +:+ +:+  +:+  +:+   \n", 0);
		printf("+#+  +:+  +#+ +#++:++#++: +#+     +#++:++#:  +#+   +#++:+    \n", 0);
		printf("+#+       +#+ +#+     +#+ +#+     +#+    +#+ +#+  +#+  +#+   \n", 0);
		printf("#+#       #+# #+#     #+# #+#     #+#    #+#     #+#    #+#  \n", 0);
		printf("###       ### ###     ### ###     ###    ### ### ###    ###  \n", 0);
		printf("                                                             \n", 0);
		printf("    Zcxq- MADE THIS MENU - ONLY BUY FROM THESE RESELLERS     \n", 0);
		printf("                                                             \n", 0);
		printf("    Vanity#8125           Night#1337          Zcxq-#1337     \n", 0);
		printf("                                                             \n", 0);
		printf("  IF YOU HAVE BOUGHT FROM GAZZASLOBBIES YOU HAVE BEEN SCAMMED\n", 0);
		printf("                                                             \n", 0);
		printf("  This menu is for self purpose only, although there are many\n", 0);
		printf("  Other Client options, do not abuse this and ruin other     \n", 0);
		printf("  Players' Gameplay by kicking, levelling or trolling unless \n", 0);
		printf("  They ask or give you permission to do so                   \n", 0);
		printf("                                                             \n", 0);
		printf("                     YOUTUBERS NOTICE:                       \n", 0);
		printf("                                                             \n", 0);
		printf("  IF YOU ARE MAKING A VIDEO ON THIS MENU, YOU NEED TO TALK   \n", 0);
		printf("  TO THE DEVELOPERS ABOUT THIS, IF YOU UPLOAD WITHOUT OUR    \n", 0);
		printf("  CONSENT WE WILL CLASS IT AS A COPYRIGHT INFRACTION AND     \n", 0);
		printf("  YOU WILL LOSE ACCESS TO THE MENU AND IT'S FUTURE UPDATES   \n", 0);


		RegisterHook(R_EndFrame_Stub, R_EndFrame_Hook);
		RegisterHook(VM_Notify_Stub, VM_Notify_Hook);
		RegisterHook(Live_GetLocalClientName_Stub, Live_GetLocalClientName_Hook);
		Cmd_AddCommand("addbot", AddBots, &AddBots_t);
		Cmd_AddCommand("spawnbot", SpawnBot, &SpawnBot_t);
		Cmd_AddCommand("botchooseteam", BotChooseTeam, &BotChooseTeam_t);
		Cmd_AddCommand("botchooseclass", BotChooseClass, &BotChooseClass_t);


		break;
	case DLL_PROCESS_DETACH:
		RemoveHook(R_EndFrame_Stub, R_EndFrame_Hook);
		RemoveHook(VM_Notify_Stub, VM_Notify_Hook);
		RemoveHook(Live_GetLocalClientName_Stub, Live_GetLocalClientName_Hook);

		Cmd_RemoveCommand("addbot");
		Cmd_RemoveCommand("spawnbot");
		Cmd_RemoveCommand("botchooseteam");
		Cmd_RemoveCommand("botchooseclass");


		break;
	}
	return TRUE;
}
