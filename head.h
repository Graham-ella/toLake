#pragma once
using namespace std;

#define max 20

typedef struct graph {
	char verlist[max];
	int edge[max][max];
	int n,e;
}MTGraph;//ͼ���ڽӾ���