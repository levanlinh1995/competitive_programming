#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <limits>
using namespace std;

int getLongPrefix(string expression) {
    stack<char> S; // to save '<' character

    int len = expression.size();
    if (len == 0) {
        return 0;
    }

    int lenOfLongPrefix = 0;

    for (int i = 0; i < len; i++)
    {
        if (expression[i] == '<') {
            S.push('<');
        } else if (expression[i] == '>') {
            if (!S.empty()) {
                S.pop();

                if (S.empty()) {
                    lenOfLongPrefix = i + 1;
                }
            } else {
                return lenOfLongPrefix;
            }
        }
    }

    return lenOfLongPrefix;
}

int main() 
{
    int T;
    vector<string> expressions;

    // read the input
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

    string line;
    for (int i = 0; i < T; i++) {
        getline(cin, line);
        expressions.push_back(line);
    }

    // process
    if (T == 0) {
        cout << 0;
        return 0;
    }

    vector<int> result;
    for (int i = 0; i < T; i++)
    {
        int len = getLongPrefix(expressions[i]);
        result.push_back(len);
    }

    // print the output
    for (int i = 0; i < T; i++)
    {
        cout << result[i] << endl;
    }
    
    cout << endl;
    return 0;
}

