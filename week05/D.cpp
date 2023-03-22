#include <iostream>

using std::cin;

void input_array(int* ptr, size_t N);
void reverse(int* ptr, size_t N);
void print(const int* ptr, size_t N);

void input_array(int* ptr, size_t N) {
  for (size_t i = 0; i != N; ++i) {
    cin >> *(ptr + i);
  }
}

void reverse(int* ptr, size_t N) {
  for (size_t i = 0; i != (N + 1) / 2; ++i) {
    std::swap(*(ptr + i), *(ptr + N - i - 1));
  }
}

void print(const int* ptr, size_t N) {
  for (size_t i = 0; i != N; ++i) {
    std::cout << *(ptr + i) << " ";
  }
}


int main() {
    int N = 0;
    int* ptr = nullptr;
    cin >> N;

    int* a = new int[N];
    ptr = a;

    input_array(ptr, N);
    reverse(ptr, N);
    print(ptr, N);

    return 0;
}