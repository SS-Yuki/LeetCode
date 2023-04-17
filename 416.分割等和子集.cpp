/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int bag_size = sum / 2;
        // dp[i][j]:在[0,i]个物体中，背包容量是j，此时可以选取得到的最大价值
        // 使每个数字作为一个物品，其重量为nums[i]，价值也为nums[i]
        vector<vector<int>> dp(nums.size(), vector<int>(bag_size + 1, 0));
        for (int j = nums[0]; j <= bag_size; j++) {
            dp[0][j] = nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= bag_size; j++) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }
        }
        return dp[nums.size() - 1][bag_size] == bag_size;
    }
};
// @lc code=end
