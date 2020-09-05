// problem: 599. Minimum Index Sum of Two Lists
// link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap1;
        unordered_map<string, int> hashmap2;
        vector<string> res;

        for (int i = 0; i < list1.size(); i++)
        {
            hashmap1[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); i++)
        {
            hashmap2[list2[i]] = i;
        }

        int minIndexSum = INT32_MAX;
        int indexSum = 0;

        for (int i = 0; i < list1.size(); i++)
        {
            string temp = list1[i];
            if (hashmap1.count(temp) > 0 && hashmap2.count(temp) > 0) {
                indexSum = hashmap1[temp] + hashmap2[temp];
                if (minIndexSum > indexSum) {
                    minIndexSum = indexSum;
                }
            }
        }

        for (int i = 0; i < list1.size(); i++)
        {
            string temp = list1[i];
            if (hashmap1.count(temp) > 0 && hashmap2.count(temp) > 0) {
                indexSum = hashmap1[temp] + hashmap2[temp];
                if (minIndexSum == indexSum) {
                    res.push_back(temp);
                }
            }
        }
        
        return res;
    }
};

int main() {
    vector<string> s1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> s2 = {"KFC","Burger King","Tapioca Express","Shogun"};

    Solution sl;
    vector<string> res = sl.findRestaurant(s1, s2);

    for (string el : res) {
        cout << el << " ";
    }

    return 0;
}