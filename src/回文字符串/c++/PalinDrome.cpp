#include <iostream>
#include <string>
/*
判断回文字符串的思想：
两个指针指向头和尾部，开始遍历。一样的往下跳。不一样就返回no。
循环结束条件是头指针大于尾指针
*/
class PalinDrome
{
private:
    /* data */
    bool isAlphOrNumber(char c);
    bool isEqualIgnoreCase(char a, char c);

public:
    bool isPalinDrome(const std::string &str);
};

bool PalinDrome::isAlphOrNumber(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

bool PalinDrome::isEqualIgnoreCase(char a, char b)
{
    if (a >= 'A' && a <= 'Z')
        a += 32;
    if (b >= 'A' && a <= 'Z')
        b += 32;
    return a == b;
}

bool PalinDrome::isPalinDrome(const std::string &str)
{
    int i = 0, j = str.length() - 1;
    while (i <= j)
    {
        if (this->isAlphOrNumber(str[i]))
            i++;
        if (this->isAlphOrNumber(str[j]))
            j--;
        if (isEqualIgnoreCase(str[i], str[j]))
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    std::string s = "123321abc";
    PalinDrome palinDrome;
    std::cout << palinDrome.isPalinDrome(s) << std::endl;
    return 0;
}