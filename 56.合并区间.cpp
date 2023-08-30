/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  static bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
  }
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), cmp);
    int begin = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] > intervals[i - 1][1]) {
        res.push_back({begin, end});
        begin = intervals[i][0];
        end = intervals[i][1];
      } else {
        intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
        end = intervals[i][1];
      }
    }
    res.push_back({begin, end});
    return res;
  }
};
// @lc code=end
