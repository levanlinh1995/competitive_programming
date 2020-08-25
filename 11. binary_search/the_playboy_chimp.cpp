// Problem: 10611 - The Playboy Chimp
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=316&page=show_problem&problem=1552

#include <iostream>
#include <vector>
using namespace std;

int bs_lower_value(const vector<int> &arr, int l, int r, int key) {
    int mid;
    int lower = -1;

    while (l <= r)
    {
        mid = l + (r - l)/2;
        
        if (arr[mid] >= key) {
            r = mid - 1;
        } 
        
        if (arr[mid] < key) {
            l = mid + 1;
            lower = mid;
        }
    }

    return lower;
}

int bs_higher_value(const vector<int> &arr, int l, int r, int key) {
    int mid;
    int higher = -1;

    while (l <= r)
    {
        mid = l + (r - l)/2;
        
        if (arr[mid] > key) {
            r = mid - 1;
            higher = mid;
        } 
        
        if (arr[mid] <= key) {
            l = mid + 1;
        }
    }

    return higher;
}

int main() {
    int N, Q;
    int x;
    vector<int> arr;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> x;

        int lower  = bs_lower_value(arr, 0, N - 1, x);
        int higher  = bs_higher_value(arr, 0, N - 1, x);

        if (lower != -1) {
            cout << arr[lower] << " ";
        } else {
            cout << "X ";
        }

        if (higher != -1) {
            cout << arr[higher];
        } else {
            cout << "X";
        }

        cout << endl;
    }
    
    
    return 0;
}