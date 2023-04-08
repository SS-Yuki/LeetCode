/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, 0));
        vector<vector<bool>> dp_or(s.size()+1, vector<bool>(p.size()+1, 0));

        dp[0][0] = true;
        for (int i = 0; i <= s.size(); i++) {
            dp_or[i][0] = true;
        }

        for (int j = 1; j <= p.size()+1; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp_or[0][j] = dp[0][j-1];
            }
        }

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (p[j-1] == '?' || p[j-1] == s[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp_or[i][j-1];
                }

                dp_or[i][j] = dp_or[i-1][j] || dp[i][j];
            }
        }

        return dp[s.size()][p.size()];
    }
};
// @lc code=end

