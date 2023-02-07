#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a=0, b=0, c=0;
    cin >> a >> b >> c;
    int D = b*b - 4*a*c;
    if (D > 0){
        cout << (0 - sqrt(D) - b)/(2*a) << ' ' << (sqrt(D) - b)/(2*a) << endl;
    }else if(D == 0){
        cout << (-b)/(2*a) << endl;
    }else{
        cout << '\n' << endl;
    }
    return 0;
}