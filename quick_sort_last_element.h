#ifndef quicksort_le
#define quicksort_le

#include <vector>
using namespace std;

template <typename T>
T partition_le(vector<T>& v, unsigned long long low, unsigned long long high) {
  
    unsigned long long pivot = v[high];
    unsigned long long i = low - 1;

    for (unsigned long long j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    
    swap(v[i + 1], v[high]);  
    return i + 1;
}
template <typename T>
void quickSort_le(vector<T>& v, unsigned long long low, unsigned long long high) {
  
    if (low < high) {
        unsigned long long pivot = partition_le(v, low, high);

        quickSort_le(v, low, pivot - 1);
        quickSort_le(v, pivot + 1, high);
    }
}

#endif