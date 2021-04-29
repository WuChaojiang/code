#pragma once

typedef int VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct 
{
	VertexType vexs[MAXVEX];		// 顶点表
	EdgeType arc[MAXVEX][MAXVEX];	// 邻接矩阵，可看作边表
	int numVertexes, numEdges;		// 图中当前的顶点数和边数
}MGraph;

class GraphAlgorithm
{
public:
	GraphAlgorithm(void);
	~GraphAlgorithm(void);

	void CreateMGrahp(MGraph *G);
	void MiniSpanTree_Prim(MGraph G);

};

