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
        vector<string> res(n, string(n, '.'));
        dfs(0, n, res);
        return ans;
    }

    void dfs(int row, int n, vector<string>& res) {
        if (row == n) {
            ans.push_back(res);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, n, res)) {
                res[row][col] = 'Q';
                dfs(row+1, n, res);
                res[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, int n, vector<string>& res) {
        for (int i = 0; i < row; i++) {
            if (res[i][col] == 'Q') {
                return false;
            }
        }
        for (int i=row, j=col; i>=0&&j>=0; i--, j--) {
            if (res[i][j] == 'Q') {
                return false;
            }
        }
        for (int i=row, j=col; i>=0&&j<n; i--, j++) {
            if (res[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<string>> ans; 
};
// @lc code=end

