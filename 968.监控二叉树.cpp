/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */
/*
0: 无监控
1：有监控
2：有摄像头

(1) 子节点均有监控：父节点无监控
(2) 子节点存在摄像头：父节点有监控
(3) 子节点存在无监控：父节点有摄像头
(4) 根节点无监控：根节点有摄像头
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
  int minCameraCover(TreeNode *root) {
    res = 0;
    if (traverse(root) == 0) {
      res++;
    }
    return res;
  }
  int traverse(TreeNode *node) {
    if (node == nullptr) {
      return 1;
    }
    int left = traverse(node->left);
    int right = traverse(node->right);
    if (left == 1 && right == 1) {
      return 0;
    }
    if (left == 0 || right == 0) {
      res++;
      return 2;
    }
    if (left == 2 || right == 2) {
      return 1;
    }
    return -1;
  }

private:
  int res;
};
// @lc code=end
