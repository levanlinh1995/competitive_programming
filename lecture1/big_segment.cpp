#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L, R;
    vector<int> L_arr;
    vector<int> R_arr;
    
    cin >> N;

    int L_min = INT32_MAX;
    int R_max = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> L >> R;
        L_arr.push_back(L);
        R_arr.push_back(R);
        L_min = min(L_min, L);
        R_max = max(R_max, R);
    }

    for (int i = 0; i < N; i++)
    {
        if (L_arr[i] == L_min && R_arr[i] == R_max) {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
