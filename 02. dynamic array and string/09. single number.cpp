// problem: 136. Single Number
// link: https://leetcode.com/problems/single-number/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        while (j < nums.size() && i < nums.size())
        {
            j = i + 1;

            if (nums[i] != nums[j]) {
                break;
            } else {
                i = j + 1;
            }
        }

        return (i > nums.size() - 1 ? -1 : nums[i]);
    }
};

int main() {
    vector<int> arr = {2, 2};

    Solution sl;
    int res = sl.singleNumber(arr);
    cout << res;

    return 0;
}