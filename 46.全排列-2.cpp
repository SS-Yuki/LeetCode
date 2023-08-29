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
        path.clear();
        res.clear();
        processed.assign(nums.size(), 0);

        backtracking(nums);

        return res;
    }

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!processed[i]) {
                processed[i] = 1;
                path.push_back(nums[i]);

                backtracking(nums);

                path.pop_back();
                processed[i] = 0;
            }
        }
    }

    vector<int> path;
    vector<vector<int>> res;
    vector<int> processed;
};
// @lc code=end

