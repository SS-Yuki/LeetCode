/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct Node {
    unordered_set<string> keys;
    int cnt;
    Node(): keys({}), cnt(1) {}
    Node(string key_, int cnt_): keys({key_}), cnt(cnt_) {}
};


class AllOne {
public:
    AllOne() {}
    
    void inc(string key) {
        //无key
        if (key_map.count(key) == 0) {
            if (node_list.empty() || node_list.begin()->cnt > 1) {
                node_list.push_front(Node());
            }
            node_list.begin()->keys.insert(key);
            key_map[key] = node_list.begin();
            return;
        }
        auto cur = key_map[key];
        auto nxt = next(cur);
        if (nxt == node_list.end() || nxt->cnt > cur->cnt + 1) {
            key_map[key] = node_list.insert(nxt, Node(key, cur->cnt + 1));
        }
        else {
            nxt->keys.insert(key);
            key_map[key] = nxt;
        }
        cur->keys.erase(key);
        if (cur->keys.empty()) {
            node_list.erase(cur);
        }
    }
    
    void dec(string key) {
        auto cur = key_map[key];
        auto pre = prev(cur);
        if (cur->cnt == 1) {
            key_map.erase(key);
            cur->keys.erase(key);
            if (cur->keys.empty()) {
                node_list.erase(cur);
            }
            return;
        }
        if (cur == node_list.begin() || pre->cnt < cur->cnt - 1) {
            key_map[key] = node_list.insert(cur, Node(key, cur->cnt - 1));
        }
        else {
            pre->keys.insert(key);
            key_map[key] = pre;
        }
        cur->keys.erase(key);
        if (cur->keys.empty()) {
            node_list.erase(cur);
        }
    }
    
    string getMaxKey() {
        if (node_list.empty()) {
            return "";
        }
        return *node_list.back().keys.begin();
    }
    
    string getMinKey() {
       if (node_list.empty()) {
            return "";
        }
        return *node_list.front().keys.begin();
    }

private:
    list<Node> node_list;
    unordered_map<string, list<Node>::iterator> key_map;
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end

