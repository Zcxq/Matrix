#pragma once
#include "tpOptions.h"
#include <string>
#include "main.h"

int wiat, CurrentMenu, CurrentOpt, MaxScroll, ScrollerY, clientShader;
bool MenuOpened;
bool saveLoadBind = false;
bool hToggleAimbot = false;
bool AC130105mm = false;
bool AC13035mm = false;
bool AC13025mm = false;
bool RPGBullets = false;
bool bGodmode;
bool bNoclip;
bool unlimitedAmmo;
bool thirdPersonMode;
const char* customName = "^5YT.com/GazzasLobbies";

struct Ammotest
{
	uint32_t ammoPrimaryReserve; //0x0000
	char pad_0004[100]; //0x0004
	uint32_t ammoSecondaryClip; //0x0068
	char pad_006C[20]; //0x006C
	uint32_t ammoPrimaryClip; //0x0080
	char pad_0084[956]; //0x0084
}; //Size: 0x0440
struct myStats {
	int32_t xp; //0x0000
	char pad_0004[4]; //0x0004
	int32_t prestige; //0x0008
	char pad_000C[4]; //0x000C
	int32_t score; //0x0010
	int32_t kills; //0x0014
	int32_t streak; //0x0018
	int32_t deaths; //0x001C
	char pad_0020[4]; //0x0020
	int32_t assists; //0x0024
	int32_t headshots; //0x0028
	char pad_002C[8]; //0x002C
	int32_t timeOne; //0x0034
	int32_t timeTwo; //0x0038
	int32_t timeThree; //0x003C
	char pad_0040[8]; //0x0040
	int32_t wins; //0x0048
	int32_t losses; //0x004C
	int32_t ties; //0x0050
	int32_t winstreak; //0x0054
	char pad_0058[1002]; //0x0058
}; //Size: 0x0442
struct ClassNames {
	char* ClassTextOne[16]; //0x0000
	char pad_0010[48]; //0x0010
	char ClassTextTwo[16]; //0x0040
	char pad_0050[48]; //0x0050
	char ClasstextThree[16]; //0x0080
	char pad_0090[48]; //0x0090
	char ClasTextFour[16]; //0x00C0
	char pad_00D0[48]; //0x00D0
	char ClassTextFive[16]; //0x0100
	char pad_0110[48]; //0x0110
	char ClassTextSix[16]; //0x0140
	char pad_0150[48]; //0x0150
	char ClassTextSeven[16]; //0x0180
	char pad_0190[48]; //0x0190
	char ClassTextEight[16]; //0x01C0
	char pad_01D0[48]; //0x01D0
	char ClassTextNine[16]; //0x0200
	char pad_0210[48]; //0x0210
	char ClassTextTen[16]; //0x0240
	char pad_0250[616]; //0x0250
}; //Size: 0x04B8

myStats* pStats;
Ammotest* localPlayerAmmo;
ClassNames* customNames;

//host shit

char* (*va)(const char* fmt, ...) = (char* (*)(const char*, ...))0x005C1F80;



void G_Damage(int targ, int inflictor, int attacker, const float* dir, const float* point, int damage, int dFlags, int mod, int weapon, int hitLoc, unsigned int modelIndex, unsigned int partName, int timeOffset) { ((void(*)(int, int, int, const float*, const float*, int, int, int, int, int, unsigned int, unsigned int, int))0x00526ED0)(targ, inflictor, attacker, dir, point, damage, dFlags, mod, weapon, hitLoc, modelIndex, partName, timeOffset); }
int GetCurrentWeapon(int Client) { return *(int*)(0x01B0E1C0 + (Client * 0x366C) + 0x2B4); }
int GEntity(int Client) { return (0x0194B9D0 + (Client * 0x274)); }



bool isAlive(int Client)
{
	if (*(int*)(0x0194B9D0 + (Client * 0x274) + 0x19C) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool SameTeam(int Client1, int Client2)
{
	if ((*(int*)(0x01B1139C + (0x366C * Client1))) == (*(int*)(0x01B1139C + (0x366C * Client2))))
	{
		return true;
	}
	else
	{
		return false;
	}
}
float Distance(Vector3 a, Vector3 b) {
	float A = a.x - b.x, B = a.y - b.y, C = a.z - b.z;
	return sqrtf((float)(A * A) + (B * B) + (C * C));
}
Vector3 GetOrigin2(int Client) {
	Vector3 Position = { *(float*)(0x0194B9D0 + (0x274 * Client) + 0x28), *(float*)(0x0194B9D0 + (0x274 * Client) + 0x2C), *(float*)(0x0194B9D0 + (0x274 * Client) + 0x30) };
	return Position;
}
const char* Dvar_GetString(const char* dvar) { return((const char* (*)(const char*))0x005BD000)(dvar); }
int NearestClient(int Client)
{
	float nearestP = 999999999.0f;
	int nearestC = -1;
	for (int i = 0; i < 18; i++)
	{
		if (i != Client)
		{
			if (isAlive(i))
			{
				float dist = Distance(GetOrigin2(i), GetOrigin2(Client));
				if (!strcmp(Dvar_GetString("ui_gametype"), "dm"))
				{
					if (dist < nearestP)
					{
						nearestP = dist;
						nearestC = i;
					}
				}
				else
				{
					if (!SameTeam(i, Client))
					{
						if (dist < nearestP)
						{
							nearestP = dist;
							nearestC = i;
						}
					}

				}
			}
		}
	}
	return nearestC;
}
void Scr_AddInt(int A) { ((void(*)(int))0x00580F40)(A); }
void Scr_AddFloat(float A) { ((void(*)(float))0x00580F90)(A); }
void Scr_AddVector(Vector3 ssssssss) { ((void(*)(float*))0x00581210)((float*)&ssssssss); }
void Scr_SetNumParam(int A) { *(int*)(0x01FDE0F8) = A; }
void Scr_ClearOutParams() { ((void(*)())0x0057F480)(); }
int Scr_GetSelf(unsigned int threadId) { return((int(*)(unsigned int))0x0057B630)(threadId); }
const char* SL_ConvertToString(int string) { return((const char* (*)(int))0x00579AF0)(string); }
void Scr_AddChar(const char* A) { ((void(*)(const char*))0x00581100)(A); }
Vector3 GScr_GetTagOrigin(int Client, const char* tag) {
	Scr_AddChar(tag);
	Scr_SetNumParam(1);
	((float* (*)(int))0x00541450)(Client);
	Vector3 Origin = *(Vector3*)(0x1B4DC8C);
	Scr_ClearOutParams();
	return Origin;
}
Vector3 PlayerAnglesToForward(int clientIndex, float Distance) {
	Vector3 Angles = { *(float*)(0x0194B9D0 + (0x274 * clientIndex) + 0x4C), *(float*)(0x0194B9D0 + (0x274 * clientIndex) + 0x50), *(float*)(0x0194B9D0 + (0x274 * clientIndex) + 0x54) };
	Vector3 Position = GScr_GetTagOrigin(clientIndex, "tag_eye");
	float angle, sr, sp, sy, cr, cp, cy, PiDiv;
	PiDiv = ((float)3.14159265358979323846 / 180.0f);
	angle = Angles.y * PiDiv;
	sy = (float)sin(angle);
	cy = (float)cos(angle);
	angle = Angles.x * PiDiv;
	sp = (float)sin(angle);
	cp = (float)cos(angle);
	angle = Angles.z * PiDiv;
	sr = (float)sin(angle);
	cr = (float)cos(angle);
	Vector3 Forward = { (cp * cy * Distance) + Position.x, (cp * sy * Distance) + Position.y, (-sp * Distance) + Position.z };
	return Forward;
}
void GScr_MagicBullet(const char* bullet, Vector3 start, Vector3 end, int ent)
{
	Scr_AddInt(ent);
	Scr_AddVector(end);
	Scr_AddVector(start);
	Scr_AddChar(bullet);
	Scr_SetNumParam(4);
	((void(*)())0x00542380)();
	Scr_ClearOutParams();
}
int GetLocalClientA() { return *(int*)(0x008A0ED0 + 0x104); }
int Scr_LocalPlayer() { return *(int*)(0x008A0ED0 + 0x104); }

void Cmd_RegisterNotification(int client, const char* action, const char* notification) { ((void(*)(int, const char*, const char*))0x00564810)(client, action, notification); }
DWORD DDD;
// boring shit 
void WriteByte(__int32 address, BYTE _byte) {
	DWORD OLD;

	VirtualProtect((LPVOID)address, 1, PAGE_READWRITE, &OLD);
	*(BYTE*)(address) = _byte;
	VirtualProtect((LPVOID)address, 1, OLD, &OLD);
}
void noRecoil() {
	static bool _person = false;
	_person = !_person;
	WriteByte(0x00479F60, _person ? 0x83 : 0xC3);
}
void redBoxes() {
	static bool _person = false;
	_person = !_person;
	WriteByte(0x004B751E, _person ? 0x75 : 0x90);//perk check 
	WriteByte(0x004B751F, _person ? 0x6F : 0x90); // second perk check
	WriteByte(0x004885A5, _person ? 0x74 : 0x75);//redboxes
}
void noKick() {
	static bool _person = false;
	_person = !_person;
	WriteByte(0x004A0850, _person ? 0xC3 : 0x83);
}
void wallHack() {
	//0x0638FCF0, 0638FCF1, 0638FCF2, 0638FCF3 0x00, 0x00, 0x34, 0x42
	static bool _person = false;
	_person = !_person;
	WriteByte(0x04A03CE, _person ? 0x0F : 0x04);
	WriteByte(0x04A03CF, _person ? 0xFF : 0x01);
	WriteByte(0x04A03D0, _person ? 0xFF : 0x00);
	WriteByte(0x04A03D1, _person ? 0xFF : 0x00);
}
void thirdPerson() {
	static bool _person = false;
	_person = !_person;
	WriteByte(0x06386DD8, _person ? 0x00 : 0x01);
}
void noSpread() {
	static bool _person = false;
	_person = !_person;
	WriteByte(0x0047A1AF, _person ? 0X74 : 0X75);
}
void superjump() {

	static bool Nice = false;
	Nice = !Nice;
	WriteByte(0x67EC88, Nice ? 0x00 : 0x00);
	WriteByte(0x67EC89, Nice ? 0xC0 : 0x00);
	WriteByte(0x67EC8A, Nice ? 0x79 : 0x1C);
	WriteByte(0x67EC8B, Nice ? 0x44 : 0x42);
}
void Speed() {
	static bool _person = false;
	_person = !_person;
	WriteByte(0x0051D67A, _person ? 0xBE : 0xEE);
	WriteByte(0x0051D67B, _person ? 0x00 : 0x02);
}
void ForceHost() {
	static bool _person = false;
	_person = !_person;
	//0638CB5C change to 0x01
	//0638CB6C change to 0x12
	WriteByte(0x0638CB5C, 0x01);
	WriteByte(0x0638CB6C, 0x12);
}
void ExplosiveBullets() {
	static bool _person = false;
	_person = !_person;
	WriteByte(0x0639A5DC, _person ? 0x00 : 0x01); // EB On
	WriteByte(0x0639A628, 0x11); // EB Range 0x0639A628
	WriteByte(0x0639A676, 0xFA); // EB Radius 0x0639A674
}
void DoubleSpeed(int Client, int Value, int Value2) { *(int*)(0x01B1138A + (GetLocalClientA() * 0x366C)) = Value; *(int*)(0x01B1138B + (GetLocalClientA() * 0x366C)) = Value2; }
void (*Cbuf_AddText)(int localClientNum, const char* text) = (void(*)(int, const char*))0x00563D10;
void SV_GameSendServerCommandA(int Client, int Reliable, const char* fmt) { ((void(*)(int, int, const char*))0x00588480)(Client, Reliable, fmt); }

//misc menu shit. 
int GetLocalClientNumber() {
	return *(int*)(0x008A0ED0 + 0x104);
}

void EndGame() { Cbuf_AddText(0, va("cmd mr %i -1 endround;")); } //implement
void FastRestart() { ((void(*)())0x005853E0)(); }
void setHealth(int Client, int Health) {
	*(int*)(0x01B11374 + (Client * 0x366C)) = Health;
	*(int*)(0x0194BB6C + (Client * 0x274)) = Health;
}
void LowGravity(int Value) {
	VirtualProtect((LPVOID)0x0051DEF6, 4, PAGE_EXECUTE_READWRITE, &DDD);
	*(int*)(0x0051DEF6) = Value;
}
int GetCurrentOffhand(int Client)
{
	return *(int*)(0x01B0E1C0 + (Client * 0x366C) + 0x2A8);
}
void Add_Ammo(int clientEntity, int weaponIndex, char weaponModel, int count, int fillClip)
{
	//Call<void>(0x0052B530, clientEntity, weaponIndex, weaponModel, count, fillClip); 0x52B530
	((void(*)(int, int, char, int, int))0x0052B530)(clientEntity, weaponIndex, weaponModel, count, fillClip);
}
void UnlimitedTime() {

	Cbuf_AddText(0, "set scr_war_timelimit 0;");
	Cbuf_AddText(0, "set scr_dm_timelimit 0;");
	SV_GameSendServerCommandA(GetLocalClientNumber(), 1, "f \"Infinite Time: ^2Set\"");
}
void noClip(int Client, int Value) { *(int*)(0x01B11554 + (Client * 0x366C)) = Value; }
//end of misc 

bool fov; 
void FOV(int value) {
	//float MyFOV = 120;
	int cg_fov = *(int*)(0x00AAC278);
	*(float*)(cg_fov + 0xC) = value;
}

//xp lobby shit 
bool gXPLobby;
void XPLobby(int Value) {
	gXPLobby = !gXPLobby;
	SV_GameSendServerCommandA(GetLocalClientA(), 1, gXPLobby ? "f \"XP Lobby: ^2ON\"" : "f \"XP Lobby: ^1OFF\"");
	Cbuf_AddText(0, gXPLobby ? va("set scr_%s_score_kill %i;set scr_%s_scorelimit 0;", Dvar_GetString("g_gametype"), Value, Dvar_GetString("g_gametype")) : va("set scr_%s_score_kill %i;set scr_%s_scorelimit 7500;", Dvar_GetString("g_gametype"), 100, Dvar_GetString("g_gametype")));

}


//spawnable shit 
Vector3 Vector(float x, float y, float z) { Vector3 M = { x, y, z }; return M; }
int GetEntity(int num) { return (0x01B14E98 + (0x274 * num)); }
void(*G_SetModel)(int clientIndex, const char* Model) = (void(*)(int, const char*))0x0054DDB0;
int(*G_Spawn)() = (int(*)())0x0054E600;
void(*SV_SetBrushModel)(int Entity) = (void(*)(int))0x00588600;
void(*SP_Script_Model)(int Entity) = (void(*)(int))0x00549120;
void(*SV_linkEntity)(int Entity) = (void(*)(int))0x005901D0;
int sEntity;
int SpawnEntity(Vector3 Origin, Vector3 Angles, const char* Model = "com_plasticcase_friendly", int Index = 4)
{
	sEntity = (int)G_Spawn();
	*(Vector3*)(sEntity + 0x138) = Origin;
	*(Vector3*)(sEntity + 0x144) = Angles;
	G_SetModel(sEntity, Model);
	SP_Script_Model(sEntity);
	*(char*)(sEntity + 0x16D) = 4;
	*(int*)(sEntity + 0x84) = Index;
	SV_SetBrushModel(sEntity);
	SV_linkEntity(sEntity);
	return sEntity;
} // spawns just a case!

void antileavexd(int i)
{
	SV_GameSendServerCommand(i, 0, "s a");
}
bool x2Speedos;
bool noClipos;
void noClip(int value) { *(char*)(0x001B11554 + (GetLocalClient() * 0x366c)) = value;}
void x2Speed(int offset) {*(int*)(0x01B11388 + (GetLocalClient() * 0x366C )) = offset;}

void (*G_GivePlayerWeapon)( int pPS, int iWeaponIndex, char altModelIndex, int Akimbo) = (void(*)(int, int, char, int))0x00550ED0; //Specifies the type of weapon, attachments, and akimbo 0x550ED0
int (*G_GetWeaponIndexForName)(const char* name) = (int(*)(const char*))0x00550AD0; //specifies the weapon index 0x550AD0
int (*G_TakePlayerWeapon)(int a1, int a2) = (int(*)(int, int))0x00550D90;
//takweapons
int (*Bg_TakePlayerWeapon)(int pState, int weapIndex, int clip) = (int(*)(int, int, int))0x00479E70;
int (*BG_GetWeaponDefs)(int a) = (int(*)(int))0x00479510;
int (*BG_GetViewmodelWeaponIndex)(int a1) = (int(*)(int))0x004795C0;
//void BG_TakePlayerWeapon(G_GetClientState(0), BG_GetViewmodelWeaponIndex(G_GetClientState(0)), 1);
void(*Scr_AddString2)(const char* A) = (void(*)(const char*))0x00581100;

void TakePWeapons(int Client) {
	Bg_TakePlayerWeapon(0x1B0E1C0 + (Client * 0x366c), BG_GetViewmodelWeaponIndex(0x1B0E1C0 + (Client * 0x366c)), 1);
	
}
void giveWeaponNonAkimbo(int client, const char* weapon){
	int weaponIndex = G_GetWeaponIndexForName(weapon);
	
	G_GivePlayerWeapon(0x1B0E1C0 + (client * 0x366c), weaponIndex, 0 , 0);
	Add_Ammo(0x194B9D0 + client * 0x274, weaponIndex, 0, 9999, 1);
	char CmdBuff[0x20];
	sprintf_s(CmdBuff, "a %i", weaponIndex);
	SV_GameSendServerCommand(client, 1, "f \"^2Weapon Given");
	 
}
void giveWeaponAkimbo(int client, const char* weapon) {
	TakePWeapons(client);
	int weaponIndex = G_GetWeaponIndexForName(weapon);
	G_GivePlayerWeapon(0x1B0E1C0 + (client * 0x366c), weaponIndex, 0, 1);
	Add_Ammo(0x194B9D0 + (client * 0x274), weaponIndex, 0, 9999, 1); //need to make unlimited 
}

