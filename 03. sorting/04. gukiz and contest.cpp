// Problem: A. GukiZ and Contest
// Link: https://codeforces.com/problemset/problem/551/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int n, a;
    vector<int> arr, sorted_arr;
    map<int, int> mp;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
        sorted_arr.push_back(a);
    }

    sort(sorted_arr.begin(), sorted_arr.end());

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (sorted_arr[i] >= sorted_arr[j] && j < n)
        {
            j++;
        }

        if (mp.find(sorted_arr[i]) == mp.end()) {
            mp[sorted_arr[i]] = n - j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << mp[arr[i]] + 1 << " ";
    }
    
    

    return 0;
}