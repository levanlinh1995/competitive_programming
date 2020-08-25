// Problem: B. George and Round
// Link: https://codeforces.com/problemset/problem/387/B

#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int N, M, x;
    vector<int> A;
    vector<int> B;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> x;
        B.push_back(x);
    }

    int count = 0;
    int i = 0;
    int j = 0;
    while (i < N && j < M)
    {
        if (A[i] <= B[j]) {
            count++;
            i++;
        }

        j++;
    }

    cout << (N - count) << endl;

    return 0;
}

