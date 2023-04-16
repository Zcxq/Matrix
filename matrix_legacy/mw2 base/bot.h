#pragma once
#include <xatomic.h>
#pragma once
struct cmd_function_s
{
	cmd_function_s* next;
	const char* name;
	void(__cdecl* function)();
};



struct usercmd_s
{
	char data[44];
};

struct sprintState_t {
	int sprintButtonUpRequired;
	int sprintDelay;
	int lastSprintStart;
	int lastSprintEnd;
	int sprintStartMaxLength;
};

struct mantleState_t {
	float yaw;
	int timer;
	int transIndex;
	int flags;
};
enum clientConnected_t : int
{
	CON_DISCONNECTED = 0x0,
	CON_CONNECTING = 0x1,
	CON_CONNECTED = 0x2,
};
enum weaponstate_t : __int32 {
	WEAPON_READY = 0x0,
	WEAPON_RAISING = 0x1,
	WEAPON_RAISING_ALTSWITCH = 0x2,
	WEAPON_DROPPING = 0x3,
	WEAPON_DROPPING_QUICK = 0x4,
	WEAPON_DROPPING_ALTSWITCH = 0x5,
	WEAPON_FIRING = 0x6,
	WEAPON_RECHAMBERING = 0x7,
	WEAPON_RELOADING = 0x8,
	WEAPON_RELOADING_INTERUPT = 0x9,
	WEAPON_RELOAD_START = 0xA,
	WEAPON_RELOAD_START_INTERUPT = 0xB,
	WEAPON_RELOAD_END = 0xC,
	WEAPON_MELEE_INIT = 0xD,
	WEAPON_MELEE_FIRE = 0xE,
	WEAPON_MELEE_END = 0xF,
	WEAPON_OFFHAND_INIT = 0x10,
	WEAPON_OFFHAND_PREPARE = 0x11,
	WEAPON_OFFHAND_HOLD = 0x12,
	WEAPON_OFFHAND_START = 0x13,
	WEAPON_OFFHAND = 0x14,
	WEAPON_OFFHAND_END = 0x15,
	WEAPON_DETONATING = 0x16,
	WEAPON_SPRINT_RAISE = 0x17,
	WEAPON_SPRINT_LOOP = 0x18,
	WEAPON_SPRINT_DROP = 0x19,
	WEAPON_NIGHTVISION_WEAR = 0x1A,
	WEAPON_NIGHTVISION_REMOVE = 0x1B,
};

enum sessionState_t : int
{
	SESS_STATE_PLAYING = 0x0,
	SESS_STATE_DEAD = 0x1,
	SESS_STATE_SPECTATOR = 0x2,
	SESS_STATE_INTERMISSION = 0x3,
};

struct WeaponState {
	int weapAnim;
	int weaponTime;
	int weaponDelay;
	int weaponRestrictKickTime;
	weaponstate_t weaponstate;
	int weapHandFlags;
	int weaponShotCount;
};

struct AmmoReserve {
	int weapon;
	int reserveAmmo;
};

struct AmmoCurrent {
	int weapon;
	int ammo;
	int akimboAmmo;
};

struct playerState_s {
	int commandTime;
	int pm_type;
	int bobCycle;
	int pm_flags;
	int otherFlags;
	int linkFlags;
	int pm_time;
	float origin[3];
	float velocity[3];
	int weaponTime;
	int weaponDelay;
	int grenadeTimeLeft;
	int throwBackGrenadeOwner;
	int remoteEyesEnt;
	int remoteEyesTagName;
	int remoteControlEnt;
	int foliageSoundTime;
	int gravity;
	float leanf;
	int speed;
	float delta_angles[3];
	int groundEntityNum;
	float vLadderVec[3];
	int jumpTime;
	float jumpoOriginZ;
	int legsTimer;
	int legsAnim;
	int torsoTimer;
	int torsoAnim;
	int legsAnimDuration;
	int torsoAnimDuration;
	int damageTimer;
	int damageDuration;
	int flinchYawAnim;
	int corspeIndex;
	int movementDir;
	int eFlags;
	int eventSequence;
	int events[4];
	int eventParms[4];
	int oldEventSequence;
	int unpredictableEventSequence;
	int unpredictableEventSequenceOld;
	int unpredictableEvents[4];
	int unpredictableEventParms[4];
	int clientNum;
	int viewModelIndex;
	float viewAngles[3];
	int viewHeightTarget;
	float viewHeightCurrent;
	int viewHeightLerpTime;
	int viewHeightLerpTarget;
	int viewHeightLerpDown;
	float viewAngleClampBase[2];
	float viewAngleClampRange[2];
	int damageEvent;
	int damageYaw;
	int damagePitch;
	int damageCount;
	int kills;
	int health;
	int assists;
	int maxHealth;
	int deaths;
	float proneDirection;
	float proneDirectionPitch;
	float proneTorsoPitch;
	int viewlocked;
	int viewlocked_entNum;
	char pad_0x0174[68];
	sprintState_t sprintState;
	float holdBreathScale;
	int holdBreathTimer;
	float moveSpeedScaleMultiplier;
	mantleState_t mantleState;
	WeaponState weaponState;
	char pad_0x0204[28];
	int weapons[15];
	char pad_0x025C[76];
	int offHandIndex;
	int offhandPrimaryClass;
	int offHandSecondaryClass;
	int weapon;
	int primaryWeaponForAltMode;
	int weapFlags;
	float fWeaponPosFrac;
	float aimSpreadScale;
	int adsDelayTime;
	int spreadOverride;
	int spreadOverrideState;
	int isDualWielding;
	AmmoReserve ammoReserve[15];
	AmmoCurrent ammoCurrent[15];
	char pad_0x0404[20];
};

struct playerTeamState_t
{
	int location;
};
enum team_t
{
	TEAM_FREE = 0x0,
	TEAM_AXIS = 0x1,
	TEAM_ALLIES = 0x2,
	TEAM_SPECTATOR = 0x3,
};
struct clientState_s
{
	int clientIndex;
	team_t team;
	int modelindex;
	int dualWielding;
	int riotShieldNext;
	int attachModelIndex[6];
	int attachTagIndex[6];
	char name[0x20];
	float maxSprintTimeMultiplier;
	int rank;
	int prestige;
	int perks[2];
	int diveState;
	int voiceConnectivityBits;
	char clanAbb[4];
};

struct clientSession_t {
	sessionState_t sessionState;
	int clientNum;
	int score;
	int deaths;
	int kills;
	int assists;
	__int16 scriptPersID;
	__int16 undefined;
	clientConnected_t connected;

	int localClient;
	int predictItemPickup;
	char name[32];
	int maxHealth; //0x3228
	int enterTime; //0x322C
	playerTeamState_t teamState; //0x3230
	int voteCount; //0x3234
	int teamVoteCount; //0x3238
	float moveSpeedScaleMultiplier; //0x323C
	int viewmodelIndex; //0x3240
	int noSpectate; //0x3244
	int teamInfo; //0x3248
	clientState_s _cs; //0x324C
	char unknown_data6[0x10]; //0x32D0
	int psOffsetTime;
	int hasRadar; //0x32E4
	int isRadarBlocked;
	char unknown_data5[0x130]; //0x32D0
};

struct gclient_s {
	playerState_s playerState;
	clientSession_t clientSession;
	char pad_0x33C4[0x2A8];
};

enum trType_t {
	TR_STATIONARY = 0x0,
	TR_INTERPOLATE = 0x1,
	TR_LINEAR = 0x2,
	TR_LINEAR_STOP = 0x3,
	TR_SINE = 0x4,
	TR_GRAVITY = 0x5,
	TR_ACCELERATE = 0x6,
	TR_DECELERATE = 0x7,
	TR_PHYSICS = 0x8,
	TR_RAGDOLL = 0x9,
};

struct trajectory_t {
	trType_t trType;
	int trTime;
	int trDuration;
	float trBase[3];
	float trDelta[3];
};

struct LerpEntityStateAnonymous {
	int data[9];
};

struct LerpEntityStateMissile {
	int launchTime;
	int flightMode;
};

struct LerpEntityStateScriptMover {
	int entToTakeMarksFrom;
	int xModelIndex;
	int animIndex;
	int animTime;
};

struct LerpEntityStateSoundBlend {
	int lerp;
};

struct LerpEntityStateLoopFx {
	int cullDist;
	int period;
};

struct LerpEntityStateTurret {
	float gunAngles[3];
	int lastBarrelRotChangeTime;
	int lastBarrelRotChangeRate;
	int lastHeatChangeTime;
	int lastHeatChangeLevel;
};

struct LerpEntityStateVehicle {
	int indices;
	int flags;
	int bodyPitch;
	int bodyRoll;
	int steerYaw;
	int gunPitch;
	int gunYaw;
	int playerIndex;
	int pad;
};

struct LerpEntityStatePlane {
	int ownerNum;
	int enemyIcon;
	int friendIcon;
};

struct LerpEntityStatePlayer {
	int leanf;
	int movementDir;
	int torsoPitch;
	int waistPitch;
	int offhandWeapon;
	int lastSpawnTime;
};

union LerpEntityStateTypeUnion {
	LerpEntityStateTurret turret;
	LerpEntityStateLoopFx loopFx;
	LerpEntityStatePlayer player;
	LerpEntityStateScriptMover scriptMover;
	LerpEntityStateVehicle vehicle;
	LerpEntityStatePlane plane;
	LerpEntityStateMissile missile;
	LerpEntityStateSoundBlend soundBlend;
	LerpEntityStateAnonymous anonymous;
};

struct LerpEntityState {
	int eFlags;
	trajectory_t pos;
	trajectory_t apos;
	LerpEntityStateTypeUnion u;
};

struct entityState_s {
	int number; // 0x0
	int eType; // 0x4
	LerpEntityState lerp; // 0x8
	int time2; // 0x78
	int otherEntityNum; // 0x7C
	int attackerEntityNum; // 0x80
	int groundEntityNum; // 0x84
	int loopSound; // 0x88
	int surfType; // 0x8C
	union {
		int brushmodel;
		int item;
		int xmodel;
		int primaryLight;
	} index;
	int clientNum;
	int iHeadIcon;
	int iHeadIconTeam;
	int solid;
	int eventParm;
	int eventSequence;
	int events[4];
	int eventParms[4];
	int wes;
	int legsAnim;
	int torsoAnim;
	union {
		int scale;
		int eventParm2;
		int helicopterStage;
	} un1;
	union {
		int hintString;
		int grenadeInPickupRange;
		int vehicleXModel;
	} un2; // 0xDC
	int clientLinkInfo;
	int partBits[6];
};

struct EntHandle {
	short number;
	short infoIndex;
};

struct entityShared_t {
	int clientMask;
	char linked;
	char bmodel;
	char svFlags;
	char inuse;
	float mins[3]; // 0x8
	float maxs[3]; // 0x14
	int contents; // 0x20
	float absmin[3]; // 0x24
	float absmax[3]; // 0x30
	float currentOrigin[3]; // 0x3C
	float currentAngles[3]; // 0x48
	EntHandle ownerNum; // 0x54
	int eventTime; // 0x58
};

struct gentity_s {
	entityState_s state;
	entityShared_t shared;
	gclient_s* client;
	char unknown_data2[0xC];
	short model;
	char physicsObject;
	char takedamage;
	char active;
	char handler;
	char team;
	char freeAfterEvent;
	short code_classname;
	short classname;
	short script_linkname;
	short target;
	short targetname;
	int attachIgnoreCollision;
	int spawnFlags;
	int flags;
	int unlinkAfterEvent; // 0x188
	int clipMask;  // 0x18C
	int processedFrame; // 0x190
	EntHandle parent; // 0x194
	int nextthink; // 0x198
	int health; // 0x19C
	int maxhealth; // 0x1A0
	int damage; // 0x1A4
	int count; // 0x1A8
	char __pad[0xC8];
};


cmd_function_s AddBots_t;
cmd_function_s SpawnBot_t;
cmd_function_s BotChooseTeam_t;
cmd_function_s BotChooseClass_t;
gentity_s* g_entities;

void(*SV_Cmd_ArgvBuffer)(int arg, char* buffer, int length) = (void(*)(int, char*, int))0x00564030;



bool(*Dvar_GetBool)(const char* dvar) = (bool(*)(const char*))0x005BCF60;

void(*Cmd_AddCommand)(const char* cmd, void(*func)(), cmd_function_s* fff) = (void(*)(const char*, void(*)(), cmd_function_s*))0x00564460;

void(*Cmd_RemoveCommand)(const char* cmd) = (void(*)(const char*))0x00564490;

gentity_s* botentity;
short(*SL_GetString)(const char* string, int size) = (short(*)(const char*, int))0x0057A4A0;



void(*Scr_AddString)(const char* A) = (void(*)(const char*))0x00581100;

void(*Scr_Notify)(gentity_s* ent, short stringValue, unsigned int paramcount) = (void(*)(gentity_s*, short, unsigned int))0x0054AE70;


void Cmd_MenuResponse_f(gentity_s* ent, const char* A, const char* B)
{
	Scr_AddString(B);
	Scr_AddString(A);
	Scr_Notify(ent, SL_GetString("menuresponse", 0), 2);
}
gentity_s* (*SV_AddTestClient)() = (gentity_s * (*)())0x00588280;

void(*Scr_AddEntity)(gentity_s* ent) = (void(*)(gentity_s*))0x0054AD50;




void SpawnBot() {
	if (Dvar_GetBool("cl_ingame")) {
		botentity = SV_AddTestClient();
		if (botentity) {
			Scr_AddEntity(botentity);
		}
	}
}

void BotChooseTeam() {
	if (Dvar_GetBool("cl_ingame")) {
		Cmd_MenuResponse_f(botentity, "team_marinesopfor", "autoassign");
	}
}

void BotChooseClass() {
	if (Dvar_GetBool("cl_ingame")) {
		Cmd_MenuResponse_f(botentity, "changeclass", va("class%i", rand() % 4));
	}
}

int(*Dvar_GetInt)(const char* dvar) = (int(*)(const char*))0x005BCF90;

int(*Com_sprintf)(char* a1, int a2, char* a3, ...) = (int(*)(char*, int, char*, ...))0x005C1F50;
void(*cBuf_AddText)(int local, const char* cmd) = (void(*)(int, const char*))0x00563D10;
void AddBots() {
	if (Dvar_GetBool("cl_ingame")) {
		if (*(int*)(0x008A4248 + 0x312C) < Dvar_GetInt("sv_maxclients") - 2) {
			cBuf_AddText(0, "spawnbot;wait 10;botchooseteam;wait 10;botchooseclass;");
		}
	}
}
