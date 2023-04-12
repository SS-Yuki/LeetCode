/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 堆排序
 * parent: (i-1)/2
 * left: i*2+1
 * right: i*2+2
 * 
 * heapify：维护堆的性质，下沉
 * 建堆：自底向上维护堆
 * 堆排序：交换最大根，重新维护堆
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

    //维护堆
    void heapify(vector<int>& nums, int n, int index) {
        int largest = index;
        int left = index*2 + 1;
        int right = index*2 + 2;
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(nums[largest], nums[index]);
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums) {
        //建堆
        for (int i = nums.size()/2-1; i >= 0; i--) {
            heapify(nums, nums.size(), i);
        }

        //排序
        for (int i = nums.size()-1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
};
// @lc code=end

