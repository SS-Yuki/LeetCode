/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // dp[i][0] 当前持有（最大值），dp[i][1] 当前不持有（最大值）
        // dp[i][0] = max(-prices[i], dp[i-1][0])
        // dp[i][1] = max(dp[i-1][0]+prices[i], dp[i-1][1])
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0] = {-prices[0], 0};
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(-prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};
// @lc code=end
