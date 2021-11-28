//
// Created by Kiven on 2021/11/28.
//

#ifndef LEETCODE_MINIMUMBUCKETS_2086_H
#define LEETCODE_MINIMUMBUCKETS_2086_H
#include<string>
using namespace std;
class MinimumBuckets {
public:
    int minimumBuckets(string street) {
        int res = 0, n = street.size();
        for(int i = 0; i < n; i++)
            if(street[i] == 'H')
                if(i > 0 && street[i - 1] == 'W') continue;
                else if(i < n - 1 && street[i + 1] == '.'){
                    street[i + 1] = 'W';
                    res++;
                }
                else if(i > 0 && street[i - 1] == '.') res++;
                else return -1;

        return res;
    }
};

#endif //LEETCODE_MINIMUMBUCKETS_2086_H
