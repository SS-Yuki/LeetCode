/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }

    bool backtracking(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if (backtracking(board)) {
                                return true;
                            }

                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int x, int y, char c) {
        for (int j = 0; j < board.size(); j++) {
            if (board[x][j] == c) {
                return false;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            if (board[i][y] == c) {
                return false;
            }
        }
        int x_st = ((x / 3) * 3);
        int y_st = ((y / 3) * 3);
        for (int i = x_st; i < x_st + 3; i++) {
            for (int j = y_st; j < y_st + 3; j++) {
                if (board[i][j] == c) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

