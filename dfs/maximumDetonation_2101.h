//
// Created by Kiven on 2021/12/14.
//

#ifndef LEETCODE_MAXIMUMDETONATION_2101_H
#define LEETCODE_MAXIMUMDETONATION_2101_H

#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& vec) {
        int n = vec.size();
        vector<vector<int>> nei(n);
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < n; j++)
                if(i != j && pow((vec[i][0] - vec[j][0]), 2) + pow((vec[i][1] - vec[j][1]), 2) <= 1ll * vec[i][2] * vec[i][2])
                    nei[i].push_back(j);

        int res = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> used;
            dfs(nei, used, i);
            res = max(res, int(used.size()));
        }
        return res;
    }

    void dfs(vector<vector<int>>& nei, unordered_set<int>& used, int i){
        if(used.count(i)) return;
        used.insert(i);
        for(int j : nei[i]) dfs(nei, used, j);
    }
};

#endif //LEETCODE_MAXIMUMDETONATION_2101_H
