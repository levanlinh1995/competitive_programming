// Problem: 1041 - Road Construction
// Link: http://lightoj.com/volume_showproblem.php?problem=1041


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7;

void MST(const vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<bool> &visited, vector<int> &path, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));
    dist[source] = 0;

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        visited[u] = true;

        for (int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> neig = graph[u][i];
            int v = neig.second;
            int w = neig.first;

            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                path[v] = u;
                pq.push(make_pair(w, v));
            }
        }
    }
}   

int calculateMinDistance(const vector<int> &dist, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dist[i];
    }
    
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T, m;
    string str;
    string city1, city2;
    int cost;

    cin >> T;

    int cases = 1;
    while (T--)
    {
        getline(cin, str); // read blank line
        cin.ignore();

        cin >> m;

        int V = m * 2;
        map<string, int> mp;
        vector<vector<pair<int, int>>> graph(V);
        vector<int> dist(V, INF);
        vector<bool> visited(V, false);
        vector<int> path(V, -1);


        int p = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> city1 >> city2 >> cost;
            if (mp.find(city1) == mp.end()) {
                mp[city1] = p++;
            }

            if (mp.find(city2) == mp.end()) {
                mp[city2] = p++;
            }

            graph[mp[city1]].push_back(make_pair(cost, mp[city2]));
            graph[mp[city2]].push_back(make_pair(cost, mp[city1]));
        }

        MST(graph, dist, visited, path, 0);

        int cost = calculateMinDistance(dist, mp.size());

        cout << "Case " << cases << ": ";

        if (cost >= INF || cost < 0) {
            cout << "Impossible";
        } else {
            cout << cost;
        }

        cout << endl;

        cases++;
    }

    return 0;
}