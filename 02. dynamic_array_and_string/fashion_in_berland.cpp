#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    if (N == 1) {
        if (arr[0] == 1) {
            cout << "YES";
        }  else {
            cout << "NO";
        }
    } else {
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] == 0) {
                count++;
                if (count > 1) {
                    break;
                }
            }
        }

        if (count == 1) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

    return 0;
}