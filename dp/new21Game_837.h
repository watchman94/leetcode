//
// Created by Kiven on 2021/10/23.
//

#ifndef LEETCODE_NEW21GAME_837_H
#define LEETCODE_NEW21GAME_837_H
#include<vector>
using namespace std;

class New21Game {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k - 1 + maxPts) return 1.0;
        vector<double> dp(n + 1, 0.0); dp[0] = 1.0;
        double res = 0.0, pre = 1.0;
        for(int i = 1; i <= n; i++){
            dp[i] = pre / maxPts;
            if(i < k) pre += dp[i];
            else res += dp[i];
            if(i >= maxPts) pre -= dp[i - maxPts];
        }
        return res;
    }
};

#endif //LEETCODE_NEW21GAME_837_H
