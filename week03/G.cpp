#include <iostream>
using namespace std;

#ifndef N
#define N 9  // actual size of the array
#endif


#include <iostream>
using namespace std;

int main() {
    int arr[N];
    int l = sizeof(arr)/sizeof(arr[0]);
    int r = 0;
    for (int i=0; i < N; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < l; i++){
        r ^= arr[i];
    } 
    cout << r << endl;
    return 0;
}