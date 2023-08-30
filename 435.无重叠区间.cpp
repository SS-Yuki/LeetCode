/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define MIN(a, b) (a) < (b) ? (a) : (b)
static bool cmp(const vector<int> &a, const vector<int> &b) {
  return a[0] < b[0];
}

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    if (intervals.size() == 0) {
      return 0;
    }
    int num = 0;
    sort(intervals.begin(), intervals.end(), cmp);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < intervals[i - 1][1]) {
        num++;
        intervals[i][1] = MIN(intervals[i - 1][1], intervals[i][1]);
      }
    }
    return num;
  }
};
// @lc code=end
