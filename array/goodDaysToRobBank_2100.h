//
// Created by Kiven on 2021/12/14.
//

#ifndef LEETCODE_GOODDAYSTOROBBANK_2100_H
#define LEETCODE_GOODDAYSTOROBBANK_2100_H

#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& vec, int t) {
        int n = vec.size();
        if(!t){
            vector<int> res(n, 0);
            iota(begin(res), end(res), 0);
            return res;
        }
        vector<int> tmp(n, 0), res;
        for(int i = 1; i < n - 1; i++) tmp[i] = vec[i] <= vec[i - 1] ? tmp[i - 1] + 1 : 0;
        for(int i = n - 2; i >= 0; i--){
            if(vec[i] <= vec[i + 1]){
                if(tmp[i + 1] + 1 >= t && tmp[i] >= t) res.push_back(i);
                tmp[i] = tmp[i + 1] + 1;
            }
            else tmp[i] = 0;
        }
        return res;
    }
};

#endif //LEETCODE_GOODDAYSTOROBBANK_2100_H
