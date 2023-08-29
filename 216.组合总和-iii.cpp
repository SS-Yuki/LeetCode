/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        res.clear();
        sum = 0;

        backtracking(n, k, 1);

        return res;
    }

    void backtracking(int n, int k, int st) {
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
            }
            return;
        }

        for (int i = st; i <= 9 - (k - path.size()) + 1; i++) {
            if (sum + i > n) {
                return;
            }

            path.push_back(i);
            sum += i;

            backtracking(n, k, i + 1);

            path.pop_back();
            sum -= i;
        }
    }

    vector<int> path;
    vector<vector<int>> res;
    int sum;

};
// @lc code=end

