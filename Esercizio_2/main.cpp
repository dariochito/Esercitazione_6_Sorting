#include <iostream>
#include <numeric>
#include "Eigen/Eigen"
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace Eigen;
using namespace SortLibrary;

int main(int argc, char **argv)
{
    unsigned int n;
    if(argc < 2)
    {
        cerr << "Please insert vector dimension from command line" << endl;
        return -1;
    }
    else  n = atoi(argv[1]);

    vector<unsigned int> v(n);
    iota(v.begin(), v.end(),n);

    cout << "Mean time with bubble sort over 100 tries using an already ordered vector is: " << meanTimeBubble(v) << " milliseconds" << endl;
    cout << "Mean time with merge sort over 100 tries using an already ordered vector is: " << meanTimeMerge(v) << " milliseconds" << endl;

    if(meanTimeBubble(v) > meanTimeMerge(v))
    {
        cout << "MergeSort method is more efficient for an ordered vector" << endl;
    }
    else cout << "BubbleSort method is more efficient for an ordered vector" << endl;

    for (unsigned int i=0; i<100000; i++)
    {
        v[i] = rand() % 100000;
    }

    cout << "Mean time with bubble sort over 100 tries using a randomly perturpated vector is: " << meanTimeBubble(v) << " milliseconds" << endl;
    cout << "Mean time with merge sort over 100 tries using a randomly perturbated vectors is: " << meanTimeMerge(v) << " milliseconds" << endl;

    if(meanTimeBubble(v) > meanTimeMerge(v))
    {
        cout << "MergeSort method is more efficient for a randomly perturbated vector" << endl;
    }
    else cout << "BubbleSort method is more efficient for a randomly perturbated vector" << endl;

    return 0;
}

