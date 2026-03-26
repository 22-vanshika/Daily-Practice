#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {

    // ================================
    // Key Points (Numeric Algorithms)
    // ================================
    /*
    - <numeric> provides algorithms for cumulative operations
    - Works on iterator ranges [begin, end)
    - Common functions: iota, accumulate, partial_sum, inner_product
    - Useful in prefix sums, totals, and mathematical operations
    */

    // iota: 250 251 252 253 254
    // partial_sum: 1 3 6 10
    // inner_product: 26
    // accumulate: 150

    // ================================
    // iota (Fill with sequence)
    // ================================

    vector<int> first(5);

    iota(first.begin(), first.end(), 250); // O(n)

    cout << "iota: ";
    for (int a : first) {
        cout << a << " ";
    }
    cout << endl;


    // ================================
    // partial_sum (Prefix Sum)
    // ================================

    vector<int> ps = {1, 2, 3, 4};
    vector<int> result(ps.size());

    partial_sum(ps.begin(), ps.end(), result.begin()); //O(n)

    cout << "partial_sum: ";
    for (int a : result) {
        cout << a << " ";
    }
    cout << endl;


    // ================================
    // inner_product (Dot Product)
    // ================================

    vector<int> a = {1, 2, 3};
    vector<int> b = {3, 4, 5};

    int dot = inner_product(a.begin(), a.end(), b.begin(), 0); // O(n)

    cout << "inner_product: " << dot << endl;


    // ================================
    // accumulate (Total Sum)
    // ================================

    vector<int> arr = {10, 20, 30, 40, 50};

    int totalSum = accumulate(arr.begin(), arr.end(), 0); // O(n)

    cout << "accumulate: " << totalSum << endl;


    return 0;
}