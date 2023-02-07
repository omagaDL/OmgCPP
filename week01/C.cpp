#include <iostream>
#include <cmath>
using namespace std;

int fact(int n){
    if (n < 0){
        return 0;
    }else if (n == 0){
        return 1;
    }else{
        return n*fact(n-1);
    }
}

int main(){
    int n=0;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}