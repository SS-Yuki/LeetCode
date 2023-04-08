/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
//双向链表节点
class Node {
public:
    Node(): key(0), value(0), pre(nullptr), nxt(nullptr) {}
    Node(int key_, int value_): key(key_), value(value_), pre(nullptr), nxt(nullptr) {}

    int key;
    int value;
    Node* pre;
    Node* nxt;
};

class LRUCache {
public:
    LRUCache(int capacity_): capacity(capacity_), size(0) {
        head = new Node();
        tail = new Node();
        head->nxt = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        else {
            Node* node = cache[key];

            //根据使用时间更新
            remove(node);
            addToHead(node);

            return node->value;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            //添加进哈希表
            Node* node = new Node(key, value);
            cache[key] = node;

            //添加进双向链表
            //根据使用时间更新
            addToHead(node);

            size++;

            if (size > capacity) {
                Node* node = tail->pre;

                //从哈希表中删除
                cache.erase(node->key);

                //从链表中删除
                remove(node);
                delete node;

                size--;
            }
        }
        else {
            Node* node = cache[key];
            node->value = value;

            //根据使用时间更新
            remove(node);
            addToHead(node);
        }
    }

    void addToHead(Node* node) {
        node->pre = head;
        node->nxt = head->nxt;
        head->nxt->pre = node;
        head->nxt = node;
    }

    void remove(Node* node) {
        node->pre->nxt = node->nxt;
        node->nxt->pre = node->pre;
    }

private:
    Node* head;
    Node* tail;
    int size;
    int capacity;
    unordered_map<int, Node*> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

