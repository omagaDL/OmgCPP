#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

char *resize(const char *buf, size_t size, size_t new_size) {
  char* new_a = new char[new_size];
  for (size_t i = 0; i != std::min(new_size, size); ++i) {
    new_a[i] = *(buf + i);
  }
  delete[] buf;
  return new_a;
}

int main() {
  // type new size here
  size_t new_size = 3;
  char *a = new char[10];
  for (int i=0; i<10; i++){
    cin >> a[i];
  }
  a = resize(a, 10, new_size);
  cout << a << endl;
  delete[] a;
}