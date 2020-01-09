#pragma once
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#define PI 3.1415926
// ���� Windows Multimedia API
#pragma comment(lib,"Winmm.lib")
//��������Ľṹ��
typedef struct thunder {
	int startX;//�����ߵ���ʼ����
	int startY;
	int endX;//������յ�����
	int endY;
	struct thunder *lchild ,*rchild;
}Thunder;

typedef Thunder *bintree;
//�ǵݹ鴴��������
bintree creattree(bintree root)
{
	int m = 0;//�����жϷ�֦��
	root = (Thunder*)malloc(sizeof(Thunder));
	/*��������Ϣ*/
	root->startX = 20 + rand() % 940;
	root->startY = 0;
	root->endX = root->startX - 50 + rand() % 100;
	root->endY = root->startY + rand() % 10 + 20;
	root->lchild = NULL;
	root->rchild = NULL;
	/*�����Ǹ��ڵ�*/
	//��Ÿ���Ľ���б�
	bintree*parent = (bintree*)malloc(sizeof(bintree));
	*parent = root;//�洢�����Ϣ
	int  parent_amount = 1;
	int branch; //���Ʒֲ����
	branch = rand() % 10 + 15;

	while (1)
	{
		//��ǰ���������Ϊ���ڵ������
		int current_amount = parent_amount * 2;
		//������ʱ�б��ŵ�ǰ��ȵĽ�㣬ָ������
		bintree *tmp_list = (bintree*)malloc(sizeof(bintree)*current_amount);
		//���ڼ�¼��ǰ��Ƚ��ǿս��ĸ���
		int count = 0;
		//������ǰ��ε����н�
		for (int i = 0; i < current_amount; i++)
		{
			if (m != branch)
			{
				Thunder *current = (Thunder *)malloc(sizeof(Thunder));
				current->startX = (parent[i / 2])->endX;//Ѱ��˫�׽��
				current->startY = (parent[i / 2])->endY;
				current->endY = current->startY + 50 + rand() % 80;//��ǰ���endY�����������
				current->lchild = NULL;
				current->rchild = NULL;
				//���뵽��ʱ�б���
				tmp_list[count] = current;
				//�ǿս���һ
				count++;
				if (i % 2 == 0)//����0ʱΪ����������1��ʱ��Ϊ������
				{
					current->endX = current->startX - 50 + rand() % 40;
					//����X�����ڿ�ʼ������ߣ������������ƫ����
					(parent[i / 2])->lchild = current;
				}
				else
				{
					current->endX = current->startX + 50 - rand() % 40;
					//����X�����ڿ�ʼ�����ұߣ������������ƫ����
					(parent[i / 2])->rchild = current;
				}
				m++;
			}
		}
		//�ͷŸ����б�
		free(parent);
		//���¸����б�
		parent = tmp_list;
		//���¸��ڵ���
		parent_amount = count;
		if (count == 0)break;
	}
	return root;
}
//�ݹ�ǰ��
void preorder(bintree root)
{
	setlinecolor(YELLOW);
	setlinestyle(PS_SOLID, 2);//�����ߵĸ�ʽ���ϸ
	if (root)
	{
		line(root->startX, root->startY, root->endX, root->endY);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}