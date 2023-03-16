#include <iostream>
#include <chrono>
#include <random>
#include <ctime>
#include <fstream>

//mt19937 engine(time(nullptr));


void forward_step(unsigned* arr,unsigned begin, unsigned end, bool& sorted){
        for (unsigned idx = begin; idx < end; ++idx)
            if (arr[idx] > arr[idx+1]){
                auto tmp = arr[idx];
                arr[idx]=arr[idx+1];
                arr[idx+1]=tmp;
                sorted = false;
            }
}

void backward_step(unsigned* arr,unsigned begin, unsigned end, bool& sorted){
        for (unsigned idx = end; idx > begin; --idx)
            if (arr[idx-1] > arr[idx]){
                auto tmp = arr[idx-1];
                arr[idx-1]=arr[idx];
                arr[idx]=tmp;
                sorted = false;
            }
}

void shaker_sort(unsigned* arr,unsigned begin, unsigned end){
    bool sorted = false;
    while((!sorted) && (begin < end) ){
        sorted = true;
        forward_step(arr,begin,end,sorted);
        end-=1;
        backward_step(arr,begin,end,sorted);
        begin+=1;
    }
}

void getting_data(unsigned arr[], unsigned const N, unsigned const step){

}

main(){
    unsigned arr[10]={443,43,4,6,7,685,5, 78,33,0};
    int begin=0 , end = 9;
    int number_array[100];

    shaker_sort(arr,begin,end);

    for (unsigned i = begin; i <= end; i++) std::cout << arr[i] << '\n'; 
    return 0;
}



