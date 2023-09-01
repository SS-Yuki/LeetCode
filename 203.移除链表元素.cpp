/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */
#include <bits/stdc++.h>
#include <cstdlib>
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
class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummyhead = new ListNode(0, head);
    ListNode *pre = dummyhead;
    while (pre != nullptr && pre->next != nullptr) {
      if (pre->next->val == val) {
        pre->next = pre->next->next;
      } else {
        pre = pre->next;
      }
    }
    return dummyhead->next;
  }
};
// @lc code=end
