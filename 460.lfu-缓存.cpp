/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct Node {
    int key;
    int value;
    int freq;
    Node* pre;
    Node* nxt;

    Node(): key(0), value(0), freq(1), pre(nullptr), nxt(nullptr) {}
    Node(int key_, int value_): key(key_), value(value_), freq(1), pre(nullptr), nxt(nullptr) {}
};

class MyList {
public:
    MyList(): size(0) {
        head = new Node();
        tail = new Node();
        head->nxt = tail;
        tail->pre = head;
    }
    ~MyList() {
        delete head;
        delete tail;
    }
    void addToHead(Node* node) {
        node->pre = head;
        node->nxt = head->nxt;
        head->nxt->pre = node;
        head->nxt = node;
        size++;
    }
    void remove(Node* node) {
        node->pre->nxt = node->nxt;
        node->nxt->pre = node->pre;
        size--;
    }
    Node* removeTail() {
        Node* node = tail->pre;
        remove(node);
        return node;
    }
    int size;
    
private:
    Node* head;
    Node* tail;
    
};

class LFUCache {
public:
    LFUCache(int capacity_): capacity(capacity_), size(0), min_freq(0) {}
    
    int get(int key) {
        //-----查找-----
        if (key_map.find(key) == key_map.end()) {
            return -1;
        }
        Node* node = key_map[key];

        //频率哈希的改变：freq，freq+1
        int freq = node->freq;
        freq_map[freq]->remove(node);
        int now_size = freq_map[freq]->size;
        if (now_size == 0) {
            MyList* list_ = freq_map[freq];
            freq_map.erase(freq);
            delete list_;
        }
        if (freq_map.find(freq+1) == freq_map.end()) {
            freq_map[freq+1] = new MyList();
        }
        freq_map[freq+1]->addToHead(node);

        if (min_freq == freq && now_size == 0) {
            min_freq++;
        }

        node->freq++;
        return node->value;
    }
    
    void put(int key, int value) {
        if (key_map.find(key) != key_map.end()) {
            //-----更新-----
            Node* node = key_map[key];
            //频率哈希的改变：freq，freq+1
            int freq = node->freq;
            freq_map[freq]->remove(node);
            int now_size = freq_map[freq]->size;
            if (now_size == 0) {
                MyList* list_ = freq_map[freq];
                freq_map.erase(freq);
                delete list_;
            }
            if (freq_map.find(freq+1) == freq_map.end()) {
                freq_map[freq+1] = new MyList();
            }
            freq_map[freq+1]->addToHead(node);

            if (min_freq == freq && now_size == 0) {
                min_freq++;
            }

            node->freq++;
            node->value = value;

            return;
        }
        
        //-----插入-----
        Node* node = new Node(key, value);
        key_map[key] = node;
        
        if (freq_map.find(1) == freq_map.end()) {
            freq_map[1] = new MyList();
        }
        freq_map[1]->addToHead(node);

        size++;

        //-----删除-----
        if (size > capacity) {
            //频率哈希删除
            Node* node = freq_map[min_freq]->removeTail();
            if (freq_map[min_freq]->size == 0) {
                MyList* list_ = freq_map[min_freq];
                freq_map.erase(min_freq);
                delete list_;
            }
            //key哈希删除
            key_map.erase(node->key);
            delete node;
            size--;
        }

        min_freq = 1;
        return;
    }

private:
    unordered_map<int, Node*> key_map;
    unordered_map<int, MyList*> freq_map;
    int min_freq;
    int capacity;
    int size;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

