// problem: 219. Contains Duplicate II
// link: https://leetcode.com/problems/contains-duplicate-ii/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.count(nums[i]) > 0) {
                if ((i - hashmap[nums[i]]) <= k) {
                    return true;
                }
            }
            hashmap[nums[i]] = i;
        }
        
        return false;
    }
};

int main() {
    vector<int> nums = {1,0,1,1};
    int k = 1;

    Solution sl;
    cout << sl.containsNearbyDuplicate(nums, k);

    return 0;
}