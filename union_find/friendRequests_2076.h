//
// Created by Kiven on 2021/11/23.
//

#ifndef LEETCODE_FRIENDREQUESTS_2076_H
#define LEETCODE_FRIENDREQUESTS_2076_H

#include <vector>
#include <numeric>
using namespace std;

class FriendRequests {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> roots(n, 0);
        iota(begin(roots), end(roots), 0);
        int m = requests.size();
        vector<bool> res(m);
        for(int i = 0; i < m; i++){
            int t1 = find(roots, requests[i][0]);
            int t2 = find(roots, requests[i][1]);
            bool flag = true;
            for(auto& r: restrictions){
                int r1 = find(roots, r[0]);
                int r2 = find(roots, r[1]);
                if((r1 == t1 && r2 == t2) || (r1 == t2 && r2 == t1)){
                    flag = false;
                    break;
                }
            }
            res[i] = flag;
            if(flag) roots[t1] = t2;
        }
        return res;
    }

    int find(vector<int>& roots, int i){
        return roots[i] = roots[i] == i ? i : find(roots, roots[i]);
    }
};

#endif //LEETCODE_FRIENDREQUESTS_2076_H
