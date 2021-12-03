//
// Created by Kiven on 2021/12/3.
//

#ifndef LEETCODE_MINIMUMDELETIONS_2091_H
#define LEETCODE_MINIMUMDELETIONS_2091_H

#include <vector>
using namespace std;

class MinimumDeletions {
public:
    int minimumDeletions(vector<int>& vec) {
        int n = vec.size();
        int i = min_element(begin(vec), end(vec)) - begin(vec);
        int j = max_element(begin(vec), end(vec)) - begin(vec);
        if(i > j) swap(i, j);
        return min(min(j + 1, n - i), n - j + i + 1);
    }
};

#endif //LEETCODE_MINIMUMDELETIONS_2091_H
