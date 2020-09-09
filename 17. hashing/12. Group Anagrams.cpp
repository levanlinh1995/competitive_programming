// problem: 49. Group Anagrams
// link: https://leetcode.com/problems/group-anagrams/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertString(string str) {
        sort(str.begin(), str.end());

        return str;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        vector<vector<string>> res = {};
        string sortedStr;

        for (string el : strs) {
            sortedStr = convertString(el);
            hashmap[sortedStr].push_back(el);
        }

        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            res.push_back(it->second);
        }
        

        return res;
    }
};

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    Solution sl;
    vector<vector<string>> res = sl.groupAnagrams(strs);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}