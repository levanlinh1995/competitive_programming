 
// Problem: Monk and Multiplication
// Link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    unsigned long long int x;
    vector<unsigned long long int> a;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    priority_queue<unsigned long long int> pq;

    for (int i = 0; i < N; i++)
    {
        pq.push(a[i]);

        if (i < 2) {
            cout << -1 << endl;
        } else {
            unsigned long long int third = pq.top();
            pq.pop();

            unsigned long long int second = pq.top();
            pq.pop();

            unsigned long long int first = pq.top();
            pq.pop();

           

            cout << third * second * first << endl;

            pq.push(third);
            pq.push(second);
            pq.push(first);
        }
    }

    return 0;
}