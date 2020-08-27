// Problem: Bishu and his Girlfriend
// Link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

void DFS(vector<int> graph[],int path[], bool visited[], int V, int start) {
    for (int i = 1; i < V; i++)
    {
        visited[i] = false;
        path[i] = -1;
    }

    stack<int> S;
    S.push(start);
    visited[start] = true;

    while (!S.empty())
    {
        int u = S.top();
        S.pop();

        for (unsigned int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            
            if (!visited[v]) {
                visited[v]= true;
                path[v] = u;
                S.push(v);
            }
        }
    }
}

int getDistance(int path[], int start, int end) {
    if (start == end) {
        return 0;
    }

    if (path[end] == -1) {
        return 0;
    }

    int f = end;
    int count = 0;
    while (true)
    {
        f = path[f];

        if (f == -1) {
            return 0;
        }

        count++;

        if (f == start) {
            return count; 
        }
    }
    
    return 0;
}

int main() 
{
    int N;
    int u,v;
    int Q;

    cin >> N;

    int V = N + 1;
    vector<int> graph[V];

    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int path[V];
    bool visited[V];
    int start = 1;

    DFS(graph, path, visited, V, start);

    cin >> Q;

    int distances[V];
    for (int i = 1; i < V; i++)
    {
        distances[i] = 0;
    }

    int girlCountry;
    for (int i = 0; i < Q; i++)
    {   
        cin >> girlCountry;
        int distance = getDistance(path, start, girlCountry);
        distances[girlCountry] = distance;
    }

    int MIN = INT32_MAX;
    for (int i = 1; i < V; i++)
    {
        if (distances[i] < MIN && distances[i] != 0) {
            MIN = distances[i];
        }
    }

    for (int i = 1; i < V; i++)
    {
        if (distances[i] == MIN) {
            cout << i;
            break;
        }
    }
    return 0;
}
