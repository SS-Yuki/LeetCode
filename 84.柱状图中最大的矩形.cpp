/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;

        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), heights.size());

        st.push(0);
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] >= heights[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    right[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }

        while (!st.empty()) {
            st.pop();
        }

        st.push(heights.size() - 1);
        for (int i = heights.size() - 2; i >= 0; i--) {
            if (heights[i] >= heights[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    left[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }

        int max = 0;

        for (int i = 0; i < heights.size(); i++) {
            int size = heights[i] * (right[i] - left[i] - 1);
            if (size > max) {
                max = size;
            }
        }

        return max;
    }
};
// @lc code=end

