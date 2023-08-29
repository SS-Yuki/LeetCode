/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();

        backtracking(nums, 0);

        return res;
    }

    void backtracking(vector<int>& nums, int k) {
        if (k == nums.size()) {
            res.push_back(path);
            return;
        }

        path.push_back(nums[k]);
        backtracking(nums, k + 1);
        path.pop_back();
        
        backtracking(nums, k + 1);
    }

    vector<int> path;
    vector<vector<int>> res;
};
// @lc code=end

