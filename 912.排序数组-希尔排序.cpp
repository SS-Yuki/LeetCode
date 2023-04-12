/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 希尔排序
 * 多组小规模的插入排序
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int delta = nums.size()/2; delta > 0; delta/=2) {
            for (int start = 0; start < delta; start++) {
                //分组插入排序，共delta组
                for (int i = start + delta; i < nums.size(); i+=delta) {
                    int tmp = nums[i];
                    int j;
                    for (j = i; j - delta >= 0 && nums[j-delta] > tmp; j-=delta) {
                        nums[j] = nums[j-delta];
                    }
                    nums[j] = tmp;
                }
            }
        }
        return nums;
    }
};
// @lc code=end