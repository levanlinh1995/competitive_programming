// Problem: B. Wrath
// Link: https://codeforces.com/problemset/problem/892/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int n, L;
    vector<int> arr;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> L;
        arr.push_back(L);
    }

    int j = n - 1;
    int latest_kill_index = 0;
    int count = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        j = min(i, j);

        latest_kill_index = max(0, i - arr[i]);

        if (latest_kill_index < j) {
            count += (j - latest_kill_index);
            j = latest_kill_index;
        }
    }

    cout << n - count;
    

    return 0;
}