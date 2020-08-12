// Method: 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int number_of_pair = 0;

    sort(arr.begin(), arr.end());

    int sub = 0;
    int i = 0, j = 1;

    while (i < n && j < n)
    {
        sub = arr[j] - arr[i];
        if (sub == k) {
            number_of_pair++;
            j++;
            i++;
        } else if(sub < k) {
            j++;
        } else {
            i++;
        }
    }
    

    cout << number_of_pair;
    
    return 0;
}


// Method: 2 (using binary search)
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int bs(const vector<int> &arr, int l, int r, int k) {
//     while (l <= r)
//     {
//         int mid = l + (r - l)/2;
//         if (arr[mid] == k) {
//             return mid;
//         } else if (arr[mid] > k) {
//             r = mid - 1;
//         } else {
//             l = mid + 1;
//         }
//     }

//     return -1;
    
// }

// int main() {
//     int n, k;

//     cin >> n >> k;
//     vector<int> arr(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int number_of_pair = 0;

//     sort(arr.begin(), arr.end());

//     for (int i = 0; i < n; i++)
//     {
//         if(bs(arr, i + 1, n - 1, arr[i] + k) != -1) {
//             number_of_pair++;
//         }
//     }

//     cout << number_of_pair;
    
//     return 0;
// }