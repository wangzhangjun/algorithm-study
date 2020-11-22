#include <iostream>

//T:O(N)  S:O(1)
int* getTwoNum(int arr[], int leng, int target) {
    int * arrRes = new int(2);
    int i = 0, j = leng-1;
    while(i < j) {
        if(arr[i] + arr[j] < target) {
            ++i;
        }else if(arr[i] + arr[j] > target){
            --j;
        }else{
            arrRes[0] = i+1;
            arrRes[1] = j+1;
            return arrRes;
         }
    }
    arrRes[0] = -1;
    arrRes[1] = -1;
    return arrRes;
}

int main()
{
    int arr[] = {1,2,3,6,8,11};
    int leng = sizeof(arr)/sizeof(int);
    int *result = getTwoNum(arr,leng, 10);
    std::cout << result[0] << std::endl;
    std::cout << result[1] << std::endl;
    delete result;
}
