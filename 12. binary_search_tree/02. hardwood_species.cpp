// Problem: 10226 - Hardwood Species
// Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167

#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main() {

    // freopen("input.txt", "r", stdin);

    int T;
    string str;
    map<string, int> mp;
    int count;
    float result;

    cin >> T;
    cin.ignore();
    getline(cin,str);

    while (T--)
    {
        count = 0;
        mp.clear();
        while (true)
        {
            getline(cin,str);
            if (str.empty()) {
                break;
            }

            mp[str]++;
            count++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            cout << it->first << " ";
            cout << fixed << setprecision(4);
            result = it->second * 100.0 /count;
            cout << result;
            cout << endl;
        }
    }

    return 0;
}