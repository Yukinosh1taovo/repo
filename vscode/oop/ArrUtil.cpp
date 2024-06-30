#include<iostream>
using namespace std;


class Array_max{
public:
    void setValue();
    void maxValue();


private:
    int array[10];
    int max;

};

void Array_max::setValue(){
    int m = 0;
    for(int i = 0; i < 10; i++)
    {

        cin >> array[i];
        if (array[i] > m) m = array[i];
    }
    max = m;
}

void Array_max::maxValue()
{
    cout << "max Value:" << max;
    return ;
}

int main()
{
    Array_max amax;
    amax.setValue();
    amax.maxValue();

    system("pause");
    return 0;
}