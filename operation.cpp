#include "head.h"

Graph* initialGraph(int matrix[n][n]) {
	Graph* G = new  Graph;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G->edge[i][j] = matrix[i][j];
		}
	}
	return G;
}

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
}

void Dijkstra(Graph* G, costtype D[n], int P[n], bool S[n]) {
	int i;
	int w;
	int sum;
	for (i = 1; i < n; i++) {
		D[i] = G->edge[0][i];
		S[i] = false;
		P[i] = 0;
	}
	S[0] = true;
	for (i = 0; i < n; i++) {
		w = MinCost(D, S);
		S[w] = true;
		for (int v = 1; v < n; v++) {
			if (!S[v]) {
				sum = D[w] + G->edge[w][v];
				if (sum < D[v]) {
					D[v] = sum;
					P[v] = w;
				}
			}
		}
	}
}

//Â·¾¶
void DisplayPath(int* P, int v) {
	if (P[v] != 0) {
		DisplayPath(P,P[v]);
		cout << P[v]<<"->";
	}
	else {
		cout << "0"<<"->";
	}
}