#include <iostream>
using namespace std;

#ifndef N
#define N 3  // actual size of the array
#endif

void print_array(int arr[N*N]) {
    for (int i = 0; i < N*N; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int arr[N*N], tr=0, k=0;
    for (int i=0; i < N*N; i++){
        cin >> arr[i];
        if (i == k*(N+1)){
            k++;
            tr += arr[i];
        }
    }
    cout << tr << endl;
    return 0;
}