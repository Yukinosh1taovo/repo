#include <stdio.h>
#include <stdlib.h>
#define MAXV 50
typedef struct ANode
{
    int adjvex;            //该边的邻接点编号
    struct ANode *nextarc; //指向下一条边的指针

} ArcNode; //边结点类型
typedef struct Vnode
{

    ArcNode *firstarc; //指向第一条边
} VNode;               //邻接表头结点类型
typedef struct
{
    VNode adjlist[MAXV]; //邻接表头结点数组
    int n, e;            //图中顶点数n和边数e
} AdjGraph;              //完整的图邻接表类型

int A[MAXV][MAXV] = {0};

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) //创建图的邻接表
{
    int i, j;
    ArcNode *p;
    G = (AdjGraph *)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) //给邻接表中所有头结点的指针域置初值
        G->adjlist[i].firstarc = NULL;
    for (i = 0; i < n; i++) //检查邻接矩阵中每个元素
        for (j = 0; j < n; j++)
            if (A[i][j] != 0) //存在一条边
            {
                p = (ArcNode *)malloc(sizeof(ArcNode)); //创建一个结点p
                p->adjvex = j;

                p->nextarc = G->adjlist[i].firstarc; //采用头插法插入结点p
                G->adjlist[i].firstarc = p;
            }
    G->n = n;
    G->e = e;
}
int visited[MAXV] = {0};
int ExistPath(AdjGraph *G, int u, int v)
{
    int w;
    ArcNode *p;
    visited[u] = 1; //置已访问标记
    if (u == v)     //找到了一条路径
        return 1;
    p = G->adjlist[u].firstarc; // p指向顶点u的第一个邻接点
    while (p != NULL)
    {
        w = p->adjvex;       // w为顶点u的邻接点
        if (visited[w] == 0) //若w顶点未访问
        {
            if (ExistPath(G, w, v)) //若从顶点w出发找到到达v的路径
                return 1;           //返回true
        }
        p = p->nextarc; // p指向顶点u的下一个邻接点
    }
    return 0; //不存在u到v的路径，返回false
}

int main()
{
    int j, k, e = 0;
    scanf("%d %d", &j, &k);
    int n = j;

    while (!(j == 0 && k == 0))
    {
        A[j][k] = 1;
        scanf("%d %d", &j, &k);
        if (j > n)
            n = j;
        if (k > n)
            n = k;
        e++;
    }
    n++;

    AdjGraph *G;
    CreateAdj(G, A, n, e);
    int u1, v1;
    scanf("%d %d", &u1, &v1);
    printf("%d", ExistPath(G, u1, v1));
    system("pause");
}