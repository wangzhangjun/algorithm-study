#include <iostream>

void searchTarget(int a[2][3],int lines/*2*/, int rows/*3*/, int target,int *result) {
    int i = 0;
    int j = rows - 1;
    while(( i<lines )&&( j>=0 )){
        if(a[i][j] < target)
            i++;
        else if(a[i][j] > target)
            j--;
        else{
            result[0] = i;
            result[1] = j;
            return;
        }
    }
}

int main(){
    int a[2][3] = {1,3,5,2,4,6};
    int result[2] = {0};
    int elements = sizeof(a) / sizeof(a[0][0]);
    int rows = sizeof(a[0]) / sizeof(a[0][0]);
    int lines = elements/rows;
    searchTarget(a,lines,rows,6,result);
    printf("result:i:%d,j:%d\n", result[0],result[1]);
    return 0;
}
