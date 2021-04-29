#include "StdAfx.h"
#include "Tree.h"
#include <stdlib.h>


BiThrTree pre; //全局变量，始终指向刚刚访问过的结点

CTree::CTree(void)
{
}


CTree::~CTree(void)
{
}

void CTree::CreateBiTree(BiThrTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiThrTree) malloc(sizeof(BiTNode));
		if (!*T)
		{
			exit(0);
		}

		(*T)->data = ch;

		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

void CTree::InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		if (!p->lchild)	// 没有左孩子
		{
			p->LTag=Thread;
			p->lchild = pre;
		}
	}
}
