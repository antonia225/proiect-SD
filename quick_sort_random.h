#ifndef quicksort_random
#define quicksort_random

#include <vector>
#include <random>
using namespace std;
template <typename T>
T partition(vector<T> &v,  long long low,long long high) {
     long long pivot = v[high];
     long long i = low - 1;

    for (long long j = low; j <= high - 1; j++) 
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }

        swap(v[i + 1], v[high]);
    return i + 1;
}
template <typename T>
T partition_r(vector<T> &v,  long long low, long long high) {
    random_device rd;                         
    mt19937 gen(rd());                        
    uniform_int_distribution<long long> dist(low, high);      

    long long random = dist(gen);
    swap(v[random], v[high]);

    return partition(v, low, high);
}
template <typename T>
void quickSort_random(vector<T>& v,  long long low, long long high) {
    if (low < high) {
        long long pivot = partition_r(v, low, high);
        quickSort_random(v, low, pivot - 1);
        quickSort_random(v, pivot + 1, high);
    }
}

#endif