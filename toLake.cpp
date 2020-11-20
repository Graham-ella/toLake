#include "head.h"
/*
解决问题的方法：

（一）寻找实际问题中的图模型
我们不妨假设农夫带着狼、羊、菜要从河的左岸到右岸，

如果在左岸记为1，如果在右岸记为0，那么初始状态（农夫、狼、羊、菜都在左岸)对应着1111，
终止状态对应着0000，过河问题转化成了从状态1111 --->  状态0000O（每位从左到右依次对应农夫、狼、羊、菜） 

一个物品有0、1两种状态，那么4个物品根据乘法原理就有16种可能，但是根据农夫不在时，羊会吃菜，狼会吃羊的条件，
我们可以删去0011，0110，0111，1000，1001，1100这6种可能。

对于剩下1111，1110，1101，1011，1010，0101，0100，0010，0001，0000这10种状态，分别把它们看成无向图的顶点，
根据农夫每次过河只能运一种东西，我们可以退出上面10种状态中哪些是相邻的，对应到图中就是哪些顶点之间有边

至此，我们就从农夫过河问题中找到了图模型

（二）利用Dijkstra算法寻找从0号顶点到9号顶点的最短路径

（三）根据打印出的路径，重新回到实际问题中去

*/

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

    Graph* G = initialGraph(matrix);//根据邻接矩阵创建图
    
    costtype D[n];//D[i]表示源点0到顶点i的当前最短路径长
    int P[n];//P[i]表示源点0到顶点i的当前最短路径上最后经过的顶点的下标
    bool S[n];//标记顶点是否被加入
    
    Dijkstra(G, D, P, S);

    //终点为下标为9的结点
    int target = 9;
    DisplayPath(P, target);//打印从顶点0到顶点9的路径
    cout << target;
    

}

