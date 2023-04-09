/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class RandomizedCollection {
public:
    RandomizedCollection(): size(0) {
        memset(nums, 0, sizeof(nums));
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            map[val].insert(size);
            nums[size++] = val;
            return false;
        }
        map[val] = {size};
        nums[size++] = val;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        //弹出某个val的位置
        int index = *map[val].begin();
        map[val].erase(index);
        //若全部弹出则删掉val的匹配
        if (map[val].size() == 0) {
            map.erase(val);
        }
        if (index != size-1) {
            map[nums[size-1]].erase(size-1);
            map[nums[size-1]].insert(index);
            
            nums[index] = nums[size-1];
        }
        size--;
        return true;
    }
    
    int getRandom() {
        return nums[rand()%size];
    }

private:
    unordered_map<int, unordered_set<int>> map;
    int nums[250000];
    int size;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

