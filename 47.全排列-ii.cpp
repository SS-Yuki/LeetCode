/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> res;
        vector<bool> is_used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(0, res, is_used, nums);
        return ans;
    }

    void dfs(int index, vector<int>& res, vector<bool>& is_used, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && !is_used[i-1]) {
                continue;
            }
            if (!is_used[i]) {
                res.push_back(nums[i]);
                is_used[i] = true;
                dfs(index+1, res, is_used, nums);
                res.pop_back();
                is_used[i] = false;
            }
        }
    }

private:
    vector<vector<int>> ans;
};
// @lc code=end

