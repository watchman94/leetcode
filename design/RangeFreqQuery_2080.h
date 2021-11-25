//
// Created by Kiven on 2021/11/25.
//

#ifndef LEETCODE_RANGEFREQQUERY_2080_H
#define LEETCODE_RANGEFREQQUERY_2080_H

#include<vector>
#include<unordered_map>
using namespace std;
class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> hash;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) hash[arr[i]].push_back(i);
    }

    int query(int l, int r, int v) {
        //if(!hash.count(v)) return 0;
        auto it1 = lower_bound(begin(hash[v]), end(hash[v]), l);
        auto it2 = upper_bound(begin(hash[v]), end(hash[v]), r);
        return  it2 - it1;
    }
};

#endif //LEETCODE_RANGEFREQQUERY_2080_H
