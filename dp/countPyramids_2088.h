//
// Created by Kiven on 2021/12/1.
//

#ifndef LEETCODE_COUNTPYRAMIDS_2088_H
#define LEETCODE_COUNTPYRAMIDS_2088_H

#include<vector>
using namespace std;

class CountPyramids {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int r1 = helper(grid);
        reverse(begin(grid), end(grid));
        return r1 + helper(grid);
    }

    int helper(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size(), res = 0;
        auto vec = grid;
        for(int i = n - 2; i >= 0; i--)
            for(int j = 1; j < m - 1; j++)
                if(vec[i][j] && vec[i + 1][j]){
                    vec[i][j] = min(vec[i + 1][j], min(vec[i + 1][j - 1], vec[i + 1][j + 1])) + 1;
                    res += vec[i][j] - 1;
                }
        return res;

    }
};

#endif //LEETCODE_COUNTPYRAMIDS_2088_H
