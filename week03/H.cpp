#include <iostream>
using namespace std;

#ifndef N
#define N 3  // actual size of the array
#endif

#ifndef M
#define M 3  // actual size of the array
#endif

void print_transoposed(int arr[N][M]){
    for (int i = 0; i < M; ++i){ 
        for (int j = 0; j < N; ++j){
            cout << arr[j][i] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int arr[N][M];
    for (int i=0; i < N; i++){
        for (int j=0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    print_transoposed(arr);
    return 0;
}