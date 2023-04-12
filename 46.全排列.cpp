/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        vector<bool> is_used(nums.size(), false);
        dfs(0, res, is_used, nums);
        return ans;
    }

    void dfs(int index, vector<int>& res, vector<bool>& is_used, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
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

