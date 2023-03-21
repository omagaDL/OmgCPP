#include<iostream> 
using namespace std;

#ifndef N
#define N 10  // actual size of the array
#endif

void gnome_sort(int (&array)[N]){
    int i=0, tmp=0;
    while (i < N) {
        if (i == 0 || array[i - 1] <= array[i])
            ++i;
        else {
            tmp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = tmp;
            --i;
        }
    }
}

/* int main() {
    int a[N] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // array initialization
    gnome_sort(a);
    for (int i=0; i<N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
} */