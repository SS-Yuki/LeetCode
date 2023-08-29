/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();

        backtracking(nums, 0);

        return res;
    }

    void backtracking(vector<int>& nums, int st) {
        if (path.size() >= 2) {
            res.push_back(path);
        }

        if (st >= nums.size()) {
            return;
        }

        unordered_set<int> set;
        for (int i = st; i < nums.size(); i++) {
            if (set.count(nums[i]) > 0) {
                continue;
            }
            set.insert(nums[i]);
            if (path.empty() || (!path.empty() && path.back() <= nums[i])) {
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
            }
            else {
                continue;
            }
        }
    }

    vector<int> path;
    vector<vector<int>> res;

};
// @lc code=end

