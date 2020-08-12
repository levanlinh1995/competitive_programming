// Method 1: NLogN
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int distinctCount(vector<int> &arr) {
    int n = arr.size();

    if (n == 0) {
        return 0;
    }

    sort(arr.begin(), arr.end());

    int count = 1;
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (arr[j] != arr[i]) {
            i = j;
            count++;
        }

        j++;
    }

    return count;
}

int main() {
    int T, N, X;
    vector<int> arr;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> X;
        arr.clear();
        for (int j = 0; j < N; j++)
        {
            int value;
            cin >> value;
            arr.push_back(value);
        }

        int count = distinctCount(arr);
        if (count == X) {
            cout << "Good";
        } else if (count > X) {
            cout << "Average";
        } else {
            cout << "Bad";
        }

        cout << endl;
    }

    return 0;
}


// Method 2:  NlogN
// #include <iostream>
// #include <algorithm>
// #include <unordered_set>
// using namespace std;

// int main() {
//     int T, N, X;
//     unordered_set<int> s;

//     cin >> T;

//     for (int i = 0; i < T; i++)
//     {
//         cin >> N >> X;
//         s.clear();
//         for (int j = 0; j < N; j++)
//         {
//             int value;
//             cin >> value;
//             s.insert(value);
//         }

//         int count = s.size();
//         if (count == X) {
//             cout << "Good";
//         } else if (count > X) {
//             cout << "Average";
//         } else {
//             cout << "Bad";
//         }

//         cout << endl;
//     }

//     return 0;
// }