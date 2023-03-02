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


int binary_search(std::vector<int> array, int elem) {
    // array is sorted in ascending order
    int L = 0;
    int R = array.size() - 1;
    int m;
    while (L < R){
        m = (R + L) / 2;

        if (array[m] = elem){
            return m;
        }

        if (array[m] < elem){
            L = m + 1;
        } else {
            R = m;
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
    file.open("time_record.csv", std::fstream::out | std::fstream::app);
    int step = 50000;
    file << "N," << "linear_searh_worst," << "linear_searh_average," << "binsearch_worst,"  << "binsearch_average" << "\n";


    for (int N = 500; N <= 1000000; N += step)
    {   
        // worst case (elem is not in the array)

        // array initialization 
        std::vector<int> array_1 = randint_array(N * step);
        int elem_1 = -1;
        file << N * step << ",";

        // linear search
        auto begin1 = std::chrono::steady_clock::now();
        for (int cnt = 1000000; cnt > 0; ++cnt){
            int number = linear_search(array_1, elem_1); 
        }
        auto end1 = std::chrono::steady_clock::now();
        auto time_span_1= std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1);
        std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1);

        // array sort for binary search
        std::sort(array_1.begin(), array_1.end());

        // binary search
        auto begin2 = std::chrono::steady_clock::now();
        for (int cnt = 1000000; cnt > 0; ++cnt){
            int number = binary_search(array_1, elem_1); 
        }
        auto end2 = std::chrono::steady_clock::now();
        auto time_span_2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2);
        std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2);


        // average case (random elem in the array)

        // array initialization
        std::vector<int> array = randint_array(N * 10000);

        // linear search
        auto begin3 = std::chrono::steady_clock::now();
        for (int cnt = 1000000; cnt > 0; ++cnt){
            int elem = array[rand() % array.size()];
            int number = linear_search(array, elem); 
        }
        auto end3 = std::chrono::steady_clock::now();
        auto time_span_3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3);
        std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3);

        // array sort for binary search
        std::sort(array.begin(), array.end());

        // binary search
        auto begin4 = std::chrono::steady_clock::now();
        for (int cnt = 1000000; cnt > 0; ++cnt){
            int elem = array[rand() % array.size()];
            int number = binary_search(array, elem); 
        }
        auto end4 = std::chrono::steady_clock::now();
        auto time_span_4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - begin4);
        std::chrono::duration_cast<std::chrono::milliseconds>(end4 - begin4);

        file << time_span_1.count() << "," << time_span_3.count() << "," << time_span_2.count() << "," << time_span_4.count() << ",";
        file << "\n";
    }

    file.close();
    return 0;
}