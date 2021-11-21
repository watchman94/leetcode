//
// Created by Kiven on 2021/11/21.
//

#ifndef LEETCODE_REVERSEEVENLENGTHGROUPS_2074_H
#define LEETCODE_REVERSEEVENLENGTHGROUPS_2074_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        return helper(head, 1);
    }

    ListNode* helper(ListNode* root, int num){
        if(!root) return nullptr;
        ListNode *res;
        res = root;
        ListNode* t1 = root;
        ListNode* t2 = t1->next;
        int tmp = 1;
        while(t2 && tmp < num){
            t1 = t2;
            t2 = t2->next;
            tmp++;
        }
        if(tmp % 2){
            t1->next = helper(t2, num + 1);
            return res;
        }


        ListNode* t0 = nullptr;
        t1 = root;
        t2 = t1 -> next;
        tmp = 1;
        while(t2 && tmp < num){
            ListNode* t3 = t2 -> next;
            t2 -> next = t1;
            t1 -> next = t0;
            t0 = t1;
            t1 = t2;
            t2 = t3;
            tmp++;
        }
        root->next = helper(t2, num + 1);
        res = t1;

        return res;

    }
};

#endif //LEETCODE_REVERSEEVENLENGTHGROUPS_2074_H
