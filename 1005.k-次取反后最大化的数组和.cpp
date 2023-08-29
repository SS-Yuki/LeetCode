/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
bool cmp(int x, int y) {
    return abs(x) > abs(y);
}
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
            if (i == nums.size() - 1 && k % 2 == 1) {
                nums[i] = -nums[i];
            }
            sum += nums[i];
        }
        return sum;
    }
};
// @lc code=end

