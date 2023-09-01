/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && slow != nullptr) {
      slow = slow->next;
      fast = fast->next;
      if (fast == nullptr) {
        return nullptr;
      }
      fast = fast->next;

      if (fast == slow) {
        ListNode *st = head;
        ListNode *st_2 = fast;
        while (st != st_2) {
          st = st->next;
          st_2 = st_2->next;
        }
        return st;
      }
    }
    return nullptr;
  }
};
// @lc code=end
