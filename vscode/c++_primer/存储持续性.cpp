/*
                                                Title  存储持续性



                存储类别如何影响信息在文件中的共享


    c++使用四种不同的方案存储数据   区别在于数据保留在内存的时间

自动存储持续性： 在函数定义 中 声明的变量（包括函数参数）的存储持续性为 自动 的
                程序开始执行其所属的函数或代码块被创建 执行完函数或代码块后内存被释放

int main()
{
    int a;
    int b=0;   //变量存储持续性为自动
}

double sum()
{
    int min;
    double max; //变量存储持续性为自动
    return min+max;
}


静态存储持续性：在函数定义 外 定义的变量  或
             使用关键字 static 定义的变量的存储持续性都为静态
            程序整个运行过程中存在

#include<iostream>
int a; //变量存储持续性为静态
int main()
{
static long long b;//变量存储持续性为静态
}


线程存储持续性(c++11)：略



动态存储持续性：使用new运算符分配的内存将一直存在  直到 使用delete运算符将其释放或程序结束为止 存储持续性为动态

#include<iostream>
int main()
{
    int higgens;  //变量higgens存储持续性为自动
    int *pt = new int;  //变量pt存储持续性为动态
    pt = &higgens;
}






*/
