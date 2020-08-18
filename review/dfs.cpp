#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>> &graph, vector<bool> &visited, vector<int> &path, int source) {
    stack<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int u = q.top();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                path[v] = u;
                q.push(v);
            }
        }
    }

}

void printPath(const vector<int> &path, int source, int end) {
    if (source == end) {
        cout << source;
        return;
    }

    if (path[end] == -1) {
        cout << "No found path";
        return;
    }

    vector<int> result;
    result.push_back(end);
    int f = end;

    while (true)
    {
        f = path[f];

        if (f == -1) {
            break;
        }

        result.push_back(f);

        if (f == source) {
            break;
        }
    }

    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int V, E;
    int u, v;

    cin >> V >> E;

    vector<vector<int>> graph(V);
    vector<bool> visited(V, false);
    vector<int> path(V, -1);

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source = 0;
    bfs(graph, visited, path, source);

    printPath(path, source, 5);

    return 0;
}