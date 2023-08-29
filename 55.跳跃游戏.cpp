/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        max = 0;
        for (int i = 0; i <= max && i < nums.size(); i++) {
            if (max < nums[i] + i) {
                max = nums[i] + i;
            }
        }

        return (max >= nums.size() - 1);
    }
    int max;
};
// @lc code=end

