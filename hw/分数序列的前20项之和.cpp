#include <iostream>


/*
题目：求分数序列的前20项之和：2/1, 3/2, 5/3, 8/5, 13/8, 21/13
分析：后一个数的分子是前一个的分母，后一个的分母是前一个的 分子+父母
*/
int main()
{
    double a = 2;  //分母
    double b = 1;  //分子
    double sum = 0;
    double temp = 0;

    for (int i = 1; i <= 20; i++){
        sum += a/b;
        temp = a;
        a = a+b;
        b = temp;
    }
    printf("%f\n", sum);
    return 0;
}