//
// Created by Kiven on 2021/10/26.
//

#ifndef LEETCODE_NEXTBEAUTIFULNUMBER_2048_H
#define LEETCODE_NEXTBEAUTIFULNUMBER_2048_H
#include <vector>
#include <cmath>
using namespace std;
class NextBeautifulNumber {
public:
    int nextBeautifulNumber(int n) {
        int m = 0;
        int tn = n;
        while(tn){
            m++;
            tn /= 10;
        }
        int tmp = pow(10, m);

        for(int i = n + 1;;i++){
            if(i >= tmp) m++;
            vector<int> vec(10, 0);
            int j = i;
            int k = 0;
            while(j){
                k++;
                vec[j % 10]++;
                if(j % 10 == 0) break;
                else if(vec[j % 10] > j % 10) break;
                else if(vec[j % 10] + m - k < j % 10) break;
                j /= 10;
            }
            if(!j){
                for(; j <= 9; j++)
                    if(vec[j] != 0 && vec[j] != j)
                        break;
                if(j == 10) return i;
            }
        }
        return -1;
    }
};

#endif //LEETCODE_NEXTBEAUTIFULNUMBER_2048_H
