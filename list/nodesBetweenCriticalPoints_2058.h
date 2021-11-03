//
// Created by Kiven on 2021/11/3.
//

#ifndef LEETCODE_NODESBETWEENCRITICALPOINTS_2058_H
#define LEETCODE_NODESBETWEENCRITICALPOINTS_2058_H

#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minT = INT_MAX;
        vector<int> res;
        ListNode* p = head;
        int pre = p->val;
        p = p->next;
        int i = 2;
        while(p && p->next){
            if((pre < p->val && p->val > p->next->val) || (pre > p->val && p->val < p->next->val)){
                if(!res.empty()) minT = min(minT, i - res.back());
                if(res.size() == 2) res.pop_back();
                res.push_back(i);
            }
            i++;
            pre = p->val;
            p = p->next;
        }
        if(res.size() < 2) return {-1, -1};
        return {minT, res.back() - res.front()};
    }
};

#endif //LEETCODE_NODESBETWEENCRITICALPOINTS_2058_H
