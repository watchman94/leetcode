//
// Created by Kiven on 2021/11/21.
//

#ifndef LEETCODE_MAXTASKASSIGN_2071_H
#define LEETCODE_MAXTASKASSIGN_2071_H
#include<vector>
#include<set>
using namespace std;
class Solution {
public:

    bool helper(int m, const vector<int>& vec, multiset<int>& mw, int pills, int strength){
        int n = mw.size();
        auto t2 = begin(mw);
        //advance(t1, m);
        advance(t2, n - m);
        //multiset<int> tmt(begin(mt), t1);
        multiset<int> tmw(t2, end(mw));
        for(int i = m - 1; i >= 0; i--){
            int tmp = vec[i];
            auto it1 = tmw.lower_bound(tmp);
            if(it1 != end(tmw)) tmw.erase(it1);
            else if(pills--){
                it1 = tmw.lower_bound(tmp - strength);
                if(it1 != end(tmw)) tmw.erase(it1);
                else return false;
            }
            else return false;
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(begin(tasks), end(tasks));
        multiset<int> mw(begin(workers), end(workers));
        int l = 0, r = min(tasks.size(), workers.size());
        while(l + 1 < r){
            int m = l + (r - l) / 2;
            if(helper(m, tasks, mw, pills, strength)) l = m;
            else r = m - 1;
        }
        if(helper(r, tasks, mw, pills, strength)) return r;
        return l;
    }
};

#endif //LEETCODE_MAXTASKASSIGN_2071_H
