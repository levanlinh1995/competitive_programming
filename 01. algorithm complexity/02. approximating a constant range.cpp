// Problem: Approximating a Constant Range
// Link: https://codeforces.com/problemset/problem/602/B

#include <bits/stdc++.h>
using namespace std;

int findMinIndex(const vector<int> &arr, const int &i, const int &j) {
    if (arr[j] > arr[i]) {
        return i;
    }

    return j;
}

int findMaxIndex(const vector<int> &arr, const int &i, const int &j) {
    if (arr[i] > arr[j]) {
        return i;
    }

    return j;
}

int main() {
    freopen("input.txt", "r", stdin);

    int N, A;
    vector<int> arr;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A;
        arr.push_back(A);
    }
    

    int len = 0;
    int i = 0;
    int j = 1;
    int minIndex = 0;
    int maxIndex = 0;
    
    while (j < N && i < N)
    {
        minIndex = findMinIndex(arr, minIndex, j);
        maxIndex = findMaxIndex(arr, maxIndex, j);

        if (abs(arr[minIndex] - arr[maxIndex]) <= 1) {
            len = max(len, j - i + 1);
            j++;
        } else {
            if (maxIndex == j) {
                minIndex = i = min(minIndex + 1, N - 1);
            }

            if (minIndex == j) {
                maxIndex = i = min(maxIndex + 1, N - 1);
            }
        }
    }

    cout << len;

    return 0;
}