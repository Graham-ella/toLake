#pragma once
#include <limits>
#include <iostream>
#include <string>
using namespace std;

#define n 10
const int infinity = 1000;

typedef struct graph {
	char verlist[n];
	int edge[n][n];
}Graph;//Í¼µÄÁÚ½Ó¾ØÕó

typedef int costtype;

Graph* initialGraph(int matrix[n][n]);

costtype MinCost(costtype D[n], bool S[n]);

void Dijkstra(Graph* G, costtype D[n], int P[n], bool S[n]);

void DisplayPath(int* P, int v);


