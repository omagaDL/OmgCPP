#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <cmath>

//unsigned count = 0;
unsigned times = 0;

void insert_sort(unsigned* arr, unsigned const begin, unsigned const end, unsigned const step){
    for (int sorted = end; sorted >= step; sorted-=step)
        for (int idx = sorted-step; idx <= end-step; idx+=step){
            //std::cout << idx << ' ' << step << '\n';
            if (arr[idx] <= arr[idx+step])
                break;
            auto tmp = arr[idx];
            arr[idx] = arr[idx+step];
            arr[idx+step] = tmp;
        }
}

void shell_sort(unsigned* arr, unsigned const begin, unsigned const end,int id){
    unsigned step = pow(2,id)-1;
    //std::cout << id << '\n';
    while(id!=0){
        for (int idx = end; end-idx < step; idx--){
            //std::cout << idx << ' ' << step << '\n';
            insert_sort(arr,begin,idx,step);
        }
        step=pow(2,id)-1;
        id--;
    }
}

unsigned max_index(unsigned const shape){
    //std::cout << shape << '\n';
    unsigned idx=0;
    unsigned a=pow(2,idx)-1;
    while(a<=shape){
        idx+=1;
        a=pow(2,idx)-1;
        //std::cout << a << ' ' << idx << '\n';
    }
    return idx;
}

void generate_rand_arr(unsigned* arr, unsigned const shape, unsigned num = 1001){
    unsigned seed = num;

    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, 2*shape);

    for (unsigned idx = 0; idx < shape; idx++) arr[idx] = dstr(rng);
}

int time_value(unsigned* arr,unsigned const begin, unsigned const end){
    unsigned index = max_index(end-begin);
    //std::cout << index << '\n';
    auto start = std::chrono::steady_clock::now();
    shell_sort(arr, begin, end, index-1);
    auto finish = std::chrono::steady_clock::now();
    auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);

    times = time_span.count();
}

void get_data(unsigned const max, unsigned move){
    unsigned arr_time[max/move];
    //unsigned arr_count[max/move];

    for (unsigned idx = move; idx <= max; idx+=move){
        unsigned begin=0 , end = idx;
        unsigned arr[idx];
        //std::cout << idx << '\n';

        generate_rand_arr(arr,idx);

        time_value(arr,begin,end);

        arr_time[idx/move-1]=times;
        //arr_count[idx/move-1]=count;
        times=0;
        //count=0;
    }

    std::ofstream out;          // поток для записи
    out.open("data_sort_shell_hibbard.csv");   // окрываем файл для записи
    if (out.is_open()){
        for (unsigned idx = 1; idx <= max/move; idx++){
            out << arr_time[idx-1] << ';' << idx*move <<  ';' << std::endl;
        }
    }
}

main(){
    unsigned max = 10000, move = 100;
    get_data(max, move);

    std::cout << "End of program" << std::endl;
}