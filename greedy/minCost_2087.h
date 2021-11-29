//
// Created by Kiven on 2021/11/29.
//

#ifndef LEETCODE_MINCOST_2087_H
#define LEETCODE_MINCOST_2087_H

#include <vector>
using namespace std;

class MinCost {
public:
    int minCost(vector<int>& s, vector<int>& h, vector<int>& r, vector<int>& c) {
        int res = 0;
        if(s[0] < h[0]) for(int i = s[0] + 1; i <= h[0]; i++) res += r[i];
        else for(int i = s[0] - 1; i >= h[0]; i--) res += r[i];
        if(s[1] < h[1]) for(int i = s[1] + 1; i <= h[1]; i++) res += c[i];
        else for(int i = s[1] - 1; i >= h[1]; i--) res += c[i];
        return res;
    }
};

#endif //LEETCODE_MINCOST_2087_H
