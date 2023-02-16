<<<<<<< HEAD
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
=======
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
>>>>>>> cd1bb8d48df2a5266d5ca5315b74e8392359a386
}