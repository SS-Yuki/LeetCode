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
  int max(int a, int b) { return a > b ? a : b; }
  int candy(vector<int> &ratings) {
    int sum = 0;
    vector<int> candy(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++) {
      if (ratings[i] > ratings[i - 1]) {
        candy[i] = candy[i - 1] + 1;
      }
    }
    for (int i = ratings.size() - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        candy[i] = max(candy[i], candy[i + 1] + 1);
      }
    }
    for (int i = 0; i < candy.size(); i++) {
      sum += candy[i];
    }
    return sum;
  }
};
// @lc code=end
