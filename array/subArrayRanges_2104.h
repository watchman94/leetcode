//
// Created by Kiven on 2021/12/16.
//

#ifndef LEETCODE_SUBARRAYRANGES_2104_H
#define LEETCODE_SUBARRAYRANGES_2104_H
#include<vector>
#include<stack>
using namespace std;
class SubArrayRanges {
public:
    long long subArrayRanges(const vector<int>& nums) {
        /*
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
        */
        using ll = long long;
        ll res = 0;
        int n = nums.size();
        stack<int> st;
        vector<ll> vec(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            vec[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            ll tmp = st.empty() ? n - i : st.top() - i;
            res -= nums[i] * (tmp * vec[i]);
            st.push(i);
        }
        st = stack<int>();
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            vec[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            ll tmp = st.empty() ? n - i : st.top() - i;
            res += nums[i] * (tmp * vec[i]);
            st.push(i);
        }
        return res;
    }

    void test(){
        auto res = subArrayRanges({1,3,3});
    }
};

#endif //LEETCODE_SUBARRAYRANGES_2104_H
