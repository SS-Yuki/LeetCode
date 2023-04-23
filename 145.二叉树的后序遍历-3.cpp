/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode *root) {
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
                s.push(cur);
                s.push(nullptr);
                if (cur->right) {
                    s.push(cur->right);
                }
                if (cur->left) {
                    s.push(cur->left);
                }
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
