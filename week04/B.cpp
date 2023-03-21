#include<iostream> 
using namespace std;

#ifndef N
#define N 10  // actual size of the array
#endif


void quickSort(int (&array)[N], int ind_left_base, int ind_right_base)
{
    int i = ind_left_base;
    int j = ind_right_base;
    int pivo = array[(i + j) / 2];
    int temp=0;

    while (i <= j)
    {
        while (array[i] < pivo)
            i++;
        while (array[j] > pivo)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > ind_left_base)
        quickSort(array, ind_left_base, j);
    if (i < ind_right_base)
        quickSort(array, i, ind_right_base);
}

/* int main() {
    int a[N] = {1, 20, 3, 4, 50, 6, 7, 8, 10, 9};  // array initialization
    quickSort(a, 2, 9);
    for (int i=0; i<N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
} */