//
// Created by Kiven on 2021/11/1.
//

#ifndef LEETCODE_PLATESBETWEENCANDLES_2055_H
#define LEETCODE_PLATESBETWEENCANDLES_2055_H

#include<vector>
#include<string>
using namespace std;

class PlatesBetweenCandles {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> l, r, v;
        int p = -1, q = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '|'){
                p = q;
                q = i;
                if(p != -1){
                    l.push_back(p);
                    r.push_back(q);
                    v.push_back(q - p - 1);
                }
            }
        }
        vector<int> pre; pre.push_back(v[0]);
        int tmp = v[0];
        for(int i = 1; i < v.size(); i++){
            tmp += v[i];
            pre.push_back(tmp);
        }
        int n = queries.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            auto it1 = lower_bound(begin(l), end(l), queries[i][0]);
            auto it2 = upper_bound(begin(r), end(r), queries[i][1]);
            if(it2 == begin(r) || it1 == end(l)) continue;
            it2--;

            int d1 = it1 - begin(l);
            int d2 = it2 - begin(r);
            int t1 = 0;
            if(d1) t1 = pre[d1 - 1];
            int tmp = pre[d2] - t1;
            if(tmp > 0) res[i] = tmp;
        }
        return res;
    }
};

#endif //LEETCODE_PLATESBETWEENCANDLES_2055_H
