#include "head.h"

Graph* initialGraph(int matrix[n][n]) {
	Graph* G = new  Graph;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G->edge[i][j] = matrix[i][j];
		}
	}
	return G;
}//根据邻接矩阵创建图

costtype MinCost(costtype D[n], bool S[n]) {
	int temp = infinity;
	int w = 1;
	for (int i = 1; i < n; i++) {
		if (!S[i] && D[i] < temp) {
			temp = D[i];
			w = i;
		}
	}
	return w;
}//从V-S中选取一个顶点w，使得D[w]最小，返回w的下标

void Dijkstra(Graph* G, costtype D[n], int P[n], bool S[n]) {
	int i;
	int w;
	int sum;
	for (i = 1; i < n; i++) {
		D[i] = G->edge[0][i];
		S[i] = false;
		P[i] = 0;
	}//初始化
	S[0] = true;
	for (i = 0; i < n; i++) {
		w = MinCost(D, S);//从V-S中选取一个顶点w，使得D[w]最小
		S[w] = true;//将w加入集合S中
		for (int v = 1; v < n; v++) {//调正D
			if (!S[v]) {
				sum = D[w] + G->edge[w][v];
				if (sum < D[v]) {//判断w的加入是否让从原点从V-S中的顶点的距离变小了，如果变小，更新D和P
					D[v] = sum;
					P[v] = w;
				}
			}
		}
	}
}

//路径
void DisplayPath(int* P, int v) {
	if (P[v] != 0) {
		DisplayPath(P,P[v]);
		cout << P[v]<<"->";
	}
	else {
		cout << "0"<<"->";
	}
}//打印源点到v的最短路径