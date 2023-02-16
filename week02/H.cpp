<<<<<<< HEAD
#include <iostream>
using namespace std;

void easy(int n, int d){
    if (d == 1){
        cout << "YES" << endl;
    }else if(n % d == 0){
        cout << "NO" << endl;
    }else{
        easy(n, d-1);
    }
}

int main(){
   int n = 0;
   cin >> n;
   easy(n, n-1);
=======
#include <iostream>
using namespace std;

void easy(int n, int d){
    if (d == 1){
        cout << "YES" << endl;
    }else if(n % d == 0){
        cout << "NO" << endl;
    }else{
        easy(n, d-1);
    }
}

int main(){
   int n = 0;
   cin >> n;
   easy(n, n-1);
>>>>>>> cd1bb8d48df2a5266d5ca5315b74e8392359a386
}