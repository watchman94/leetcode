//
// Created by Kiven on 2021/11/27.
//

#ifndef LEETCODE_MAXDISTTOCLOSEST_849_H
#define LEETCODE_MAXDISTTOCLOSEST_849_H
#include <vector>
using namespace std;
class MaxDistToClosest {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0, n = seats.size();
        while(i < n && !seats[i]) i++;
        int res = i;
        int t = i;
        i += 1;
        for(; i < n; i++)
            if(seats[i]){
                res = max((i - t) / 2, res);
                t = i;
            }
        res = max(n - 1 - t, res);
        return res;
    }
};

#endif //LEETCODE_MAXDISTTOCLOSEST_849_H
