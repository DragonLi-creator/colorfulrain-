#pragma once
#include<stdio.h>
#include <stdlib.h> 
#include <conio.h>   //包含getch()和_kbhit,图形函数
#include <graphics.h>
#include <time.h>    
#include <dos.h>
#include<process.h>    //多线程
#include<Windows.h>
#include <Mmsystem.h>	
#include<easyx.h>
#pragma comment ( lib, "Winmm.lib" )
MOUSEMSG m;

int window_X = 1080;//图形界面宽度
int window_Y = 960;//图形界面高度
int raindropnumber=70;//雨量
int waterHeight = 550;//池塘绘制时的y坐标
int wind = 50;//风力

typedef struct rainCircle//涟漪结构体
{
	int x;//涟漪中心点x坐标
	int y;//涟漪中心点y坐标
	int r;//涟漪最大半径
	int curR;//涟漪当前半径
	int rainCircleSpeed;//涟漪扩散速度
}RC;
//雨的链表节点结构体
typedef struct Rain
{
	int x0, y0;//雨滴的起始位置
	int endY;//雨滴形成涟漪时的尾坐标
	int x, y;//雨滴的终止位置
	int step;//步进
	COLORREF color;//雨滴的颜色

	//雨滴的绘制所需的参数
	int left;
	int top;
	int right;
	int bottom;
	double stangle;
	double endangle;
	int n;
	int isriffle;//标志是否变成涟漪
	RC riffle;//雨滴所对应的涟漪
	Rain * next;

}Rain;
Rain *head;
