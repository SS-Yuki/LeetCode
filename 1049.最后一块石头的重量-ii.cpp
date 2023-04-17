/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int bag_size = sum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(bag_size + 1, 0));
        for (int j = stones[0]; j <= bag_size; j++) {
            dp[0][j] = stones[0];
        }
        for (int i = 1; i < stones.size(); i++) {
            for (int j = 1; j <= bag_size; j++) {
                if (j < stones[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
                }
            }
        }
        return (sum - dp[stones.size() - 1][bag_size]) - dp[stones.size() - 1][bag_size];
    }
};
// @lc code=end
