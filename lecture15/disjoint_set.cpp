#include <bits/stdc++.h>
using namespace std;

#define V 50

void makeSet(int parent[]) {
    for (int i = 1; i < V; i++)
    {
        parent[i] = i;
    }
}

int findSet(int parent[], int u) {
    while (u != parent[u])
    {
        u = parent[u];
    }
    
    return u;
}

void unionSet(int parent[], int u, int v) {
    int parent_u = findSet(parent, u);
    int parent_v = findSet(parent, v);

    if (u == v) {
        return ;
    }

    parent[u] = v;
}

int main() {
    freopen("input.txt", "r", stdin);

    int parent[V];
    int E, u, v, type;

    cin >> E;

    makeSet(parent);

    while (E--)
    {
        cin >> u >> v >> type;
        if (type == 1) {
            unionSet(parent, u, v);
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