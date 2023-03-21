#include<iostream> 
using namespace std;

#ifndef N
#define N 10  // actual size of the array
#endif


void toDown(int (&array)[N], int root, int bottom)
{
  int maxChild;
  int done = 0;
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (array[root * 2] > array[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (array[root] < array[maxChild]) 
    {
      int temp = array[root];
      array[root] = array[maxChild];
      array[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
}


void heops_sort(int (&array)[N]) 
{
  for (int i = (N / 2); i >= 0; i--)
    toDown(array, i, N - 1);
  for (int i = N - 1; i >= 1; i--)
  {
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;
    toDown(array, 0, i - 1);
  }
}

int main() {
    int a[N] = {1, 20, 3, 4, 50, 6, 7, 8, 10, 9};  // array initialization
    heops_sort(a);
    for (int i=0; i<N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}