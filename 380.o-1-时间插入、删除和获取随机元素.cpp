/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class RandomizedSet {
public:
    RandomizedSet(): size(0) {
        memset(nums, 0, sizeof(nums));
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        map[val] = size;
        nums[size++] = val;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        //nums填充空缺
        int index = map[val];
        nums[index] = nums[size-1];
        map[nums[size-1]] = index;
        map.erase(val);
        size--;
        return true;
    }
    
    int getRandom() {
        // srand(static_cast<unsigned int>(time(0)));
        return nums[rand()%size];
    }

private:
    unordered_map<int, int> map;
    int nums[250000];
    int size;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

