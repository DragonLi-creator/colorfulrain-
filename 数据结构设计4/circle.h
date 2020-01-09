#pragma once
#include"init.h"
#include"creat_rain.h"

void updateRainCircle(Rain *r)//������������
{
	r->riffle.curR += r->riffle.rainCircleSpeed;//�õ�ǰ�뾶���
}
void drawRainCircle(Rain *r)//������������
{
	float H = rand() % 360;// ɫ��
	float S = 1;		// ���Ͷ�
	float V = 1;		// ����

	setlinecolor(HSVtoRGB(H, S, V));
	//����Բ
	ellipse(r->riffle.x - r->riffle.curR, r->riffle.y - r->riffle.curR / 3, r->riffle.x + r->riffle.curR, r->riffle.y + r->riffle.curR / 3);
}
void clearRainCircle(Rain *r)//�����������
{

	//ʹ�ó�����ɫ���ǵ��������Դﵽ���Ч��
	setcolor(getpixel(r->riffle.x, r->riffle.y));
	ellipse(r->riffle.x - r->riffle.curR, r->riffle.y - r->riffle.curR / 3, r->riffle.x + r->riffle.curR, r->riffle.y + r->riffle.curR / 3);

}
void riffleInWater(Rain *r)//��������
{
	//��������ǰ�뾶�ﵽ���뾶ʱ��������ʧ���������
	if (r->riffle.curR >= r->riffle.r)
	{
		clearRainCircle(r);//�����������
		reviveRaindrop(r);//������³�ʼ��
	}
	else
	{
		clearRainCircle(r);//�����������
		updateRainCircle(r);//������������ʹ��ǰ�뾶����
		drawRainCircle(r);//������������
	}
}
