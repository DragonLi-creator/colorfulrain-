#pragma once
#include"init.h"

//创建单个雨滴函数
Rain *createRaindrop()
{
	Rain *rain;
	rain = (struct Rain*)malloc(sizeof(Rain));
	//为雨滴分配动态内存

	rain->x0 = rand() % window_X;//雨滴随机生成位置的确定
	rain->y0 = 22 + rand() % 150;
	rain->endY = waterHeight + rand() % 130;//雨滴的结束y坐标要在池塘之内

	rain->left = rain->x0;//绘制雨滴的参数的确定
	rain->top = rain->y0;
	rain->right = rain->x0 + 20;
	rain->bottom = rain->y0 + 25;
	rain->stangle = 3.92;
	rain->endangle = 5.49;
	float H = rand() % 360;// 色相
	float S = 1;		// 饱和度
	float V = 1;		// 亮度
	rain->color = HSVtoRGB(H, S, V);//HSVtoRGB函数 宏用于通过红、绿、蓝颜色分量合成颜色。
	rain->step = raindropnumber;

	rain->isriffle = 0;

	rain->riffle.x = rain->x0;
	rain->riffle.y = rain->endY;
	// rain->endY随机生成
	rain->riffle.r = rand() % 30 + 20;//最大半径
	rain->riffle.curR = rand() % 4;//当前半径
	rain->riffle.rainCircleSpeed = raindropnumber / 10;//使涟漪扩散速度与雨量相协调
	rain->next = NULL;
	return rain;
}

//雨滴重新生成
void reviveRaindrop(Rain *rain)
{
	rain->x0 = rand() % window_X;//雨滴随机生成位置的确定
	rain->y0 = 22 + rand() % 150;
	rain->endY = waterHeight + 90 + rand() % 70;//雨滴的结束y坐标要在池塘之内

	rain->left = rain->x0;//绘制雨滴的参数的确定
	rain->top = rain->y0;
	rain->right = rain->x0 + 20;
	rain->bottom = rain->y0 + 25;
	rain->stangle = 3.92;
	rain->endangle = 5.49;
	float H = rand() % 360;// 色相
	float S = 1;		// 饱和度
	float V = 1;		// 亮度
	rain->color = HSVtoRGB(H, S, V);//HSVtoRGB函数 宏用于通过红、绿、蓝颜色分量合成颜色。
	rain->step = raindropnumber;

	rain->isriffle = 0;
	rain->riffle.x = rain->x0;
	rain->riffle.y = rain->endY;
	rain->riffle.r = rand() % 30 + 12;
	rain->riffle.curR = rand() % 4;
	rain->riffle.rainCircleSpeed = raindropnumber / 10;//使涟漪扩散速度与雨量相协调

}

//形成雨滴的链表（循环列表）
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


//计算雨线中雨滴的下一个位置
void rainMove(Rain *r)
{
	if (MouseHit())
		m = GetMouseMsg();// 获取鼠标指针位置（屏幕坐标）

	//判断鼠标是否在窗口之内
	if (m.x >= 0 && m.x <= window_X && m.y >= 0 && m.y <= window_Y)
	{
		//雨滴的x随风而改变
		//雨滴的y增大更多
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

		Sleep(1);//加快雨滴(模拟狂风骤雨)

	}
	else
	{
		r->y0 += raindropnumber;
		Sleep(10);//修改Sleep时间，减缓雨滴(模拟和风细雨)

	}

}

//绘制雨滴
void drawRain(Rain *r)
{
	setfillcolor(r->color);//填充随机颜色(雨滴内)
	setlinecolor(r->color);//填充随机颜色(雨滴线)

	fillpie(r->x0, r->y0, r->x0 + 8, r->y0 + 24, r->stangle, r->endangle);//绘制雨滴
}
