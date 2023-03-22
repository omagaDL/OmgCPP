#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool reserve_memory(int*&, size_t);
void free_memory(int*);

bool reserve_memory(int*& dst, size_t N) {
  if (dst != nullptr || N <= 0) {
    return false;
  }
  dst = new int[N];
  return true;
}

void free_memory(int* ptr) {
  delete[] ptr;
}


int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;
    cout << reserve_memory(ptr, N) << endl;
    free_memory(ptr);
    return 0;
}