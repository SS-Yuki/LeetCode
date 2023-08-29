/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
vector<string> dir = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        path.clear();
        if (digits.size() == 0) {
            return res;
        }
        backtracking(digits);
        return res;
    }

    void backtracking(string digits) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        for (char c : dir[(digits[path.size()] - '2')]) {
            path.push_back(c);
            backtracking(digits);
            path.pop_back();
        }
    }

    vector<string> res;
    string path;
};
// @lc code=end

