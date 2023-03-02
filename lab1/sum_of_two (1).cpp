#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include <chrono>
#include <random>
#include <algorithm>
#include <fstream>


bool square_compexity_search(std::vector<int> array, int Sum){
    for (int i = 0; i < array.size() - 1; ++i){
        for (int j = i + 1; j < array.size(); ++j){
            if (array[i] + array[j] == Sum){
                return true;
            }
        }
    }
    return false;
}


bool linear_compexity_search(std::vector<int> array, int Sum){
    int L = 0;
    int R = array.size();
    while (L != R){
        if (array[L] + array[R] == Sum & array[L] != array[R]){
            return true;
        } else if (array[L] + array[R] < Sum){
            ++L;
        } else if (array[L] + array[R] < Sum){
            --R;
        }
    }
    return false;
}


std::vector<int> randint_array(int size)
{
    std::vector<int> arr;
    srand(time(NULL)); // инициализация генерации случайных чисел
 
    for (int i = 0; i < size; i++){
        arr.push_back(rand());
    }  

    return arr;
}


int step = 50000;


int main(){
    std::fstream file1, file2;
    file1.open("task2.1.csv", std::fstream::out | std::fstream::app);
    file2.open("task2.1.csv", std::fstream::out | std::fstream::app);
    file1 << "N," << "time_lin\n";
    file2 << "N," << "time_sqr\n";
    for (int N = 100; N <= 1000100; N = N + 50000){
        std::vector<int> array = randint_array(N * step);

        file1 << N << ",";

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt!= 0; --cnt){
            int Sum = rand();
            int ans = linear_compexity_search(array, Sum);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        file1 << time_span.count() << ",";
    }
    for (int N = 500; N <= 5000; N = N + 500){
        std::vector<int> array = randint_array(N * step);
        std::sort(array.begin(), array.end());
        file2 << N << ",";
        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 5000; cnt!= 0; --cnt){
            int Sum = rand();
            int ans = square_compexity_search(array, Sum);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        file2 << time_span.count() << "\n";

    }
    file1.close();
    file2.close();
    return 0;
}
