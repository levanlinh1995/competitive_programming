#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

void BFS(vector<int> graph[],int path[], bool visited[], int V, int start) {
    for (int i = 0; i < V; i++)
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

        for (int i = 0; i < graph[u].size(); i++)
        {
            int c = graph[u][i];
            if (!visited[c]) {
                S.push(c);
                path[c] = u;
                visited[c] = true;
            }
        }
    }
}

void printShortesPath(int path[], int start, int destination) {
    if (start == destination) {
        cout << start << " ";
        return;
    }

    if (path[destination] == -1) {
        cout << "not found";
        return;
    }
    
    if (path[destination] != -1) {
        printShortesPath(path, start, path[destination]);
        cout << destination << " ";
    }
}

void printShortestPath2(int path[], int start, int destination) {
    if (path[destination] == -1) {
        cout << "not found";
        return;
    }

    vector<int> result;

    int f = destination;
    while(1) {
        result.push_back(f);
        f = path[f];

        if (f == -1) {
            cout << "not found";
            return;
        }

        if (start == f) {
            result.push_back(start);
            break;
        }
    }

    for (int i = result.size() - 1; i >= 0 ; i--)
    {
        cout << result[i] << " ";
    }
}

int main() 
{
    int V, E;
    int x,y;

    cin >> V >> E;

    vector<int> graph[V];
    for (int i = 0; i < E; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bool visited[V];
    int path[V];

    int start = 0;
    BFS(graph, path, visited, V, start);

    // printShortesPath(path, start, 5);
    printShortestPath2(path, start, 5);
    
    cout << endl;
    return 0;
}
