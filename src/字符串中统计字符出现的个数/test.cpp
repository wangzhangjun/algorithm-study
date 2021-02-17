#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
/*
统计某个字符串中出现某个字符的个数，忽略大小写
*/
void wordLength(std::string &str, char target)
{
    int i = 0;
    for(auto it = str.begin(); it != str.end(); it++) {
        if(toupper(*it) == toupper(target)) {  //tolower(c) 大写转小写
            i++;
        }
    }
    std::cout << i << std::endl;
}
int main() {
    std::string str = "";
    getline(std::cin, str);
    char target;
    std::cin >> target;
    wordLength(str, target);
    return 0;
}
