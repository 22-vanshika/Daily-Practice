#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // ================================
    // Key Points (Set Algorithms)
    // ================================
    /*
    - Works only on SORTED ranges ⚠️
    - Output is also sorted
    - Uses iterators → output via inserter
    - Common operations: union, intersection, difference, symmetric difference
    */


    vector<int> first = {1, 2, 3, 4};
    vector<int> second = {3, 4, 5, 6};


    // ================================
    // set_symmetric_difference O(n)
    // ================================

    vector<int> res1;

    set_symmetric_difference(
        first.begin(), first.end(),
        second.begin(), second.end(),
        inserter(res1, res1.begin())
    );

    cout << "Symmetric Difference: ";
    for (int a : res1) cout << a << " ";
    cout << endl;


    // ================================
    // set_difference (first - second) O(n)
    // ================================

    vector<int> res2;

    set_difference(
        first.begin(), first.end(),
        second.begin(), second.end(),
        inserter(res2, res2.begin())
    );

    cout << "Difference (first - second): ";
    for (int a : res2) cout << a << " ";
    cout << endl;


    // ================================
    // set_intersection     O(n)
    // ================================

    vector<int> res3;

    set_intersection(
        first.begin(), first.end(),
        second.begin(), second.end(),
        inserter(res3, res3.begin())
    );

    cout << "Intersection: ";
    for (int a : res3) cout << a << " ";
    cout << endl;


    // ================================
    // set_union O(n)
    // ================================

    vector<int> res4;

    set_union(
        first.begin(), first.end(),
        second.begin(), second.end(),
        inserter(res4, res4.begin())
    );

    cout << "Union: ";
    for (int a : res4) cout << a << " ";
    cout << endl;


    return 0;
}


Symmetric Difference: 1 2 5 6
Difference (first - second): 1 2
Intersection: 3 4
Union: 1 2 3 4 5 6