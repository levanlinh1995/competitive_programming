#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int N, x;
    vector<int> cards;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        cards.push_back(x);
    }

    int sum1 = 0;
    int sum2 = 0;
    int i = 0;
    int j = N - 1;
    int k = 0;
    int temp = 0;
    while (k < N)
    {
        if (cards[i] > cards[j]) {
            temp = cards[i];
            i++;
        } else {
            temp = cards[j];
            j--;
        }

        if (k % 2 == 0) {
            sum1 += temp;
        } else {
            sum2 += temp;
        }

        k++;
    }

    cout << sum1 << " " << sum2;

    return 0;
}