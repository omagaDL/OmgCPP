#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a=0, b=0, c=0;
    cin >> a >> b >> c;
    if ((b*b-4*a*c) > 0){
        cout << (-sqrt(b*b-4*a*c)-b)/(2*a) << ' ' << (sqrt(b*b-4*a*c)-b)/(2*a) << endl;
    }else if((b*b-4*a*c) == 0){
        cout << (sqrt(b*b-4*a*c)-b)/(2*a) << endl;
    }else{
        cout << '\n' << endl;
    }
    return 0;
}