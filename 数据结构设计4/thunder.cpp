
#include"init.h"
#include"circle.h"
#include"creat_rain.h"
#include"circle.h"
#include"background.h"
#include"rain.h"
#include"thunder.h"

void op() 
{
	creatRain();
	Rain *p;
	p = head->next;
	MOUSEMSG m;
	while (1) 
	{
		if (p == NULL) {
			p = head;
		}
		else
		{
			//当标志为0即雨滴还没有变成涟漪时，雨滴继续下落
			if (p->isriffle == 0) {
				rainDrop(p);
			}

			//当标志为1即雨滴变成涟漪时，绘制相应涟漪
			if (p->isriffle == 1)
			{
				riffleInWater(p);
			}
		}
		p = p->next;
	}
}
//开线程
void thundernode(void *p)
{
	IMAGE bg2;
	loadimage(&bg2, L"E:\\vs2017\\数据结构设计4\\0002.jpg");
	while (1)
	{
		thunder *root;
		bintree *root1 = &root;
		int thnum = 2 + rand() % 5;
		for (int i = 0; i < thnum; i++)
		{
			mciSendString(L"open E:\\vs2017\\数据结构设计4\\thundermusic.mp3 alias bkcmsic1", NULL, 0, NULL);
			mciSendString(L"play bkcmsic1 repeat", NULL, 0, NULL);
			drawstar(); //画星空
			root = creattree(*root1);
			preorder(root);
			free(root);
			Sleep(600);
			//cleardevice();
			putimage(0, 0, &bg2);
			drawstar(); //画星空
		}
	}
}

int main() 
{
	begin();
	MOUSEMSG m;

	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x < 900 && m.x>750 && m.y < 720 && m.y>650)
			{
				int i;
				IMAGE bg2;
				loadimage(&bg2, L"E:\\vs2017\\数据结构设计4\\0002.jpg");
				initgraph(1080, 960); // 创建绘图窗
				mciSendString(L"open E:\\vs2017\\数据结构设计4\\rain2.mp3 alias bkcmsic2", NULL, 0, NULL);
				mciSendString(L"play bkcmsic2 repeat", NULL, 0, NULL);
				putimage(0, 0, &bg2);
				//srand()用来设置rand()产生随机数时的随机数种子。参数seed必须是个整数，
				//通常可以利用geypid()或time(0)的返回值来当做seed。如果每次seed都设相同值，
				//rand()所产生的随机数值每次就会一样。
				srand((unsigned)time(NULL));
				_beginthread(thundernode, 0, NULL);
				op();
			}
		}
	}
	closegraph();
	return 0;
}