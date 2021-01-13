#include <iostream>
#include <string>
#include <stack>

/*
例如：
输入：s = "bcabc"
输出："abc"
输入：s = "cbacdcbc"
输出："acdb"

leetcode上的题目：
1. 题目为字符串去重，所以如果一个字母只出现了一次，则该字母必须被选取出来。
2. 字典序最小，即字母升序的排列字符串肯定是最小的字典序。

以bcabc为例，从头开始扫描，第一个b，因为只有一个先加入到结果集中，c没有出现过，也添加到结果集中，接着是a，因为a比c小且c在a之后还出现了，所以要删除第一个c，接着遍历到b，这时候的结果集是ba，同样会发现b也在后面出现了，所以第一个b要丢弃。最终得到的结果是abc。

从以上模型可以看出，符合先进后出的模型，所以要借助于栈，当扫描字符串时，判断栈顶的字符是否大于当前字符，如果大于，则应该删除栈顶字符（出栈），去除后，再判断新的栈顶与当前字符的大小。重复至栈为空，或者栈顶字符不大于当前字符，则入栈。另外因为每个字符只能出现一次，所以在入栈时，要判断如果已经存在于栈中，则不能加入到栈，在出栈时，如果当前字符之后再也没有这个字符了，则不能出栈。

为此，代码设计如下：
1. 使用stack数据结构。
2. 记录每个字符最后出现的下标，以判断当前字符之后还有没有出现过这个字符。
3. 要记录当前的字符是否已经在栈中出现了。

*/
void removeDuplicatLetter(const char *str)
{
    bool visted[26] = {0};
    int lastIndex[26] = {-1};
    std::stack<char> s;
    for (int i = 0; i < strlen(str); i++)
    {
        lastIndex[str[i] - 'a'] = i; //记录每个字符在str中最后出现的位置
    }
    for (int i = 0; i < strlen(str); i++)
    {
        if (visted[str[i] - 'a']) //是否已经在栈中
        {
            continue;
        }
        //如果栈顶最后出现的位置大于当前值的位置，说明后面还会有出现该字符，pop
        while ((!s.empty()) && (s.top() > str[i]) && (lastIndex[s.top() - 'a'] > i))
        {
            visted[s.top() - 'a'] = false;
            s.pop();
        }
        s.push(str[i]);
        visted[str[i] - 'a'] = true;
    }

    std::string resLetter("");
    while (!s.empty())
    {
        resLetter.push_back(s.top());
        s.pop();
    }
    reverse(resLetter.begin(), resLetter.end());
    std::cout << resLetter << std::endl;
}

int main()
{
    //std::string s("bcabc");
    std::string s("cbacdcbc");
    removeDuplicatLetter(s.c_str());
    return 0;
}