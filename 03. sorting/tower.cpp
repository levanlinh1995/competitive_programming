// Problem: Towers
// Link: https://codeforces.com/problemset/problem/37/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int N, l;
    map<int, int> mp;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> l;
        mp[l]++;
    }

    int highLargestTower = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        highLargestTower = max(highLargestTower, it->second);
    }

    cout << highLargestTower << " " << mp.size();
    
    return 0;
}