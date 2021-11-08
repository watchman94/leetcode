//
// Created by Kiven on 2021/11/8.
//

#ifndef LEETCODE_COUNTVOWELS_2063_H
#define LEETCODE_COUNTVOWELS_2063_H
#include<string>
#include<unordered_set>
using namespace std;

class CountVowels {
public:
    long long countVowels(string word) {
        long long res = 0;
        int n = word.size();
        unordered_set<char> hash = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++){
            if(hash.count(word[i]))
                res += 1ll * (i + 1) * (n - i);
        }
        return res;
    }
};

#endif //LEETCODE_COUNTVOWELS_2063_H
