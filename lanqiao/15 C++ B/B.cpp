#include<bits/stdc++.h>

using namespace std;

int ans = 0;

int main()
{
    // 假定水平路程和垂直路程 Sx = 2k1x Sy = 2k2y   Sx = dx * t
    // 水平垂直速度分量 dx/dy = 15/17 
    // 求出k1和k2的最简分式比(即最短路程第一次回到原点) 代入计算

    int numerator = 15 * 233333;
    int denominator = 17 * 343720;

    int g = __gcd(numerator, denominator);

    numerator /= g;
    denominator /= g;

    cout << numerator << "/" << denominator << '\n'; // k1 k2

    double t = 2 * numerator * 343720 / 15;

    double s = sqrt((15 * t) * (15 * t) + (17 * t) * (17 * t));

    printf("%.2lf\n", s);

    system("pause");






}