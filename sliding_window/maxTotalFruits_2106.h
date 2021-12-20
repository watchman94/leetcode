//
// Created by Kiven on 2021/12/20.
//

#ifndef LEETCODE_MAXTOTALFRUITS_2106_H
#define LEETCODE_MAXTOTALFRUITS_2106_H

#include<vector>
using namespace std;

class MaxTotalFruits {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        auto l = upper_bound(begin(fruits), end(fruits), vector<int>{startPos - k});
        int sum = 0;
        int res = 0;
        for(auto r = l; r < end(fruits) && (*r)[0] <= startPos + k; r++){
            sum += (*r)[1];
            while(min(startPos - 2 * (*l)[0] + (*r)[0], 2 * (*r)[0] - startPos - (*l)[0]) > k) sum -= (*l++)[1];
            res = max(sum, res);
        }
        return res;
    }
};

#endif //LEETCODE_MAXTOTALFRUITS_2106_H
