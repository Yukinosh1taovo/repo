#include <stdio.h>
#include <stdlib.h>
#define MAXV 1000
int A[MAXV][MAXV] = {0};
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
void DispAdj(AdjGraph *G) //输出邻接表G
{
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%d:", i);
        while (p != NULL)
        {
            printf("%d ", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}

int main()
{
    AdjGraph *G;
    int l;
    int n, e;
    scanf("%d %d %d", &n, &e, &l);
    if (n <= 1 || n > 10)
        return 0;
    if (l == 0)
        for (int i = 0; i < e; i++)
        {
            int j, k;
            scanf("%d %d", &j, &k);
            A[j - 1][k - 1] = 1;
            A[k - 1][j - 1] = 1;
        }
    if (l == 1)
        for (int i = 0; i < e; i++)
        {
            int j, k;
            scanf("%d %d", &j, &k);
            A[j - 1][k - 1] = 1;
        }
    for (int h = 0; h < n; h++)
    {
        for (int m = 0; m < n; m++)
            printf("%d ", A[h][m]);
        printf("\n");
    }

    for (int p = 0; p < n; p++)
    {
        printf("%d:", p);
        for (int v = n - 1; v >= 0; v--)
        {
            if (A[p][v] == 1)
                printf("%d ", v);
        }
        printf("\n");
    }
}
