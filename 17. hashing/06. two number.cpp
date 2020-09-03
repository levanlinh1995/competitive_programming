// problem: 1. Two Sum
// link: https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.count(target - nums[i]) > 0) {
                return { i, hashmap[target - nums[i]] };
            }

            hashmap[nums[i]] = i;
        }

        return res;
    }
};

int main() {
    vector<int> nums = {3, 3};
    int target = 6;

    vector<int> res;

    Solution sl;
    res = sl.twoSum(nums, target);

    for (int el : res) {
        cout << el << " ";
    }

    return 0;
}