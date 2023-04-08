/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <bits/stdc++.h>    
using namespace std;

// @lc code=start
struct MyTreeNode {
    string val;
    MyTreeNode *left;
    MyTreeNode *right;
    MyTreeNode() : val(""), left(nullptr), right(nullptr) {}
    MyTreeNode(string x) : val(x), left(nullptr), right(nullptr) {}
    MyTreeNode(string x, MyTreeNode *left, MyTreeNode *right) : val(x), left(left), right(right) {}
};

class Trie {
public:
    Trie(): root(nullptr) {

    }
    
    void insert(string word) {
        if (!root) {
            root = new MyTreeNode(word);
            return;
        }
        MyTreeNode* p = root;
        int flag = -1;
        MyTreeNode* parent;
        while (p) {
            parent = p;
            if (word < p->val) {
                p = p->left;
                flag = 0;
            }
            else if (word > p->val) {
                p = p->right;
                flag = 1;
            }
            else {
                return;
            }
        }
        p = new MyTreeNode(word);
        if (flag == 0) {
            parent->left = p;
        }
        else if (flag == 1) {
            parent->right = p;
        }
    }
    
    bool search(string word) {
        MyTreeNode* p = root;
        while (p) {
            if (word < p->val) {
                p = p->left;
            }
            else if (word > p->val) {
                p = p->right;
            }
            else {
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        MyTreeNode* p = root;
        while (p) {
            auto res = mismatch(prefix.begin(), prefix.end(), p->val.begin());
            if (res.first == prefix.end()) {
                return true;
            }
            else if (prefix < p->val) {
                p = p->left;
            }
            else if (prefix > p->val) {
                p = p->right;
            }
        }
        return false;
    }

private:
    MyTreeNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

