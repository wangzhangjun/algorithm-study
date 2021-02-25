#include <iostream>
#include <map>
#include <vector>

/*
题目：
求数组中，超过一半以上的数字的个数
编译：g++ --std=c++11 test.cpp
*/
bool cmp(std::pair<int, int> &m1, std::pair<int, int> &m2)
{
    return m1.second > m2.second ;
}

//这个函数遍历太多了，只是为了学习map的排序
void hashFunc(int a[], int size)
{
    std::map<int ,int> numCountMap;
    std::vector<std::pair<int, int> > sortMapVector;
    for(int i = 0; i < size; i++) {
        auto it  = numCountMap.find(a[i]);
        if(it == numCountMap.end()) {
            numCountMap.insert(std::make_pair(a[i],1));
        }else{
            numCountMap[it->first] = it->second + 1;
        }
    }

    for(auto it = numCountMap.begin(); it != numCountMap.end(); ++it) {
        sortMapVector.push_back(*it);
    }
    
    std::sort(sortMapVector.begin(), sortMapVector.end(), cmp);//按照value排序
    std::cout << sortMapVector[0].second << std::endl;  //排序后第一个就是最大的
}

//这个才是正确的解法
//时间O(N),空间O(N)因为空间借助了一个Map
void hashFunc1(int a[], int size)
{
    std::map<int, int> numCountMap;
    std::vector<std::pair<int, int> > sortMapVector;
    int maxNum = 0, maxCount = 0, newCount = 0;
    for (int i = 0; i < size; i++)
    {
        auto it = numCountMap.find(a[i]);
        if (it == numCountMap.end())
        {
            newCount = 1;
            numCountMap.insert(std::make_pair(a[i], newCount));
        }
        else
        {
            newCount = it->second + 1;
            numCountMap[it->first] = newCount;
        }
        if(newCount > maxCount) {
            maxCount = newCount;
            maxNum = a[i];
        }
    }
    std::cout << maxNum << std::endl;
}

//方法2：使用摩尔计数法
//遍历数组，让num = a[0], count = 1, 开始遍历，当a[i]==num的时候，count+1, 不等时，count-1, 当count=0时，说明抵消了，num重新赋值给当前值，count=1
void hashFunc2(int a[], int size)
{
    int num = a[0], count = 1;
    for (int i = 0; i < size; i++)
    {
        if(count  == 0) {
            num = a[i];
            count = 1;
        }
        if(num == a[i]) {
            count++;
        }
        if(num != a[i]) {
            count--;
        }
    }
    std::cout << num << std::endl;
}

int main()
{
    int a[] = {1,1,1,1,1,3,3};
    hashFunc2(a, sizeof(a)/sizeof(int));
    return 0;
}