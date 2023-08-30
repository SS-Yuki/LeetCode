/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  int candy(vector<int> &ratings) {
    int len = ratings.size();
    vector<int> left(len, 0);
    vector<int> right(len, 0);
    int sum = 0;
    for (int i = 0; i < len; i++) {
      if (i > 0 && ratings[i] > ratings[i - 1]) {
        left[i] = left[i - 1] + 1;
      } else {
        left[i] = 1;
      }
    }
    for (int i = len - 1; i >= 0; i--) {
      if (i < len - 1 && ratings[i] > ratings[i + 1]) {
        right[i] = right[i + 1] + 1;
      } else {
        right[i] = 1;
      }
      sum += max(left[i], right[i]);
    }
    return sum;
  }
};
// @lc code=end
