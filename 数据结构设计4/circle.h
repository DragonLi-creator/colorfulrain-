#pragma once
#include"init.h"
#include"creat_rain.h"

void updateRainCircle(Rain *r)//更新涟漪函数
{
	r->riffle.curR += r->riffle.rainCircleSpeed;//让当前半径变大
}
void drawRainCircle(Rain *r)//绘制涟漪函数
{
	float H = rand() % 360;// 色相
	float S = 1;		// 饱和度
	float V = 1;		// 亮度

	setlinecolor(HSVtoRGB(H, S, V));
	//画椭圆
	ellipse(r->riffle.x - r->riffle.curR, r->riffle.y - r->riffle.curR / 3, r->riffle.x + r->riffle.curR, r->riffle.y + r->riffle.curR / 3);
}
void clearRainCircle(Rain *r)//清除涟漪函数
{

	//使用池塘颜色覆盖掉涟漪，以达到清除效果
	setcolor(getpixel(r->riffle.x, r->riffle.y));
	ellipse(r->riffle.x - r->riffle.curR, r->riffle.y - r->riffle.curR / 3, r->riffle.x + r->riffle.curR, r->riffle.y + r->riffle.curR / 3);

}
void riffleInWater(Rain *r)//涟漪函数
{
	//当涟漪当前半径达到最大半径时，涟漪消失并重生雨滴
	if (r->riffle.curR >= r->riffle.r)
	{
		clearRainCircle(r);//清除涟漪函数
		reviveRaindrop(r);//雨滴重新初始化
	}
	else
	{
		clearRainCircle(r);//清除涟漪函数
		updateRainCircle(r);//更新涟漪函数使当前半径增大
		drawRainCircle(r);//绘制涟漪函数
	}
}
