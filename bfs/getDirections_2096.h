//
// Created by Kiven on 2021/12/9.
//

#ifndef LEETCODE_GETDIRECTIONS_2096_H
#define LEETCODE_GETDIRECTIONS_2096_H

#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    using mp = pair<TreeNode*, string>;

    string getDirections(TreeNode* root, int s, int d) {
        unordered_map<TreeNode*, TreeNode*> hash;
        TreeNode* start = nullptr;
        dfs(root, hash, s, start);
        vector<TreeNode*> vec{start};
        unordered_map<TreeNode*, mp> used;
        used[start] = {nullptr, ""};
        TreeNode* dst;
        bool flag = false;
        while(!flag){
            vector<TreeNode*> tvec;
            for(auto& p : vec){
                if(p->val == d){
                    dst = p;
                    flag = true;
                    break;
                };
                if(p->left && !used.count(p->left)){
                    tvec.emplace_back(p->left);
                    used[p->left] = {p, "L"};
                }
                if(p->right && !used.count(p->right)){
                    tvec.emplace_back(p->right);
                    used[p->right] = {p, "R"};
                }
                if(hash.count(p) && !used.count(hash[p])){
                    tvec.emplace_back(hash[p]);
                    used[hash[p]] = {p, "U"};
                }
            }
            swap(vec, tvec);
        }
        return dfs2(dst, used);
    }

    string dfs2(TreeNode* root, unordered_map<TreeNode*, mp>& hash){
        if(!root) return "";
        return dfs2(hash[root].first, hash) + hash[root].second;
    }

    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& hash, int s, TreeNode*& start){
        if(!root) return;
        if(root->val == s) start = root;
        if(root->left) hash[root->left] = root;
        if(root->right) hash[root->right] = root;
        dfs(root->left, hash, s, start);
        dfs(root->right, hash, s, start);
    }
};

#endif //LEETCODE_GETDIRECTIONS_2096_H
