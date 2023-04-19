/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto str : strs) {
            int num_0 = 0;
            int num_1 = 0;
            for (char c : str) {
                if (c == '0') {
                    num_0++;
                } else {
                    num_1++;
                }
            }
            for (int i = m; i >= num_0; i--) {
                for (int j = n; j >= num_1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - num_0][j - num_1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
