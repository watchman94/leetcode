//
// Created by Kiven on 2021/10/26.
//

#ifndef LEETCODE_COUNTHIGHESTSCORENODES_2049_H
#define LEETCODE_COUNTHIGHESTSCORENODES_2049_H
#include <vector>
#include <unordered_map>
using namespace std;
class CountHighestScoreNodes {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<int, vector<int>> hash;
        int n = parents.size();
        for(int i = 0; i < n; i++) hash[parents[i]].push_back(i);
        vector<pair<int, int>> vp(n);
        dfs(0, vp, hash);
        long long tmax = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            auto [ln, rn] = vp[i];
            int pn = n - 1 - ln - rn;
            long long tmp = 1ll * max(1, ln) * max(1, rn) * max(1, pn);
            if(tmp > tmax){
                tmax = tmp;
                cnt = 1;
            }
            else if(tmp >= tmax)
                cnt++;
        }
        return cnt;
    }

    int dfs(int i, vector<pair<int, int>>& vp, unordered_map<int, vector<int>>& hash){
        int l = 0, r = 0;
        if(!hash.count(i)){
            vp[i] = {0, 0};
            return 1;
        }
        l = dfs(hash[i][0], vp, hash);
        if(hash[i].size() > 1) r = dfs(hash[i][1], vp, hash);
        vp[i] = {l, r};
        return l + r + 1;
    }

};

#endif //LEETCODE_COUNTHIGHESTSCORENODES_2049_H
