#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>
#include <typeinfo>
#include<map>
#include <algorithm>
using namespace std;
 void spilt_string2(const std::string& strIn, const std::string& div, std::vector<std::string>& vecOut) {
    std::string::size_type pos1(0);
    std::string::size_type pos2 = strIn.find(div);

    while(std::string::npos != pos2) {
        vecOut.push_back(strIn.substr(pos1, pos2 - pos1));
        pos1 = pos2 + div.size();
        pos2 = strIn.find(div, pos1);
    }

    if(pos1 != strIn.length()){
        vecOut.push_back(strIn.substr(pos1));
    }
}
void juzinixu()
{
    string str;
    std::vector<std::string> vecOut;
    getline(std::cin, str);
    spilt_string2(str, " ", vecOut);
    for(int i =vecOut.size()-1; i>=0; i--) {
        std::cout << vecOut[i] << " ";
    }
    std::cout << endl;
}
int main()
{
    juzinixu();
    return 0;
}
