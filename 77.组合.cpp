/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        path.clear();
        res.clear();

        backtracking(n, k, 1);

        return res;
    }

    void backtracking(int n, int k, int st) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = st; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

