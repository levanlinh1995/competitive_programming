#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

using namespace std;

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

    sort(arr.begin(), arr.end());

    int mid = n/2;

    cout << arr[mid];
    
    

    return 0;
}