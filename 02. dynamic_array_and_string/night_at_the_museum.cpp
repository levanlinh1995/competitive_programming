// Problem: A. Night at the Museum
// Link: http://codeforces.com/contest/731/problem/A

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string item_name;
    cin >> item_name;
    int len = 'z' - 'a'; // 25
    int half_len = len/2 + 1;   //13

    int result = 0;
    char start = 'a';
    for (int i = 0; i < item_name.size(); i++)
    {
        char c = item_name[i];
        int distance = abs(start - c);

        if (distance < 13) {
            result += distance;
        } else {
            result += len - distance + 1;
        }


        start = c;
    }

    cout <<  result;

    return 0;
}
