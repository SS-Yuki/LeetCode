/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyStack {
public:
    MyStack(): index(0) {}
    
    void push(int x) {
        q[index].push(x);
    }
    
    int pop() {
        while (q[index].size() > 1) {
            q[1-index].push(q[index].front());
            q[index].pop();
        }
        int x = q[index].front();
        q[index].pop();
        index = 1 - index;
        return x;
    }
    
    int top() {
        return q[index].back();
    }
    
    bool empty() {
        return q[index].empty();
    }

private:
    queue<int> q[2];
    int index;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

