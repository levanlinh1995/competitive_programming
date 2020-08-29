// Problem: 459 - Graph Connectivity
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

#include <bits/stdc++.h>
using namespace std;

#define MAX_LEN  26
vector<int> parent(MAX_LEN);
vector<int> ranks(MAX_LEN);

void makeSet(int N, int &disjointSetCount) {
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }

    disjointSetCount = N + 1;
}

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }

    return parent[u];
}

void unionSet(int u, int v, int &disjointSetCount) {
    int up = findSet(u);
    int vp = findSet(v);

    if (up == vp) {
        return;
    }

    if (ranks[up] > ranks[vp]) {
        parent[vp] = up;
    } else if (ranks[up] < ranks[vp]) {
        parent[up] = vp;
    } else {
        parent[up] = vp;
        ranks[vp]++;
    }

    disjointSetCount--;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T;
    int N, u, v;
    int disjointSetCount = 0;
    string str;

    cin >> T;
    cin.ignore();
    getline(cin, str);

    while (T--)
    {
        while (getline(cin, str))
        {
            if (str.empty()) {
                break;
            }

            if (str.size() == 1) {
                N = str[0] - 'A';
                makeSet(N, disjointSetCount);
            } else {
                u = str[0] - 'A';
                v = str[1] - 'A';
                unionSet(u, v, disjointSetCount);
            }
        }

        cout << disjointSetCount << endl;
        if (T > 0) {
            cout << endl;
        }
    }
    
    return 0;
}
