#include <iostream>

using namespace std;

int main() {
    double* dbl = nullptr;
    double zero=0;
    dbl = &zero;
    cout << dbl << endl;
    dbl -= 3;
    cout << dbl << endl;
    cout << *dbl << endl;
    dbl += 5;
    cout << dbl << endl;
    cout << *dbl << endl;
    return 0;
}