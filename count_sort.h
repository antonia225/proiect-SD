#ifndef countsort
#define countsort

#include <vector>
using namespace std;

void count_sort(vector<long long> &v, long long Max){
    vector<long long> fr(Max + 1, 0);
    vector<long long> sorted_vector;
    for (long long i = 0; i < v.size(); i++)
        fr[v[i]]++;
    for (long long i = 0; i <= Max; i++)
        for (long long j = 1; j <= fr[i]; j++)
            sorted_vector.push_back(i);
}

#endif