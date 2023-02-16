#include <iostream>
#include <cmath>
using namespace std;

int recursive_factorial(int n){
    if (n < 0){
        return 0;
    }else if (n == 0){
        return 1;
    }else{
        return n*recursive_factorial(n-1);
    }
}

int main(){
    int n=0;
    cin >> n;
    cout << recursive_factorial(n) << endl;
    return 0;
}