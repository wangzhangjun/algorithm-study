#include <iostream>
#include <list>

//g++ --std=c++11 lru.cpp

void lruSearch(std::list<int> &lruList, int target)
{
    for (auto it = lruList.begin(); it != lruList.end(); ++it)
    {
        if (*it == target)
        {
            lruList.push_front(*it);
            lruList.erase(it);
            return;
        }
    }
    lruList.push_front(target);
}

void printLru(std::list<int> &lruList)
{
    for (int n : lruList)
    {
        std::cout << n << std::endl;
    }
}

int main()
{
    std::list<int> lruList;
    lruList.push_back(0);
    lruList.push_back(1);
    lruList.push_back(2);
    lruList.push_back(3);
    lruList.push_back(4);
    printLru(lruList);
    std::cout << "lru search........." << std::endl;
    lruSearch(lruList, 3);
    printLru(lruList);
    return 0;
}
