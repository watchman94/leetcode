//
// Created by Kiven on 2021/12/9.
//

#ifndef LEETCODE_VALIDARRANGEMENT_2097_H
#define LEETCODE_VALIDARRANGEMENT_2097_H

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& p) {
        int n = p.size();
        unordered_map<int, vector<int>> nei;
        unordered_map<int, int> in, out;
        nei.reserve(n);
        in.reserve(n);
        out.reserve(n);
        for(auto& v : p){
            nei[v[0]].push_back(v[1]);
            out[v[0]]++;
            in[v[1]]++;
        }
        int start = begin(nei)->first;
        for(auto& [i, c] : out)
            if(c - in[i] == 1)
                start = i;
        vector<vector<int>> res;
        dfs(nei, res, start);
        reverse(begin(res), end(res));
        return res;
    }

    void dfs(unordered_map<int, vector<int>>& nei, vector<vector<int>>& res, int i){
        while(!nei[i].empty()){
            int t = nei[i].back();
            nei[i].pop_back();
            dfs(nei, res, t);
            res.push_back({i, t});
        }
    }


};

#endif //LEETCODE_VALIDARRANGEMENT_2097_H
