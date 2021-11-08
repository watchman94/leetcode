//
// Created by Kiven on 2021/11/8.
//

#ifndef LEETCODE_MINIMIZEDMAXIMUM_2064_H
#define LEETCODE_MINIMIZEDMAXIMUM_2064_H
#include<vector>
using namespace std;

class MinimizedMaximum {
public:
    int minimizedMaximum(int n, vector<int>& qs) {
        int r = *max_element(begin(qs), end(qs));
        int l = 0;
        int m = qs.size();
        while(l < r){
            vector<int> tqs = qs;
            int mid = l + (r - l) / 2;
            int i = 0;
            for(int j = 0; i < m && j < n; j++){
                if(tqs[i] > mid) tqs[i] -= mid;
                else i++;
            }
            if(i >= m) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};

#endif //LEETCODE_MINIMIZEDMAXIMUM_2064_H
