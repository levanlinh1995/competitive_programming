// problem: 217. Contains Duplicate
// link: https://leetcode.com/problems/contains-duplicate/description/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;

        for (int x : nums) {
            auto res = hashset.insert(x);

            if (!res.second) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 1, 3};

    Solution sl;
    cout << sl.containsDuplicate(arr);

    return 0;
}