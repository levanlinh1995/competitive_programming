#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() 
{
    freopen("input.txt", "r", stdin);

    int N, K, x;
    vector<int> arr;
    unordered_map<int, int> mp;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    int i = 0;
    int j = 0;
    int L = -1;
    int R = -1;
    int min_sum = INT32_MAX;
    int sum = 0;
    int distinct_number_count = 0;

    while (i < N && j < N)
    {
        if (mp.size() < K) {
            mp[arr[j]]++;
            sum += arr[j];
        }

        if (mp.size() == K) {
            if (sum < min_sum) {
                min_sum = sum;
                L = i + 1;
                R = j + 1;
            }

            sum -= arr[i];

            if (mp[arr[i]] > 1) {
                mp[arr[i]]--;
            } else if (mp[arr[i]] == 1) {
                mp.erase(mp.find(arr[i]));
            }

            i++;
        }
        
        if (mp.size() < K) {
            j++;
        }
    }

    cout << L << " " << R << endl;
    
    return 0;
}