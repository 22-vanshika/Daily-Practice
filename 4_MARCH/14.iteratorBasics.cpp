#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

int main() {

    // ================================
    // Key Points (Iterators)
    // ================================
    /*
    - Iterators are like pointers used to access container elements
    - Different containers support different iterator types
    - Random Access → +, -, indexing (vector)
    - Bidirectional → forward & backward (list)
    - Forward → only forward (forward_list)
    - Always use *it to access value
    - begin() → first element, end() → one past last
    */


    // ================================
    // Random Access Iterator (vector)
    // ================================

    vector<int> arr = {10, 20, 30, 40, 50};

    // Forward traversal + modification
    for (auto it = arr.begin(); it != arr.end(); it++) {
        *it = *it + 7;
        cout << *it << " ";
    }
    cout << endl;

    // Backward traversal
    for (auto it = arr.end(); it != arr.begin();) {
        it--;
        cout << *it << " ";
    }
    cout << endl;

    // Random access
    auto itVec = arr.begin() + 3;
    cout << *itVec << endl;


    // ================================
    // Bidirectional Iterator (list)
    // ================================

    list<int> myList = {10, 20, 30};

    // Forward traversal + modification
    for (auto it = myList.begin(); it != myList.end(); it++) {
        *it = *it + 2;
        cout << *it << " ";
    }
    cout << endl;

    // Backward traversal
    for (auto it = myList.end(); it != myList.begin();) {
        it--;
        *it = *it + 5;
        cout << *it << " ";
    }
    cout << endl;


    // ================================
    // Forward Iterator (forward_list)
    // ================================

    forward_list<int> fl = {30, 20, 10};

    // Forward traversal + modification
    for (auto it = fl.begin(); it != fl.end(); it++) {
        *it = *it + 5;
    }

    for (auto it = fl.begin(); it != fl.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;


    // ================================
    // Output
    // ================================
    /*
    17 27 37 47 57
    57 47 37 27 17
    47
    12 22 32
    37 27 17
    35 25 15
    */

    return 0;
}