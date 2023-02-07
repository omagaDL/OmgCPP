#include <iostream>
#include <cmath>
using namespace std;

int nod(int n, int m){
    int t=n;
    if (n < m){
        n = m;
        m = t;
    }
    if ((n % m) == 0){
        return m;
    }else{
        return nod((n % m), m);
    }

}

int main(){
    int n=0, m=0;
    cin >> n >> m;
    cout << n*m/(nod(n, m)) << endl;
    cout << 10 / 3;
    return 0;
}