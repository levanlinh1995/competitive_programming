// Problem: A. Chores
// Link: http://codeforces.com/problemset/problem/169/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n, a, b, h;
    int x;

    vector<int> arr;

    cin >> n >> a >> b;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        arr.push_back(h);
    }

    sort(arr.begin(), arr.end());

    if (arr[b] == arr[b - 1]) {
        cout << 0;
    } else {
        cout << arr[b] - arr[b - 1]; 
    }

    return 0;
}