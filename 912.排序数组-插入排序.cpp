/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 插入排序
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //[0, i)已排好
        for (int i = 1; i < nums.size(); i++) {
            int tmp = nums[i];
            // (j, i] > tmp
            int j;
            for (j = i; j > 0 && nums[j-1] > tmp; j--) {
                nums[j] = nums[j-1];
            }
            nums[j] = tmp;
        }
        return nums;
    }
};
// @lc code=end

