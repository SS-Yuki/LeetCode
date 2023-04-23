/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        stack<TreeNode *> s;
        if (root == nullptr) {
            return ans;
        }
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            s.pop();
            if (cur != NULL) {
                if (cur->right) {
                    s.push(cur->right);
                }
                if (cur->left) {
                    s.push(cur->left);
                }
                s.push(cur);
                s.push(nullptr);
            } else {
                cur = s.top();
                s.pop();
                ans.push_back(cur->val);
            }
        }
        return ans;
    }
};
// @lc code=end
