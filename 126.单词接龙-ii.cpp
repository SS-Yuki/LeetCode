/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        bool find = false;
        for (auto word : wordList) {
            words.insert(word);
            if (word == endWord) {
                find = true;
            }
        }
        if (!find) {
            return ans;
        }
        vector<string> path;
        path.push_back(beginWord);
        search(beginWord, path, returnLen(beginWord, endWord, wordList), endWord);
        return ans;
    }

    int returnLen(string beginWord, string endWord, vector<string> &wordList) {
        int len = beginWord.size();
        q.push(beginWord);
        length[beginWord] = 1;
        while (q.size() > 0) {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < len; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == cur[i]) {
                        continue;
                    }
                    string str = cur;
                    str[i] = c;
                    if (words.count(str) > 0 && length.count(str) == 0) {
                        if (str == endWord) {
                            return length[cur] + 1;
                        }
                        length[str] = length[cur] + 1;
                        q.push(str);
                    }
                }
            }
        }
        return length[endWord];
    }

    void search(string root, vector<string> &path, int n, string target) {
        if (path.size() == n) {
            if (path.back() == target) {
                ans.push_back(path);
            }
            return;
        }
        for (int i = 0; i < root.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == root[i]) {
                    continue;
                }
                string str = root;
                str[i] = c;
                if (words.count(str) > 0 && searched.count(str) == 0) {
                    path.push_back(str);
                    searched.insert(str);
                    search(str, path, n, target);
                    path.pop_back();
                    searched.erase(str);
                }
            }
        }
    }

private:
    unordered_map<string, unordered_set<string>> edge;
    queue<string> q;
    unordered_set<string> words;
    unordered_map<string, int> length;
    vector<vector<string>> ans;
    unordered_set<string> searched;
};
// @lc code=end
