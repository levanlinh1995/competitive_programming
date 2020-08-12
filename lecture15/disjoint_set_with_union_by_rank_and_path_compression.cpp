#include <bits/stdc++.h>
using namespace std;

#define V 50

void makeSet(int parent[], int rank[]) {
    for (int i = 1; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findSet(int parent[], int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent, parent[u]);
    }

    return parent[u];
}

void unionSet(int parent[], int rank[], int u, int v) {
    int up = findSet(parent, u);
    int vp = findSet(parent, v);

    if (up == vp) {
        return;
    }

    if (rank[up] > rank[vp]) {
        parent[vp] = up;
    } else if (rank[up] < rank[vp]) {
        parent[up] = vp;
    } else {
        parent[vp] = up;
        rank[up]++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int parent[V];
    int rank[V];
    int E, u, v, type;

    cin >> E;

    makeSet(parent, rank);

    while (E--)
    {
        cin >> u >> v >> type;
        if (type == 1) {
            unionSet(parent, rank, u, v);
        } else {
            int parent_u = findSet(parent, u);
            int parent_v = findSet(parent, v);
            if (parent_u == parent_v) {
                cout << "YES";
            } else {
                cout << "NO";
            }

            cout << endl;
        }
    }
    
    return 0;
}