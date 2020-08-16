#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int const INF = INT32_MAX;


struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

int dijkstra(vector<vector<pair<int, int>>> &graph, vector<int> dist, int start, int end) {
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
                q.push(make_pair(neib.first, w + neib.second));
                dist[neib.first] = w + neib.second;
            }
        }
        
    }

    return dist[end];
    
}

int main() {
    int datasets;
    int N, M, K, S, T;
    int d, c, l;
    int u, v, q;

    cin >> datasets;

    for (int i = 0; i < datasets; i++)
    {
        cin >> N >> M >> K >> S >> T;
        N = N + 1;

        vector<vector<pair<int, int>>> graph(N, vector<pair<int, int>>());
        vector<int> dist(N, INF);

        for (int j = 0; j < M; j++)
        {
            cin >> d >> c >> l;
            graph[d].push_back(make_pair(c, l));
        }

        int smallest = INF;
        for (int j = 0; j < K; j++)
        {
            cin >> u >> v >> q;
            graph[u].push_back(make_pair(v, q)); 
            graph[v].push_back(make_pair(u, q));
            int distance = dijkstra(graph, dist, S, T);
            if (distance < smallest) {
                smallest = distance;
            }

            graph[u].pop_back(); 
            graph[v].pop_back();
        }

        if (smallest != INF) {
            cout << smallest << endl;
        } else {
            cout << -1 << endl;
        }
    }
    

    return 0;
}