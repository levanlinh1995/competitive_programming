// Problem: B. Passwords
// Link: https://codeforces.com/problemset/problem/721/B

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    string pass;
    string correct_pass;
    vector<string> passwords;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> pass;
        passwords.push_back(pass);
    }

    cin >> correct_pass;

    int corr_pass_len = correct_pass.size();

    int best_count = 0;
    int worst_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (passwords[i].size() < corr_pass_len) {
            best_count++;
        }

        if (passwords[i].size() <= corr_pass_len) {
            worst_count++;
        }
    }

    int best = best_count + 1 + ((best_count/k) * 5);
    int worst = worst_count + (((worst_count - 1)/k) * 5);
    
    cout << best << " " << worst;
    

    return 0;
}