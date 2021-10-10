//
// Created by Kiven on 2021/10/10.
//

#ifndef LEETCODE_MINOPERATIONS_2033_H
#define LEETCODE_MINOPERATIONS_2033_H
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
using namespace std;
class  minOperations_2033{
public:
    int minOperations(const vector<vector<int>>& grid, int x) {
        vector<int> vec;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if((grid[i][j] - grid[0][0]) % x != 0) return -1;
                else vec.push_back(grid[i][j]);
        sort(begin(vec), end(vec));
        int n = vec.size(), res = 0;
        int mid = *(begin(vec) + n / 2);
        for(int i = 0; i < n; i++){
            if((vec[i] - mid) % x) return -1;
            res += abs(vec[i] - mid) / x;
        }
        return res;
    }

    string test(){
        assert(minOperations({{2,4},{6,8}}, 2) == 4);
        assert(minOperations({{1,5},{2,3}}, 1) == 5);
        assert(minOperations({{1,2},{3,4}}, 2) == -1);
        return "Test OK";
    }
};
#endif //LEETCODE_MINOPERATIONS_2033_H
