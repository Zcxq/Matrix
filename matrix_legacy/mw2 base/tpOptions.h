#pragma once
struct Vector2 { float x, y; };
struct Vector3 { float x, y, z; };
struct Vector4 { float x, y, z; };
Vector3 SavedMe;
Vector3 GetOrigin(int Client) {
	Vector3 Position = { *(float*)(0x0194B9D0 + (0x274 * Client) + 0x28), *(float*)(0x0194B9D0 + (0x274 * Client) + 0x2C), *(float*)(0x0194B9D0 + (0x274 * Client) + 0x30) };
	return Position;
}
void SetOrigin(int Client, Vector3 Origin)
{
	*(float*)(0x01B0E1DC + (0x366C * Client)) = Origin.x;
	*(float*)(0x01B0E1E0 + (0x366C * Client)) = Origin.y;
	*(float*)(0x01B0E1E4 + (0x366C * Client)) = Origin.z;
}
int GetLocalClient() { return *(int*)(0x008A0ED0 + 0x104); }
void SV_GameSendServerCommand(int Client, int Reliable, const char* fmt) { ((void(*)(int, int, const char*))0x00588480)(Client, Reliable, fmt); }
void Teli(int Where) {
	if (Where == 0) {
		//Save
		SavedMe = GetOrigin(GetLocalClient());
		SV_GameSendServerCommand(GetLocalClient(), 1, "f \"Position Saved!\"");
	}
	if (Where == 1) {
		//Load
		SetOrigin(GetLocalClient(), SavedMe);
		SV_GameSendServerCommand(GetLocalClient(), 1, "f \"Position Loaded!\"");
	}
	if (Where == 2) {
		//Sky
		Vector3 M = { 9999999999, 0, 0 };
		SetOrigin(GetLocalClient(), M);
		SV_GameSendServerCommand(GetLocalClient(), 1, "f \"Teleported To Sky\"");
	}
	if (Where == 3) {
		Vector3 M = { 698.07, 924.07, 418.12 };
		SetOrigin(GetLocalClient(), M);
		SV_GameSendServerCommand(GetLocalClient(), 1, "f \"Teleported To Underground\"");
	}
}
