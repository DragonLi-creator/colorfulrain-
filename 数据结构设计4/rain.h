#pragma once
#include"init.h"
#include"creat_rain.h"
#include"clean_rain.h"
//������εĶ���Ч��
void rainDrop(Rain *r)
{
	
	if (r->y0 >= r->endY) {
		cleanRain(r);//�����β������µ�
		riffleInWater(r);

		r->isriffle = 1;

	}
	else {
		cleanRain(r);
		rainMove(r);
		drawRain(r);
	}

}
