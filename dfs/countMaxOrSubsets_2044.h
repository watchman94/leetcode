//
// Created by Kiven on 2021/10/20.
//

#ifndef LEETCODE_COUNTMAXORSUBSETS_2044_H
#define LEETCODE_COUNTMAXORSUBSETS_2044_H
#include<vector>
#include<cmath>
using namespace std;
class CountMaxOrSubsets {
public:

    int countMaxOrSubsets(const vector<int>& vec){
        int n = vec.size();
        int dst = 0;
        for(int i : vec) dst |= i;
        return dfs(vec, 0, 0, dst);
    }

    int dfs(const vector<int>& vec, int i, int orn, int dst){
        int n = vec.size();
        if(i == n) return orn == dst;
        if(orn == dst) return pow(2, n - i);
        int r1 = dfs(vec, i + 1, orn | vec[i], dst);
        int r2 = dfs(vec, i + 1, orn, dst);
        return r1 + r2;
    }

};

#endif //LEETCODE_COUNTMAXORSUBSETS_2044_H
