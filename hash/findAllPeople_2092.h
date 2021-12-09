//
// Created by Kiven on 2021/12/9.
//

#ifndef LEETCODE_FINDALLPEOPLE_2092_H
#define LEETCODE_FINDALLPEOPLE_2092_H

#include<vector>
#include<functional>
#include<queue>
using namespace std;

class FindAllPeople {
public:

    vector<int> findAllPeople(int n, vector<vector<int>>& vec, int p) {
        vector<vector<pair<int, int>>> nei(n);
        for(auto& v : vec){
            nei[v[0]].emplace_back(v[1], v[2]);
            nei[v[1]].emplace_back(v[0], v[2]);
        }
        using mp = pair<int, int>;
        priority_queue<mp, vector<mp>, greater<mp>> pq;
        pq.emplace(0, 0);
        pq.emplace(0, p);
        vector<bool> known(n, false);
        while(!pq.empty()){
            auto [time, id] = pq.top();
            pq.pop();
            if(known[id]) continue;
            known[id] = true;
            for(auto& [n, t] : nei[id]){
                if(!known[n] && t >= time)
                    pq.emplace(t, n);
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++)
            if(known[i])
                res.push_back(i);
        return res;
    }
};

#endif //LEETCODE_FINDALLPEOPLE_2092_H
