// Problem: 10227 Forests
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1168

#include <bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &ranks, int &disjointSet) {
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
    
    disjointSet = parent.size();
}

int findSet(vector<int> &parent, int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent, parent[u]);
    }

    return parent[u];
}

void unionSet(vector<int> &parent, vector<int> &ranks, int u, int v, int &disjointSet) {
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

    disjointSet--;
}   

int main() {
    freopen("input.txt", "r", stdin);

    int testCase, P, T, p, t;
    string str;
    stringstream ss;
    vector<set<int>> person;
    vector<int> parent;
    vector<int> ranks;
    int disjointSet;

    cin >> testCase;
    cin.ignore();

    getline(cin, str); // blank line

    while (testCase--)
    {
        cin >> P >> T;
        cin.ignore();

        person.clear();
        person.resize(P);
        parent.resize(P);
        ranks.resize(P);

        while (getline(cin, str))
        {
            if (str.empty()) {
                break;
            }

            int flag = 0;
            int data;
            ss << str;
            while (ss >> data)
            {
                if (!flag) {
                    p = data;
                    flag = 1;
                } else {
                    t = data;
                }
            }

            ss.clear();


            person[p - 1].insert(t - 1);
        }

        makeSet(parent, ranks, disjointSet);

        for (int i = 0; i < P - 1; i++)
        {
            for (int j = i + 1; j < P; j++)
            {
                if (person[j] == person[i]) {
                    unionSet(parent, ranks, i, j, disjointSet);
                }
            }
        }

        cout << disjointSet << endl;
        if (testCase > 0) {
            cout << endl;
        }
    }

    return 0;
}