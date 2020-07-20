#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;

    int Time[N];

    for (int i = 0; i < N; i++)
    {
        cin >> Time[i];
    }

    int result = 0;
    

    for (int i = 0; i < N; i++)
    {
        if (result + 15 >= Time[i]) {
            result = Time[i];
        } else {
            result += 15;
            cout << result;
            return 0;
        }
    }

    if (Time[N - 1] + 15 >= 90) {
        result = 90;
    } else {
        result = Time[N - 1] + 15;
    }

    cout << result;

    return 0;
}