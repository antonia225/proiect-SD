#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include "generatorme.h"
#include "Headere_Sortari/merge_sort.h"
#include "Headere_Sortari/count_sort.h"
#include "Headere_Sortari/quick_sort_random.h"
#include "Headere_Sortari/quick_sort_last_element.h"
#include "Headere_Sortari/radix_sort.h"
#include "Headere_Sortari/shell_sort.h"
#include "Headere_Sortari/heap_sort.h"
using namespace std;
using namespace chrono;

ofstream gheap("output_heap_sort.csv");
ofstream gquickran("output_quick_sort_random.csv");
ofstream gquickle("output_quick_sort_le.csv");
ofstream gmerge("output_merge_sort.csv");
ofstream gshell("output_shell_sort.csv");
ofstream gcount("output_count_sort.csv");
ofstream gradixb10("output_radix_sort_10.csv");
ofstream gradixb216 ("output_radix_sort_2^16.csv");
ofstream gshellk("output_shell_sort_knuth.csv");
ofstream gshells("output_shell_sort_sedgewick.csv");



template <typename T>
bool validare(vector<T> v)
{
    for (unsigned long long i = 1; i < v.size(); i++)
        if (v[i] < v[i - 1])
            return 0;
    return 1;
}

int main()
{
    gheap << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gquickran << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gquickle << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gmerge << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gshell << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gcount << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gradixb10 << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gradixb216 << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gshellk << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";
    gshells << "N, min, max, sortat_crescator, sortat_descrescator, aproape_s_c, aproape_s_d, random_uniform, numere_aproape_identice, gauss, inv_gauss\n";

    for (int i = 0; i < 1; i++)
    {   
            mt19937 rng(random_device{}());
            uniform_int_distribution<long long> random(0, LONG_LONG_MAX);
            long long nrmin=random(rng);
            long long nrmax=random(rng);
            if(nrmin>nrmax)
                swap(nrmin,nrmax);
            uniform_int_distribution<int> choice(0,2);
            long long n=choice(rng);
            if (n==0)
                n=1000;
            else if(n==1)
                n==1000000;
            else
                n=1000000000;
            n=1000;
            vector<long long> Sortat_Cresc = Generator_Numere_Sortate_Crescator(nrmin, nrmax, n);
            vector<long long> Sortat_Descresc = Generator_Numere_Sortate_Descrescator(nrmin, nrmax, n);
            vector<long long> Aproape_Sortat_Cresc = Generator_Numere_Aproape_Crescator(nrmin, nrmax,n);
            vector<long long> Aproape_Sortat_Descresc = Generator_Numere_Aproape_Descrescator(nrmin, nrmax, n);
            vector<long long> Random_Uniform = Generator_Numere_Random_Uniform(nrmin, nrmax, n);
            vector<long long> Numere_Identice = Generator_Numere_Identice(nrmin, nrmax, n);
            vector<long long> Gauss = Generator_Numere_Random_Gaussian(nrmin, nrmax, n);
            vector<long long> Inv_Gauss = Generator_Numere_Random_Inverted_Gaussian(nrmin, nrmax, n);

            vector<long long> v(n);
            // heap sort
            gheap << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                heapSort(v);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gheap << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gheap << "-1,0,";
            }
            gheap << endl;

            // // merge_sort
            gmerge << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            try
            {
                v = Gauss;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                vector<long long> temp(n);
                auto start = high_resolution_clock::now();
                mergeSort(v, 0, n - 1, temp);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gmerge << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gmerge << "-1,0,";
            }
            gmerge << endl;

            // quickSort_randomPivot
            gquickran << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                quickSort_random(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickran << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickran << "-1,0,";
            }
            gquickran << endl;

            // quick_sort_le
            gquickle << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gquickle << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gquickle << "-1,0,";
            }
            gquickle << endl;

            // count sort
            gcount << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                count_sort(v, nrmax);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                count_sort(v, nrmax);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                count_sort(v, nrmax);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                count_sort(v, nrmax);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                count_sort(v, nrmax);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                quicksort_le(v, 0, n - 1);
                count_sort(v, nrmax);
                auto end=high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                count_sort(v, nrmax);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                count_sort(v, nrmax);
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gcount << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gcount << "-1,0,";
            }
            gcount << endl;

            // radix sort base 10
            gradixb10 << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 10);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb10 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb10 << "-1,0,";
            }
            gradixb10 << endl;

            // radix sort base 2^16
            gradixb216 << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                Radix_Sort(v, 65536);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gradixb216 << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gradixb216 << "-1,0,";
            }
            gradixb216 << endl;
            //shell sort clasic
            gshell << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                shell_sort(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshell << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshell << "-1,0,";
            }
            gshell << endl;

            // shell sort knuth generalized
            gshellk << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                shell_sort_knuth_generalized(v, 3, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshellk << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshellk << "-1,0,";
            }
            gshellk << endl;

            // shell sort sedgewick
            gshells << n << "," << nrmin << "," << nrmax << ",";
            try
            {
                v = Sortat_Cresc;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            try
            {
                v = Sortat_Descresc;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Cresc;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            try
            {
                v = Aproape_Sortat_Descresc;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            try
            {
                v = Random_Uniform;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            try
            {
                v = Numere_Identice;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            try
            {
                v = Gauss;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            try
            {
                v = Inv_Gauss;
                auto start = high_resolution_clock::now();
                shell_sort_sedgewick(v, n);              
                auto end = high_resolution_clock::now();
                duration<double> elapsed = end - start;
                gshells << elapsed.count() << "," << validare(v) << ",";
            }
            catch (...)
            {
                gshells << "-1,0,";
            }
            gshells << endl;
            
        }
    return 0;
}