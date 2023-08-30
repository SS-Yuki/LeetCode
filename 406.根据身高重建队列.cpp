/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
bool cmp(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] > b[0];
}
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> queue;
    for (int i = 0; i < people.size(); i++) {
      int pos = people[i][1];
      queue.insert(queue.begin() + pos, people[i]);
    }
    return queue;
  }
};
// @lc code=end
