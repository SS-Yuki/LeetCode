/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> res;
    unordered_map<char, int> map;
    int pos = INT_MIN;
    int last;
    for (int i = 0; i < s.size(); i++) {
      map[s[i]] = i;
    }
    for (int i = 0; i < s.size(); i++) {
      if (map[s[i]] > pos) {
        pos = map[s[i]];
      }
      if (i == pos) {
        if (res.empty()) {
          res.push_back(i + 1);
          last = i;
        } else {
          res.push_back(i - last);
          last = i;
        }
      }
    }
    return res;
  }
};
// @lc code=end
