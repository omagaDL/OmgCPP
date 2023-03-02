#include <iostream>
#include <vector>
#include <valarray>
#include <chrono>
#include <random>
#include <functional>
#include <algorithm>
#include <fstream>


int linear_search(std::vector<int> array, int elem){
    for (int i = 0; i < array.size(); ++i){
        if (array[i] == elem){
            return i;
        }
    }
    return -1;
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


int main() {
    // making csv for record
    std::fstream file;
    file.open("A_record.csv", std::fstream::out | std::fstream::app);
    file << "N," << "time_A\n";
    for (int N = 5000; N <= 100000; N += 5000)
    {   
        // average case (random elem in the array)

        // array initialization
        std::vector<int> array = randint_array(N);

        // linear search
        auto begin = std::chrono::steady_clock::now();
        for (int cnt = 100000; cnt > 0; ++cnt){
            int elem = array[rand() % array.size()];
            int number = linear_search(array, elem);
            if (number > 0){ 
                array[number] = array[0];
                array[0] = elem;
            }
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        file << N << time_span.count() << "\n";
    }

    file.close();
    return 0;
}
