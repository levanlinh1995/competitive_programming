// problem: soldier and banana
// link: https://codeforces.com/problemset/problem/546/A

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {
    int k, n, w;

    cin >> k >> n >> w;

    int total = 0;
    for (int i = 1; i <= w; i++)
    {
        total += i * k;
    }

    int borr = total - n;

    if (borr > 0) {
        cout << borr;
    } else {
        cout << 0;
    }
    
    

    return 0;
}