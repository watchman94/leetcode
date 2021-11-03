//
// Created by Kiven on 2021/11/3.
//

#ifndef LEETCODE_MINIMUMOPERATIONS_2059_H
#define LEETCODE_MINIMUMOPERATIONS_2059_H
#include<vector>
using namespace std;

class MinimumOperations {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> used(1001, false);
        vector<int> vec{start};
        int res = 0;
        auto check = [&](int t){return t >= 0 && t <= 1000 && !used[t];};
        while(!vec.empty()){
            vector<int> tvec;
            for(int i : vec){
                if(i == goal) return res;
                if(!check(i)) continue;
                used[i] = true;
                for(int n : nums){
                    auto tmp = {i + n, i - n, i ^ n};
                    tvec.insert(end(tvec), begin(tmp), end(tmp));
                }
            }

            swap(tvec, vec);
            res++;
        }
        return -1;
    }
};
#endif //LEETCODE_MINIMUMOPERATIONS_2059_H
