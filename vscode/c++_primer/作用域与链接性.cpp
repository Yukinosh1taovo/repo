/*
                作用域(scope)描述了名称在文件的多大范围可见 如函数中定义变量可在该函数中使用而不能在其他函数内使用  文件中函数外定义的变量可在所有函数中使用(单个文件)

                链接性(linkage)描述了名称如何在不同单元间共享 链接性为 外部 的名称可在文件间共享 链接性为 内部 的名称只能由一个文件中的函数共享  无链接性 不能共享(多个文件)



自动存储持续性的作用域和链接性： 自动存储持续性的作用域为局部 没有链接性

当外部变量名称与内部相同时

#include<iostream>
int teledeli; //全局变量 存储持续性为静态 作用域为全局 外部链接性
bool function()
{
    int teledeli; //局部变量 存储持续性为自动 作用域为局部 无链接性 全局变量teledeli被隐藏 执行完该代码块后全局定义teledeli重新可见
}

静态存储持续性的作用域和链接性：



    外部链接性(可在其他文件访问)
#include<iostream>
int variable;
int main()
{
    variable = 114514;
    return 0;
}



    内部链接性(只能在当前文件中访问)
#include<iostream>
static int variable;
int main()
{
    variable = 114514;
    return 0;
}


    无链接性(只能在当前函数或代码块中访问)
#include<iostream>

int main()
{
    static int variable;
    variable = 114514;
    return 0;
}



*/