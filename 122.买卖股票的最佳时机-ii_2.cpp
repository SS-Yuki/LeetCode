/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int num;
        for (int i = 1; i < prices.size(); i++) {
            num = prices[i] - prices[i-1];
            if (num > 0) {
                res += num;
            }
        }
        return res;
    }
};
// @lc code=end
