#include <iostream>
using namespace std;
#define Maxsize 50

typedef int Elmetype;

typedef struct //顺序表类型//
{
    Elmetype data[Maxsize];
    int length;
} Sqlist;

//顺序表基本操作//

void CreateList(Sqlist *&L, Elmetype a[], int n) //整体建立顺序表//
{

    int i = 0;
    L = (Sqlist *)malloc(sizeof(Sqlist));
    while (i < n)
    {
        L->data[i] = a[i];
        i++;
    }
    L->length = i;
}

void InitList(Sqlist *L) //初始化顺序表//
{
    L = (Sqlist *)malloc(sizeof(Sqlist));
    L->length = 0;
}

void Destroylist(Sqlist *&L) //销毁顺序表//
{
    free(L);
}

bool ListEmpty(Sqlist *L) //判断顺序表是否为空表//
{

    return (L->length == 0);
}

int ListLength(Sqlist *L) //返回顺序表的长度//
{

    return (L->length);
}

void DispList(Sqlist *L) //输出顺序表//
{

    for (int i = 0; i < L->length; i++)
        cout << L->data[i] << ' ';
    cout << endl;
}

bool GetElem(Sqlist *L, int i, Elmetype &e) //按序号求线性表中元素//
{
    if (i <= 1 || i >= L->length)
        return false;
    e = L->data[i - 1]; //取元素的值赋给e//
    return true;
}

int LocateElme(Sqlist *L, Elmetype e) //按照元素值查找//
{
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    if (i >= L->length)
        return false;
    return i + 1;
}

bool ListInsert(Sqlist *&L, int i, Elmetype e) //在第i个位置插入元素e//
{
    int j;
    if (i < 1 || i > L->length + 1 || L->length == Maxsize)
        return false;
    i--;
    for (j = L->length; j > i; j--)
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    L->length++;
    return true;
}

bool ListDelete(Sqlist *&L, int i, Elmetype &e) // 删除顺序表中第i个元素//
{
    int j;
    if (i < 1 || i > L->length)
        return false;
    i--;
    e = L->data[i];
    for (j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j + 1];
    L->length--;
    return true;
}

//顺序表基本算法//

//删除值为x的元素//

void delnode1(Sqlist *&L, Elmetype x) //整体建表法
{
    int i, k = 0;
    for (i = 0; i < L->length; i++)

        if (L->data[i] != x)
            L->data[k++] = L->data[i];

    L->length = k;
}

void delnode2(Sqlist *&L, Elmetype x) //元素移动法
{

    int i = 0, k = 0;
    while (i < L->length)
    {
        if (L->data[i] == x)
            k++;
        else
            L->data[i - k] = L->data[i];
        i++;
    }
    L->length -= k;
}

//以第一个元素为分界线，将所有小于等于它的元素移到该基准的后面，将所有大于它的元素移动到该基准的后面//

void partition1(Sqlist *&L) //快速排序划分1//
{
    int i = 0, j = L->length - 1;
    int temp;
    while (i < j)
    {

        while (i < j && L->data[j] > L->data[0])
            j--;
        while (i < j && L->data[i] <= L->data[0])
            i++;
        if (i < j)
        {
            temp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = temp;
        }
    }
    temp = L->data[i];
    L->data[i] = L->data[0];
    L->data[0] = temp;
}

void partition2(Sqlist *&L) //快速排序划分2//
{
    int i = 0, j = L->length - 1;
    Elmetype base = L->data[0];
    while (i < j)
    {
        while (i < j && L->data[j] > base)
            j--;
        L->data[i] = L->data[j];
        while (i < j && L->data[i] <= base)
            i++;
        L->data[j] = L->data[i];
    }
    L->data[i] = base;
}

//将所有奇数移到偶数的前面//

void move1(Sqlist *&L) //快速排序划分//
{
    int i = 0, j = L->length - 1;
    int temp;
    while (i < j)
    {
        while (i < j && L->data[i] % 2 != 0)
            i++;
        while (i < j && L->data[j] % 2 == 0)
            j--;
        if (i < j)
        {
            temp = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = L->data[i];
        }
    }
}

void move2(Sqlist *&L) //区间划分//
{
    int i = -1, j;
    int temp;
    for (j = 0; j < L->length - 1; j++)
    {
        if (L->data[j] % 2 == 1)
        {
            i++;
            if (i != j)
            {
                temp = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = temp;
            }
        }
    }
}

int main()
{

    int a[20] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};
    Sqlist *L;
    CreateList(L, a, 10);
    move1(L);
    DispList(L);
    system("pause");
}