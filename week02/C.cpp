#include <iostream>
#include <cmath>
using namespace std;

void deg2(int n){
    if (n == 1){
        cout << "YES" << endl;
    }else if (n % 2 != 0){
        cout << "NO" << endl;
    }else{
        return deg2(n/2);
    }
}

int main(){
    int n=0;
    cin >> n;
    deg2(n);
    return 0;
}