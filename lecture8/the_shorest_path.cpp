#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct option
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

int getIndex(vector<string> vect, string key) {
    vector<string>::iterator it = find(vect.begin(), vect.end(), key);
    int index = distance(vect.begin(), it);

    return index;
}


void dijkstra(vector<vector<pair<int, int>>> graph, vector<int> &dist, int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> q;
    q.push(make_pair(source, 0));
    dist[source] = 0;

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
                q.push(make_pair(neib.first, w + neib.second));
            }
        }
        
    }
    
}

int main() {
    const int INF = INT32_MAX;
    int s, n, p, nr, cost, r;
    string name, name1, name2;

    cin >> s;
    for (int i = 0; i < s; i++)
    {
        cin >> n;
        n = n + 1;
        vector<string> city_mapping(n, "");
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        vector<int> dist(n, INF);

        for (int j = 1; j < n; j++)
        {
            cin >> name;

            city_mapping[j] = name;

            cin >> p;
            for (int k = 0; k < p; k++)
            {
                cin >> nr >> cost;
                graph[j].push_back(make_pair(nr, cost));
            }
        }

        cin >> r;

        for (int j = 0; j < r; j++)
        {
            cin >> name1 >> name2;
            int source = getIndex(city_mapping, name1);
            int destination = getIndex(city_mapping, name2);

            for (int k = 1; k < n; k++)
            {
                dist[k] = INF;
            }
            
            dijkstra(graph, dist, source);
            cout << dist[destination] << endl;
        }
    }
    
    return 0;
}