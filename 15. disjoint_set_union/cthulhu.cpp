// Problem: Cthulhu
// Link: https://codeforces.com/problemset/problem/104/C

#include <bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &ranks, int &disjointSetCount) {
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }

    disjointSetCount = parent.size();
}

int findSet(vector<int> &parent, int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent, parent[u]);
    }

    return parent[u];
}

void unionSet(vector<int> &parent, vector<int> &ranks, int u, int v, int &disjointSetCount) {
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

    disjointSetCount--;
}

int main() {
    freopen("input.txt", "r", stdin);

    vector<int> parent;
    vector<int> ranks;
    int disjointSetCount;
    int n, m, x, y;

    cin >> n >> m;

    if (n != m) {
        cout << "NO";
        return 0;
    }

    parent.resize(n);
    ranks.resize(n);
    makeSet(parent, ranks, disjointSetCount);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        unionSet(parent, ranks, x - 1, y - 1, disjointSetCount);
    }

    if (disjointSetCount == 1) {
        cout << "FHTAGN!";
    } else {
        cout << "NO";
    }
    

    return 0;
}