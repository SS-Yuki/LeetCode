/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        // left-right=target
        // left+left=right+target+left=sum+target
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 == 1 || (sum + target) < 0) {
            return 0;
        }
        int bag_size = (sum + target) / 2;
        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bag_size; j >= 0; j--) {
                if (j >= nums[i]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[bag_size];
    }
};
// @lc code=end
