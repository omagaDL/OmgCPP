#include <iostream>
using namespace std;

#ifndef N
#define N 6  // actual size of the array
#endif

void swap(int& rha, int& lha){
    int a;
    a = rha;
    rha = lha;
    lha = a;
}

void print_array(int arr[N]) {
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int arr[N];
    for (int i=0; i < N; i++){
        cin >> arr[i];
    }
    for (int i=0; i<N/2; i++){
        swap(arr[i], arr[N-i-1]);
    }
    print_array(arr);
    return 0;
}