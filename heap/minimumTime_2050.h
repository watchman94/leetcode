//
// Created by Kiven on 2021/10/27.
//

#ifndef LEETCODE_MINIMUMTIME_2050_H
#define LEETCODE_MINIMUMTIME_2050_H

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& times) {
        vector<int> in(n + 1);
        vector<vector<int>> out(n + 1);
        for(const auto& r : rel){
            in[r[1]]++;
            out[r[0]].push_back(r[1]);
        }

        using mp = pair<int, int>;
        priority_queue<mp, vector<mp>, greater<mp>> pq;
        for(int i = 1; i <= n; i++)
            if(!in[i]) pq.emplace(times[i - 1], i);

        int res = 0;
        while(!pq.empty()){
            auto [t, c] = pq.top();
            pq.pop();
            res = t;
            for(auto i : out[c]){
                in[i]--;
                if(!in[i]) pq.emplace(times[i - 1] + t, i);
            }

        }
        return res;
    }
};

#endif //LEETCODE_MINIMUMTIME_2050_H
