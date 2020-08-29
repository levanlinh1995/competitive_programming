// Problem: Minimum Loss
// Link: https://www.hackerrank.com/challenges/minimum-loss/problem

#include <iostream>
#include <set>
using namespace std;

const long long int MAX = 1e17;

int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    long long int p;
    set<long long int> prices;
    set<long long int>::iterator it;
    long long int min_val = MAX;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        
        it = prices.upper_bound(p);
        if (it != prices.end()) {
            min_val = min(*it - p, min_val);
        }

        prices.insert(p);
    }

    if (min_val != MAX) {
        cout << min_val;
    } else {
        cout << -1;
    }

    return 0;
}