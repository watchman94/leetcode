//
// Created by Kiven on 2021/11/22.
//

#ifndef LEETCODE_DECODECIPHERTEXT_2075_H
#define LEETCODE_DECODECIPHERTEXT_2075_H
#include <string>
using namespace std;
class DecodeCiphertext {
public:
    string decodeCiphertext(string encode, int rows) {
        int c = encode.size() / rows;
        string res;
        for(int i = 0; i < c; i++)
            for(int j = 0, k = i; j < rows && k < c; j++, k++) res += encode[j * c + k];
        int i = res.size() - 1;
        while(i >= 0 && res[i] == ' ') i--;
        return res.substr(0, i + 1);
    }
};

#endif //LEETCODE_DECODECIPHERTEXT_2075_H
