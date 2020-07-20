#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int d_row[4] = {0, 0, -1, 1};
int d_col[4] = {-1, 1, 0, 0};


vector<pair<int, int>> DFS(vector<char> map[], vector<bool> visited[], int m, int n, pair<int, int> start) {
    vector<pair<int, int>> new_visited;

    stack<pair<int, int>> S;
    S.push(start);
    visited[start.first][start.second] = true;
    new_visited.push_back(start);

    bool temp = false;

    while (!S.empty())
    {
        pair<int, int> u = S.top();
        S.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> v = {u.first + d_row[i], u.second + d_col[i]};
            if (map[v.first][v.second] == '.' && !visited[v.first][v.second]) {
                if (v.first > 0 && v.first < n - 1 && v.second > 0 && v.second < m - 1) 
                {
                    S.push(v);
                    new_visited.push_back(v);
                } else {
                    temp = true;
                }

                visited[v.first][v.second] = true;
            }
        }
    }

    if (temp == true) {
        new_visited.clear();
    }

    return new_visited;
}

bool sortbysec(const pair<int, int> &el1,const pair<int, int> &el2) {
    return el1.second < el2.second;
}

int main() 
{
    int n, m, k;
    char el;

    cin >> n >> m >> k;

    vector<char> map[n];
    vector<bool> visited[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> el;
            map[i].push_back(el);
            visited[i].push_back(false);
        }
    }

    vector<vector<pair<int, int>>> lakes;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i > 0 && i < n - 1 && j > 0 && j < m - 1 && map[i][j] == '.' && !visited[i][j]) {
                pair<int, int> u = {i, j};

                vector<pair<int, int>> new_visited;
                new_visited = DFS(map, visited, m, n, u);
                
                if (new_visited.size() > 0) {
                    lakes.push_back(new_visited);
                }
            }
        }
    }

    int count = 0;

    if (k == 0) {
        for (unsigned int i = 0; i < lakes.size(); i++)
        {
            for (unsigned int j = 0; j < lakes[i].size(); j++)
            {
                pair<int, int> water = {lakes[i][j].first, lakes[i][j].second};
                map[water.first][water.second] = '*';
                count++;
            }
        }
    } else {

        if (lakes.size() - k > 0) {
            vector<pair<int, int>> lakeSize;

            for (unsigned int i = 0; i < lakes.size(); i++)
            {
                lakeSize.push_back(make_pair(i, lakes[i].size()));
            }

            sort(lakeSize.begin(), lakeSize.end(), sortbysec);

            vector<int> needed;

            for (int i = 0; i < lakes.size() - k; i++)
            {
                needed.push_back(lakeSize[i].first);
            }
            
            for (unsigned int i = 0; i < needed.size(); i++)
            {
                for (unsigned int j = 0; j < lakes[needed[i]].size(); j++)
                {
                    pair<int, int> water = {lakes[needed[i]][j].first, lakes[needed[i]][j].second};
                    map[water.first][water.second] = '*';
                    count++;
                }
            }
        }

    }

    cout << count << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
