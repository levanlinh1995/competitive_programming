// Solution: OPCPIZZA - Pizzamania
// Link: https://www.spoj.com/problems/OPCPIZZA

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bs(const vector<int> &arr,const int &key) {
    int l = 0;
    int r = arr.size() - 1;
    int mid;

    while (l <= r)
    {
        mid = l + (r-l)/2;
        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    int t, n, m;
    int x;

    cin >> t;
    vector<int> money;

    for (int i = 0; i < t; i++)
    {
        money.clear();
        cin >> n >> m;


        for (int j = 0; j < n; j++)
        {
            cin >> x;
            money.push_back(x);
        }

        sort(money.begin(), money.end());

        int count = 0;
        for (int j = 0; j < n; j++)
        {
            int find = bs(money, m - money[j]);
            if (find != -1) {
                count++;
            }
        }

        cout << count/2 << endl;
        
    }
    

    return 0;
}