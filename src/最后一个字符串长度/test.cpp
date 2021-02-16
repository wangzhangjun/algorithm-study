#include <iostream>
#include <vector>

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

void wordLength(std::string &str)
{
    std::vector<std::string> output;
    spilt_string(str, " ", output);
    int size = output.size();
    std::cout << output[size-1].length() << std::endl;
}
int main() {
    std::string str = "";
    getline(std::cin, str);
    wordLength(str);
    return 0;
}
