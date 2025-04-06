#ifndef radixsort
#define radixsort

#include <vector>
using namespace std;

//radix Sort - baza arbitrara
//radixx sort reprezinta o metoda mai buna de a fae counting sort
//in radix sort utilizam counting sort pe cifrele numarului intr-o anumita baza
//vom prezenta algoritmul general pto baza arbitrara b (se poate inlocui cu 10, 2^16 sau orice altceva)
//vom face sortarea mergand de la LSD la MSD

//mai intai vreau sa aflu cel mai mare element din vector (ca sa stiu cate cifre am maxim)
long long val_maxima(vector<long long> &v) {
    long long Maxim = v[0];
    long long n = v.size();
    for (long long i = 0; i < n; i++)
        if (v[i] > Maxim)
            Maxim = v[i];
    return Maxim;
}

//acum avem nevoie de o functie de tip Count_Sort care ordoneaza niste numere in baza b dupa o pozitie data poz = putere a lui b
void Count_Sort_Poz(vector<long long> &v, long long poz, long long b) {
    vector<long long> poz_sorted(v.size());
    vector<long long> count(b, 0);
    for (long long i = 0; i < v.size(); i++)
        count[(v[i] / poz) % b]++;
    for (int i = 1; i < b; i++)
        count[i] += count[i - 1];
    for (long long i = v.size() - 1; i >= 0; i--) {
        long long digit = (v[i] / poz) % b;
        poz_sorted[count[digit] - 1] = v[i];
        count[digit]--;
    }
    for (long long i = 0; i < v.size(); i++)
        v[i] = poz_sorted[i];
}

//facem functia explicita de radix sort
void Radix_Sort(vector<long long> &v, long long b) {
    long long Maxim = val_maxima(v);
    for (long long poz = 1; Maxim / poz > 0; poz *= b)
        Count_Sort_Poz(v, poz, b);
}

#endif