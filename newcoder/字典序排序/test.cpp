#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>
#include <typeinfo>
#include <map>
#include <algorithm>


/*
两种解法：
第一种是：使用sort默认会进行字典序排序。 sort排序vector
第二种是：使用set，但是会去掉重复的。
*/
using namespace std;
void zidianxupaixu()
{
    int n;
    cin >> n;
    vector<string> res(n);
    for(int i = 0; i < n; i ++){
        cin >> res[i];
    }
    sort(res.begin(), res.end());
    for(string s : res) cout << s << endl;


//    set<string> input;
//    input.insert("cap");
//    input.insert("to");
//    input.insert("card");
//    input.insert("two");
//    input.insert("too");
//    input.insert("up");
//    input.insert("boat");
//    input.insert("boot");
//    for(auto it = input.begin(); it!=input.end();it++) {
//        cout << *it << endl;
//    }
//
//    std::cout << "===========" << std::endl;


}
int main()
{
    zidianxupaixu();
    return 0;
}
