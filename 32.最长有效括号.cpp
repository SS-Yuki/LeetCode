/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);

        int max_length = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i-2>=0) ? dp[i-2] + 2 : 2;
                }
                else {
                    if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = i-dp[i-1]-2 >= 0 ? dp[i-1] + 2 + dp[i-dp[i-1]-2]
                                                    : dp[i-1] + 2;
                    }
                }
            }
            if (dp[i] > max_length) {
                max_length = dp[i];
            }
        }

        return max_length;
    }
};
// @lc code=end

