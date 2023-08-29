/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;   
        st.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    int index = st.top();
                    st.pop();
                    res[index] = i - index;
                }
                st.push(i);
            }
        }

        return res;
    }
};
// @lc code=end

