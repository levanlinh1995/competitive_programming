#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

int d_row[] = {0, 0, -1, -1};
int d_col[] = {-1, -1, 0, 0};

using namespace std;

// dfs
int getTime(vector<vector<int>> matrix, vector<vector<bool>> visited, int R, int C, pair<int, int> start, pair<int, int> end) {
    int time = 0;

    stack<pair<int, int>> S;
    S.push(start);
    visited[start.first][start.second] = true;
    time++;

    while (!S.empty())
    {
        pair<int, int> top = S.top();
        S.pop();

        for (int i = 0; i < 4; i++)
        {
            int neib_row = d_row[i] + top.first;
            int neib_col = d_col[i] + top.second;

            if (neib_row >= 0 && neib_row < R
                && neib_col >= 0 && neib_col < C && !visited[neib_row][neib_col] && matrix[neib_row][neib_col] != 1) {
                S.push(make_pair(neib_row, neib_col));
                visited[neib_row][neib_col] = true;
                time++;

                if (neib_row == end.first && neib_col == end.second) {
                    return time;
                }
            }
        }
        
    }

    return time;
}

int main() {
    int R, C, rows, row_index, bom_number, col;
    int start_row, start_col, end_row, end_col;

    while (1)
    {
        cin >> R >> C;

        if (R == 0 && C == 0) {
            break;
        }

        cin >> rows;

        vector<vector<int>> matrix(R, vector<int> (C, 0));
        vector<vector<bool>> visited(R, vector<bool> (C, false));


        for (int j = 0; j < rows; j++)
        {
            cin >> row_index >> bom_number;

            for (int k = 0; k < bom_number; k++)
            { 
                cin >> col;
                matrix[row_index][col] = 1;
            }
        }

        cin >> start_row >> start_col;
        cin >> end_row >> end_col;

        pair<int, int> start(start_row, start_col);
        pair<int, int> end(end_row, end_col);

        int result = getTime(matrix, visited, R, C, start, end);
        cout << result << endl;
    }
    

    return 0;
}