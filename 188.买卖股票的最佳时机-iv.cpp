/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        // dp[i][j][0]：第j+1次持有，dp[i][j][1]：第j+1次不持有
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(k, vector<int>(2, 0)));
        for (int j = 0; j < k; j++) {
            dp[0][j] = {-prices[0], 0};
        }
        // i:到达第几天
        // j：处于第几轮交易
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j][0] = max((j == 0 ? 0 : dp[i - 1][j - 1][1]) - prices[i], dp[i - 1][j][0]);
                dp[i][j][1] = max(dp[i - 1][j][0] + prices[i], dp[i - 1][j][1]);
            }
        }
        return dp[prices.size() - 1][k - 1][1];
    }
};
// @lc code=end
