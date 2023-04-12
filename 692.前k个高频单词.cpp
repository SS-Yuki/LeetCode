/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
typedef pair<string, int> Node;
auto cmp = [](Node a, Node b) {return a.second == b.second ? a.first < b.first : a.second > b.second;};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto word: words) {
            if (key_table.count(word) == 0) {
                key_table[word] = 1;
                continue;
            }
            key_table[word]++;
        }
        priority_queue<Node, vector<Node>, decltype(cmp)> heap_(cmp);
        for (auto& it: key_table) {
            heap_.push(it);
            if (heap_.size() > k) {
                heap_.pop();
            }
        }
        vector<string> ans(k, "");
        for (int i = k-1; i >= 0; i--) {
            ans[i] = heap_.top().first;
            heap_.pop();
        }
        return ans;
    }

private:
    unordered_map<string, int> key_table;
};
// @lc code=end

