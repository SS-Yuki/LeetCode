/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    //[left, right]
    int partition_(vector<int>& nums, int left, int right) {
        int r = rand() % (right - left + 1) + left;
        swap(nums[left], nums[r]);

        int pivot = nums[left];
        //[left+1, j] <= pivot, (j, i) > pivot
        int j = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] <= pivot) {
                j++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[left], nums[j]);
        return j;
    }

    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        srand((unsigned)time(NULL));
        int left = 0;
        int right = nums.size()-1;
        while (true) {
            int res = partition_(nums, left, right);
            if (res == target) {
                return nums[target];
            }
            else if (res < target) {
                left = res + 1;
            }
            else {
                right = res - 1;
            }
        }  
        return 0;
    }
};
// @lc code=end

