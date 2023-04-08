/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-3; i++) {
            long sum_3 = target - nums[i];

            for (int j = i + 1; j < nums.size()-2; j++) {
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    
                    if (nums[left] + nums[right] == sum_3 - nums[j]) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left<right && nums[left] == nums[left-1]) {
                            left++;
                        }
                        while (left<right && nums[right] == nums[right+1]) {
                            right--;
                        }
                    }
                    else if (nums[left] + nums[right] > sum_3 - nums[j]) {
                        right--;
                    }
                    else {
                        left++;
                    }
                    
                }
                while(j+1<nums.size()-2 && nums[j+1]==nums[j]) {
                    j++;
                }
            }

            while(i+1<nums.size()-3 && nums[i+1]==nums[i]) {
                i++;
            }

        }

        return ans;
    }
};
// @lc code=end

