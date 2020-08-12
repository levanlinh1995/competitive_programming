#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bs_first(vector<int> &arr, const int &key) {
    int l = 0;
    int r = arr.size() - 1;
    int mid;

    while (l <= r)
    {
        mid = l + (r-l)/2;

        if (arr[mid] == key && (l == mid || key > arr[mid - 1])) {
            return mid;
        } else if (key > arr[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int N, Q;
    int x, y;

    int test_case = 1;
    while (true)
    {
        cin >> N >> Q;

        if (N == 0 && Q == 0) {
            break;
        }

        vector<int> marbles;

        for (int i = 0; i < N; i++)
        {
            cin >> x;
            marbles.push_back(x);
        }

        sort(marbles.begin(), marbles.end());

        cout << "CASE# " << test_case << ":" << endl;
        int result = 0;
        for (int i = 0; i < Q; i++)
        {
            cin >> y;

            result = bs_first(marbles, y);

            if (result == -1) {
                cout << y << " not found";
            } else {
                cout << y << " found at " << result + 1;
            }

            cout << endl;
        }


        test_case++;
    }
    
    


    return 0;
}