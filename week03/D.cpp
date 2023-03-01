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
    int arr[N], k=0, p=0, n=0;
    for (int i=0; i < N; i++){
        cin >> arr[i];
        if (arr[i] < 0){
            k++;
        }
    }
    int nrr[k], prr[N-k];
    for (int i=0; i<N; i++){
        if (arr[i] >= 0){
            prr[p] = arr[i];
            p++;
        }else{
            nrr[n] = arr[i];
            n++;
        }
    }
    for (int i=0; i<N; i++){
        if (i <= N-k-1){
            arr[i] = prr[i];
        }else{
            arr[i] = nrr[i-N+k];
        }
    }
    print_array(arr);
    return 0;
}