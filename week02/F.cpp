<<<<<<< HEAD
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
=======
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
>>>>>>> cd1bb8d48df2a5266d5ca5315b74e8392359a386
}