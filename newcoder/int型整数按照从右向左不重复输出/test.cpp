
#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <string.h>
#include <typeinfo>
#include<map>
#include <algorithm>

using namespace std;
void intToString()
{
    int n;
    cin >> n;
    std::vector<char> result;
    std::string test = std::to_string(n);
    for(int i = test.length() - 1; i >= 0; i--) {

        auto it = find(result.begin(), result.end(), test[i]);
        if(it == result.end()) {
            result.push_back(test[i]);
        }
    }
    for(int i=0; i<result.size(); i++) {
        std::cout << result[i];
    }
    std::cout << endl;
}
int main()
{
    intToString();
    return 0;
}
