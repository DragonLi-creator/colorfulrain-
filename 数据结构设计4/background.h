#pragma once
#include"stdio.h"
#include "graphics.h "   // 引用图形库头文件
#include "conio.h"
#include<math.h>
#include<time.h>
#include<stdbool.h>
#define PI 3.1415926

void begin()
{
	initgraph(1080, 960);
	IMAGE bg1;
	loadimage(&bg1, L"E:\\vs2017\\数据结构设计4\\0001.jpg");   //加载开始界面
	putimage(0, 0, &bg1);
	settextstyle(65, 20, _T("楷体"));// 设置字体（长，宽，字体形式）
	settextcolor(WHITE);//字体颜色
	setbkmode(TRANSPARENT);//字体背景
	TCHAR s3[] = _T("池塘夜降彩色雨");
	outtextxy(410, 100, s3);//输出字体位置（x,y,输出的字符串）
	settextstyle(50, 20, _T("楷体"));
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	TCHAR s4[] = _T("开始");
	outtextxy(785, 660, s4);
	TCHAR s5[] = _T("组长：李龙");
	outtextxy(20, 500, s5);
	setbkmode(TRANSPARENT);
	TCHAR s6[] = _T("组员：张沐阳");
	outtextxy(20, 560, s6);
	setbkmode(TRANSPARENT);
	TCHAR s7[] = _T("      李霆");
	outtextxy(20, 620, s7);
	setbkmode(TRANSPARENT);
	TCHAR s8[] = _T("      林绮婷");
	outtextxy(20, 680, s8);
	setbkmode(TRANSPARENT);
	TCHAR s9[] = _T("指导老师：靳雁霞");
	outtextxy(20, 740, s9);
}

void star(int x, int y) //画星星函数
{
	int i, a;
	int n = 5;
	int x1[5], y1[5], x2[5], y2[5];
	setcolor(YELLOW);
	for (i = 0; i < 5; i++)
	{
		x1[i] = (int)(x + n * cos(i * 72 * PI / 180));
		y1[i] = (int)(y + n * sin(i * 72 * PI / 180));
		x2[i] = (int)(x + n / 2 * cos(i * 72 * PI / 180));
		y2[i] = (int)(y + n / 2 * sin(i * 72 * PI / 180));
	}
	for (i = 0; i < 5; i++)
	{
		a = i + 1;
		if (a > 4) a = 0;
		line(x2[i], y2[i], x1[a], y1[a]);//增加星星的数量
		line(x2[i]+250, y2[i]+250, x1[a]+250, y1[a]+250);
		line(x2[i] + 450, y2[i] + 100, x1[a] + 450, y1[a] + 100);
	}
}

void drawstar() //画星空
{
	int a[] = { 40,250,140,140,90,350,300};
	int b[] = { 40,25,99,100,98,60,78 }, i;
	setfillstyle(1);//设置当前填充样式,不填充
	for (i = 0; i < 7; i++)
	{
		star(a[i], b[i]);
		//floodfill(a[i], b[i], YELLOW);
	}
}

