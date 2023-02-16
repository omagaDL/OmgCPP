<<<<<<< HEAD
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
=======
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
>>>>>>> cd1bb8d48df2a5266d5ca5315b74e8392359a386
}