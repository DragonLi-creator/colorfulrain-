#pragma once
#include"init.h"


//�߳���������ε���һ��λ��
void cleanRain(Rain *r)
{
	setfillcolor(getpixel(r->x0 + 5, r->y0 + 5));//��䱳����ɫ(�����)
	setlinecolor(getpixel(r->x0 + 5, r->y0 + 5));//��䱳��ɫ(�����)

	fillpie(r->x0, r->y0, r->x0 + 8, r->y0 + 24, r->stangle, r->endangle);//���ƺڻ������
}
