//
// Created by Kiven on 2021/10/19.
//

#ifndef LEETCODE_KTHSMALLESTPRODUCT_2040_H
#define LEETCODE_KTHSMALLESTPRODUCT_2040_H
#include<vector>
#include<algorithm>
using namespace std;
class KthSmallestProduct {
public:
    using ll = long long;
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        auto it1 = lower_bound(begin(nums1), end(nums1), 0);
        auto it2 = lower_bound(begin(nums2), end(nums2), 0);
        vector<ll> n1(begin(nums1), it1), p1(it1, end(nums1));
        vector<ll> n2(begin(nums2), it2), p2(it2, end(nums2));
        for_each(begin(n1), end(n1), [](ll& n){n *= -1;});
        for_each(begin(n2), end(n2), [](ll& n){n *= -1;});
        reverse(begin(n1), end(n1));
        reverse(begin(n2), end(n2));
        ll neg_sum = n1.size() * p2.size() + n2.size() * p1.size();
        bool flag = true;
        if(neg_sum < k) k -= neg_sum;  //find in positive
        else{      //find in negative
            k = neg_sum - k + 1;
            swap(n2, p2);
            flag = false;
        }

        ll l = 0, r = 1e10;
        while(l < r){
            ll m = l + (r - l) / 2;
            if(solver(n1, n2, m) + solver(p1, p2, m) >= k) r = m;
            else l = m + 1;
        }
        return flag ? l : -1 * l;

    }

    ll solver(vector<ll>& v1,  vector<ll>& v2, long long m){
        ll res = 0;
        ll ns = v2.size();
        long long j = ns - 1;
        for(auto i : v1){
            while(j >= 0 && i * v2[j] > m) j--;
            res += j + 1;
        }
        return res;
    };
};

#endif //LEETCODE_KTHSMALLESTPRODUCT_2040_H
