/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int dollar_5 = 0, dollar_10 = 0, dollar_20 = 0;
    for (int i = 0; i < bills.size(); i++) {
      if (bills[i] == 5) {
        dollar_5++;
      }
      if (bills[i] == 10) {
        if (dollar_5 == 0) {
          return false;
        }
        dollar_5--;
        dollar_10++;
      }
      if (bills[i] == 20) {
        if (dollar_10 > 0 && dollar_5 > 0) {
          dollar_10--;
          dollar_5--;
          dollar_20++;
        } else if (dollar_5 >= 3) {
          dollar_5 -= 3;
          dollar_20++;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
