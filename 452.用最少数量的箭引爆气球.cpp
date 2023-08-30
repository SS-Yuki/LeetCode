/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
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
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.size() == 0) {
      return 0;
    }
    int num = 1;
    sort(points.begin(), points.end(), cmp);
    int edge = points[0][1];
    for (int i = 1; i < points.size(); i++) {
      if (points[i][0] <= edge) {
        edge = MIN(edge, points[i][1]);
      } else {
        num++;
        edge = points[i][1];
      }
    }
    return num;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> points = {{7, 15}, {6, 14}, {8, 12}, {3, 4}, {4, 13},
                                {6, 14}, {9, 11}, {6, 12}, {4, 13}};
  s.findMinArrowShots(points);
}
