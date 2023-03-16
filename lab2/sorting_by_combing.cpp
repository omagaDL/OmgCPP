#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <fstream>

unsigned count = 0;
unsigned times = 0;

void bubble_sort(unsigned* arr,unsigned begin, unsigned end, unsigned step, bool score = true){
    bool sorted=false;
    for(int last = end-step; last >= 0 and !sorted; last-=step){
        sorted = true;
        for (unsigned idx = begin; idx <= last; idx+=step)
            if (arr[idx] > arr[idx+step]){
                auto tmp = arr[idx];
                arr[idx]=arr[idx+step];
                arr[idx+step]=tmp;
                sorted = false;
                if (score){ count +=1; }
            }
    }
}

void sort_by_combing(unsigned* arr,unsigned const begin, unsigned const end){
    unsigned step = (end-begin)/2;
    while(step!=0){
        bubble_sort(arr,begin,end,step);
        step=step/2;
    }
}

void generate_rand_arr(unsigned* arr, unsigned const shape, unsigned num = 1001){
    unsigned seed = num;

    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, 2*shape);

    for (unsigned idx = 0; idx < shape; idx++) arr[idx] = dstr(rng);
}

int time_value(unsigned* arr,unsigned const begin, unsigned const end){
    auto start = std::chrono::steady_clock::now();
    sort_by_combing(arr, begin, end);
    auto finish = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);

    times = time_span.count();
}

void get_data(unsigned const max, unsigned move){
    unsigned arr_time[max/move];
    unsigned arr_count[max/move];

    for (unsigned idx = move; idx <= max; idx+=move){
        unsigned begin=0 , end = idx;
        unsigned arr[idx];

        generate_rand_arr(arr,idx);

        time_value(arr,begin,end);

        arr_time[idx/move-1]=times;
        arr_count[idx/move-1]=count;
        times=0;
        count=0;
    }

    std::ofstream out;          // поток для записи
    out.open("data_sort_by_combing.csv");   // окрываем файл для записи
    if (out.is_open()){
        for (unsigned idx = 1; idx <= max/move; idx++){
            out << arr_time[idx-1] << ';' << arr_count[idx-1] << ';' << idx*move <<  ';' << std::endl;
        }
    }
}

main(){
    unsigned max = 10000, move = 100;
    get_data(max, move);

    std::cout << "End of program" << std::endl;  
}