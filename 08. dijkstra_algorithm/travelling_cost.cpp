// Problem: TRVCOST - Travelling cost
// Link: https://www.spoj.com/problems/TRVCOST

#include <iostream>
#include <queue>

using namespace std;

struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};


void dijkstra(vector<vector<pair<int, int>>> graph, vector<int> &path, vector<int> &dist, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> q;
    q.push(make_pair(start,0));
    dist[start] = 0;

    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();

        int u = top.first;
        int w = top.second;
        
        for (unsigned int i = 0; i < graph[u].size(); i++)
        {
            pair<int, int> neib = graph[u][i];

            if (w + neib.second < dist[neib.first]) {
                dist[neib.first] = w + neib.second;
                path[neib.first] = u;
                q.push(make_pair(neib.first, w + neib.second));
            }
        }
    }
}

int main() {
    int N;
    int A, B, W;
    int Q;
    int U, V;
    const int INF = INT32_MAX;

    cin >> N;

    int Vert = 500 + 1;

    vector<vector<pair<int, int>>> graph(Vert, vector<pair<int, int>> ());
    vector<int> path(Vert, -1);
    vector<int> dist(Vert, INF);

    for (int i = 0; i < N; i++)
    {
        cin >> A >> B >> W;

        graph[A].push_back(make_pair(B, W));
        graph[B].push_back(make_pair(A, W));
    }

    cin >> U;

    dijkstra(graph, path, dist, U);

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> V;
        if (dist[V] != INF) {
            cout << dist[V] << endl;
        } else {
            cout << "NO PATH" << endl;
        }
    }
    
    return 0;
}