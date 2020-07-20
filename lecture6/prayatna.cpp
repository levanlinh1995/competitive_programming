#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

void find_friends(vector<int> graph[], bool visited[], int N, int start) {
    stack<int> S;
    S.push(start);
    visited[start] = true;

    while (!S.empty()) {
        int u = S.top();
        S.pop();

        for (unsigned int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];

            if (!visited[v]) {
                visited[v]= true;
                S.push(v);
            }
        }
        
    }
}

int main() 
{

    int T, N, E;
    int a, b;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> E;

        if (E == 0) {
            cout << N << endl;
            continue;
        }

        vector<int> graph[N];
        bool visited[N];


        for (int i = 0; i < E; i++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }


        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
        }

        int result = 0;

        for (int i = 0; i < N; i++)
        {
            if (visited[i] == false) {
                result++;
                find_friends(graph, visited, N, i);
            }
        }

        cout << result << endl;
    }
    return 0;
}
