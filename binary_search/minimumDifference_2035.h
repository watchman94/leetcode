//
// Created by Kiven on 2021/10/13.
//

#ifndef LEETCODE_MINIMUMDIFFERENCE_2035_H
#define LEETCODE_MINIMUMDIFFERENCE_2035_H
#include<vector>
#include<algorithm>
#include<numeric>
#include<cassert>
using namespace std;

class minimumDifference_2035{
public:
    int minimumDifference(const vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1), right(n + 1);
        //O(pow(2, n) * n)
        for(int i = 1; i < (1 << n); i++){
            int s = 0, l = 0, r = 0;
            for(int j = 0; j < n; j++)
                if(i & (1 << j)){
                    s++;
                    l += nums[j];
                    r += nums[j + n];
                }
            left[s].push_back(l);
            right[s].push_back(r);
        }
        //O(n * 6435 * log(6435)),  6435(the maximum size of right[i]) : combination 7 elements from 15 elements
        for(auto& r : right) sort(begin(r), end(r));
        int res = min(abs(sum - 2 * left[n][0]), abs(sum - 2 * right[n][0]));

        //O(n * 6435 * log(6435))
        for(int i = 1; i < n; i++)
            for(const auto& l : left[i]){
                int t = (sum - 2 * l) / 2;
                int ri = n - i;
                auto it = lower_bound(begin(right[ri]), end(right[ri]), t);
                if(it != end(right[ri])) res = min(res, abs(sum - 2 * l - 2 * (*it)));
                if(it != begin(right[ri])){
                    it--;
                    res = min(res, abs(sum - 2 * l - 2 * (*it)));
                }
                if(res == 0) return 0;
            }
        return res;
    }

    void test(){
        assert(minimumDifference({3,9,7,3}) == 2);
        assert(minimumDifference({-36, 36}) == 72);
        assert(minimumDifference({2,-1,0,4,-2,-9}) == 0);
    }
};




#endif //LEETCODE_MINIMUMDIFFERENCE_2035_H
