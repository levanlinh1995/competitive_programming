#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int N;
    queue<int> deck1;
    vector<int> discarded_cards;

    while (true)
    {
        cin >> N;
        if (N == 0) {
            break;
        }

        discarded_cards.clear();

        for (int i = 1; i <= N; i++)
        {
            deck1.push(i);
        }

        int i = 1;
        int val;

        while (!deck1.empty())
        {
            val = deck1.front();
            deck1.pop();

            if (i % 2 != 0) {
                if (!deck1.empty()) {
                    discarded_cards.push_back(val);
                }
            } else {
                if (!deck1.empty()) {
                    deck1.push(val);
                }
            }

            i++;
        }

        cout << "Discarded cards:";
        if (N != 1) {
            cout << " ";
        }
        for (int i = 0; i < discarded_cards.size(); i++)
        {
            if (i == N - 2) {
                cout << discarded_cards[i];
            } else {
                cout << discarded_cards[i] << ", ";
            }
        }
        cout << endl << "Remaining card: " << val << endl;

        
    }
    
    return 0;
}