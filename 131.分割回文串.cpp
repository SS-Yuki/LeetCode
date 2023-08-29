/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();

        backtracking(0, s);

        return res;
    }

    void backtracking(int st, string s) {
        if (st >= s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = st; i < s.size(); i++) {
            // [st, i]
            if (isPalindrome(s, st, i)) {
                path.push_back(s.substr(st, i - st + 1));

                backtracking(i + 1, s);

                path.pop_back();
            }
            else {
                continue;
            }
        }
    }

    bool isPalindrome(string s, int begin, int end) {
        int i = begin, j = end;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> res;
    vector<string> path;
};
// @lc code=end

