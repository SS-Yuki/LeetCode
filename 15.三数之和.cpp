/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        int left;
        int right;

        if (nums.size() < 3) {
            return res;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-2; i++) {
            left = i + 1;
            right = nums.size() - 1;
            if(nums[i] > 0)break;
            while (left < right) {
                
                if (nums[left] + nums[right] == -nums[i]) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left<right && nums[left] == nums[left-1]) {
                        left++;
                    }
                    while (left<right && nums[right] == nums[right+1]) {
                        right--;
                    }
                }
                else if (nums[left] + nums[right] > -nums[i]) {
                    right--;
                }
                else {
                    left++;
                }
                
            }
            while(i+1<nums.size()-2 && nums[i+1]==nums[i]) {
                i++;
            }
        }

        return res;

    }
};
// @lc code=end

