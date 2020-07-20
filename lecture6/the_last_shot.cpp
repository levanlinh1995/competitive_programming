#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int getImpact(vector<int> graph[], bool visited[], int V, int start) {
    int maxImpact = 0;

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    stack<int> S;
    S.push(start);
    visited[start] = true;
    maxImpact++;

    while (!S.empty())
    {
        int u = S.top();
        S.pop();

        for (unsigned int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];

            if (!visited[v]) {
                S.push(v);
                visited[v] = true;
                maxImpact++;
            }
        }
    }
    
    return maxImpact;
}

int main() 
{
    int N, M;
    int A, B;

    cin >> N >> M;

    int V = N + 1;
    vector<int> graph[V];
    bool visited[V];

    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        graph[A].push_back(B);
    }

    vector<int> impacts;
    for (int i = 1; i < V; i++)
    {
        // base on DFS
        int numberOfImpact = getImpact(graph, visited,V, i);
        impacts.push_back(numberOfImpact);
    }

    cout << *max_element(impacts.begin(), impacts.end());

    return 0;
}
