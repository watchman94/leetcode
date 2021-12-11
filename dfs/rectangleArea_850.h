//
// Created by Kiven on 2021/12/11.
//

#ifndef LEETCODE_RECTANGLEAREA_850_H
#define LEETCODE_RECTANGLEAREA_850_H

#include<vector>
#include<cassert>

using namespace std;
class RectangleArea {
public:
    int rectangleArea(vector<vector<int>> vec) {
        vector<vector<int>> allVec;
        for(auto&& v : vec)
            helper(allVec, move(v), 0);
        int res = 0;
        const int mod = 1e9 + 7;
        for(auto& v : allVec) res = (res + (1ll * v[2] - v[0]) * (1ll * v[3] - v[1])) % mod;
        return res;
    }
    void helper(vector<vector<int>>& allVec, vector<int>&& vec, int i){
        if(i == allVec.size()){
            allVec.emplace_back(vec);
            return;
        }
        auto tvec = allVec[i];
        if(vec[2] <= tvec[0] || vec[3] <= tvec[1] || vec[0] >= tvec[2] || vec[1] >= tvec[3]){
            helper(allVec, move(vec), i + 1);
            return;
        }
        if(vec[0] < tvec[0]) helper(allVec, {vec[0], vec[1], tvec[0], vec[3]}, i + 1);
        if(vec[2] > tvec[2]) helper(allVec, {tvec[2], vec[1], vec[2], vec[3]}, i + 1);
        if(vec[1] < tvec[1]) helper(allVec, {max(vec[0], tvec[0]), vec[1], min(vec[2], tvec[2]), tvec[1]}, i + 1);
        if(vec[3] > tvec[3]) helper(allVec, {max(vec[0], tvec[0]), tvec[3], min(vec[2], tvec[2]), vec[3]}, i + 1);
    }

    void test(){
        assert(rectangleArea({{0,0,2,2},{1,0,2,3},{1,0,3,1}}) == 6);
    }
};

#endif //LEETCODE_RECTANGLEAREA_850_H
