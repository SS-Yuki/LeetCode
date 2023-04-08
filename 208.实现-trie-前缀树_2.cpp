/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <bits/stdc++.h>    
using namespace std;

// @lc code=start
class Trie {
public:
    Trie(): isEnd(false) {
        memset(nxt, 0, sizeof(nxt));
    }
    
    void insert(string word) {
        Trie* trie = this;
        for (char c: word) {
            if (!trie->nxt[c-'a']) {
                trie->nxt[c-'a'] = new Trie();
            }
            trie = trie->nxt[c-'a'];
        }
        trie->isEnd = true;
    }
    
    bool search(string word) {
        Trie* trie = this;
        for (char c: word) {
            if (!trie->nxt[c-'a']) {
                return false;
            }
            trie = trie->nxt[c-'a'];
        }
        return trie->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* trie = this;
        for (char c: prefix) {
            if (!trie->nxt[c-'a']) {
                return false;
            }
            trie = trie->nxt[c-'a'];
        }
        return true;
    }

private:
    bool isEnd;
    Trie* nxt[26];
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

