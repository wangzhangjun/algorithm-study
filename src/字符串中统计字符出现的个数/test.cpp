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
