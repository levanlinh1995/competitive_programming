#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int getCutSum(const vector<int> &arr, int mid) {
    long long int sum = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] > mid) {
            sum += arr[i] - mid;
        } else {
            break;
        }
    }
    
    return sum;
}

int getHigh(const vector<int> &arr, int m) {
    int n = arr.size();
    int l = 0;
    int r = arr[n - 1];
    int mid;
    long long int sum;
    int result;

    while (l <= r)
    {
        mid = l + (r - l)/2;
        sum = getCutSum(arr, mid);

        if (sum == m) {
            return mid;
        }

        if (sum > m) {
            l = mid + 1;
            result = mid;
        } else {
            r = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, m;
    vector<int> a;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    cout << getHigh(a, m);

    return 0;
}