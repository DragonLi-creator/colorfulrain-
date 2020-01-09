#pragma once
#include"init.h"


//檫除雨线中雨滴的上一个位置
void cleanRain(Rain *r)
{
	setfillcolor(getpixel(r->x0 + 5, r->y0 + 5));//填充背景颜色(雨滴内)
	setlinecolor(getpixel(r->x0 + 5, r->y0 + 5));//填充背景色(雨滴线)

	fillpie(r->x0, r->y0, r->x0 + 8, r->y0 + 24, r->stangle, r->endangle);//绘制黑或蓝雨滴
}
