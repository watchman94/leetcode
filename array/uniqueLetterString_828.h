//
// Created by Kiven on 2021/10/16.
//

#ifndef LEETCODE_UNIQUELETTERSTRING_828_H
#define LEETCODE_UNIQUELETTERSTRING_828_H
#include<string>
#include<vector>
#include<cmath>
#include<cassert>
using namespace std;

class UniqueLetterString_828 {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> vec(26, vector<int>(2, -1));
        const int mod = pow(10, 9) + 7;
        int n = s.size(), res = 0;
        for(int i = 0; i < n; i++){
            int j = s[i] - 'A';
            res = (res + (i - vec[j][1]) * (vec[j][1] - vec[j][0]) % mod) % mod;
            vec[j][0] = vec[j][1];
            vec[j][1] = i;
        }
        for(int i = 0; i < 26; i++)
            res = (res + (n - vec[i][1]) * (vec[i][1] - vec[i][0]) % mod) % mod;
        return res;
    }

    void test(){
        assert(uniqueLetterString("ABC") == 10);
        assert(uniqueLetterString("ABA") == 8);
        assert(uniqueLetterString("LEETCODE") == 92);
    }
};

#endif //LEETCODE_UNIQUELETTERSTRING_828_H
