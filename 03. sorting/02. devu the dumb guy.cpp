// Problem: B. Devu, the Dumb Guy
// Link: http://codeforces.com/problemset/problem/439/B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int u_lli;

int main() {

    freopen("input.txt", "r", stdin);

    int n, x, c;
    vector<u_lli> arr;

    cin >> n >> x;
    
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        arr.push_back(c);
    }

    u_lli minAmountOfTime = 0;

    priority_queue<u_lli, vector<u_lli>, greater<u_lli>> pq(arr.begin(), arr.end());

    while (!pq.empty())
    {
        u_lli val = pq.top();
        pq.pop();

        minAmountOfTime += val * x;

        if (x > 1) {
            x--;
        }
    }

    cout << minAmountOfTime;

    return 0;
}