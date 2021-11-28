//
// Created by Kiven on 2021/11/26.
//

#ifndef LEETCODE_KMIRROR_2081_H
#define LEETCODE_KMIRROR_2081_H

#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
class KMirror{
public:
    using ll = long long;
    vector<string> v1{""}, v2{"0"};
    ll kMirror(int k, int n){
        ll res = 0;
        vector<string> vec;
        for(int i = 1; i < k && n; i++){
            v2.push_back(to_string(i));
            n--;
            res += i;
        }
        if(!n) return res;
        return res + dfs(k, n);
    }

    ll dfs(int k, int n){
        if(n == 0) return 0;
        vector<string> tv;
        ll res = 0;
        for(int i = 0; i < k && n > 0; i++)
            for(int j = 0; j < v1.size() && n > 0; j++){
                tv.emplace_back(to_string(i) + v1[j] + to_string(i));
                if(i == 0) continue;
                ll tmp = base10(tv.back(), k);
                if(helper(tmp)){
                    res += tmp;
                    n--;
                }
            }
        swap(v1, v2);
        swap(v2, tv);
        return res + dfs(k, n);
    }

    ll base10(const string& str, int k){
        ll res = 0;
        int n = str.size();
        for(int i = 0; i < n; i++) res = res * k + (str[i] - '0');
        return res;
    }

    bool helper(ll num){
        string str = to_string(num);
        int n = str.size();
        int i = 0, j = n - 1;
        while(i < j && str[i] == str[j]){
            i++;
            j--;
        }
        return !(i < j);
    }
};

void kMirror_test(){
    KMirror t;
    assert(t.kMirror(3, 7) == 499);
    assert(t.kMirror(7, 17) == 20379000);
}

#endif //LEETCODE_KMIRROR_2081_H
