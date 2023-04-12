/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 快速排序
 * 随机数：解决顺序数组退化问题
 * 双/三路排序：解决数组中元素重复次数多
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int position = partition(nums, left, right);
        quickSort(nums, left, position-1);
        quickSort(nums, position+1, right);
    }

    // int partition(vector<int>& nums, int left, int right) {
    //     int rand_ = rand() % (right - left + 1) + left;
    //     swap(nums[left], nums[rand_]);

    //     int pivot = nums[left];
    //     //[left+1, j] [j+1, i)
    //     int j = left;
    //     for (int i = left + 1; i <= right; i++) {
    //         if (nums[i] <= pivot) {
    //             j++;
    //             swap(nums[j], nums[i]);
    //         }
    //     }
    //     swap(nums[j], nums[left]);
    //     return j;
    // }

    //双路快排
    int partition(vector<int>& nums, int left, int right) {
        int rand_ = rand() % (right - left + 1) + left;
        swap(nums[left], nums[rand_]);

        int pivot = nums[left];
        //[left+1, i) (j, right]
        int i = left + 1;
        int j = right;
        while (true) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }
            while (i <= j && nums[j] > pivot) {
                j--;
            }

            if (i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        swap(nums[j], nums[left]);
        return j;
    }
};
// @lc code=end

