/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;

        st.push(0);
        for (int i = 1; i < 2 * nums.size(); i++) {
            int index = i % nums.size();
            if (nums[index] <= nums[st.top()]) {
                st.push(index);
            }
            else {
                while (!st.empty() && nums[index] > nums[st.top()]) {
                    if (res[st.top()] == -1) {
                        res[st.top()] = nums[index];
                    }
                    st.pop();
                }
                st.push(index);
            }
        }

        return res;
    }
};
// @lc code=end

