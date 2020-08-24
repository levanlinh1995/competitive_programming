#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    int N, a;
    queue<int> mobileList;
    stack<int> sideStreet;
    vector<int> sorted_mobileList;
    vector<int> result;

    while (true)
    {
        cin >> N;
        if (N == 0) {
            break;
        }

        sorted_mobileList.clear();
        result.clear();

        for (int i = 0; i < N; i++)
        {
            cin >> a;
            mobileList.push(a);
            sorted_mobileList.push_back(a);
        }
        
        sort(sorted_mobileList.begin(), sorted_mobileList.end()); // ascending

        while (!mobileList.empty())
        {
            int front = mobileList.front();

            if (sideStreet.empty()) {
                sideStreet.push(front);
                mobileList.pop();
            } else {
                int top = sideStreet.top();
                if (front > top) {
                    result.push_back(top);
                    sideStreet.pop();
                } else {
                    sideStreet.push(front);
                    mobileList.pop();
                }
            }
        }

        while (!sideStreet.empty())
        {
            int top = sideStreet.top();
            sideStreet.pop();

            result.push_back(top);
        }
        
        bool temp = true;
        for (int i = 0; i < N; i++)
        {
            if (result[i] != sorted_mobileList[i]) {
                temp = false;
                break;
            }
        }

        if (temp) {
            cout << "yes";
        } else {
            cout << "no";
        }

        cout << endl;
    }
    
    return 0;
}