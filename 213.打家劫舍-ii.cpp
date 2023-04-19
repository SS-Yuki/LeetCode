/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(robLinear(nums, 0, nums.size() - 2), robLinear(nums, 1, nums.size() - 1));
    }

    int robLinear(vector<int> &nums, int begin, int end) {
        vector<int> dp(end - begin + 1, 0);
        if (begin == end) {
            return nums[begin];
        }
        dp[0] = nums[begin];
        dp[1] = max(nums[begin], nums[begin + 1]);
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(nums[begin + i] + dp[i - 2], dp[i - 1]);
        }
        return dp[dp.size() - 1];
    }
};
// @lc code=end
