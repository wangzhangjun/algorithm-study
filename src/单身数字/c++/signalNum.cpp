#include <iostream>
#include<set>

int signaleNumberWithSet(int *nums, int len)
{
    int result = 0;
    std::set<int> numSet;
    int sum = 0, signalSum =0;
    for(int i =0; i < len; i++ ) {
        if((numSet.find(nums[i])) == numSet.end()){
            numSet.insert(nums[i]);
            signalSum += nums[i];
        }
        sum += nums[i];
    }
    return 2*signalSum - sum;
}

int signalNumWithXor(int *nums, int len )
{
    int result = 0;
    for (int i =0; i < len; i++ ) {
        result ^= nums[i];
    }
    return result;
}

int main(){
    int nums[] = {5,7,5,6,6};
    int result1 = signaleNumberWithSet(nums, sizeof(nums)/sizeof(int));
    std::cout << result1 << std::endl;
    int result = signalNumWithXor(nums, sizeof(nums)/sizeof(int));
    std::cout << result << std::endl;
}