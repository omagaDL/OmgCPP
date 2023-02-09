#include <iostream>
#include <cmath>
using namespace std;

int recursive_power(int n, int deg){
    if (deg == 0){
        return 1;
    }else{
        return recursive_power(n, deg-1)*n;
    }
   
}

int main(){
    int n=0, deg=0;
    cin >> n >> deg;
    cout << recursive_power(n, deg) << endl;
    return 0;
}