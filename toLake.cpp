#include "head.h"

int main()
{
    int matrix[10][10] = {
        {infinity,infinity,infinity,infinity,infinity,1,infinity,infinity,infinity,infinity},
        {infinity,infinity,infinity,infinity,infinity,infinity,1,1,infinity,infinity},
        {infinity,infinity,infinity,infinity,infinity,1,1,infinity,1,infinity},
        {infinity,infinity,infinity,infinity,infinity,infinity,infinity,1,1,infinity},
        {infinity,infinity,infinity,infinity,infinity,infinity,infinity,1,infinity,1},
        {1,infinity,1,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
        {infinity,1,1,infinity,infinity,infinity,infinity,infinity,infinity,infinity},
        {infinity,1,infinity,1,1,infinity,infinity,infinity,infinity,infinity},
        {infinity,infinity,1,1,infinity,infinity,infinity,infinity,infinity,infinity},
        {infinity,infinity,infinity,infinity,1,infinity,infinity,infinity,infinity,infinity},
    };//分析题目，得到对应图的邻接矩阵

    Graph* G = initialGraph(matrix);
    
    costtype D[n];
    int P[n];
    bool S[n];
    
    Dijkstra(G, D, P, S);

    //终点为下标为9的结点
    int target = 9;
    DisplayPath(P, target);
    cout << target;
    

}

