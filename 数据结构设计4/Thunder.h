#pragma once
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define PI 3.1415926
// 引用 Windows Multimedia API
#pragma comment(lib,"Winmm.lib")
//定义闪电的结构体
typedef struct thunder {
	int startX;//闪电线的起始坐标
	int startY;
	int endX;//闪电的终点坐标
	int endY;
	struct thunder *lchild ,*rchild;
}Thunder;

typedef Thunder *bintree;
//非递归创建二叉树
bintree creattree(bintree root)
{
	int m = 0;//用来判断分枝数
	root = (Thunder*)malloc(sizeof(Thunder));
	/*输入结点信息*/
	root->startX = 20 + rand() % 940;
	root->startY = 0;
	root->endX = root->startX - 50 + rand() % 100;
	root->endY = root->startY + rand() % 10 + 20;
	root->lchild = NULL;
	root->rchild = NULL;
	/*创建非根节点*/
	//存放父类的结点列表
	bintree*parent = (bintree*)malloc(sizeof(bintree));
	*parent = root;//存储结点信息
	int  parent_amount = 1;
	int branch; //控制分叉个数
	branch = rand() % 10 + 15;

	while (1)
	{
		//当前结点个数设计为父节点的两倍
		int current_amount = parent_amount * 2;
		//创建临时列表存放当前深度的结点，指针数组
		bintree *tmp_list = (bintree*)malloc(sizeof(bintree)*current_amount);
		//用于记录当前深度结点非空结点的个数
		int count = 0;
		//创建当前层次的所有结
		for (int i = 0; i < current_amount; i++)
		{
			if (m != branch)
			{
				Thunder *current = (Thunder *)malloc(sizeof(Thunder));
				current->startX = (parent[i / 2])->endX;//寻找双亲结点
				current->startY = (parent[i / 2])->endY;
				current->endY = current->startY + 50 + rand() % 80;//当前结点endY向下随机延伸
				current->lchild = NULL;
				current->rchild = NULL;
				//加入到临时列表中
				tmp_list[count] = current;
				//非空结点加一
				count++;
				if (i % 2 == 0)//当余0时为左子树，余1的时候为右子树
				{
					current->endX = current->startX - 50 + rand() % 40;
					//结束X坐标在开始坐标左边，以随机数控制偏移量
					(parent[i / 2])->lchild = current;
				}
				else
				{
					current->endX = current->startX + 50 - rand() % 40;
					//结束X坐标在开始坐标右边，以随机数控制偏移量
					(parent[i / 2])->rchild = current;
				}
				m++;
			}
		}
		//释放父层列表
		free(parent);
		//更新父层列表
		parent = tmp_list;
		//更新父节点数
		parent_amount = count;
		if (count == 0)break;
	}
	return root;
}
//递归前序
void preorder(bintree root)
{
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 2);//设置线的格式与粗细
	if (root)
	{
		line(root->startX, root->startY, root->endX, root->endY);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}