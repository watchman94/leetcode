//
// Created by Kiven on 2021/10/17.
//

#ifndef LEETCODE_CONSECUTIVENUMBERSSUM_829_H
#define LEETCODE_CONSECUTIVENUMBERSSUM_829_H

#include<cassert>
#include<cmath>
using namespace std;

class ConsecutiveNumbersSum_829 {
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        for(int i = 1; i < sqrt(2 * n); i++)
            if((n - i * (i - 1) / 2) % i == 0) res++;
        return res;
    }

    void test(){
        assert(consecutiveNumbersSum(5) == 2);
        assert(consecutiveNumbersSum(9) == 3);
        assert(consecutiveNumbersSum(15) == 4);
    }

};

#endif //LEETCODE_CONSECUTIVENUMBERSSUM_829_H
