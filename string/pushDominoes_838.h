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
        /*
         //method 1
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
         */

        //method 2
        int j = -1;
        int n = dominoes.size();
        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R') j = i;
            else if(dominoes[i] == 'L') j = -1;
            if(j == -1) vec[i] = 1e5 + 1;
            else vec[i] = i - j;
        }
        string res;
        j = -1;
        int d;
        for(int i = n - 1; i >= 0; i--){
            if(dominoes[i] == 'L') j = i;
            else if(dominoes[i] == 'R') j = -1;
            if(j == -1) d = 1e5 + 1;
            else d = j - i;
            if(d < vec[i]) res += "L";
            else if(d > vec[i]) res += "R";
            else res += ".";
        }
        reverse(begin(res), end(res));
        return res;



    }

    void test(){
        assert(pushDominoes(".L.R...LR..L..") == "LL.RR.LLRRLL..");
    }
};

#endif //LEETCODE_PUSHDOMINOES_838_H
