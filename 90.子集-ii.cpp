/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();

        sort(nums.begin(), nums.end());

        backtracking(nums, 0);

        return res;
    }

    void backtracking(vector<int>& nums, int st) {
        for (auto x : path) {
            cout << x << "\t";
        }
        cout << endl;
        
        res.push_back(path);

        if (st >= nums.size()) {
            return;
        }

        for (int i = st; i < nums.size(); ) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();

            i++;
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
        }
    }

    vector<int> path;
    vector<vector<int>> res;
};

// @lc code=end

