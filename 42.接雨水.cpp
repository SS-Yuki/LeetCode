/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;

        vector<int> left(height.size(), -1);
        vector<int> right(height.size(), -1);

        stack<int> st;

        st.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] <= height[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int index = st.top();
                    right[index] = i;
                    st.pop();
                    if (!st.empty()) {
                        left[index] = st.top();
                    }
                }
                st.push(i);
            }
        }

        for (int i = 0; i < height.size(); i++) {
            if (left[i] == -1 || right[i] == -1) {
                continue;
            }
            int h = min(height[left[i]], height[right[i]]) - height[i];
            sum += h * (right[i] - left[i] -1);
        }

        return sum;
    }

    int min(int x, int y) {
        return (x < y ? x : y);
    }
};


// @lc code=end

int main() {
    Solution s;
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(h);
    
}

