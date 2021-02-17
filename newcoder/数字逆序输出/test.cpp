#include <iostream>
#include <vector>

using namespace std;
void intToString()
{
    int n;
    cin >> n;
    std::vector<char> result;
    std::string test = std::to_string(n);
    for(int i = test.length() - 1; i >= 0; i--) {
        std::cout << test[i] ;
    }
    std::cout << endl;
}

int main()
{
    intToString();
    return 0;
}
