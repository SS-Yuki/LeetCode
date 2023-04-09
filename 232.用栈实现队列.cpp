/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        s[0].push(x);
    }
    
    int pop() {
        if (s[1].empty()) {
            while (!s[0].empty()) {
                int x = s[0].top();
                s[1].push(x);
                s[0].pop();
            }    
        }
        int x = s[1].top();
        s[1].pop();
        return x;
    }
    
    int peek() {
        if (s[1].empty()) {
            while (!s[0].empty()) {
                int x = s[0].top();
                s[1].push(x);
                s[0].pop();
            }    
        }
        int x = s[1].top();
        return x;
    }
    
    bool empty() {
        return s[0].empty() && s[1].empty();
    }

private:
    stack<int> s[2];
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

