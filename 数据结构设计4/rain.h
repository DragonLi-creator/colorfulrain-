#pragma once
#include"init.h"
#include"creat_rain.h"
#include"clean_rain.h"
//整个雨滴的动画效果
void rainDrop(Rain *r)
{
	
	if (r->y0 >= r->endY) {
		cleanRain(r);//清除雨滴并绘制新的
		riffleInWater(r);

		r->isriffle = 1;

	}
	else {
		cleanRain(r);
		rainMove(r);
		drawRain(r);
	}

}
