//
// Created by Kiven on 2021/11/1.
//

#ifndef LEETCODE_MAXTWOEVENTS_2054_H
#define LEETCODE_MAXTWOEVENTS_2054_H

#include<map>
#include<vector>
using namespace std;

class MaxTwoEvents {
public:
    int maxTwoEvents(vector<vector<int>>& vec) {
        map<int, int> hash;
        sort(begin(vec), end(vec));
        int i = vec.back()[0];
        int v = vec.back()[2];
        int n = vec.size();
        for(int j = n - 2; j >= 0; j--){
            if(vec[j][0] < i){
                hash[i] = v;
                i = vec[j][0];
            }
            v = max(v, vec[j][2]);
        }
        hash[i] = v;
        int res = 0;
        for(int i = 0; i < n; i++){
            int tmp = vec[i][2];
            auto it = hash.upper_bound(vec[i][1]);
            if(it != end(hash)) tmp += it->second;
            res = max(res, tmp);
        }
        return res;
    }
};

#endif //LEETCODE_MAXTWOEVENTS_2054_H
