#pragma once
#include "resizing.h"
#include "misc.h"
#include "menuBuilding.h"
#include "bot.h"
#include "unlockall.h"
#include <shellapi.h>




bool vision;
/* main */ const char* MainMenuText[19] = { "OFF-HOST Options", "HOST Options", "DrawText Menu", "Color Options", "Stats Menu", "Teleport Menu", "Spawnables Menu", "Projectiles Menu", "More Host Options", "Aimbot Shit", "Names Menu", "Map Options", "Weapon Menu", "Visions Menu", "Resize Menu","New Layouts", "All Client", "Infections", "All Client Fun" };
/* menu1 */ const char* Menu1Text[7] = { "Red Boxes", "No Recoil", "No Spread", "No Kick", "ThirdPerson", "Wall Haxs", "FOV 120" }; //done
/* menu2 */ const char* Menu2Text[8] = { "Force Host", "Xp Lobby", "Super Speed", "Super Jump", "Add Bot", "Aimbot", "2x Speed", "No Clip" };//done
/* menu3 */ const char* Menu3Text[14] = { "What is this?", "XP Lobby",  "Best Menu is Matrix",  "Advertise My Shit",  "Discord Server",  "Shame the leechers",  "Creator's Discord",  "Advertise",  "Sellix",  "XP Info",  "Say it!",  "GitHub",  "Fake Ban",  "SECRET...", }; //done
/* menu4 */ const char* Menu4Text[7] = { "Red Theme", "Green Theme", "Blue Theme", "Yellow Theme", "White Theme", "Pink Theme", "TBA" }; //done
/* menu5 */ const char* statsMenu[16] = { "Level 70", "Legit Stats","High Stats", "Insane Stats", "Reset Stats", "Unlock All", "Colored Classes", "Presitge 4", "Prestige 5", "Prestige 6", "Prestige 7", "Prestige 8", "Prestige 9", "Prestige 10", "Prestige 11", "Prestige 0" }; //done
/* menu6 */ const char* Clients[5] = { "Save Location", "Load Location", "Save & Load Binds", "Top Of Rust", "To Sky" }; //done
/* menu7 */ const char* SpawnablesMenu[9] = { "Care Package Green", "Care Package Red", "Pine Tree", "Truck", "PlasticWall", "Tree", "PaveLow", "Dumpster", "Pine Tree" };//done
/* menu8 */ const char* ProjectilesMenu[8] = { "AC130 105mm", "AC130 40mm", "AC130 25mm", "RPG Bullets", "Explosive Bullets", }; //done
/* menu9 */ const char* MoreHostOptMenu[5] = { "God Mode", "Unlimited Ammo", "No Time Limit", "Low Gravity", "Fast Restart" };
/* menu10 */ const char* offHostAimbot[5] = { "Main Aimbot", "[iw4x ONLY] Bone ESP", "[iw4x ONLY] Tracking", "[iw4x ONLY] SilentAim", "[iw4x ONLY] Spinbot" };
/* menu11 */ const char* ipSpoofingMenu[9] = { "Become Zcxq-",  "MATRIX IN MW2", "Lord of them all", "NULL", "MORSE CODE", "BLANK", ".gg/racademy", "SPOOF FOR YT", "RESET" };
/* menu12 */ const char* gamerTagMenu[11] = { "Afghan", "Derail",  "Estate",  "Favela",  "Highrise",  "Karachi",  "Quarry",  "Rundown",  "Rust",  "Terminal", "Sub-Base" };
/* menu13 */ const char* weaponsMenuText[10] = { "Gold Deagle", "DW SCAR-H", "M16", "DW Intervention", "DW FN Fal", "Default Weapon", "DW RPG", "DW UZI", "DW AA12", "REMOVE ALL" };
/* menu14 */ const char* visionsMenuText[7] = { "Chrome", "COD 4", "Silver Scale", "Black Vision", "Potatoe Like", "Rainbow [TBA]", "Inverted [TBA]" };
/* menu15 */ const char* resizeMenuText[16] = { "resize shader X", "resize shader Y", "resize shader W", "resize shader H", "resize title X", "resize title Y ", "resize title Scale", "resize Opt X", "resize Opt Y", "resize Opt Scale", "resize sub X ", "reszie sub Y", "resize sub Scale", "Scroller Y", "Scroller X", "Scroller W" };
/* menu16 */ const char* newMenuLayouts[4] = { "TBA", "TBA", "TBA", "TBA" };
/* menu17 */ const char* allClient[17] = { "Unlock All ", "Level 70", "Insane Stats", "Legit Stats", "Prestige 0", "Prestige 1", "Prestige 2", "Prestige 3", "Prestige 4", "Prestige 5", "Prestige 6", "Prestige 7", "Prestige 8", "Prestige 9", "Prestige 10", "Quick Recovery", "Colored Classes" }; //done
/* menu18 */ const char* infectionsMenu[5] = { "Fake Infectable Menu", "Gay Mode Type", "The Game Mode", "Nuke Timer" }; //done
/* menu19 */ const char* allClientFun[5] = { "Third Person", "Chrome Mod", "Gold Deagle", "DW Default weapon", "Full Bright Vision" };
void DrawMenu() {
	Shaders();
	//InfoShader();
	//AddInfo();
	AddTitle("MATR!X [LEGACY]");
	//AddName("");

	switch (CurrentMenu) {
	case MainMenu:
		for (int i = 0; i < 20; i++) { AddSub(i, MainMenuText[i]); }
		break;
	case Menu1:
		for (int i = 0; i < 7; i++) { AddOpt(i, Menu1Text[i]); }
		break;
	case Menu2:
		for (int i = 0; i < 8; i++) { AddOpt(i, Menu2Text[i]); }
		break;
	case Menu3:
		for (int i = 0; i < 14; i++) { AddOpt(i, Menu3Text[i]); }
		break;
	case Menu4:
		for (int i = 0; i < 6; i++) { AddOpt(i, Menu4Text[i]); } break;
	case Menu5:
		for (int i = 0; i < 16; i++) { AddOpt(i, statsMenu[i]); } break;
	case Menu6:
		for (int i = 0; i < 5; i++) { AddOpt(i, Clients[i]); } break;
	case Menu7:
		for (int i = 0; i < 7; i++) { AddOpt(i, SpawnablesMenu[i]); } break;
	case Menu8:
		for (int i = 0; i < 5; i++) { AddOpt(i, ProjectilesMenu[i]); } break;
	case Menu9:
		for (int i = 0; i < 5; i++) { AddOpt(i, MoreHostOptMenu[i]); } break;
	case Menu10:
		for (int i = 0; i < 5; i++) { AddOpt(i, offHostAimbot[i]); } break;
	case Menu11:
		for (int i = 0; i < 9; i++) { AddOpt(i, ipSpoofingMenu[i]); } break;
	case Menu12:
		for (int i = 0; i < 11; i++) { AddOpt(i, gamerTagMenu[i]); } break;
	case Menu13:
		for (int i = 0; i < 6; i++) { AddOpt(i, visionsMenuText[i]); } break;
	case Menu14:
		for (int i = 0; i < 7; i++) { AddOpt(i, resizeMenuText[i]); } break;
	case Menu15:
		for (int i = 0; i < 10; i++) { AddOpt(i, weaponsMenuText[i]); } break;
	case Menu16:
		for (int i = 0; i < 17; i++) { AddOpt(i, allClient[i]); } break;
	case Menu17:
		for (int i = 0; i < 4; i++) { AddOpt(i, infectionsMenu[i]); } break;
	case Menu18:
		for (int i = 0; i < 4; i++) { AddOpt(i, newMenuLayouts[i]); } break;
	case Menu19:
		for (int i = 0; i < 5; i++) { AddOpt(i, allClientFun[i]); } break;
	}
}
void SelectSub() {
	switch (CurrentMenu) {
	case MainMenu:
		if (CurrentOpt == 0) { CurrentOpt = 0; CurrentMenu = Menu1; }
		if (CurrentOpt == 1) { CurrentOpt = 0; CurrentMenu = Menu2; }
		if (CurrentOpt == 2) { CurrentOpt = 0; CurrentMenu = Menu3; }
		if (CurrentOpt == 3) { CurrentOpt = 0; CurrentMenu = Menu4; }
		if (CurrentOpt == 4) { CurrentOpt = 0; CurrentMenu = Menu5; }
		if (CurrentOpt == 5) { CurrentOpt = 0; CurrentMenu = Menu6; }
		if (CurrentOpt == 6) { CurrentOpt = 0; CurrentMenu = Menu7; }
		if (CurrentOpt == 7) { CurrentOpt = 0; CurrentMenu = Menu8; }
		if (CurrentOpt == 8) { CurrentOpt = 0; CurrentMenu = Menu9; }
		if (CurrentOpt == 9) { CurrentOpt = 0; CurrentMenu = Menu10; }
		if (CurrentOpt == 10) { CurrentOpt = 0; CurrentMenu = Menu11; }
		if (CurrentOpt == 11) { CurrentOpt = 0; CurrentMenu = Menu12; }
		if (CurrentOpt == 12) { CurrentOpt = 0; CurrentMenu = Menu13; }
		if (CurrentOpt == 13) { CurrentOpt = 0; CurrentMenu = Menu14; }
		if (CurrentOpt == 14) { CurrentOpt = 0; CurrentMenu = Menu15; }
		if (CurrentOpt == 15) { CurrentOpt = 0; CurrentMenu = Menu16; }
		if (CurrentOpt == 16) { CurrentOpt = 0; CurrentMenu = Menu17; }
		if (CurrentOpt == 17) { CurrentOpt = 0; CurrentMenu = Menu18; }
		if (CurrentOpt == 18) { CurrentOpt = 0; CurrentMenu = Menu19; }

		break;
	}
}
void SelectOpt() {
	switch (CurrentMenu) {
	case Menu1:
		if (CurrentOpt == 0) { redBoxes(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 Red Boxes\""); } //redboxes } 
		if (CurrentOpt == 1) { noRecoil(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 No Recoil\""); } //no recoil }
		if (CurrentOpt == 2) { noSpread(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 No Spread\""); } //no spread }
		if (CurrentOpt == 3) { noKick(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 No Kick\""); } //No Kick }
		if (CurrentOpt == 4) { thirdPerson(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 ThirdPerson\""); } //Thirdperson }
		if (CurrentOpt == 5) { wallHack(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 Wallhack\""); } //wallHaxs }
		if (CurrentOpt == 6) { fov = !fov; FOV(fov ? 120 : 60); SV_GameSendServerCommand(GetLocalClient(), 1, fov ? "f \"^5 Fov On\"" : "f \"^5 Fov Off\""); }
		break;
	case Menu2:
		if (CurrentOpt == 0) { ForceHost(); } //force host } 
		if (CurrentOpt == 1) { XPLobby(60000); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^!\""); } //aimbot} 
		if (CurrentOpt == 2) { Speed(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 Super Speed On\""); } //super speed} 
		if (CurrentOpt == 3) { superjump(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1[MATR!X] ^5 Super Jump On\""); } //super jump} 
		if (CurrentOpt == 4) { AddBots(); } //Bot} 
		if (CurrentOpt == 5) { hToggleAimbot = !hToggleAimbot; hToggleAimbot ? true : false;  SV_GameSendServerCommand(GetLocalClient(), 1, hToggleAimbot ? "f \"^5 Aimbot On\"" : "f \"^5 Aimbot Off\""); } //aimbot} 
		if (CurrentOpt == 6) { x2Speedos = !x2Speedos;  x2Speed(x2Speedos ? 0x40400000 : 0x3F800000);  SV_GameSendServerCommand(GetLocalClient(), 1, x2Speedos ? "f \"^5 2x Speed On\"" : "f \"^5 x2 Speed Off\""); }
		if (CurrentOpt == 7) { noClipos = !noClipos; noClip(noClipos ? 2 : 0); SV_GameSendServerCommand(GetLocalClient(), 1, noClipos ? "f \"^5 No Clip On\"" : "f \"^5 No Clip Off\""); }
		break;
	case Menu3:
		if (CurrentOpt == 0) { SV(-1, 0, "c \"^1This is MATRIX MENU > BUY IT NOW !!\""); } //tell them skids
		if (CurrentOpt == 1) { SV(-1, 0, "c \"^6XP Lobby: ^2ACTIVE\""); } //XP Lobby
		if (CurrentOpt == 2) { SV(-1, 0, "c \"^3Fuck you and your shit menu's ^1MATRIX RULES !!!!\""); } //whos boss
		if (CurrentOpt == 3) { SV(-1, 0, "c \"^1YT.com/Zcxq-   BEST MW2 MENU'S\""); } //advertise my shit
		if (CurrentOpt == 4) { SV(-1, 0, "c \"^3 discord.gg/8SEnBvebVt\""); } //discord
		if (CurrentOpt == 5) { SV(-1, 0, "c \"^7THIS IS ^1MATR!X [LEGACY]^7: GET THE ^2BETTER MENU ^7KID\""); } //what menu
		if (CurrentOpt == 6) { SV(-1, 0, "c \"Add the discord: ^5Zcxq-#5842 \""); } //add me
		if (CurrentOpt == 7) { SV(-1, 0, "c \"^3Buy best CoD Cheats & Game Trainers in discord !!!\""); } //sales advert
		if (CurrentOpt == 8) { SV(-1, 0, "c \"^6racademy.sellix.io ^2BUY BEST CHEATS ONLINE\""); } //sellix
		if (CurrentOpt == 9) { SV(-1, 0, "c \"^3XP Lobby: ^2ENABLED ^7| ^5With ^15mil ^5Per Kill \""); } //XP Info
		if (CurrentOpt == 10) { SV(-1, 0, "c \"^1Zcxq- Owns this Lobby !!!\""); } //Troll
		if (CurrentOpt == 11) { SV(-1, 0, "c \"^4Find FREE Cheats on GitHub: ^2github.com/Zcxq\""); } //GitHub
		if (CurrentOpt == 12) { SV(-1, 0, "c \"^1YOU HAVE BEEN BANNED\""); } //Banned
		if (CurrentOpt == 13) { SV(-1, 0, "c \"^0ATREXITIVE SNIFFS CHEESY FEET FOR MONEY\""); } //cheesy
		break;
	case Menu4:
		if (CurrentOpt == 0) { r = 255; g = 0; b = 0; rS = 255; gS = 0; bS = 0; }// red 
		if (CurrentOpt == 1) { r = 0; g = 255; b = 0; rS = 0; gS = 255; bS = 0; } // green
		if (CurrentOpt == 2) { r = 0; g = 0; b = 255; rS = 0; gS = 0; bS = 255; }//blue
		if (CurrentOpt == 3) { r = 255; g = 233; b = 0; rS = 255; gS = 233; bS = 0; }//yellow
		if (CurrentOpt == 4) { r = 255; g = 244; b = 255; rS = 255; gS = 255; bS = 255; }//white
		if (CurrentOpt == 5) { r = 255; g = 0; b = 127; rS = 255; gS = 0; bS = 127; }//pink
		break;
	case Menu5: //stats menu.
		if (CurrentOpt == 0) { pStats = (myStats*)(0x01B8B7E8); pStats->xp = 2516000; }
		if (CurrentOpt == 1) {
			pStats = (myStats*)(0x01B8B7E8); pStats->assists = 12000; pStats->kills = 12000; pStats->deaths = 6000; pStats->wins = 5000;
			pStats->losses = 2500; pStats->score = 4200000; pStats->headshots = 6420; pStats->ties = 2103; pStats->streak = 25; pStats->timeOne = 400000;
			pStats->timeThree = 400; pStats->timeTwo = 400; pStats->winstreak = 20;
		}//legit

		if (CurrentOpt == 2) {
			pStats = (myStats*)(0x01B8B7E8);  pStats->assists = 999999; pStats->kills = 999999; pStats->deaths = 999999; pStats->wins = 999999;
			pStats->losses = 999999; pStats->score = 999999; pStats->headshots = 999999; pStats->ties = 999999; pStats->streak = 99999; pStats->timeOne = 9999999;
			pStats->timeThree = 9999999; pStats->timeTwo = 999999; pStats->winstreak = 999999;
		} //high

		if (CurrentOpt == 3) {
			pStats = (myStats*)(0x01B8B7E8); pStats->assists = 0; pStats->kills = 0; pStats->deaths = 0; pStats->wins = 0;
			pStats->losses = 0; pStats->score = 0; pStats->headshots = 0; pStats->ties = 0; pStats->streak = 0; pStats->timeOne = 0;
			pStats->timeThree = 0; pStats->timeTwo = 0; pStats->winstreak = 0; pStats->xp = 0; pStats->prestige = 0;
		}//insane

		if (CurrentOpt == 4) {
			pStats = (myStats*)(0x01B8B7E8); pStats->assists = 999999999999; pStats->kills = 999999999999; pStats->deaths = 999999999999; pStats->wins = 9999999999990;
			pStats->losses = 9999999999990; pStats->score = 9999999999990; pStats->headshots = 9999999999990; pStats->ties = 9999999999990; pStats->streak = 9999999999990; pStats->timeOne = 9999999999990;
			pStats->timeThree = 9999999999990; pStats->timeTwo = 9999999999990; pStats->winstreak = 9999999999990; pStats->xp = 999999999999; pStats->prestige = 999999999999;
		}//reset

		if (CurrentOpt == 5) { pStats = (myStats*)(0x01B8B7E8); ACSunlock(0); } //unlock all
		if (CurrentOpt == 6) {} //COLORED CLASSES
		if (CurrentOpt == 7) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 4; }
		if (CurrentOpt == 8) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 5; }
		if (CurrentOpt == 9) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 6; }
		if (CurrentOpt == 10) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 7; }
		if (CurrentOpt == 11) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 8; }
		if (CurrentOpt == 12) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 9; }
		if (CurrentOpt == 13) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 10; }
		if (CurrentOpt == 14) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 11; }
		if (CurrentOpt == 15) { pStats = (myStats*)(0x01B8B7E8); pStats->prestige = 0; } //TBA
		break;
	case Menu6:
		if (CurrentOpt == 0) { Teli(0); }
		if (CurrentOpt == 1) { Teli(1); }
		if (CurrentOpt == 2) { saveLoadBind = true; SV(-1, 0, "c \"^5button Bind activated. F6 to Save F7 to Load :)\""); }
		if (CurrentOpt == 3) { Teli(4); }
		if (CurrentOpt == 4) { Teli(2); }
		break;
	case Menu7:
		if (CurrentOpt == 0) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "com_plasticcase_friendly", 4); }
		if (CurrentOpt == 1) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "com_plasticcase_enemy", 4); }
		if (CurrentOpt == 2) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "foliage_cod5_tree_pine05_large", 4); }
		if (CurrentOpt == 3) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "vehicle_moving_truck", 4); }
		if (CurrentOpt == 4) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "com_plastic_wall", 4); }
		if (CurrentOpt == 5) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "foliage_tree_oak_1", 4); }
		if (CurrentOpt == 6) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "pavelow_mp", 4); }
		if (CurrentOpt == 7) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "me_dumpster", 4); }
		if (CurrentOpt == 8) { SpawnEntity(PlayerAnglesToForward(GetLocalClient(), 200), Vector(0, 0, 0), "foliage_cod5_tree_pine05_large", 4); }

		break;
	case Menu8:
		if (CurrentOpt == 0) { AC130105mm = !AC130105mm; AC130105mm ? true : false;  SV_GameSendServerCommand(GetLocalClient(), 1, AC130105mm ? "f \"^5 Projectile On\"" : "f \"^5 Projectile Off\""); } //ac130 105mm
		if (CurrentOpt == 1) { AC13035mm = !AC13035mm; AC13035mm ? true : false; SV_GameSendServerCommand(GetLocalClient(), 1, AC13035mm ? "f \"^5 Projectile On\"" : "f \"^5 Projectile Off\""); } //ac130 40mm
		if (CurrentOpt == 2) { AC13025mm = !AC13025mm; AC13025mm ? true : false; SV_GameSendServerCommand(GetLocalClient(), 1, AC13025mm ? "f \"^5 Projectile On\"" : "f \"^5 Projectile Off\""); } //ac130 25mm
		if (CurrentOpt == 3) { RPGBullets = !RPGBullets;  RPGBullets ? true : false; SV_GameSendServerCommand(GetLocalClient(), 1, RPGBullets ? "f \"^5 Projectile On\"" : "f \"^5 Projectile Off\""); } //RPB Bullets
		if (CurrentOpt == 4) { ExplosiveBullets(); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^5 EB On\""); }
		break;
	case Menu9:
		if (CurrentOpt == 0) { bGodmode = !bGodmode; setHealth(GetLocalClient(), bGodmode ? 0x7FFFFFFFF : 100); SV_GameSendServerCommand(GetLocalClient(), 1, bGodmode ? "f \"^5God On\"" : "f \"^5God Off\""); } //god mode 
		if (CurrentOpt == 1) { unlimitedAmmo = !unlimitedAmmo;  SV_GameSendServerCommand(GetLocalClient(), 1, unlimitedAmmo ? "f \"^5 You Got Ammo\"" : "f \"^5 Mad Ammo Gone Gone\""); } //unlimited ammo
		if (CurrentOpt == 2) { UnlimitedTime(); } //no time limit
		if (CurrentOpt == 3) { LowGravity(100); } //low gravity
		if (CurrentOpt == 4) { FastRestart(); } //fast restart
		break;
	case Menu10: //aimbot menu 
		if (CurrentOpt == 0) { hToggleAimbot = !hToggleAimbot; hToggleAimbot ? true : false;  SV_GameSendServerCommand(GetLocalClient(), 1, hToggleAimbot ? "f \"^5 Aimbot On\"" : "f \"^5 Aimbot Off\""); } //aimbot 
		if (CurrentOpt == 1) {}
		if (CurrentOpt == 2) {}
		if (CurrentOpt == 3) {}
		if (CurrentOpt == 4) {}
		break;
	case Menu11: //ip spoofing menu 
		if (CurrentOpt == 0) { customName = "^1Zcxq-#5824"; }
		if (CurrentOpt == 1) { customName = "^4MATR!X In MW2"; }
		if (CurrentOpt == 2) { customName = "^2Lord Foog the 2st"; }
		if (CurrentOpt == 3) { customName = "^0NULL"; }
		if (CurrentOpt == 4) { customName = "^8--. .- -.--"; }
		if (CurrentOpt == 5) { customName = "^0."; }
		if (CurrentOpt == 6) { customName = "^5discord.gg/8SENBvebVt"; }
		if (CurrentOpt == 7) { customName = "^1Definately not a Youtuber"; }
		if (CurrentOpt == 8) { customName = "^1Zcxq- ^4Made ^6MATR!X"; }
		break;
	case Menu12: //Map menu "Im Your Man Bite ME", "Only The Best Over Here", "100KD PlaYER Im Legit", "Suck Me Like A Porno", "Nothing", "Your UserName Registered"
		if (CurrentOpt == 0) { ("mp_afghan"); FastRestart(); }    //Afghan 
		if (CurrentOpt == 1) { ("mp_derail"); FastRestart(); }    //Derail
		if (CurrentOpt == 2) { ("mp_estate"); FastRestart(); }    //Estate
		if (CurrentOpt == 3) { ("mp_favela"); FastRestart(); }    //Favela
		if (CurrentOpt == 4) { ("mp_highrise"); FastRestart(); }  //Highrise
		if (CurrentOpt == 5) { ("mp_karachi"); FastRestart(); }   //Karachi
		if (CurrentOpt == 6) { ("mp_quarry"); FastRestart(); }    //Quarry
		if (CurrentOpt == 7) { ("mp_rundown"); FastRestart(); }   //Rundown
		if (CurrentOpt == 8) { ("mp_rust"); FastRestart(); }      //Rust
		if (CurrentOpt == 9) { ("mp_terminal"); FastRestart(); }  //Terminal
		if (CurrentOpt == 10) { ("mp_subbase"); FastRestart(); }  //Sub Base
		break;
	case Menu13: // visions menu 
		if (CurrentOpt == 0) { vision = !vision; vision ? SV(-1, 0, "s r_specularmap \"3\"") : SV(-1, 0, "s r_specularmap \"0\""); }
		if (CurrentOpt == 1) { SV(-1, 0, "M thermal_mp"); }
		if (CurrentOpt == 2) { vision = !vision; vision ? SV(-1, 0, "s r_fullbright \"1\"") : SV(-1, 0, "s r_fullbright \"0\""); }
		if (CurrentOpt == 3) { vision = !vision; vision ? SV(-1, 0, "s r_scaleviewport \"0.4\"") : SV(-1, 0, "s r_scaleviewport \"1\""); }
		if (CurrentOpt == 4) { vision = !vision; vision ? SV(-1, 0, "M inverted_mp \"1\"") : SV(-1, 0, "M inverted_mp \"0\""); }
		if (CurrentOpt == 5) {}
		if (CurrentOpt == 6) {}
		break;
	case Menu14: //done.
		if (CurrentOpt == 0) { if (GetAsyncKeyState(VK_F1)) { resizeShaderX(shaderX1 + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeShaderX(shaderX1 - 10); } }
		if (CurrentOpt == 1) { if (GetAsyncKeyState(VK_F1)) { resizeShaderY(shaderY1 + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeShaderY(shaderY1 - 10); } }
		if (CurrentOpt == 2) { if (GetAsyncKeyState(VK_F1)) { resizeShaderW(shaderW1 + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeShaderW(shaderW1 - 10); } }
		if (CurrentOpt == 3) { if (GetAsyncKeyState(VK_F1)) { resizeShaderH(shaderH1 + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeShaderH(shaderH1 - 10); } }
		// title text
		if (CurrentOpt == 4) { if (GetAsyncKeyState(VK_F1)) { resizeTitleX(textTitleX + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeTitleX(textTitleX - 10); } }
		if (CurrentOpt == 5) { if (GetAsyncKeyState(VK_F1)) { resizeTitleY(textTitleY + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeTitleY(textTitleY - 10); } }
		if (CurrentOpt == 6) { if (GetAsyncKeyState(VK_F1)) { resizeTitleS(textTitleScale + 0.1); } else if (GetAsyncKeyState(VK_F2)) { resizeTitleS(textTitleScale - 0.1); } }
		// opt text
		if (CurrentOpt == 7) { if (GetAsyncKeyState(VK_F1)) { resizeOptX(textOptX + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeOptX(textOptX - 10); } }
		if (CurrentOpt == 8) { if (GetAsyncKeyState(VK_F1)) { resizeOptY(textOptY + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeOptY(textOptY - 10); } }
		if (CurrentOpt == 9) { if (GetAsyncKeyState(VK_F1)) { resizeOptS(textOptScale + 0.1); } else if (GetAsyncKeyState(VK_F2)) { resizeOptS(textOptScale - 0.1); } }
		// sub text 
		if (CurrentOpt == 10) { if (GetAsyncKeyState(VK_F1)) { resizeSubX(textSubX + 10); AddSub(1, "Positioning"); } else if (GetAsyncKeyState(VK_F2)) { resizeSubX(textSubX - 10); AddSub(1, "Positioning"); } }
		if (CurrentOpt == 11) { if (GetAsyncKeyState(VK_F1)) { resizeSubY(textSubY + 10); AddSub(1, "Positioning"); } else if (GetAsyncKeyState(VK_F2)) { resizeSubY(textSubY - 10); AddSub(1, "Positioning"); } }
		if (CurrentOpt == 12) { if (GetAsyncKeyState(VK_F1)) { resizeSubS(textSubScale + 0.1); AddSub(1, "Positioning"); } else if (GetAsyncKeyState(VK_F2)) { resizeSubS(textSubScale - 0.1); AddSub(1, "Positioning"); } }
		//scroller pos.
		if (CurrentOpt == 13) { if (GetAsyncKeyState(VK_F1)) { resizeScrollerY(scrollerY1 + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeScrollerY(scrollerY1 - 10); } }
		if (CurrentOpt == 14) { if (GetAsyncKeyState(VK_F1)) { resizeScrollerX(scrollerX1 + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeScrollerX(scrollerX1 - 10); } }
		if (CurrentOpt == 15) { if (GetAsyncKeyState(VK_F1)) { resizeScrollerW(scrollerW1 + 10); } else if (GetAsyncKeyState(VK_F2)) { resizeScrollerW(scrollerW1 - 10); } }
		break;
	case Menu15: //weapons menu "Gold Deagle", "AC130 105mm", "AC130 40mm", "AC130 25mm", "DW Intervention", "DW FN Fal", "Default Weapon", "DW RPG", "", ""
		if (CurrentOpt == 0) { giveWeaponNonAkimbo(GetLocalClient(), "deserteaglegold_mp"); } //GOLD DEAGLE
		if (CurrentOpt == 1) { giveWeaponAkimbo(GetLocalClient(), "scar_mp"); } //scar
		if (CurrentOpt == 2) { giveWeaponAkimbo(GetLocalClient(), "m16_mp"); } //m16_mp
		if (CurrentOpt == 3) { giveWeaponAkimbo(GetLocalClient(), "cheytac_fmj_mp"); } //DW INTERVENTION
		if (CurrentOpt == 4) { giveWeaponAkimbo(GetLocalClient(), "fal_xmags_mp"); } //DW FAL
		if (CurrentOpt == 5) { giveWeaponAkimbo(GetLocalClient(), "defaultweapon_mp"); } //DEFAULT WEAPON
		if (CurrentOpt == 6) { giveWeaponAkimbo(GetLocalClient(), "rpg_mp"); } //DW RPG
		if (CurrentOpt == 7) { giveWeaponAkimbo(GetLocalClient(), "uzi_acog_silencer_mp"); }
		if (CurrentOpt == 8) { giveWeaponAkimbo(GetLocalClient(), "aa12_grip_xmags_mp"); }
		if (CurrentOpt == 9) { TakePWeapons(GetLocalClient()); } //remove weapons
		break; //GET THIS DONE TODAY! 
	case Menu16://all client menu
		if (CurrentOpt == 0) { for (int i = 0; i < 17; i++) { ACSunlock(i); } }// unlock all
		if (CurrentOpt == 1) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2056 206426"); } }//rank
		if (CurrentOpt == 2) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2076 C09EF87F 2084 A401 2072 C09EF87F 2096 89A20A 2092 89A20A 2152 C09EF87F 2156 3905 2116 00EB41 2120 00EB41 2128 C09EF87F 2132 A401 2136 89A20A 2140 3905 2080 3905"); } }//derank
		if (CurrentOpt == 3) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2056 206426 2076 16D801 2084 B8A8 2120 005E1A 2128 3B32 2132 CE0D 2096 85E8 2092 8948 2136 35 2140 2B 2080 39 2152 F4F901 2156 F94709"); } }//legit stats
		if (CurrentOpt == 4) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 00000"); } }//prestige 0
		if (CurrentOpt == 5) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 01000"); } }//1
		if (CurrentOpt == 6) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 02000"); } }//2
		if (CurrentOpt == 7) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 03000"); } }//3
		if (CurrentOpt == 8) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 04000"); } }//4
		if (CurrentOpt == 9) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 05000"); } }//5
		if (CurrentOpt == 10) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 06000"); } }//6
		if (CurrentOpt == 11) { for (int i = 0; i < 17; i++) SV(i, 0, "J 2064 07000"); {} }//7
		if (CurrentOpt == 12) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 08000"); } }//8
		if (CurrentOpt == 13) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 09000"); } }//9
		if (CurrentOpt == 14) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 2064 0A000"); } }//10
		if (CurrentOpt == 15) { for (int i = 0; i < 17; i++) { ACSunlock(i); quickRecovery(i); } }// quick recovery
		if (CurrentOpt == 16) { for (int i = 0; i < 17; i++) { SV(i, 0, "J 3040 5E31436C617373204F6E650000 3104 5E32436C6173732054776F0000 3168 5E33436C6173732054687265650000 3232 5E34436C61737320466F75720000 3296 5E35436C61737320466976650000 3360 5E36436C617373205369780000 3424 5E32436C61737320536576656E0000 3488 5E31436C6173732045696768740000 3552 5E35436C617373204E696E650000 3616 5E34436C6173732054656E00000"); } }
		break;
	case Menu17://infections menu
		if (CurrentOpt == 0) { SV(-1, 0, "s ui_mapname \"^4https://github.com/Zcxq\""); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^3Map Name Spoofed Sucessfully!\""); }
		if (CurrentOpt == 1) { SV(-1, 0, "s ui_gametype \"^2Gay^6Mode ^5Suck^3Match\"");  SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^3Game Mode Spoofed Sucessfully!\""); }
		if (CurrentOpt == 2) { SV(-1, 0, "s ui_gametype \"^2Zcxq-'s Modded Lobby\""); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^3Game Mode Spoofed Sucessfully!\""); }
		if (CurrentOpt == 3) { SV(-1, 0, "s scr_nuketimer \"1337\""); SV_GameSendServerCommand(GetLocalClient(), 1, "f \"^1Get A nuke... Idiot\""); }
		if (CurrentOpt == 4) { SV(-1, 0, "s ui_"); } //think of something
		break;
	case Menu18://new layouts 
		if (CurrentOpt == 0) {}
		if (CurrentOpt == 1) {}
		if (CurrentOpt == 2) {}
		if (CurrentOpt == 3) {}
		break;
	case Menu19://All Client Fun 
		if (CurrentOpt == 0) { for (int i = 0; i < 17; i++) { thirdPersonMode = !thirdPersonMode; thirdPersonMode ? SV(i, 0, "s camera_thirdPerson \"1\"") : SV(i, 0, "s camera_thirdPerson \"0\""); } } //thirdperson s camera_thirdPerson 
		if (CurrentOpt == 1) { for (int i = 0; i < 17; i++) { vision = !vision; vision ? SV(i, 0, "s r_specularmap \"3\"") : SV(i, 0, "s r_specularmap \"0\""); } } //chrome mod
		if (CurrentOpt == 2) { for (int i = 0; i < 17; i++) { giveWeaponNonAkimbo(i, "deserteaglegold_mp"); } } //gold deagle
		if (CurrentOpt == 3) { for (int i = 0; i < 17; i++) { giveWeaponAkimbo(i, "defaultweapon_mp"); } } //dw intervention
		if (CurrentOpt == 4) { for (int i = 0; i < 17; i++) { vision = !vision; vision ? SV(i, 0, "s r_fullbright \"1\"") : SV(i, 0, "s r_fullbright \"0\""); } } //full bright vision
		break;

	}

}
void GoBack() {

	switch (CurrentMenu) {
	case MainMenu:
		if (CurrentMenu == MainMenu) { MenuOpened = true; }
		break;
	case Menu1:
		if (CurrentMenu == Menu1) { CurrentMenu = MainMenu; CurrentOpt = 0; }
		break;
	case Menu2:
		if (CurrentMenu == Menu2) { CurrentMenu = MainMenu; CurrentOpt = 1; }
		break;
	case Menu3:
		if (CurrentMenu == Menu3) { CurrentMenu = MainMenu; CurrentOpt = 2; }
		break;
	case Menu4:
		if (CurrentMenu == Menu4) { CurrentMenu = MainMenu; CurrentOpt = 3; }
		break;
	case Menu5:
		if (CurrentMenu == Menu5) { CurrentMenu = MainMenu; CurrentOpt = 4; }
		break;
	case Menu6:
		if (CurrentMenu == Menu6) { CurrentMenu = MainMenu; CurrentOpt = 5; }
		break;
	case Menu7:
		if (CurrentMenu == Menu7) { CurrentMenu = MainMenu; CurrentOpt = 6; }
		break;
	case Menu8:
		if (CurrentMenu == Menu8) { CurrentMenu = MainMenu; CurrentOpt = 7; }
		break;
	case Menu9:
		if (CurrentMenu == Menu9) { CurrentMenu = MainMenu; CurrentOpt = 8; }
		break;
	case Menu10:
		if (CurrentMenu == Menu10) { CurrentMenu = MainMenu; CurrentOpt = 9; }
		break;
	case Menu11:
		if (CurrentMenu == Menu11) { CurrentMenu = MainMenu; CurrentOpt = 10; }
		break;
	case Menu12:
		if (CurrentMenu == Menu12) { CurrentMenu = MainMenu; CurrentOpt = 11; }
		break;
	case Menu13:
		if (CurrentMenu == Menu13) { CurrentMenu = MainMenu; CurrentOpt = 12; }
		break;
	case Menu14:
		if (CurrentMenu == Menu14) { CurrentMenu = MainMenu; CurrentOpt = 13; }
		break;
	case Menu15:
		if (CurrentMenu == Menu15) { CurrentMenu = MainMenu; CurrentOpt = 14; }
		break;
	case Menu16:
		if (CurrentMenu == Menu16) { CurrentMenu = MainMenu; CurrentOpt = 15; }
		break;
	case Menu17:
		if (CurrentMenu == Menu17) { CurrentMenu = MainMenu; CurrentOpt = 16; }
		break;
	case Menu18:
		if (CurrentMenu == Menu18) { CurrentMenu = MainMenu; CurrentOpt = 17; }
		break;
	case Menu19:
		if (CurrentMenu == Menu19) { CurrentMenu = MainMenu; CurrentOpt = 18; }
		break;
	}
}
void ButtonMonitor() {
	wiat++;
	if (wiat > 6) {
		if (!MenuOpened) {
			if (GetAsyncKeyState(VK_INSERT)) {
				MenuOpened = true;
				CurrentOpt = 0;
				CurrentMenu = MainMenu;
				ScrollerY = scrollerY1;
			}
		}
		else {
			if (GetAsyncKeyState(VK_INSERT)) {
				MenuOpened = false;
			}
			if (GetAsyncKeyState(VK_UP)) {
				CurrentOpt--;
				if (CurrentOpt < 0) {
					CurrentOpt = MaxScroll;
				}
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				CurrentOpt++;
				if (CurrentOpt > MaxScroll) {
					CurrentOpt = 0;
				}
			}
			if (GetAsyncKeyState(VK_SPACE)) {
				SelectSub();
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				SelectOpt();
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				GoBack();
			}
		}
		wiat = 0;
		if (saveLoadBind != false) {
			if (GetAsyncKeyState(VK_F6)) {
				SV(-1, 0, "c \"^5Saved Location :)\"");
				//saveLocation(); 
				Teli(0);
			}
			if (GetAsyncKeyState(VK_F7)) {
				SV(-1, 0, "c \"^5Loaded Location :)\"");
				//loadLocation();
				Teli(1);
			}
		}

	}
}
void RunMenu() {
	ButtonMonitor();
	if (MenuOpened) {
		if (ScrollerY < (resizeScrollerY(scrollerY1) + (CurrentOpt * 30))) {
			ScrollerY += 10;
		}
		if (ScrollerY > (resizeScrollerY(scrollerY1) + (CurrentOpt * 30)))
		{
			ScrollerY -= 10;
		}
		if (MenuOpened)DrawMenu();
	}
}







