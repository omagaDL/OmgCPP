#include <iostream>
using namespace std;

#ifndef N
#define N 6  // actual size of the array
#endif


int binarysearch(int array[N]){
    int left = -1;
    int right = N;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (array[middle] < 1) {
            left = middle;
        }else {
            right = middle;
        }
    }
    return left;
}

int main(){
    int arr[N];
    for (int i=0; i < N; i++){
        cin >> arr[i];
    }
    cout << binarysearch(arr) << endl;
    return 0;
}