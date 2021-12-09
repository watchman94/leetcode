//
// Created by Kiven on 2021/12/9.
//

#ifndef LEETCODE_DELETEMIDDLE_2095_H
#define LEETCODE_DELETEMIDDLE_2095_H

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
    ListNode* deleteMiddle(ListNode* root) {
        if(!root->next) return nullptr;
        ListNode *fast = root->next, *slow = root;
        ListNode* res = root;
        while(fast && fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return res;
    }
};

#endif //LEETCODE_DELETEMIDDLE_2095_H
