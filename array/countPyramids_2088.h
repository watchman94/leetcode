//
// Created by Kiven on 2021/11/30.
//

#ifndef LEETCODE_COUNTPYRAMIDS_2088_H
#define LEETCODE_COUNTPYRAMIDS_2088_H

#include<vector>
#include<cassert>
using namespace std;

class CountPyramids {
public:
    int countPyramids(vector<vector<int>> grid) {
        int r1 = helper(grid);
        reverse(begin(grid), end(grid));
        return r1 + helper(grid);
    }

    int helper(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<int>> vec(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j]){
                    int l = vec[i][j] + 1;
                    bool flag = true;
                    //bool flag1 = false;
                    while(i + l < n && j - l >= 0 && j + l < m && flag){
                        for(int k = j - l; k <= j + l; k++)
                            if(!grid[i + l][k]){
                                flag = false;
                                break;
                            }
                        if(flag){
                            l++;
                            //flag1 = true;
                        }
                    }
                    int h = 0;
                    while(l > 1){
                        for(int k = j - h; k <= j + h; k++){
                            if(!vec[i + h][k]) {
                                res += l - 1;
                                vec[i + h][k] = l - 1;
                            }
                        }
                        l--;
                        h++;
                    }
                }
        return res;
    }

    void test(){
        assert(countPyramids({{0,0,0,1,0,0,0},{0,0,1,1,1,0,0},{0,1,1,1,1,0,0},{1,1,1,1,1,1,1}}) == 12);
    }
};

#endif //LEETCODE_COUNTPYRAMIDS_2088_H
