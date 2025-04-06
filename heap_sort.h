#ifndef heapsort
#define heapsort

#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void heapify(vector<T> &arr, unsigned long long n, unsigned long long i)
{
    unsigned long long largest = i;
    unsigned long long left = 2 * i + 1;
    unsigned long long right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <typename T>
void heapSort(vector<T> &arr)
{
    unsigned long long n = arr.size();

    for (long  long i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (long long i  = (n / 2) - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
#endif