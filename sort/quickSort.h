//
// Created by Kiven on 2021/11/5.
//

#ifndef LEETCODE_QUICKSORT_H
#define LEETCODE_QUICKSORT_H

#include<vector>
#include<cassert>
#include<iterator>
#include<iostream>
#include<random>

using namespace std;

void qsortHelper(vector<int>& vec, int i, int j){
    if(i >= j) return;
    int p = i, q = j;
    /*
    while(p < q){
        while(p < q && vec[q] >= vec[i]) q--;
        while(p < q && vec[p] <= vec[i]) p++;
        swap(vec[p], vec[q]);
    }
    swap(vec[i], vec[q]);
    */

    while(p < q){
        while(p < q && vec[p] <= vec[j]) p++;
        while(p < q && vec[q] >= vec[j]) q--;

        swap(vec[p], vec[q]);
    }
    swap(vec[j], vec[p]);

    qsortHelper(vec, i, q - 1);
    qsortHelper(vec, q + 1, j);
}

void qsort(vector<int>& vec){
    int n = vec.size();
    qsortHelper(vec, 0, n - 1);
}

void qsort_test(){
    vector<int> vec = {5,4,3,2,1};
    qsort(vec);
    copy(begin(vec), end(vec), ostream_iterator<int>(cout, "\t")); cout << endl;
    vec = {1,2,3,4,5};
    qsort(vec);
    copy(begin(vec), end(vec), ostream_iterator<int>(cout, "\t")); cout << endl;
    vec = {1,1,1,1,1};
    qsort(vec);
    copy(begin(vec), end(vec), ostream_iterator<int>(cout, "\t")); cout << endl;
    vec.clear();
    for(int i = 0; i < 100; i++) vec.push_back(rand() % 100);
    copy(begin(vec), end(vec), ostream_iterator<int>(cout, "\t")); cout << endl;
    cout << accumulate(begin(vec), end(vec), 0) << endl;
    qsort(vec);
    copy(begin(vec), end(vec), ostream_iterator<int>(cout, "\t")); cout << endl;
    cout << accumulate(begin(vec), end(vec), 0) << endl;
}



#endif //LEETCODE_QUICKSORT_H
