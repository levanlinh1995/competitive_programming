#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int A_N, B_N, K, M;
    int x;
    vector<int> A;
    vector<int> B;

    cin >> A_N >> B_N;
    cin >> K >> M;

    for (int i = 0; i < A_N; i++)
    {
        cin >> x;
        A.push_back(x);
    }

    for (int i = 0; i < B_N; i++)
    {
        cin >> x;
        B.push_back(x);
    }

    cout << (A[K - 1] < B[B_N - M] ? "YES" : "NO");

    return 0;
}