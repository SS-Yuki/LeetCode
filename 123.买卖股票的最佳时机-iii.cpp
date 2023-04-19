/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // dp[i][0][0]：第一次持有，dp[i][0][1]：第一次不持有
        // dp[i][1][0]：第二次持有，dp[i][0][1]：第二次不持有
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, 0)));
        dp[0][0] = {-prices[0], 0};
        dp[0][1] = {-prices[0], 0};
        // i:到达第几天
        // j：处于第几轮交易
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j][0] = max((j == 0 ? 0 : dp[i - 1][j - 1][1]) - prices[i], dp[i - 1][j][0]);
                dp[i][j][1] = max(dp[i - 1][j][0] + prices[i], dp[i - 1][j][1]);
            }
        }
        return max(dp[prices.size() - 1][0][1], dp[prices.size() - 1][1][1]);
    }
};
// @lc code=end
