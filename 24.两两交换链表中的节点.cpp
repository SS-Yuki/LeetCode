/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 每个循环三步转化
// 虚拟头结点保证操作统一
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummyhead = new ListNode(-1, head);
    ListNode *cur = dummyhead;
    while (cur->next != nullptr && cur->next->next != nullptr) {
      ListNode *tmp = cur->next->next;
      cur->next->next = cur->next->next->next;
      tmp->next = cur->next;
      cur->next = tmp;
      cur = cur->next->next;
    }
    return dummyhead->next;
  }
};
// @lc code=end
