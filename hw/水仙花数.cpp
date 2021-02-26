#include <iostream>

/*
题目：水仙花数:一个三位数，各位数字的立方和等于该数字本身。
*/
void isShuiXianHua(int num) 
{
    int hun = num / 100 ;  //百位
    int ten = (num - hun * 100) / 10; //十位
    int ind = num % 10;  //个位

    if ((hun * hun * hun + ten * ten * ten + ind * ind * ind) == num) {
        printf("%d  ", num);
    }
}
int main()
{
    for (int i = 100; i < 1000; ++i)
    {
        isShuiXianHua(i);
    }
    return 0;
}