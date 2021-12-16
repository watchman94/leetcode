//
// Created by Kiven on 2021/12/16.
//

#ifndef LEETCODE_SUBARRAYRANGES_2104_H
#define LEETCODE_SUBARRAYRANGES_2104_H
#include<vector>
using namespace std;
class SubArrayRanges {
public:
    long long subArrayRanges(vector<int>& nums) {
        using ll = long long;
        ll res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ll mi = nums[i], ma = nums[i];
            for(int j = i + 1; j < n; j++){
                if(nums[j] < mi) mi = nums[j];
                else if(nums[j] > ma) ma = nums[j];
                res += ma - mi;
            }
        }
        return res;
    }
};

#endif //LEETCODE_SUBARRAYRANGES_2104_H
