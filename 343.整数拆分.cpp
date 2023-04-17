/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        // dp[i]:将i拆分，乘积最大的值
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            int max_ = 0;
            for (int j = 1; j <= i - 2; j++) {
                int cur = max(j * (i - j), j * dp[i - j]);
                if (cur > max_) {
                    max_ = cur;
                }
            }
            dp[i] = max_;
        }
        return dp[n];
    }
};
// @lc code=end
