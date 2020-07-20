#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int> &arr, int n, int i) {
    int size = n;
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[smallest] > arr[left]) {
        smallest = left;
    }

    if (right < size && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        minHeapify(arr, n, smallest);
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

void pop(vector<int> &arr) {
    int len = arr.size();
    if (len == 0) {
        return;
    }

    arr[0] = arr[len - 1];
    arr.pop_back();

    minHeapify(arr, arr.size(), 0);
}


void buildHeap(vector<int> &arr, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}

int main() {
    vector<int> arr = {7, 12, 6, 10, 17, 15, 2, 4};

    buildHeap(arr, arr.size());
    push(arr, 3);
    pop(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}