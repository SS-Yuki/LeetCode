/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 冒泡排序
 * 若其中一轮无交换，则已排好序
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; i++) {
            bool flag = true;
            for (int j = 0; j < nums.size()-1-i; j++) {
                if (nums[j] > nums[j+1]) {
                    flag = false;
                    swap(nums[j], nums[j+1]);
                }
            }
            if (flag) {
                return nums;
            }
        }
        return nums;
    }
};
// @lc code=end

