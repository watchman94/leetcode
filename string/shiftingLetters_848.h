//
// Created by Kiven on 2021/11/6.
//

#ifndef LEETCODE_SHIFTINGLETTERS_848_H
#define LEETCODE_SHIFTINGLETTERS_848_H
#include<string>
#include<vector>
using namespace std;
class ShiftingLetters {
public:
    string shiftingLetters(string s, const vector<int>& shifts) {
        using ll = long long;
        int n = shifts.size();
        vector<ll> vec(n, 0); vec[n - 1] = shifts[n - 1];
        for(int i = n - 2; i >= 0; i--) vec[i] = shifts[i] + vec[i + 1];
        string res;
        for(int i = 0; i < n; i++) res += ((s[i] - 'a') + vec[i]) % 26 + 'a';
        return res;
    }

    void test(){
        auto res = shiftingLetters("aaa", {1,1,1});
    }

};

#endif //LEETCODE_SHIFTINGLETTERS_848_H
