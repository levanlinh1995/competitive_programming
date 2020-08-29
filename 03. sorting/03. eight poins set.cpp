// Problem: B. Eight Point Sets
// Link: https://codeforces.com/contest/334/problem/B

#include <bits/stdc++.h>
using namespace std;

// struct cmp
// {
//     bool operator() (pair<int, int> p1, pair<int, int> p2) {
//         return ((p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second));
//     }
// };

 bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return ((p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second));
}


int main() {
    freopen("input.txt", "r", stdin);
    int x, y;
    set<int> unique_x;
    set<int> unique_y;
    vector<pair<int, int>> points;  // x, y

    for (int i = 0; i < 8; i++)
    {
        cin >> x >> y;
        unique_x.insert(x);
        unique_y.insert(y);
        points.push_back(make_pair(x, y));
    }

    if (unique_x.size() != 3 || unique_y.size() != 3) {
        cout << "ugly";
        return 0;
    }

    sort(points.begin(), points.end(), cmp);

    int k = 0;
    int i, j;
    set<int>::iterator it1;
    set<int>::iterator it2;
    for (it1 = unique_x.begin(), i = 0; it1 != unique_x.end(); it1++, i++) // x
    {
        for (it2 = unique_y.begin(), j = 0; it2 != unique_y.end(); it2++, j++) // y
        {
            if (i == j && i == 1) {
               continue;
            }

            if (points[k].first == *it1 && points[k].second == *it2) {
                k++;
            } else {
                cout << "ugly";
                return 0;
            }
        }
    }

    cout << "respectable";
    
    return 0;
}