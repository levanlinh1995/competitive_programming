#include <iostream>
#include <string>
using namespace std;

int main() {
    string S, T;
    
    cin >> S >> T;

    int len_S = S.size();
    int len_T = T.size();

    int S_count[26] = {};
    int T_count[26] = {};

    for (int i = 0; i < len_S; i++)
    {
        S_count[S[i] - 'a']++;
    }

    for (int i = 0; i < len_T; i++)
    {
        T_count[T[i] - 'a']++;
    }

    bool is_automaton = false;
    bool is_array = true;

    for (int i = 0; i < 26; i++)
    {
        if (T_count[i] > S_count[i]) {
            cout << "need tree";
            return 0;
        } else if (T_count[i] < S_count[i]) {
            is_automaton = true;
        }
    }

    int count = 0;
    int j = 0;
    int i = 0;
    while (i < len_T && j < len_S)
    {
        if (T[i] == S[j]) {
            count++;
            i++;
        }

        j++;
    }

    if (count == len_T) {
        is_array = false;
    }

    if (is_automaton && is_array) {
        cout << "both";
    } else if (is_automaton) {
        cout << "automaton";
    } else if (is_array) {
        cout << "array";
    }

    return 0;
}