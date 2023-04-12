/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 归并排序
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1, tmp);
        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if (left == right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid, tmp);
        mergeSort(nums, mid + 1, right, tmp);
        merge(nums, left, right, mid, tmp);
    }

    void merge(vector<int>& nums, int left, int right, int mid, vector<int>& tmp) {
        for (int i = left; i <= right; i++) {
            tmp[i] = nums[i];
        }
        //[left, i), [mid+1, j), [left, k)
        int i = left;
        int j = mid + 1;
        int k = left;
        while (k <= right) {
            if (i > mid) {
                nums[k] = tmp[j];
                j++;
            }
            else if (j > right) {
                nums[k] = tmp[i];
                i++;
            }
            else if (tmp[i] <= tmp[j]) {
                nums[k] = tmp[i];
                i++;
            }
            else {
                nums[k] = tmp[j];
                j++;
            }
            k++;
        }
    }
};
// @lc code=end

