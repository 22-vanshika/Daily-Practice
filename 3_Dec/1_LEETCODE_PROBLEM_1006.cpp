#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mul(int n) {
        if (n <= 0)
            return 0;
        else if (n <= 2)
            return n;
        return n * (n - 1) / (n - 2);
    }

    int rec(int n) {
        if (n <= 0)
            return 0;
        return n - mul(n - 1) + rec(n - 4);
    }

    int clumsy(int n) {
        return mul(n) + rec(n - 3);
    }
};

int main() {
    Solution obj;
    int n;
    cin >> n;          // input value
    cout << obj.clumsy(n) << endl;
    return 0;
}


// 1006. Clumsy Factorial

// The factorial of a positive integer n is the product of all positive integers less than or equal to n.

// For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
// We make a clumsy factorial using the integers in decreasing order by swapping out the multiply operations for a fixed rotation of operations with multiply '*', divide '/', add '+', and subtract '-' in this order.

// For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
// However, these operations are still applied using the usual order of operations of arithmetic. We do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

// Additionally, the division that we use is floor division such that 10 * 9 / 8 = 90 / 8 = 11.

// Given an integer n, return the clumsy factorial of n.