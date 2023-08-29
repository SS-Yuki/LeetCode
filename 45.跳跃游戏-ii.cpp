/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int top = 0;
        int step = 0;
        int max = INT_MIN;
        if (nums.size() == 1) {
            return 0;
        }
        for (int i = 0; i <= top; i++) {
            // 本步能覆盖的最大值
            if (max < i + nums[i]) {
                max = i + nums[i];
            }
            if (max >= nums.size() - 1) {
                return step + 1;
            }
            // 查看下一步能覆盖的最大范围
            if (i == top) {
                step++;
                top = max;
            }
        }
        return step;
    }
};
// @lc code=end

