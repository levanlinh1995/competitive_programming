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
    int V = path.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, option> q;
    q.push(make_pair(start, 0));
    dist[start] = 0;

    while (!q.empty())
    {
        pair<int, int> top = q.top();
        q.pop();

        int u = top.first;
        int w = top.second;

        for (int i = 0; i < graph[u].size(); i++)
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

int main () {
    int V, E;
    int x, y, distance;

    const int INF = INT32_MAX;

    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V, vector<pair<int, int>> ()) ;
    vector<int> path(V, -1);
    vector<int> dist(V, INF);

    for (int i = 0; i < E; i++)
    {
        cin >> x >> y >> distance;
        graph[x].push_back(make_pair(y, distance));
    }

    int start = 0; 
    int destination = 5;
    dijkstra(graph, path, dist, start);


    cout << "result: " << dist[destination];

    return 0;
}
