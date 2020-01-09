#pragma once
#include"init.h"

//����������κ���
Rain *createRaindrop()
{
	Rain *rain;
	rain = (struct Rain*)malloc(sizeof(Rain));
	//Ϊ��η��䶯̬�ڴ�

	rain->x0 = rand() % window_X;//����������λ�õ�ȷ��
	rain->y0 = 22 + rand() % 150;
	rain->endY = waterHeight + rand() % 130;//��εĽ���y����Ҫ�ڳ���֮��

	rain->left = rain->x0;//������εĲ�����ȷ��
	rain->top = rain->y0;
	rain->right = rain->x0 + 20;
	rain->bottom = rain->y0 + 25;
	rain->stangle = 3.92;
	rain->endangle = 5.49;
	float H = rand() % 360;// ɫ��
	float S = 1;		// ���Ͷ�
	float V = 1;		// ����
	rain->color = HSVtoRGB(H, S, V);//HSVtoRGB���� ������ͨ���졢�̡�����ɫ�����ϳ���ɫ��
	rain->step = raindropnumber;

	rain->isriffle = 0;

	rain->riffle.x = rain->x0;
	rain->riffle.y = rain->endY;
	// rain->endY�������
	rain->riffle.r = rand() % 30 + 20;//���뾶
	rain->riffle.curR = rand() % 4;//��ǰ�뾶
	rain->riffle.rainCircleSpeed = raindropnumber / 10;//ʹ������ɢ�ٶ���������Э��
	rain->next = NULL;
	return rain;
}

//�����������
void reviveRaindrop(Rain *rain)
{
	rain->x0 = rand() % window_X;//����������λ�õ�ȷ��
	rain->y0 = 22 + rand() % 150;
	rain->endY = waterHeight + 90 + rand() % 70;//��εĽ���y����Ҫ�ڳ���֮��

	rain->left = rain->x0;//������εĲ�����ȷ��
	rain->top = rain->y0;
	rain->right = rain->x0 + 20;
	rain->bottom = rain->y0 + 25;
	rain->stangle = 3.92;
	rain->endangle = 5.49;
	float H = rand() % 360;// ɫ��
	float S = 1;		// ���Ͷ�
	float V = 1;		// ����
	rain->color = HSVtoRGB(H, S, V);//HSVtoRGB���� ������ͨ���졢�̡�����ɫ�����ϳ���ɫ��
	rain->step = raindropnumber;

	rain->isriffle = 0;
	rain->riffle.x = rain->x0;
	rain->riffle.y = rain->endY;
	rain->riffle.r = rand() % 30 + 12;
	rain->riffle.curR = rand() % 4;
	rain->riffle.rainCircleSpeed = raindropnumber / 10;//ʹ������ɢ�ٶ���������Э��

}

//�γ���ε�����ѭ���б�
void creatRain()
{
	Rain *p1, *p2;

	p2 = createRaindrop();
	p1 = p2;
	head = p1;
	for (int i = 0; i < raindropnumber; i++)
	{
		p2 = createRaindrop();
		p1->next = p2;
		p1 = p2;
	}
	p1->next = head;
}


//������������ε���һ��λ��
void rainMove(Rain *r)
{
	if (MouseHit())
		m = GetMouseMsg();// ��ȡ���ָ��λ�ã���Ļ���꣩

	//�ж�����Ƿ��ڴ���֮��
	if (m.x >= 0 && m.x <= window_X && m.y >= 0 && m.y <= window_Y)
	{
		//��ε�x�����ı�
		//��ε�y�������
		if (m.mkRButton) {
			r->y0 += 2 * raindropnumber;
		}
		else {
			r->y0 += raindropnumber;
		}
		if (m.x > 720)
		{
			r->x0 += wind;
			r->riffle.x += wind;
		}
		if (m.x < 360)
		{
			r->x0 -= wind;
			r->riffle.x -= wind;

		}

		Sleep(1);//�ӿ����(ģ��������)

	}
	else
	{
		r->y0 += raindropnumber;
		Sleep(10);//�޸�Sleepʱ�䣬�������(ģ��ͷ�ϸ��)

	}

}

//�������
void drawRain(Rain *r)
{
	setfillcolor(r->color);//��������ɫ(�����)
	setlinecolor(r->color);//��������ɫ(�����)

	fillpie(r->x0, r->y0, r->x0 + 8, r->y0 + 24, r->stangle, r->endangle);//�������
}
