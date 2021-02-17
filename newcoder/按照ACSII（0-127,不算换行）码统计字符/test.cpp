#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>
#include <typeinfo>
#include<map>
#include <algorithm>
void zifutongji()
{
    std::string input;
    getline(std::cin, input);
    std::set<char> set1;
    for(int i =0; i<input.length(); i++) {
        set1.insert(input[i]);
    }
    std::cout << set1.size() <<std::endl;
}
int main()
{
    zifutongji();
    return 0;
}
