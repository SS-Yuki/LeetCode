/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 选择排序
 * 交换次数少
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // [0, i)已排好序
        //每轮选择最小值
        for (int i = 0; i < nums.size()-1; i++) {
            int min_ = i;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] < nums[min_]) {
                    min_ = j;
                }
            }
            swap(nums[i], nums[min_]);
        }
        return nums;
    }
};
// @lc code=end

