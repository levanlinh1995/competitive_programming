#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (i != largest) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = n/2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[i], arr[0]);

        maxHeapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {4, 1, 2, 7, 3};

    heapSort(arr);

    for (int el : arr) {
        cout << el << " ";
    }

    return 0;
}