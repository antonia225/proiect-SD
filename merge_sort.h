#ifndef merge_sort
#define merge_sort

#include <vector>
using namespace std;
template <typename T>
void merge(vector<T> &v, unsigned long long left, unsigned long long mid, unsigned long long right, vector<T> &temp)
{
    unsigned long long n1 = mid - left + 1;
    unsigned long long n2 = right - mid;

    for (unsigned long long i = 0; i < n1; i++)
        temp[left + i] = v[left + i];
    for (unsigned long long j = 0; j < n2; j++)
        temp[mid + 1 + j] = v[mid + 1 + j];

    unsigned long long i = left;
    unsigned long long j = mid + 1;
    unsigned long long k = left;

    while (i <= mid && j <= right)
    {
        if (temp[i] <= temp[j])
            v[k++] = temp[i++];
        else
            v[k++] = temp[j++];
    }

    while (i <= mid)
        v[k++] = temp[i++];
    while (j <= right)
        v[k++] = temp[j++];
}
template <typename T>
void mergeSort(vector<T> &v, unsigned long long left, unsigned long long right, vector<T> &temp)
{
    if (left >= right)
        return;

    unsigned long long mid = left + (right - left) / 2;
    mergeSort(v, left, mid, temp);
    mergeSort(v, mid + 1, right, temp);
    merge(v, left, mid, right, temp);
}

#endif 