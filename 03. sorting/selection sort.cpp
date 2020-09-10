#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    int indexMin;

    for (int i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexMin]) {
                indexMin = j;
            }
        }
        swap(arr[i], arr[indexMin]);
    }
}

int main() {
    vector<int> arr = {4, 1, 2, 7, 3};

    selectionSort(arr);

    for (int el : arr) {
        cout << el << " ";
    }

    return 0;
}