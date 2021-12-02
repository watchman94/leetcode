//
// Created by Kiven on 2021/12/2.
//

#ifndef LEETCODE_GETAVERAGES_2090_H
#define LEETCODE_GETAVERAGES_2090_H

#include<vector>
#include<numeric>
using namespace std;

class GetAverages {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, -1);
        if(n < 2 * k + 1) return res;
        long long tmp = accumulate(begin(nums), begin(nums) + 2 * k + 1, 0ll);
        for(int i = k; i < n - k; i++){
            res[i] = tmp / (2 * k + 1);
            tmp -= nums[i - k];
            if(i + k + 1 < n) tmp += nums[i + k + 1];
        }
        return res;
    }
};

#endif //LEETCODE_GETAVERAGES_2090_H
