#include <iostream>
#include <cmath>
using namespace std;

int fibonacci(int i){
    if (i <= 1){
        return 1;
    } else{
        return (fibonacci(i-1) + fibonacci(i-2));
    }
}

int main(){
    int i=0;
    cin >> i;
    cout << fibonacci(i) << endl;
    return 0;
}