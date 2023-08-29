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
        path.clear();
        res.clear();
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            cout << num << "\t";
        }
        cout << endl;
        processed.assign(nums.size(), 0);

        backtracking(nums);
        return res;
    }

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size();) {
            if (!processed[i]) {
                processed[i] = 1;
                path.push_back(nums[i]);

                backtracking(nums);

                path.pop_back();
                processed[i] = 0;

                i++;
                while (i < nums.size() && nums[i] == nums[i - 1]) {
                    i++;
                }
            }
            else {
                i++; 
            }
        }
    }

    vector<int> path;
    vector<vector<int>> res;
    vector<int> processed;

};

// @lc code=end

