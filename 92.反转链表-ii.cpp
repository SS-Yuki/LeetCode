/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *pre = nullptr;
    ListNode *process_end = nullptr;

    ListNode *process_pre = nullptr;
    ListNode *process_cur = head;

    int count_1 = left;
    while (count_1) {
      pre = process_pre;
      process_pre = process_cur;
      process_cur = process_cur->next;
      count_1--;
    }

    process_end = process_pre;

    int count_2 = right - left;
    while (count_2) {
      ListNode *tmp = process_cur->next;
      process_cur->next = process_pre;
      process_pre = process_cur;
      process_cur = tmp;
      count_2--;
    }

    if (pre != nullptr) {
      pre->next = process_pre;
    }
    process_end->next = process_cur;

    if (pre == nullptr) {
      return process_pre;
    }
    return head;
  }
};
// @lc code=end
