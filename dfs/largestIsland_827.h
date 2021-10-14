//
// Created by Kiven on 2021/10/14.
//

#ifndef LEETCODE_LARGESTISLAND_827_H
#define LEETCODE_LARGESTISLAND_827_H

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<cassert>
using namespace std;

class LargestIsland_827 {
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> hash;
        int n = grid.size(), m = grid[0].size(), id = 2, res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1) {
                    hash[id] = dfs(i, j, grid, id);
                    res = max(res, hash[id++]);
                }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 0) {
                    unordered_set<int> used;
                    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    int tmp = 1;
                    for(auto& dir : dirs){
                        int x = i + dir[0], y = j + dir[1];
                        if(x < 0 || x >= n || y < 0 || y >= m) continue;
                        if(grid[x][y] != 0 && !used.count(grid[x][y])){
                            used.insert(grid[x][y]);
                            tmp += hash[grid[x][y]];
                        }
                    }
                    res = max(res, tmp);
                }
        return res;

    }

    int dfs(int i, int j, vector<vector<int>>& grid, int id){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) return 0;
        grid[i][j] = id;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        for(auto& dir : dirs) res += dfs(i + dir[0], j + dir[1], grid, id);
        return 1 + res;
    }

    void test(){
        vector<vector<int>> vec = {{1, 0}, {0, 1}};
        assert(largestIsland(vec) == 3);
        vec = {{1, 1}, {0, 1}};
        assert(largestIsland(vec) == 4);
        vec = {{1, 1}, {1, 1}};
        assert(largestIsland(vec) == 4);
    }
};
#endif //LEETCODE_LARGESTISLAND_827_H
