/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, 0));
        dp[0][0] = true;
        for (int j = 1; j <= p_len; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= s_len; i++) {
            for (int j = 1; j <= p_len; j++) {
                if (p[j - 1] != '*') {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
            }
        }
        return dp[s_len][p_len];
    }
};
// @lc code=end
