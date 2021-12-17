//
// Created by Kiven on 2021/12/17.
//

#ifndef LEETCODE_MINIMUMREFILL_2105_H
#define LEETCODE_MINIMUMREFILL_2105_H

#include<vector>
using namespace std;

class MinimumRefill {
public:
    int minimumRefill(const vector<int>& plants, int capacityA, int capacityB) {
        int i = 0, j = plants.size() - 1;
        int ta = capacityA, tb = capacityB;
        int res = 0;
        while(i < j){
            ta = ta >= plants[i] ? ta - plants[i] : (res++, capacityA - plants[i]);
            tb = tb >= plants[j] ? tb - plants[j] : (res++, capacityB - plants[j]);
            i++, j--;
        }
        if(i == j && max(ta, tb) < plants[i]) res++;
        return res;
    }

    void test(){
        auto res = minimumRefill({726,739,934,116,643,648,473,984,482,85,850,806,146,764,156,66,186,339,985,237,662,552,800,78,617,933,481,652,796,594,151,82,183,241,525,221,951,732,799,483,368,354,776,175,974,187,913,842}, 1439, 1207);
    }
};

#endif //LEETCODE_MINIMUMREFILL_2105_H
