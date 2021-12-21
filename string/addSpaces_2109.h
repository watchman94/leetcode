//
// Created by Kiven on 2021/12/21.
//

#ifndef LEETCODE_ADDSPACES_2109_H
#define LEETCODE_ADDSPACES_2109_H
#include <string>
#include <vector>
using namespace std;
class AddSpaces {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int i = 0;
        for(int j = 0; i < s.size() && j < spaces.size(); i++){
            if(i == spaces[j]){
                res += " ";
                j++;
            }
            res += s[i];
        }
        if(i < s.size()) res += s.substr(i);
        return res;
    }
};

#endif //LEETCODE_ADDSPACES_2109_H
