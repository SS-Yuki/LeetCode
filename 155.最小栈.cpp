/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if (min_stack.size() == 0 || val <= min_stack[min_stack.size()-1]) {
            min_stack.emplace_back(val);
        }
        stack.emplace_back(val);
    }
    
    void pop() {
        if (min_stack[min_stack.size()-1] == stack[stack.size()-1]) {
            min_stack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return min_stack[min_stack.size()-1];
    }

private:
    vector<int> stack;
    vector<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

