#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>

void test()
{
    std::string str;
    while(getline(std::cin , str)) {  //mac上cmd+d会推出，windows上EOF退出
       while(str.size() >= 8) {
           std::cout << str.substr(0,8) << std::endl;
           str = str.substr(8);
       }
        if(str.size() > 0) {
            int tmp = 8 - str.size();
            for(int i =0; i < tmp; i++) {
                str += '0';
            }
            std::cout << str << std::endl;
        }
    }
}
int main() {
    test();
    return 0;
}
