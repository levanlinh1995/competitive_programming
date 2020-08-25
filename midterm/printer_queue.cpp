// problem: printer queue
// link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3252

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n;
    string str;

    cin >> n;
    cin >>str;

    if (n < 26) {
        cout << "NO";
        return 0;
    }

    int count = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 0; j < str.size(); j++)
        {
            if ((int) str[j] == i || (int) str[j] == (i + 32)) {
                count++;
                break;
            }
        }
    }


    if (count == 26) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    

    return 0;
}