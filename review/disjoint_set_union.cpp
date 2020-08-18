#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 500;

void makeSet(vector<int> &parent, vector<int> ranks) {
    for (int i = 0; i < MAX_LEN; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findSet(vector<int> &parent, int u) {
    if (u != parent[u]) {
        parent[u] = findSet(parent, parent[u]);
    }

    return parent[u];
}

void unionSet(vector<int> &parent, vector<int> &ranks, int u, int v) {
    int up = findSet(parent, u);
    int vp = findSet(parent, v);

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
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    int u, v, type;

    vector<int> parent(MAX_LEN);
    vector<int> ranks(MAX_LEN);

    cin >> n;

    makeSet(parent, ranks);

    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> type;
        if (type == 1) {
            unionSet(parent, ranks, u, v);
        } else {
            int up = findSet(parent, u);
            int vp = findSet(parent, v);

            if (up == vp) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}