#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
#include <sstream>
using namespace std;

string streetParade(queue<int> mobiles, int N) {
    stack<int> S;
    queue<int> result;

    while (!mobiles.empty())
    {
        int currentMobile = mobiles.front();
        mobiles.pop();

        if (!mobiles.empty()) {
            int previousMobile = mobiles.front();
            
            if (currentMobile > previousMobile) {
                if (S.empty()) {
                    S.push(currentMobile);
                } else {
                    if (currentMobile < S.top()) {
                        S.push(currentMobile);
                    } else {
                        return "no";
                    }
                }
            } else {
                if (S.empty()) {
                    result.push(currentMobile);
                } else {
                    if (currentMobile < S.top()) {
                        result.push(currentMobile);
                    } else {
                        return "no";
                    }
                }
            }
        } else {
            if (S.empty()) {
                result.push(currentMobile);
            } else {
                if (currentMobile < S.top()) {
                    result.push(currentMobile);
                } else {
                    return "no";
                }
            }
        }
    }

    while (!S.empty())
    {
        result.push(S.top());
        S.pop();
    }
    

    if (result.size() == N) {
        return "yes";
    } else {
        return "no";
    }
}

void readInput(queue<int> &Ns, queue<string> &mobiles) {
    int N;
    string line;

    while (1) {
        cin >> N;
        if (N == 0) {
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

        getline(cin, line);

        Ns.push(N);
        mobiles.push(line);
    }
}

int main() 
{
    queue<int> Ns;
    queue<string> mobileList;
    queue<string> result;

    readInput(Ns, mobileList);

    while (!mobileList.empty())
    {
        queue<int> mobiles;
        string number;
        stringstream ss(mobileList.front());
        mobileList.pop();

        while (getline(ss, number, ' '))
        {
            mobiles.push(stoi(number));
        }

        string temp = streetParade(mobiles, Ns.front());
        Ns.pop();

        result.push(temp);
    }

    while (!result.empty())
    {
        cout << result.front() << endl;
        result.pop();
    }

    cout << endl;
    return 0;
}

