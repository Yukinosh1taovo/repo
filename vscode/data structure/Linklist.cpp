#include <iostream>
using namespace std;

typedef int Elmetype;

typedef struct LinkNode //单链表类型//
{
    Elmetype data;
    struct LinkNode *next;
} LinkNode;

void CreateListF(LinkNode *L, Elmetype a[], int n) //头插法建立单链表//
{
    LinkNode *s;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));

        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}

void CreateListR(LinkNode *L, Elmetype a[], int n) //尾插法建立单链表//
{
    LinkNode *s, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    r = L;
    for (int i = 0; i < n; i++)
    {
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

void InitList(LinkNode *&L) //初始化单链表//
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void DestroyList(LinkNode *&L) //销毁单链表//
{
    LinkNode *pre, *p;
    pre = L;
    p = pre->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

bool Listempty(LinkNode *L) //判断单链表是否为空//
{
    return (L->next == NULL);
}

int ListLength(LinkNode *L) //求单链表的长度//
{

    int n = 0;
    LinkNode *p = L->next;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

void DispList(LinkNode *L) //输出单链表//
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

bool GetElem(LinkNode *L, int i, Elmetype &e) //按序号查找单链表中第i个元素//
{
    LinkNode *p = L;
    int j = 0;
    if (i <= 0)
        return false;
    while (j < i && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    e = p->data;
    return true;
}

int LocateElem(LinkNode *L, Elmetype e) //按元素值e查找单链表并返回逻辑序号//
{
    int i = 1;
    LinkNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        i++;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    else
        return i;
}

int ListDelete(LinkNode *&L, int i) //删除单链表中第i个元素//
{
    int j = 0;
    LinkNode *p = L, *q;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
        return true;
    }
}

bool ListInsert(LinkNode *&L, Elmetype e, int i) //将e插入单链表中作为第i个元素//
{
    int j = 1;
    LinkNode *p = L->next;
    if (i <= 1)
        return false;
    while (p != NULL && j < i - 1)
    {

        j++;
        p = p->next;
    }
    if (p == NULL)
        return false;
    LinkNode *s;
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

void split(LinkNode *L, LinkNode *L1, LinkNode *L2)
//将单链表L(a1,b1,a2,b2...,an,bn)拆分为 L1(a1,a2...an), L2(bn,bn-1...b1)//
{
    LinkNode *p = L->next, *r1, *q;
    L1 = L;
    r1 = L1;
    L2 = (LinkNode *)malloc(sizeof(LinkNode));
    L2->next = NULL;
    while (p != NULL)
    {
        r1->next = p;
        r1 = p;
        p = p->next;
        q = p->next;
        p->next = L2->next;
        L2->next = p;
        p = q;
    }
    r1->next = NULL;
}

void delmaxnode(LinkNode *L) //删除单链表中唯一最大结点（双指针）//
{
    LinkNode *p = L->next, *pre = L, *maxp = p, *maxpre = pre;
    while (p != NULL)
    {
        if (p->data > maxp->data)
        {
            maxp = p;
            maxpre = pre;
        }
        pre = p;
        p = p->next;
    }
    maxpre->next = maxp->next;
    free(maxp);
}

void sort(LinkNode *&L) //单链表递增排序//
{
    LinkNode *p, *pre, *q;
    p = L->next->next;
   
    while (p != NULL)
    {
        pre = L;
        q = p->next;
        while (pre->next != NULL && p->data > pre->next->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

void experiment1(LinkNode *&L)
{

    LinkNode *p, *q, *qnext;

    q = p->next->next;
    p->next->next = NULL;
    while (q != NULL)
    {
        p = L;
        qnext = q->next;
        while (q != NULL && q->data > p->next->data)
            p = p->next;
        q->next = p->next;
        p->next = q;
        q = qnext;
    }
}

int main()
{
    int a[10] = {4, 2, 6, 8, 4, 6, 7, 0, 7, 5};
    LinkNode *L;
    CreateListR(L, a, 10);
    sort(L);
    DispList(L);
    system("pause");
}
