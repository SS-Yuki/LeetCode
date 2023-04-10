/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        //[0,j]符合条件
        int j = 1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[j-1]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};
// @lc code=end

