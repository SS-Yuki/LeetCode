/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //[0,j]!=0, (j,i)=0
        int j = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                j++;
                nums[j] = nums[i];
            }
        }
        for (int k = j + 1; k < nums.size(); k++) {
            nums[k] = 0;
        }
    }
};
// @lc code=end

