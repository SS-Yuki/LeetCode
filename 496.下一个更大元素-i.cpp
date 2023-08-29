/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res(nums1.size(), -1);
        stack<int> st;

        st.push(nums2[0]);
        for (int i = 1; i < nums2.size(); i++) {
            if (nums2[i] <= st.top()) {
                st.push(nums2[i]);
            }
            else {
                while (!st.empty() && nums2[i] > st.top()) {
                    map[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (map.count(nums1[i]) > 0) {
                res[i] = map[nums1[i]];
            }
        }

        return res;
    }
};
// @lc code=end

