/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct MyListNode {
  int val;
  MyListNode *pre;
  MyListNode *nxt;
  MyListNode() : val(-1), pre(nullptr), nxt(nullptr) {}
  MyListNode(int val_) : val(val_), pre(nullptr), nxt(nullptr) {}
  MyListNode(int val_, MyListNode *pre_, MyListNode *nxt_)
      : val(val_), pre(pre_), nxt(nxt_) {}
};

class MyLinkedList {
public:
  MyLinkedList() {
    head = new MyListNode();
    tail = new MyListNode();
    head->nxt = tail;
    tail->pre = head;
    num = 0;
  }

  int get(int index) {
    if (index >= num) {
      return -1;
    }
    MyListNode *res = head->nxt;
    while (index > 0) {
      res = res->nxt;
      index--;
    }
    return res->val;
  }

  void addAtHead(int val) {
    MyListNode *node = new MyListNode(val, head, head->nxt);
    head->nxt->pre = node;
    head->nxt = node;
    num++;
  }

  void addAtTail(int val) {
    MyListNode *node = new MyListNode(val, tail->pre, tail);
    tail->pre->nxt = node;
    tail->pre = node;
    num++;
  }

  void addAtIndex(int index, int val) {
    if (index > num) {
      return;
    }
    MyListNode *pos_nxt = head->nxt;
    while (index > 0) {
      pos_nxt = pos_nxt->nxt;
      index--;
    }
    MyListNode *pos_pre = pos_nxt->pre;
    MyListNode *node = new MyListNode(val, pos_pre, pos_nxt);
    pos_pre->nxt = node;
    pos_nxt->pre = node;
    num++;
  }

  void deleteAtIndex(int index) {
    if (index >= num) {
      return;
    }
    MyListNode *node = head->nxt;
    while (index > 0) {
      node = node->nxt;
      index--;
    }
    MyListNode *pos_pre = node->pre;
    MyListNode *pos_nxt = node->nxt;
    pos_pre->nxt = pos_nxt;
    pos_nxt->pre = pos_pre;
    delete node;
    num--;
  }

private:
  MyListNode *head;
  MyListNode *tail;
  int num;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
