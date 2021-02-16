#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>
#include <typeinfo>

using namespace std;
void spilt_string(const std::string& strIn, const std::string& div, std::vector<std::string>& vecOut) {
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
void  sishewuru()
{
    std::string str;
    cin >> str;
    std::vector<std::string> vecOut;
    spilt_string(str, ".", vecOut);
    int zhengshu  = -1;

    //找到小数点后面的第一位
    char c = vecOut[1][0];
    const char *tmp1 = &c;
    int first = atoi(tmp1);

    if(first >= 5) {
        zhengshu = std::stoi( vecOut[0]) + 1;
    }else{
        zhengshu = std::stoi( vecOut[0]);
    }
    std::cout << zhengshu << std::endl;
}

int main() {
    sishewuru();
    return 0;
}
