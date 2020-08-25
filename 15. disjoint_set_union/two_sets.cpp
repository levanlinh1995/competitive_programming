// Problem: Two Sets
// Link: https://codeforces.com/problemset/problem/468/B

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n, a, b;
    int p;
    vector<int> arr;
    map<int, int> mp;
    vector<int> result;

    cin >> n >> a >> b;

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        arr.push_back(p);
        mp[p] = temp++;
    }

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a - arr[i]) != mp.end()) {
            result.push_back(0);
        } else if (mp.find(b - arr[i]) != mp.end()) {
            result.push_back(1);
        } else {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << result[i] << " ";
        }
    } else {
        cout << "NO";
    }
    


    

    return 0;
}