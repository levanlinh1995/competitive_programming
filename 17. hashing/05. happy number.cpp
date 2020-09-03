// problem: 202. Happy Number
// link: https://leetcode.com/problems/happy-number/description/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int calculateSquareSum(int n) {
        int sum = 0;

        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return sum;
    }

    // method 1
    bool isHappy(int n) {
        unordered_set<int> hashset;

        while (true)
        {
            n = calculateSquareSum(n);
            if (n == 1) {
                return true;
            }

            if (hashset.find(n) != hashset.end()) {
                return false;
            }

            hashset.insert(n);
        }
    }

    // method 2
    // bool isHappy(int n) {
    //     int slow = n;
    //     int fast = calculateSquareSum(n);
    //     while (slow != fast)
    //     {
    //         if (slow == 1) {
    //             return true;
    //         }

    //         slow = calculateSquareSum(slow);
    //         fast = calculateSquareSum(calculateSquareSum(fast));
    //     }

    //     return (slow == 1);
    // }
};

int main() {
    Solution sl;

    int n = 20;

    cout << sl.isHappy(n);

    return 0;
}