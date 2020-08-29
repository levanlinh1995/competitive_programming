// Problem: A. Vitaly and Strings
// Link: http://codeforces.com/problemset/problem/518/A

#include <iostream>
#include <string>
using namespace std;

int main() {
    string S, T, need;

    cin >> S >> T;

    int S_sum = 0;
    int T_sum = 0;

    int i = S.size() - 1;
    while (i >= 0)
    {
        if (S[i] == 'z') {
            S[i] = 'a';
        } else {
            S[i]++;
            break;
        }
        
        i--;
    }
    

    if (S == T) {
        cout << "No such string";
        return 0;
    }

    cout << S;

    return 0;
}
