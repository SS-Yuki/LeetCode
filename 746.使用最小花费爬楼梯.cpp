/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int len = cost.size();
        vector<int> dp(len + 1, 0);
        for (int i = 2; i <= len; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[len];
    }
};
// @lc code=end
