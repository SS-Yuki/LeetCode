/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue_;
        for (int i = 0; i < k; i++) {
            queue_.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            int top = queue_.top();
            if (nums[i] > top) {
                queue_.pop();
                queue_.push(nums[i]);
            }
        }
        return queue_.top();
    }
};
// @lc code=end

