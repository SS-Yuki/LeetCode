/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int fib(int n) {
        // vector<int> dp(n + 1, 0);
        // dp[0] = 0;
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        if (n < 2) {
            return n;
        }
        int dp0 = 0;
        int dp1 = 1;
        int tmp;
        for (int i = 2; i <= n; i++) {
            tmp = dp1;
            dp1 = dp0 + dp1;
            dp0 = tmp;
        }
        return dp1;
    }
};
// @lc code=end
