<<<<<<< HEAD
#include <iostream>
using namespace std;

int reverse_number(long long number){
    long long n = 0;
    while(number){
        n = 10*n + number%10;
        number /= 10;
    }
    return n;
}

int main(){
    
    long long n = 0;
    cin >> n;
    if (reverse_number(n) == n){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}
=======
#include <iostream>
using namespace std;

int reverse_number(long long number){
    long long n = 0;
    while(number){
        n = 10*n + number%10;
        number /= 10;
    }
    return n;
}

int main(){
    long long n = 0;
    cin >> n;
    if (reverse_number(n) == n){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}
>>>>>>> cd1bb8d48df2a5266d5ca5315b74e8392359a386
