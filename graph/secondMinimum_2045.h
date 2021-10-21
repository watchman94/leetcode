//
// Created by Kiven on 2021/10/21.
//

#ifndef LEETCODE_SECONDMINIMUM_2045_H
#define LEETCODE_SECONDMINIMUM_2045_H
#include<vector>
#include<queue>
using namespace std;

class SecondMinimum {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int t1, int t2) {
        vector<vector<int>> nei(n + 1, vector<int>());
        for(const auto& e : edges) nei[e[0]].push_back(e[1]), nei[e[1]].push_back(e[0]);
        vector<vector<int>> times(n + 1, vector<int>()); times[1].push_back(0);
        using time_node = pair<int, int>;
        priority_queue<time_node, vector<time_node>, greater<time_node>> pq; pq.emplace(0, 1);
        int res = -1;
        while(!pq.empty()){
            auto [cur, node] = pq.top(); pq.pop();
            if(node == n && times[node].size() == 2){
                res = times[node][1];
                break;
            }
            int newTime = ((cur / t2 % 2) ? (cur / t2 + 1) * t2 : cur) + t1;
            for(auto& other : nei[node]){
                if(times[other].size() == 0 || (times[other].size() == 1 && times[other][0] != newTime)){
                    times[other].push_back(newTime);
                    pq.emplace(newTime, other);
                }
            }
        }
        return res;
    }
};

#endif //LEETCODE_SECONDMINIMUM_2045_H
