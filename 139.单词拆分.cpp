/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 1; j <= s.size(); j++) {
            for (int i = 0; i < wordDict.size(); i++) {
                if (j >= wordDict[i].size()) {
                    if (dp[j - wordDict[i].size()] && s.substr(j - wordDict[i].size(), wordDict[i].size()) == wordDict[i]) {
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
