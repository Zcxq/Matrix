#pragma once


struct color_s {
	float r, g, b, a;
	color_s(float _r, float _g, float _b, float _a);

};
color_s::color_s(float r, float g, float b, float a)
{
	this->r = r / 255.0f;
	this->g = g / 255.0f;
	this->b = b / 255.0f;
	this->a = a / 255.0f;

}

float shaderX1 = 500;
float shaderY1 = 0;
float shaderW1 = 320;
float shaderH1 = 680;
float textTitleX = 515; 
float textTitleY = 65; 
float textTitleScale = 1.2; 
float textOptX = 515; 
float textOptY = 115;
float textOptScale = 1;
float textSubX = 515;
float textSubY = 115;
float textSubScale = 1;
float scrollerX1 = 500; 
float scrollerY1 = 85; 
float scrollerW1 = 319; 



//shader main menu below.
float resizeShaderX(float shaderSize) {
	shaderX1 = shaderSize;
	return shaderSize;
}
float resizeShaderY(float shaderSize) {
	shaderY1 = shaderSize;
	return shaderSize;
}
float resizeShaderW(float shaderSize) {
	shaderW1 = shaderSize;
	return shaderSize;
}
float resizeShaderH(float shaderSize) {
	shaderH1 = shaderSize;
	return shaderSize;
}
//title text sizing below
float resizeTitleX(float shaderSize) {
	textTitleX = shaderSize;
	return shaderSize;
}
float resizeTitleY(float shaderSize) {
	textTitleY = shaderSize;
	return shaderSize;
}
float resizeTitleS(float shaderSize) {
	textTitleScale = shaderSize;
	return shaderSize;
}
//opt text resize 
float resizeOptX(float shaderSize) {
	textOptX = shaderSize;
	return shaderSize;
}
float resizeOptY(float shaderSize) {
	textOptY = shaderSize;
	return shaderSize;
}
float resizeOptS(float shaderSize) {
	textOptScale = shaderSize;
	return shaderSize;
}
//sub text below 
float resizeSubX(float shaderSize) {
	textSubX = shaderSize;
	return shaderSize;
}
float resizeSubY(float shaderSize) {
	textSubY = shaderSize;
	return shaderSize;
}
float resizeSubS(float shaderSize) {
	textSubScale = shaderSize;
	return shaderSize;
}

float resizeScrollerX(float shaderSize) {
	scrollerX1 = shaderSize;
	return shaderSize;
}
float resizeScrollerY(float shaderSize) {
	scrollerY1 = shaderSize;
	return shaderSize;
}
float resizeScrollerW(float shaderSize) {
	scrollerW1 = shaderSize;
	return shaderSize;
}



