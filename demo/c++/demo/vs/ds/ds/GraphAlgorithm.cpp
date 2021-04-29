#include "StdAfx.h"
#include "GraphAlgorithm.h"


GraphAlgorithm::GraphAlgorithm(void)
{
}


GraphAlgorithm::~GraphAlgorithm(void)
{
}

void GraphAlgorithm::CreateMGrahp(MGraph *G)
{
	int i,j,k,w;
	printf("输入顶点数和边数:\n");
	scanf("%d, %d", &G->numVertexes, &G->numEdges); // 输入顶点数和边数
	for (i = 0; i < G->numVertexes; i++) 
		scanf("%d", &G->vexs[i]);

	for (i = 0; i < G->numVertexes; i++)
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
			else
			{
				G->arc[i][j] = INFINITY;
			}
		}
	}

	for (k = 0; k <G->numEdges; k++)
	{
		printf("输入边(vi,vj)上的下标i，下标j和权w：\n");
		scanf("%d,%d,%d", &i,&j,&w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}


void GraphAlgorithm::MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];	 // 保存相关顶点小标
	int lowcost[MAXVEX]; // 保存相关顶点间边的全值
	lowcost[0] = 0; // 初始化第一个顶点下标为0，表示v0已纳入最小生成树
	adjvex[0] = 0; // 初始化第一个权值为0，现在从顶点v0开始
	for (i = 1; i < G.numVertexes; i++) // 循环除下标为0外的全部顶点
	{
		lowcost[i] = G.arc[0][i]; // 将v0顶点与之有边的权值存入数组，作为初始值
		adjvex[i] = 0; // 初始化都为v0的下标
	} // 8~12读取邻接矩阵的第一行数据。完成初始化工作。
	for (i = 1; i < G.numVertexes; i++)
	{
		min = INFINITY;
		j = 1; k = 0;
		while (j < G.numVertexes) // 循环全部顶点，将最小的权重放在对应的lowcost中
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		printf("(%d,%d)", adjvex[k], k); // 打印当前顶点边中权值最小的边
		lowcost[k] = 0; // 将当前顶点的权值设置为0，表示此顶点已完成任务。以下的代码还更新了与顶点k相关的lowcost值，和顶点为j对应最小路径的连接点
		for (j = 1; j < G.numVertexes; j++) // 循环所有顶点
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{  // 若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
				lowcost[j] = G.arc[k][j];  //  将较小权值存入lowcoast	// 与顶点j相关的lowcost，并且当前j不在生成树中。
				adjvex[j] = k; // 将下标为k的顶点存入adjvex中				// 与j顶点对应的最小路径的点
			}
		}
	}
}

