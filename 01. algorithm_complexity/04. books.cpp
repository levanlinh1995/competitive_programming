// Problem: B. Books
// Link: https://codeforces.com/problemset/problem/279/B

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int N, T, x;
    vector<int> arr;

    cin >> N >> T;


    for (int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    
    int i = 0;
    int j = 0;
    int remaining_amount = T;
    int max_total = 0;
    int count = 0;

    while (i < N && j < N)
    {
        if (arr[j] <= remaining_amount) {
            remaining_amount -= arr[j];
            count++;
            j++;

            if (count > max_total) {
                max_total = count;
            }

        } else {
            count--;
            remaining_amount += arr[i];
            i++;
        }
    }
    
    
    cout << max_total;

    return 0;
}