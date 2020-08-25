// Problem: 10608 - Friends
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549

#include <bits/stdc++.h>
using namespace std;
#define MAX 30001
int parent[MAX];
int ranks[MAX];
int sizes[MAX];

void makeSet() {
    for (int i = 1; i < MAX; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
        sizes[i] = 1;
    }
}

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }

    return parent[u];
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    
    if (vp == up) {
        return;
    }

    if (ranks[up] > ranks[vp]) {
        parent[vp] = up;
        sizes[up] += sizes[vp];
    } else if (ranks[up] < ranks[vp]) {
        parent[up] = vp;
        sizes[vp] += sizes[up];
    } else {
        parent[up] = vp;
        ranks[vp]++;
        sizes[vp] += sizes[up];
    }
} 

int main() {
    // freopen("input.txt", "r", stdin);

    int T, N, M, A, B;

    cin >> T;

    while (T--)
    {
        makeSet();
        cin >> N >> M;
        while (M--)
        {
            cin >> A >> B;
            unionSet(A, B);
        }

        int res = 0;
        for (int i = 1; i <= N; i++)
        {
            res = max(res, sizes[i]);
        }

        cout << res << endl;
    }
    
    return 0;
}