/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <bits/stdc++.h> 
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        int max_length = 0;
        int left = 0;
        int right = 0;

        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if (dp[i][j] && j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }

        return s.substr(left, max_length);    
    }
};
// @lc code=end

