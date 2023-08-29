/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sum = 0;

        sort(candidates.begin(), candidates.end());
        // candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        for (auto num : candidates) {
            cout << num << endl;
        }

        backtracking(0, candidates, target);

        return res;
    }

    void backtracking(int st, vector<int>& candidates, int target) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = st; i < candidates.size(); ) {
            if (sum + candidates[i] > target) {
                break;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(i + 1, candidates, target);

            sum -= candidates[i];
            path.pop_back();

            // 同层去重
            i++;
            while (i < candidates.size() && candidates[i] == candidates[i - 1]) {
                i++;
            }
        }
    }

    vector<vector<int>> res;
    vector<int> path;
    int sum;
    // unordered_set<int> set;
};


// @lc code=end

int main() {
    Solution s;
    vector<int> v = {10,1,2,7,6,1,5};
    vector<vector<int>> res = s.combinationSum2(v, 8);
    cout << "------" << endl;
    for (auto vv : res) {
        for (auto num : vv) {
            cout << num << "\t";
        }
        cout << endl;
    }
    return 0;
}

