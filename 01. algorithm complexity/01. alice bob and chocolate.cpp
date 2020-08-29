// Problem: Alice Bob and Chocolate
// Link: https://codeforces.com/problemset/problem/6/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int n, t;
    vector<int> bars;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        bars.push_back(t);
    }

    int i = 0;
    int j = n - 1;
    long long int sum1 = 0; // Alice
    long long int sum2 = 0; // Bob
    int count1 = 0;
    int count2 = 0;

    while (i <= j)
    {
        if (sum1 > sum2) {
            sum2 += bars[j];
            count2++;
            j--;
        } else if (sum1 <= sum2) {
            sum1 += bars[i];
            count1++;
            i++;
        }
    }

    cout << count1 << " " << count2;
    
    
}