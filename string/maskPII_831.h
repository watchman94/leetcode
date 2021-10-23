//
// Created by Kiven on 2021/10/23.
//

#ifndef LEETCODE_MASKPII_831_H
#define LEETCODE_MASKPII_831_H

#include<string>
using namespace std;

class MaskPII {
public:
    string maskPII(string str) {
        auto i = str.find('@');
        string res;
        if(i != string::npos){
            res = tolower(str[0]);
            res += "*****";
            res += tolower(str[i - 1]);
            res += "@";
            auto k = str.find('.');
            for(int j = i + 1; j < k; j++) res += tolower(str[j]);
            res += ".";
            for(int j = k + 1; j < str.size(); j++) res += tolower(str[j]);
        }
        else{
            int cnt = 0; string tmp;
            for(const auto& ch : str)
                if(isdigit(ch)){
                    cnt++;
                    tmp += ch;
                }
            if(cnt == 10) res = "***-***-";
            else if(cnt == 11) res = "+*-***-***-";
            else if(cnt == 12) res = "+**-***-***-";
            else res = "+***-***-***-";
            res += tmp.substr(tmp.size() - 4, 4);
        }
        return res;
    }
};

#endif //LEETCODE_MASKPII_831_H
