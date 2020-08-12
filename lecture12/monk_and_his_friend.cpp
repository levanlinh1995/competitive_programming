#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int T, N, M;
    double x;
    unordered_set<double> s;
    unordered_set<double>::iterator it;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        s.clear();

        for (int j = 0; j < N; j++)
        {
            cin >> x;
            s.insert(x);
        }

        for (int j = 0; j < M; j++)
        {
            cin >> x;
            it = s.find(x);
            if (it == s.end()) {
                cout << "NO";
                s.insert(x);
            } else {
                cout << "YES";
            }
            cout << endl;
        }
    }
    
    
    return 0;
}