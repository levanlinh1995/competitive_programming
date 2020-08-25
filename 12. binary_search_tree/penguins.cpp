// Problem: Penguins
// LinK: https://acm.timus.ru/problem.aspx?space=1&num=1585

#include <iostream>
#include <map>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    int n;
    string s;
    map<string, int> mp;

    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, s);

        mp[s]++;
    }

    string res;
    int maxi = -1;

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        if (it->second > maxi)
        {
            maxi = it->second;
            res = it->first;
        }
    }

    cout << res;

    return 0;
}