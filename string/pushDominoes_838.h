//
// Created by Kiven on 2021/10/23.
//

#ifndef LEETCODE_PUSHDOMINOES_838_H
#define LEETCODE_PUSHDOMINOES_838_H

#include<string>
#include<cassert>

using namespace std;

class PushDominoes {
public:
    string pushDominoes(string dominoes) {
        string res;
        using mp = pair<char, int>;
        vector<mp> vec;
        int n = dominoes.size();
        for(int i = 0; i < n; i++){
            if(dominoes[i] == '.') continue;
            if(dominoes[i] == 'R'){
                if(vec.empty()) res += string(i, '.');
                else if(vec.back().first == 'L') res += string(i - 1 - vec.back().second, '.');
                else res += string(i - vec.back().second, 'R');
            }
            else{
                if(vec.empty()) res += string(i + 1, 'L');
                else if(vec.back().first == 'L') res += string(i - vec.back().second, 'L');
                else{
                    int l = i - vec.back().second + 1;
                    res += string(l / 2, 'R');
                    if(l % 2) res += string(1, '.');
                    res += string(l / 2, 'L');
                }
            }
            vec.emplace_back(dominoes[i], i);
        }
        int d = n - res.size();
        (vec.empty() || vec.back().first == 'L') ? res += string(d, '.') : res += string(d, 'R');
        return res;
    }

    void test(){
        assert(pushDominoes(".L.R...LR..L..") == "LL.RR.LLRRLL..");
    }
};

#endif //LEETCODE_PUSHDOMINOES_838_H
