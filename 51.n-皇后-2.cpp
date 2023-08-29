/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        arr.clear();
        res.clear();

        backtracking(n);

        return res;
    }

    void backtracking(int n) {
        if (arr.size() == n) {
            res.push_back(toPath(arr));
            return;
        }

        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < arr.size(); j++) {
                // 目标点 (arr.size(), i)
                // 已保存的点 (j, arr[j])
                if ((arr[j] == i) || (arr.size() - j == i - arr[j]) || (arr.size() - j == arr[j] - i)) {
                    flag = false;
                }
            }
            if (flag) {
                arr.push_back(i);

                backtracking(n);

                arr.pop_back();
            }
        }
    }

    vector<string> toPath(vector<int> &arr) {
        string str(arr.size(), '.');
        vector<string> path(arr.size(), str);
        for (int i = 0; i < arr.size(); i++) {
            path[i][arr[i]] = 'Q';
        }
        return path;
    }

    vector<int> arr;
    vector<vector<string>> res;
};
// @lc code=end

