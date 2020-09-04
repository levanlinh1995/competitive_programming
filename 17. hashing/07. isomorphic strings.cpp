// problem: 205. Isomorphic Strings
// link: https://leetcode.com/problems/isomorphic-strings/description/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // Method 1
        unordered_map<char, char> m;
        unordered_set<char> visited;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i])) {
                if (m[s[i]] != t[i]) return false;
            } else {
                if (visited.count(t[i])) return false;
                m[s[i]] = t[i];
                visited.insert(t[i]);
            }
        }
        return true;

        // Method 2
        // int m1[256] = {0}, m2[256] = {0}, n = s.size();
        // for (int i = 0; i < n; ++i)
        // {
        //     if (m1[s[i]] != m2[t[i]])
        //         return false;
        //     m1[s[i]] = i + 1;
        //     m2[t[i]] = i + 1;
        // }
        // return true;
    }
};

int main()
{
    string s = "abba";
    string t = "abab";

    Solution sl;
    cout << sl.isIsomorphic(s, t);

    return 0;
}