#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        if (swapped == false) {
            break;
        }
    }
}

int main() {
    vector<int> arr = {4, 1, 2, 7, 3};

    bubbleSort(arr);

    for (int el : arr) {
        cout << el << " ";
    }

    return 0;
}