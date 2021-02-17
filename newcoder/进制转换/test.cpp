#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>

using namespace std;

/*
任意进制转换成任意进制，注意修改下面的a和b的值。
16进制输入：0X13，程序会默认跳过前两个0X字符
测试其他时，注意修改跳过前两个字符0x
*/
const int MAXSIZE = 10000;
char str[MAXSIZE];  //输入的字符串
int a  = 16;        //当前的进制
int b = 10;         //要转换的目标进制


void decToOther(int tmp, int b)
{//十进制转换为任意进制
    int i = 0;
    int s[MAXSIZE] = { 0 };
    while (tmp != 0)            //十进制转换为目标进制算法，结果放到数组s中
    {
        s[i] = tmp % b;
        tmp= tmp / b;
        i++;
    }
    //cout << a << "进制数" << str << "的" << b << "进制表示为：";
    for (; i > 0; i--)          //利用ascll编码实现字母表示两位整数，并倒序输出转换结果
    {
        if (s[i - 1] > 9 && s[i - 1] <= 35)
            cout << (char)(s[i - 1] + 55);          //当s[i-1]为整数10时（char)(10+55)='A'，输出'A'
        else if (s[i - 1] > 35 && s[i - 1] <= 61)
            cout << (char)(s[i - 1] + 61);          //当s[i-1]为整数36时（char)(36+61)='a'，输出'a'
        else
            cout << s[i - 1];           //个位数输出本身
    }
    cout << '\n';
}

void otherToDec(int a, const char *str, int b)
{
    //任意进制转换为十进制
    int tmp = 0;            //tmp保存十进制的值
    int c = 1;          //初始化权值为1
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        int x;          //存放当前位的数字
        if (str[i] >= 'A' && str[i] <= 'Z')         //字母A~Z表示整数10~35
            x = str[i] - 'A' + 10;
        else if (str[i] >= 'a' && str[i] <= 'z')            //字母a~z表示整数36~61
            x = str[i] - 'a' + 36;
        else
            x = str[i] - '0';
        tmp = tmp + x * c;          //累加将各个位上的值
        c = c * a;         //更新权值
    }
    decToOther(tmp, b);         //由十进制转换为目标进制
}
int main() {
    //a、s、b分别为目前的进制、待转换的内容、目标进制
    while (cin >> str ){
        std::string cstr(str);
        otherToDec(a, cstr.substr(2).c_str(), b);  //cstr.substr(2).c_str()：跳过前面两个0x
    }
    return 0;
}
