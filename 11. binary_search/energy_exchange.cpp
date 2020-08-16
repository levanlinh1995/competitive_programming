#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    vector<int> arr;

    cin >> n >> k;

    double energySum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        energySum += x;
    }

    double left, right, mid, lostSum, transferSum;
    double res;

    left = 0;
    right = 1000;

    while (right - left > 1e-9) {
        mid = left + (right - left)/2;

        transferSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid) {
                transferSum += arr[i] - mid;
            }
        }

        lostSum = transferSum * k / 100;

        if (mid * n <= energySum - lostSum) {
            left = mid;  
            res = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed <<  setprecision(9);
    cout << res;

    return 0;
}