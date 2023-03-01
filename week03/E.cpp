#include <iostream>
using namespace std;

#ifndef N
#define N 3  // actual size of the array
#endif

void swap(int& rha, int& lha){
    int a;
    a = rha;
    rha = lha;
    lha = a;
}

void print_array(int arr[2*N]) {
    for (int i = 0; i < 2*N; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void sort(int arr[2*N]){
    for (int i=1; i<2*N; i++)
    {
        if (arr[i-1] > arr[i]){
            swap(arr[i-1], arr[i]);
            i=0;
        }
    }
    print_array(arr);
}

int main(){
    int srr[2*N] = {0};
    for (int i=0; i < 2*N; i++){
        cin >> srr[i];
    }
    sort(srr);
    return 0;
}