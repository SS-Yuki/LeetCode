/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    //nums1:[0,1,2...i-1],[i,i+1,i+2...m-1] i,n-i
    //nums2:[0,1,2...j-1],[j,j+1,j+2...n-1] j,n-j
    //i+j=(m+n+1)/2-1
    //0<=i<=m,0<=j<=n
    //m<=n,保证遍历i时，求得j在[0,n]

    //nums1[i-1]<=nums2[j]
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        double res = 0;

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        int left_max = 0;
        int right_min = 0;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            int nums1_i_1 = (i-1<0) ? INT_MIN : nums1[i-1];
            int nums1_i = (i==m) ? INT_MAX : nums1[i];
            int nums2_j_1 = (j-1<0) ? INT_MIN : nums2[j-1];
            int nums2_j = (j==n) ? INT_MAX : nums2[j];

            if (nums1_i_1 <= nums2_j) {
                left_max = max(nums1_i_1, nums2_j_1);
                right_min = min(nums1_i, nums2_j);

                left = i + 1;
            }
            else {
                right = i - 1;
            }
        }

        if ((m+n)%2==0) {
            res = (left_max + right_min) / 2.0;
        }
        else {
            res = left_max;
        }

        return res;
    }
};
// @lc code=end

