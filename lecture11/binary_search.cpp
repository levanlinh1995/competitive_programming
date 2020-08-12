#include <iostream>
#include <vector>
using namespace std;

int binary_search_iteration(const vector<int> &arr, int key) {
    int l = 0;
    int r = arr.size() - 1;
    int mid;

    while (l <= r) {
        mid = (l + r) / 2;
        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    int x;
    vector<int> arr;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    int res = binary_search_iteration(arr, 10);
    cout << "result: " << res;

    return 0;
}