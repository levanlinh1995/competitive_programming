// problem: 349. Intersection of Two Arrays
// link: https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset1;
        unordered_set<int> hashset2;

        for (int el : nums1) {
            hashset1.insert(el);
        }

        for (int el : nums2) {
            hashset2.insert(el);
        }

        if (hashset1.size() < hashset2.size()) {
            return this->findIntersection(hashset1, hashset2);
        } else {
            return this->findIntersection(hashset2, hashset1);
        }
    }

    vector<int> findIntersection(unordered_set<int> hashset1, unordered_set<int> hashset2) {
        vector<int> result;

        for (auto it = hashset1.begin(); it != hashset1.end(); it++)
        {
            if (hashset2.find(*it) != hashset2.end()) {
                result.push_back(*it);
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};

    Solution sl;

    vector<int> res = sl.intersection(nums1, nums2);

    for (int el : res) {
        cout << el << " ";
    }

    return 0;
}