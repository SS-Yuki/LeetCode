/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //[0,j]保证没有val的
        int j = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};
// @lc code=end

