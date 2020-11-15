#include <iostream>
#include <vector>
#include <map>

class GetTwoNum
{
private:
    /* data */
public:
    static std::vector<int> getByForceLoop(std::vector<int> &arr, int target);
    static std::vector<int> getByHashMap(std::vector<int> &arr, int target);
};

std::vector<int> GetTwoNum::getByForceLoop(std::vector<int> &arr, int target)
{
    std::vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            if ((arr[i] + arr[j]) == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    res.push_back(-1);
    res.push_back(-1);
    return res;
}

std::vector<int> GetTwoNum::getByHashMap(std::vector<int> &arr, int target)
{
    std::vector<int> res;
    std::map<int, int> myMap;
    for (int i = 0; i < arr.size(); i++)
    {
        int numNeed = target - arr[i];
        if (myMap.find(numNeed) != myMap.end())
        {
            res.push_back(myMap[numNeed]);
            res.push_back(i);
            return res;
        }
        myMap.insert(std::make_pair(arr[i], i));
    }
    res.push_back(-1);
    res.push_back(-1);
    return res;
}

int main()
{
    int myints[] = {1, 2, 3, 6, 8, 11};
    std::vector<int> arr(myints, myints + sizeof(myints) / sizeof(int));

    std::vector<int> res = GetTwoNum::getByForceLoop(arr, 10);
    std::cout << res[0] << std::endl;
    std::cout << res[1] << std::endl;

    std::vector<int> res1 = GetTwoNum::getByHashMap(arr, 10);
    std::cout << res1[0] << std::endl;
    std::cout << res1[1] << std::endl;
}
