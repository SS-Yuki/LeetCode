/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool find = false;
        for (auto word: wordList) {
            words.insert(word);
            if (word == endWord) {
                find = true;
            }
        }
        if (!find) {
            return 0;
        }
        int len = beginWord.size();
        q.push(beginWord);
        ans[beginWord] = 1;
        while (q.size()>0) {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < len; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == cur[i]) {
                        continue;
                    }
                    string str = cur;
                    str[i] = c;
                    if (words.count(str) > 0 && ans.count(str) == 0) {
                        if (str == endWord) {
                            return ans[cur] + 1;
                        }
                        ans[str] = ans[cur] + 1;
                        q.push(str);
                    }
                }
            }
            
        }
        return ans[endWord];
    }
private:
    unordered_map<string, unordered_set<string>> edge;
    queue<string> q;
    unordered_set<string> words;
    unordered_map<string, int> ans;
};
// @lc code=end

