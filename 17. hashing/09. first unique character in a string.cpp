// problem: 387. First Unique Character in a String
// link: https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;

        for (int i = 0; i < s.size(); i++)
        {
            hashmap[s[i]]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (hashmap[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    string s = "loveleetcode";
    Solution sl;
    cout << sl.firstUniqChar(s);

    return 0;
}