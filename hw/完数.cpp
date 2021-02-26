#include <iostream>
#include <vector>

/*
题目：一个数如果等于它的因子之和，这个数就称为完数。例如：6 = 1+2=3
因子：所有可以整除这个数的数,不包括这个数自身。
因数：所有可以整除这个数的数,包括这个数自身。
*/
std::vector<int> YinZi(int num) 
{
    std::vector<int> result;
    result.push_back(1); //1肯定是
    for(int i = 2; i <= num; i++) {
        if(num % i == 0) {
            result.push_back(i);
        }
    }
    result.pop_back(); //删除本身
    return result;
}

int main()
{
    for(int i = 0; i<= 1000; i++) {
        int sum = 0;
        std::vector<int> result = YinZi(i);
        for (std::vector<int>::iterator it = result.begin(); it != result.end(); it++){
            sum += *it;
        }
        if (sum == i){
            std::cout << "完数: " << i << std::endl;
        }
    }
    return 0;
}