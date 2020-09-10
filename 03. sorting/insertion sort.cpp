#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
    int n = arr.size();
    int temp;
    int j;

    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];

            j--;
        }

        arr[j + 1] = temp;
    }
}

int main() {
    vector<int> arr = {4, 1, 2, 7, 3};

    insertionSort(arr);

    for (int el : arr) {
        cout << el << " ";
    }

    return 0;
}