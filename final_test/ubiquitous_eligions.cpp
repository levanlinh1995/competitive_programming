#include <bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &ranks, int &numberOfReligion) {
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
    
    numberOfReligion = parent.size();
}

int findSet(vector<int> &parent, int u) {
    if (u != parent[u]) {
        parent[u] = findSet(parent, parent[u]);
    }

    return parent[u];
}

void unionSet(vector<int> &parent, vector<int> &ranks, int u, int v, int &numberOfReligion) {
    int up = findSet(parent, u);
    int vp = findSet(parent, v);

    if (up == vp) {
        return;
    }

    if (ranks[up] < ranks[vp]) {
        parent[up] = vp;
    } else if (ranks[up] > ranks[vp]) {
        parent[vp] = up;
    } else {
        parent[up] = vp;
        ranks[vp]++;
    }

    numberOfReligion--;
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, m;
    int u, v;
    int testCase = 1;

    int numberOfReligion = 0;

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        vector<int> parent(n);
        vector<int> ranks(n);


        makeSet(parent, ranks, numberOfReligion);

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            unionSet(parent, ranks, u, v, numberOfReligion);
        }

        cout << "Case " << testCase << ": " << numberOfReligion << endl;

        testCase++;
    }
    

    return 0;
}