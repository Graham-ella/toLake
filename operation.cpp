#include "head.h"

Graph* initialGraph(int matrix[n][n]) {
	Graph* G = new  Graph;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G->edge[i][j] = matrix[i][j];
		}
	}
	return G;
}//�����ڽӾ��󴴽�ͼ

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
}//��V-S��ѡȡһ������w��ʹ��D[w]��С������w���±�

void Dijkstra(Graph* G, costtype D[n], int P[n], bool S[n]) {
	int i;
	int w;
	int sum;
	for (i = 1; i < n; i++) {
		D[i] = G->edge[0][i];
		S[i] = false;
		P[i] = 0;
	}//��ʼ��
	S[0] = true;
	for (i = 0; i < n; i++) {
		w = MinCost(D, S);//��V-S��ѡȡһ������w��ʹ��D[w]��С
		S[w] = true;//��w���뼯��S��
		for (int v = 1; v < n; v++) {//����D
			if (!S[v]) {
				sum = D[w] + G->edge[w][v];
				if (sum < D[v]) {//�ж�w�ļ����Ƿ��ô�ԭ���V-S�еĶ���ľ����С�ˣ������С������D��P
					D[v] = sum;
					P[v] = w;
				}
			}
		}
	}
}

//·��
void DisplayPath(int* P, int v) {
	if (P[v] != 0) {
		DisplayPath(P,P[v]);
		cout << P[v]<<"->";
	}
	else {
		cout << "0"<<"->";
	}
}//��ӡԴ�㵽v�����·��