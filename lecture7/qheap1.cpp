#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

void minHeapify(vector<int> &q, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right =  2*i + 2;

    if (left <  q.size() && q[left] < q[smallest]) {
        smallest = left;
    }

    if (right <  q.size() && q[right] < q[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(q[smallest], q[i]);
        minHeapify(q, smallest);
    }
}

void push(vector<int> &arr, int value) {
    arr.push_back(value);
    int i = arr.size() - 1;

    while (i != 0 && arr[i] < arr[(i - 1 ) / 2])
    {
        swap(arr[(i-1) / 2], arr[i]);
        i = (i - 1) / 2;
    }
}

void pop(vector<int> &q, int value) {
    vector<int>::iterator it = find(q.begin(), q.end(), value);
    int len = q.size();
    int index = it - q.begin();
    q[index] = q[len - 1];
    q.pop_back();

    minHeapify(q, index);
}

void buildHeap(vector<int> &q) {
    for (int i = q.size()/2 - 1; i >= 0; i--)
    {
        minHeapify(q, i);
    }
    
}

int main () {
    int Q;
    int v; 
    int type;
    vector<int> q;
    
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> type;

        if (type == 1) {
            cin >> v;
            push(q, v);
            
        } else if (type == 2) {
            cin >> v;
            pop(q, v);
            buildHeap(q);

        } else if (type == 3) {
            cout << q.front() << endl;
        }
    }

    return 0;
}