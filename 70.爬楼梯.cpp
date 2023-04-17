/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        int dp1 = 1;
        int dp2 = 2;
        int tmp;
        for (int i = 3; i <= n; i++) {
            tmp = dp2;
            dp2 = dp1 + dp2;
            dp1 = tmp;
        }
        return dp2;
    }
};
// @lc code=end
