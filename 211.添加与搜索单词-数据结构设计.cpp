/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class WordDictionary {
public:
    WordDictionary(): isEnd(false) {
        memset(nxt, 0, sizeof(nxt));
    }
    
    void addWord(string word) {
        WordDictionary* cur = this;
        for (char c: word) {
            if (!cur->nxt[c-'a']) {
                cur->nxt[c-'a'] = new WordDictionary();
            }
            cur = cur->nxt[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return findPart(word, 0, this);
    }

    bool findPart(string word, int index, WordDictionary* root) {
        if (!root) {
            return false;
        }
        if (index == word.size()) {
            return root->isEnd;
        }
        char c = word[index];
        if (word[index] != '.') {
            return findPart(word, index+1, root->nxt[c-'a']);
        }
        else {
            for (WordDictionary* child: root->nxt) {
                if (findPart(word, index+1, child)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool isEnd;
    WordDictionary* nxt[26];
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

