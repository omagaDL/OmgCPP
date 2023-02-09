#include <iostream>
using namespace std;

int main(){
    int n=-1, a;
    do{
        cin >> a;
        if (a % 2 == 0) n++;
    }
    while(a != 0);
    cout << n << endl;
    return 0;
}