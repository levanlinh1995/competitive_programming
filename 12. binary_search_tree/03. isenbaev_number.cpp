// Problem: 1837. Isenbaev's Number
// Link: http://acm.timus.ru/problem.aspx?space=1&num=1837

#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 305;

void bfs(const vector<vector<int>> &graph, vector<int> &dist, vector<bool> &visited, int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++)
        {
            int u = graph[v][i];

            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int n;
    int k = 1;
    map<string, int> mapping;
    string member_name1, member_name2, member_name3;
    vector<vector<int>> graph(MAX);
    vector<int> dist(MAX, 0);
    vector<bool> visited(MAX, false);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> member_name1 >> member_name2 >> member_name3;

        if (!mapping[member_name1]) {
            mapping[member_name1] = k++;
        }

        if (!mapping[member_name2]) {
            mapping[member_name2] = k++;
        }

        if (!mapping[member_name3]) {
            mapping[member_name3] = k++;
        }

        graph[mapping[member_name1]].push_back(mapping[member_name2]);
        graph[mapping[member_name2]].push_back(mapping[member_name1]);
        graph[mapping[member_name1]].push_back(mapping[member_name3]);
        graph[mapping[member_name3]].push_back(mapping[member_name1]);
        graph[mapping[member_name2]].push_back(mapping[member_name3]);
        graph[mapping[member_name3]].push_back(mapping[member_name2]);
    }

    bfs(graph, dist, visited, mapping["Isenbaev"]);
    
    for (auto it = mapping.begin(); it != mapping.end(); it++)
    {
        cout << it->first << " ";
        if (it->first == "Isenbaev") {
            cout << 0;
        } else if (dist[it->second] == 0) {
            cout << "undefined";
        } else {
            cout << dist[it->second];
        }

        cout << endl;
    }
    
    return 0;
}