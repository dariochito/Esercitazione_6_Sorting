#ifndef __SORTING_ALGORITHM_H
#define __SORTING_ALGORITHM_H

#include <vector>
#include <chrono>
#include <unistd.h>

using namespace std;
using namespace chrono;

namespace SortLibrary {

template<typename T>
void Merge(vector<T>& v,
           const unsigned int& sx,
           const unsigned int& cx,
           const unsigned int& dx){

    unsigned int i = sx;
    unsigned int j = cx + 1;

    vector<T> b;
    b.reserve(dx - sx + 1);

    while( i <= cx && j <= dx)
    {
        if (v[i] <= v[j])
            b.push_back(v[i++]);
        else
            b.push_back(v[j++]);
    }

    if (i <= cx)
        b.insert(b.end(), v.begin() + i, v.begin() + cx + 1);
    if ( j <= dx)
        b.insert(b.end(), v.begin() + j, v.begin() + dx + 1);

    copy(b.begin(), b.end(), v.begin() + sx);

}

template<typename T>
void MergeSort(vector<T>& v,
               const unsigned int& sx,
               const unsigned int& dx){

    if (sx < dx)
    {
        unsigned int cx = (sx + dx) / 2;
        MergeSort(v, sx, cx);
        MergeSort(v, cx + 1, dx);

        Merge(v, sx, cx, dx);
    }

}

template<typename T>
void MergeSort(vector<T>& v){
    MergeSort(v, 0, v.size()-1); /**We give MergeSort the vector as imput: then it does the divide
                                    et impera thing*/
}


template<typename T>
void BubbleSort(std::vector<T>& data)
{
    size_t rem_size = data.size();
    size_t last_seen = rem_size;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (size_t i = 1; i < rem_size; i++) {
            if (data[i-1] > data[i]) {
                std::swap(data[i-1], data[i]);
                swapped = true;
                last_seen = i;
            }
        }
//        rem_size = rem_size - 1;
        rem_size = last_seen;
    }
}

template<typename T>
double timeBubble(vector<T>& data)
{
    steady_clock::time_point t_begin= chrono::steady_clock::now();
    BubbleSort(data);

    sleep(1);

    steady_clock::time_point t_end= chrono::steady_clock::now();
    double duration = duration_cast<chrono::milliseconds>(t_end - t_begin).count();

    return duration;

}

template<typename T>
double timeMerge(vector<T>& v)
{
    steady_clock::time_point t_begin= chrono::steady_clock::now();
    MergeSort(v);

    sleep(1);

    steady_clock::time_point t_end= chrono::steady_clock::now();
    double duration = duration_cast<chrono::milliseconds>(t_end - t_begin).count();

    return duration;

}

template<typename T>
double meanTimeBubble(vector<T>& v)
{
    double sum = 0;
    unsigned int i = 0;
    while(i<100)
    {
        sum = sum + timeBubble(v);
        i++;
    }
    double mean_time = sum/100;
    return mean_time;
}

template<typename T>
double meanTimeMerge(vector<T>& v)
{
    double sum = 0;
    unsigned int i = 0;
    while(i<100)
    {
        sum = sum + timeMerge(v);
        i++;
    }
    double mean_time = sum/100;
    return mean_time;
}

}

#endif // __SORTING_ALGORITHM_H
