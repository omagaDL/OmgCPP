#include <iostream>
using namespace std;

int main() {
    int *ptr = nullptr;
    int d=0, in=-1;

    cin >> in;

    while (in != 0) {
        d++;
        int *ptarr = new int[d];
        for (int i = 0; i < d - 1; i++) {
            ptarr[i] = ptr[i];
        }
        ptarr[d - 1] = in;
        cin >> in;
        delete[] ptr;
        ptr = ptarr;
    }
    for (int i = 0; i < d - 1; i++) {
        cout << ptr[i] - ptr[i + 1] << " ";
    }
    cout << endl;
    delete[] ptr;
    return 0;
}