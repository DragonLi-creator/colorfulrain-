#pragma once
#include<stdio.h>
#include <stdlib.h> 
#include <conio.h>   //����getch()��_kbhit,ͼ�κ���
#include <graphics.h>
#include <time.h>    
#include <dos.h>
#include<process.h>    //���߳�
#include<Windows.h>
#include <Mmsystem.h>	
#include<easyx.h>
#pragma comment ( lib, "Winmm.lib" )
MOUSEMSG m;

int window_X = 1080;//ͼ�ν�����
int window_Y = 960;//ͼ�ν���߶�
int raindropnumber=70;//����
int waterHeight = 550;//��������ʱ��y����
int wind = 50;//����

typedef struct rainCircle//�����ṹ��
{
	int x;//�������ĵ�x����
	int y;//�������ĵ�y����
	int r;//�������뾶
	int curR;//������ǰ�뾶
	int rainCircleSpeed;//������ɢ�ٶ�
}RC;
//�������ڵ�ṹ��
typedef struct Rain
{
	int x0, y0;//��ε���ʼλ��
	int endY;//����γ�����ʱ��β����
	int x, y;//��ε���ֹλ��
	int step;//����
	COLORREF color;//��ε���ɫ

	//��εĻ�������Ĳ���
	int left;
	int top;
	int right;
	int bottom;
	double stangle;
	double endangle;
	int n;
	int isriffle;//��־�Ƿ�������
	RC riffle;//�������Ӧ������
	Rain * next;

}Rain;
Rain *head;
