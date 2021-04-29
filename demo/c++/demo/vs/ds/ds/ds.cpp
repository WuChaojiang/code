// ds.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GraphAlgorithm.h"


int _tmain(int argc, _TCHAR* argv[])
{
	GraphAlgorithm ga;
	MGraph g;
	ga.CreateMGrahp(&g);
	ga.MiniSpanTree_Prim(g);


	return 0;
}

