#pragma once

typedef enum {Link, Thread} PointTag;

typedef int TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
	PointTag LTag, RTag;
} BiThrTNode, *BiThrTree;

class CTree
{
public:
	CTree(void);
	~CTree(void);

	void CreateBiTree(BiThrTree *T);
	void InThreading(BiThrTree p);
};

