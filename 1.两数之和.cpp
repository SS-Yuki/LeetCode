/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) == m.end()) {
                m[nums[i]] = i;
            }
            else {
                res.push_back(m[target - nums[i]]);
                res.push_back(i);
            }
        } 
        return res;
    }
};
// @lc code=end

