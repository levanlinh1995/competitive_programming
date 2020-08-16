#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int> &arr, int k) {

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > k) {
            return false;
        }

        if (arr[i]  == k) {
            k--;
        }
    }

    return true;
}

int bs(const vector<int> &arr, const vector<int> &sub) {
    int l = 0;
    int r = arr[arr.size() - 1];
    int mid;
    int res;

    while (l <= r)
    {
        mid = (l + r)/2;

        if (check(sub, mid)) {
            r = mid - 1;
            res = mid;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main() {
    int T, n, r;
    vector<int> arr;
    vector<int> sub;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        arr.clear();
        sub.clear();

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> r;
            arr.push_back(r);
        }

        sub.push_back(arr[0]);
        for (int j = 1; j < n; j++)
        {
            sub.push_back(arr[j] - arr[j - 1]);
        }

        int res = bs(arr, sub);

        cout << "Case " << i + 1 << ": " << res;
        cout << endl;
    }

    return 0;
}