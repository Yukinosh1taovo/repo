#include<iostream>
using namespace std;


class Clock{
public:
    Clock(int newH, int newM, int newS); // 构造函数声明
    Clock(const Clock &c); // 复制构造函数声明
    ~Clock(); // 析构函数声明
    friend void printHour(Clock ); // 友元函数声明
    void print() const; // 常成员函数声明
    void setTime(int newH = 0, int newM = 0, int newS = 0);// 成员函数1声明
    void showTime();// 成员函数2声明
    static void display(); // 静态成员函数声明
    static string brand;// 静态成员变量声明
    
    

private:
    int hour;
    int minute;
    int second;
    
};




 // 构造函数定义
Clock::Clock(int newH, int newM, int newS): hour(newH), minute(newM), second(newS){}

// 复制构造函数定义
Clock::Clock(const Clock &c){
    hour = c.hour;
    minute = c.minute;
    second = c.second;
}

// 析构函数定义
Clock::~Clock(){};

// 友元函数定义
void printHour(Clock c) // 注意printHour不是任何类的成员函数
{
    cout << "hour of clock :" << c.hour; 
}

// 常成员函数定义 不能修改对象的成员变量
void Clock::print() const 
{

}

// 成员函数1
void Clock::setTime(int newH, int newM, int newS)  
{
    hour = newH;
    minute = newM;
    second = newS;
}

// 成员函数2
void Clock::showTime()
{
    cout << hour << ":" << minute << ":" << second;
}

// 静态成员函数定义
 void  Clock::display() {

}

// 静态成员变量定义
string Clock::brand = "casio";


int main(){
    Clock c(0, 0, 0);
    c.showTime();
    Clock c1 = c;

    const Clock c2(12,50,10); // 常对象创建 只能调用常成员函数
    


    system("pause");
    return 0;
}