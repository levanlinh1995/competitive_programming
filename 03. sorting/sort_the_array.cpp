// Problem: B. Sort the Array
// Link: http://codeforces.com/problemset/problem/451/B

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end) {
    while (start < end)
    {
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        swap(arr[start], arr[end]);

        start++;
        end--;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, a;
    vector<int> arr, sorted_arr;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
        sorted_arr.push_back(a);
    }

    sort(sorted_arr.begin(), sorted_arr.end());

    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != sorted_arr[i]) {
            l = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != sorted_arr[i]) {
            r = i;
            break;
        }
    }

    reverseArray(arr, l, r);
    // reverse(arr.begin() + l, arr.begin() + r + 1);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != sorted_arr[i]) {
            cout << "no";
            return 0;
        }
    }
    
    cout << "yes" << endl;
    if (l == r) {
        cout << "1 1";
    } else {
        cout << l + 1 << " " << r + 1;

    }
    
    return 0;
}