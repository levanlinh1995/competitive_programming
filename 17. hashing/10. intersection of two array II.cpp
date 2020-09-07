// problem: 350. Intersection of Two Arrays II
// link: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap1;
        unordered_map<int, int> hashmap2;
        vector<int> res;

        for (int i = 0; i < nums1.size(); i++)
        {
            hashmap1[nums1[i]]++;
        }
        
        for (int i = 0; i < nums2.size(); i++)
        {
            hashmap2[nums2[i]]++;
        }

        int count = 0;
        for (auto it = hashmap1.begin(); it != hashmap1.end(); it++)
        {
            if (hashmap2.count(it->first)) {
                count = min(hashmap2[it->first], it->second);

                for (int i = 0; i < count; i++)
                {
                    res.push_back(it->first);
                }
            }
        }
        
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 4, 9, 1};
    vector<int> nums2 = {4, 9, 9, 3};

    Solution sl;
    vector<int> res = sl.intersect(nums1, nums2);
    for (int el : res) {
        cout << el << " ";
    }

    return 0;
}