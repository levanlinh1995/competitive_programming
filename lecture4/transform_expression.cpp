#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return 1;
    }

    return 0;
}

int isOperand(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

int getPriority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    }

    return -1;
}

string getRPN(string expression) {
    stack<char> S;
    queue<char> P;
    string result;

    for (unsigned int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if (isOperator(c)) {
            if (!S.empty()) {
                if (getPriority(c) > getPriority(S.top())) {
                    S.push(c);
                } else {
                    while (!S.empty())
                    {
                        if (S.top() == '(') {
                            break;
                        }

                        P.push(S.top());
                        S.pop();
                    }

                    S.push(c);
                }
            } else {
                S.push(c);
            }
            
        } else if (isOperand(c)) {
            P.push(c);
        } else if (c == '(' || c == ')') {
            if (c == '(') {
                S.push(c);
            } else {
                while (!S.empty())
                {
                    if (S.top() == '(') {
                        S.pop();
                        break;
                    }

                    P.push(S.top());
                    S.pop();
                }
            }
        }
    }

    while (!S.empty())
    {
        P.push(S.top());
        S.pop();
    }

    while (!P.empty())
    {
        char c = P.front();
        result.push_back(c);
        P.pop();
    }

    return result;
}

int main() 
{
    int T;
    string line;
    vector<string> expressions;
    vector<string> output;

    // read the input
    cin >> T;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < T; i++) {
        getline(cin, line);
        expressions.push_back(line);
    }


    // process
    for (int i = 0; i < T; i++) {
        output.push_back(getRPN(expressions[i]));
    }


    // print output
    for (int i = 0; i < T; i++)
    {
        cout << output[i] << endl;
    }

    cout << endl;
    return 0;
}

