#pragma once
using namespace std;
#include "main.h"
enum Addresses {
	R_AddCmdDrawText_a = 0x004113D0,
	R_RegisterFont_a = 0x004C5930,
	CG_DrawRotatedPicPhysical_a = 0x0048B580,
	Material_RegisterHandle_a = 0x0040FD60,
	scrPlacement_a = 0x10FB800,

};
enum eMenu {
	MainMenu, //0
	Menu1, //1
	Menu2, //2
	Menu3, //3
	Menu4, //4	
	Menu5,
	Menu6,
	Menu7,
	Menu8,
	Menu9,
	Menu10,
	Menu11,
	Menu12,
	Menu13,
	Menu14,
	Menu15,
	Menu16,
	Menu17, 
	Menu18,
	Menu19,
};
enum Addresses1 {
	party_minLobbyTime = 0x0638D230,
	bandwidthtest_enable = 0x0638DA34,
	connectTimeOut = 0x0638D27C,
	party_autoteams = 0x0638D198,
	party_maxTeamDiff = 0x0638D1E4,
	requireOpenNat = 0x85CCC0,
	doWeSuckAsHost = 0x6427E66,
	partymigrate_timeoutmax = 0x0638D9E8
};
color_s Red = color_s(255, 0, 0, 255);
color_s Green = color_s(0, 255, 0, 255);
color_s Blue = color_s(0, 0, 255, 255);
color_s Cyan = color_s(0, 255, 255, 255);
color_s Yellow = color_s(229, 255, 0, 255);
color_s White = color_s(255, 255, 255, 255);
color_s Pink = color_s(255, 0, 242, 255);
color_s Black_s = color_s(0, 0, 0, 200);
int MenuColor, InfoColor, InfoShaderColor, TextColor;

int r = 199;
int g = 36; 
int b = 177; 


int rS = 199; 
int gS = 36; 
int bS = 177;


//Draw Text:
void (*R_AddCmdDrawText)(const char* text, int maxChars, void* font, float x, float y, float xScale, float yScale, float rotation, const float* color, int style) = (void(*)(const char*, int, void*, float, float, float, float, float, const float*, int)) R_AddCmdDrawText_a;
void* (*R_RegisterFont)(const char* name, UINT64 imageTrack) = (void* (*)(const char*, UINT64))R_RegisterFont_a;
//Draw Shader:
void* (*Material_RegisterHandle)(const char* name, int imageTrack) = (void* (*)(const char*, int)) Material_RegisterHandle_a;
void (*CG_DrawRotatedPicPhysical)(int scrPlace, float x, float y, float width, float height, float angle, const float* color, void* material) = (void (*)(int, float, float, float, float, float, const float*, void*)) CG_DrawRotatedPicPhysical_a;
//void CG_DrawRotatedPicPhysical(int scrPlace, float x, float y, float w, float h, float angle, const float* color, void* material)
void DrawShader(float x, float y, float w, float h, color_s color, const char* material) {
	CG_DrawRotatedPicPhysical(scrPlacement_a, x, y, w, h, 0, (float*)&color, Material_RegisterHandle(material, 0));
}
void Drawtext(const char* text, float x, float y, float scale, color_s color, const char* font) {
	R_AddCmdDrawText(text, 0x7FFFFFFF, R_RegisterFont(font, 5), x, y, scale, scale, 0, (float*)&color, 0);
}
void AddInfo() {
	Drawtext("Space To Select Sub", 16, 27, 0.5, color_s(0, 255, 255, 255), "fonts/boldFont"); // work on this!
	Drawtext("Right To Select Opt", 16, 48, 0.5, color_s(0, 255, 255, 255), "fonts/boldFont"); // work on this!
	Drawtext("Left To Go Back", 16, 68, 0.5, color_s(0, 255, 255, 255), "fonts/boldFont");
}
void InfoShader() {
	DrawShader(4, 6, 235, 70, color_s(0, 0, 0, 130), "white");
	DrawShader(4, 6, 2, 70, color_s(0, 255, 255, 255), "white"); //left side bar
	DrawShader(235, 6, 2, 70, color_s(0, 255, 255, 255), "white"); //right side bar 
	DrawShader(4, 6, 232, 2, color_s(0, 255, 255, 255), "white"); //top side bar
	DrawShader(4, 75, 232, 2, color_s(0, 255, 255, 255), "white"); //bottom side bar
}
void Shaders() {
	DrawShader(resizeShaderX(shaderX1), resizeShaderY(shaderY1), resizeShaderW(shaderW1), resizeShaderH(shaderH1), Black_s, "white");
	//DrawShader(500, 0, 2, 720 + (15 * MaxScroll), Cyan, "white"); //left side bar
	//DrawShader(817, 0, 2, 720 + (15 * MaxScroll), Cyan, "white"); //right side bar
	DrawShader(resizeScrollerX(scrollerX1), ScrollerY, resizeScrollerW(scrollerW1), 35, color_s(rS, gS, bS, 255), "white"); //scroller
	//new shader size;
}
void AddTitle(const char* title) {
	Drawtext(title, resizeTitleX(textTitleX), resizeTitleY(textTitleY), resizeTitleS(textTitleScale), color_s(r, g, b, 255), "fonts/boldFont");
}
void AddName(const char* title) {
	Drawtext(title, 490, 100, 0.5, color_s(0, 255, 255, 255), "fonts/boldFont");
}
void AddOpt(int A, const char* B) {
	Drawtext(B, resizeOptX(textOptX), resizeOptY(textOptY) + (30 * A), resizeOptS(textOptScale), (CurrentOpt == A) ? color_s(0, 0, 0, 255) : color_s(255, 255, 255, 255), "fonts/boldFont");
	MaxScroll = A;
}
void AddSub(int A, const char* B) {
	Drawtext(B, resizeSubX(textSubX), resizeSubY(textSubY) + (30 * A), resizeSubS(textSubScale), (CurrentOpt == A) ? color_s(0, 0, 0, 255) : color_s(255, 255, 255, 255), "fonts/boldFont");
	MaxScroll = A;
}