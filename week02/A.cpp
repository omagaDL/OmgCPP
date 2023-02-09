#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a=0;
    cin >> a;
    if (((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0)){
        cout << "YES" << endl;
    }else if ((a % 100 == 0) && (a % 400 != 0)){
        cout << "NO" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}