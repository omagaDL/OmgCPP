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
    int arr[N], k=0;
    cin >> k;
    for (int i=0; i < N; i++){
        cin >> arr[i];
    }
    for (int i=0; i < k; i++){
        for (int j=0; j < N; j++){
        swap(arr[j], arr[N-1]);
        }
    }
    print_array(arr);
    return 0;
}