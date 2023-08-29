/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sum = 0;

        sort(candidates.begin(), candidates.end());

        backtracking(0, candidates, target);

        return res;
    }

    void backtracking(int st, vector<int>& candidates, int target) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = st; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) {
                break;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(i, candidates, target);

            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> res;
    vector<int> path;
    int sum;
};
// @lc code=end

