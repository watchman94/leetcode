//
// Created by Kiven on 2021/12/16.
//

#ifndef LEETCODE_SORTRACKER_2102_H
#define LEETCODE_SORTRACKER_2102_H
#include<set>
#include<string>
using namespace std;

class SORTracker {
public:
    set<pair<int, string>> tree;
    set<pair<int, string>>::iterator it;
    SORTracker(){

    }

    void add(string name, int score){
        score *= -1;
        tree.emplace(score, name);
        if(tree.size() == 1){
            it = begin(tree);
            return;
        }
        if(score < it->first || (score == it->first && name < it->second)) it--;
    }

    string get(){
        string res = it->second;
        it++;
        return res;
    }
};

#endif //LEETCODE_SORTRACKER_2102_H
