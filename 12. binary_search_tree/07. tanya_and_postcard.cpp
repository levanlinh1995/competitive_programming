 
// Problem: B. Tanya and Postcard
// Link: https://codeforces.com/contest/518/problem/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    map<char, int> mp_s;
    map<char, int> mp_t;

    for (int i = 0; i < t.size(); i++)
    {
        mp_t[t[i]]++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        mp_s[s[i]]++;
    }

    int count_yay = 0;
    int count_whoops = 0;
    int temp;
    char c;

    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
        temp = min(mp_s[c], mp_t[c]);
        count_yay += temp;
        mp_s[c]-= temp;
        mp_t[c]-= temp;
    }

    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];

        if (c >= 'a') {
            temp = min(mp_s[c], mp_t[c - 32]);
            count_whoops += temp;
            mp_s[c] -= temp;
            mp_t[c - 32] -= temp;
        } else {
            temp = min(mp_s[c], mp_t[c + 32]);
            count_whoops += temp;
            mp_s[c] -= temp;
            mp_t[c + 32] -= temp;
        }
    }

    cout << count_yay << " " << count_whoops;
    
    return 0;
}