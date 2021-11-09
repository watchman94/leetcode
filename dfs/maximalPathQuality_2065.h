//
// Created by Kiven on 2021/11/9.
//

#ifndef LEETCODE_MAXIMALPATHQUALITY_2065_H
#define LEETCODE_MAXIMALPATHQUALITY_2065_H

#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class MaximalPathQuality {
public:

    int maximalPathQuality(const vector<int>& values, const vector<vector<int>>& edges, int maxTime) {
        unordered_map<int, vector<pair<int, int>>> hash;
        for(const auto& e : edges){
            hash[e[0]].emplace_back(e[1], e[2]);
            hash[e[1]].emplace_back(e[0], e[2]);
        }
        if(hash[0].empty()) return values[0];
        int n = values.size();
        vector<int> used(n, 0);
        int ans = 0;
        dfs(0, 0, 0,hash, maxTime, used, values, ans);
        return ans;
    }

    void dfs(int i, int t, int v, unordered_map<int, vector<pair<int, int>>>& hash, int maxTime, vector<int>& used, const vector<int>& values, int& ans){
        used[i]++;
        if(used[i] == 1) v += values[i];
        if(i == 0) ans = max(v, ans);
        for(auto& [nei, tmpT]: hash[i])
            if(tmpT + t <= maxTime) {
                dfs(nei, t + tmpT, v, hash, maxTime, used, values, ans);
            }
        used[i]--;
    }

    void test(){
        auto res = maximalPathQuality({0, 32, 10, 43}, {{0,1,10},{1,2,15},{0,3,10}}, 49);
        res = maximalPathQuality({0, 1, 2}, {{1,2,10}}, 49);
        res = maximalPathQuality({0, 5, 10}, {{0,1,10}, {0,2,10}}, 11);
    }


};

#endif //LEETCODE_MAXIMALPATHQUALITY_2065_H
