// 数组 字符串 结构 指针使用

#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct CandyBur
{

    string brand;
    double weight;
    long long calorie;
};
int main()
{

    CandyBur s01, s02, s03;                      // 创建该种类型变量
    s01.brand = "yuzusoft";                      // 使用成员运算符访问成员
    CandyBur *pa = &s02;                         // 创建指向这种结构的指针
    pa->brand = "sprite";                        // 将指针设置为有效地址后，使用间接成员运算符来访问成员
    CandyBur structarray[3];                     // 创建结构数组
    structarray[0].weight = 114.514;             // 使用成员运算符访问成员
    (*(structarray + 1)).brand = "key";          //(*(structarry+1))等价于 structarray[1]  是一个存储地址的指针
    const CandyBur *arp[3] = {&s01, &s02, &s03}; // 创建一个 常量 指针数组  （不可修改）
    cout << arp[1]->brand << endl;               // 通过指针数组访问成员
    auto ppa = arp;                              // 比 const CandyBur **ppa = arp;智能 创建指向上述数组的 常量 指针
    cout << (*ppa)->brand << endl;
    cout << (*(ppa + 1))->brand << endl
         << endl;

    system("pause");
}


/*
大型文件 三部分

头文件__  结构声明 函数原型声明
源代码文件  与结构文件有关的函数（main）代码
源代码文件   调用与结相关的函数的代码

*/