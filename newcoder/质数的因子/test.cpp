#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>
/*
    不需要判断是不是素数
*/

//判断是素数
bool isPrimeNumber(long number_cur )
{
    if (number_cur<=0)
    {
        return false;//返回非质数
    }
    bool is_prime = true; //默认为false ：即不为质数
    for (int i = 2;i < number_cur;i++)
    {
        int is_remain = number_cur % i; //求余数
        if (is_remain == 0)
        {
            is_prime = false;
            break;
        }
    }
    return is_prime; //默认为质数
}

void zhiyinzi()
{
    long a;
    cin >> a;
    while(a!=1)
    {
        for(int i=2;i<=a;i++)
        {
            if(a%i==0)
            {
                cout<<i<<' ';
                a=a/i;
                break;
            }
        }
    }
}
int main() {
    zhiyinzi();
    return 0;
}
