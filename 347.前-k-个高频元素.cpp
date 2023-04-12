/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
typedef pair<int, int> Node;
auto cmp = [](Node a, Node b) {return a.second > b.second;};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (auto num: nums) {
            if (key_table.count(num) == 0) {
                key_table[num] = 1;
                continue;
            }
            key_table[num]++;
        }
        priority_queue<Node, vector<Node>, decltype(cmp)> heap_(cmp);
        for (auto& it: key_table) {
            heap_.push(it);
            if (heap_.size() > k) {
                heap_.pop();
            }
        }
        vector<int> ans(k, 0);
        for (int i = k-1; i >= 0; i--) {
            ans[i] = heap_.top().first;
            heap_.pop();
        }
        return ans;
    }
private:
    unordered_map<int, int> key_table;
};
// @lc code=end

