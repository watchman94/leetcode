//
// Created by Kiven on 2021/11/24.
//

#ifndef LEETCODE_WATERINGPLANTS_2079_H
#define LEETCODE_WATERINGPLANTS_2079_H

#include<vector>
using namespace std;
class WateringPlants {
public:
    int wateringPlants(vector<int>& plants, int c) {
        int t = c;
        int n = plants.size();
        int res = 0;
        for(int i = 0; i < n; i++)
            if(t >= plants[i]){
                res++;
                t -= plants[i];
            }
            else{
                res += 2 * i + 1;
                t = c - plants[i];
            }

        return res;
    }
};

#endif //LEETCODE_WATERINGPLANTS_2079_H
