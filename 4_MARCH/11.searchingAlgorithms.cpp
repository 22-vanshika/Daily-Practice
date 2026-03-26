#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // ================================
    // Key Points (Searching Algorithms)
    // ================================
    /*
    - Most searching algorithms require sorted data (binary_search, bounds)
    - Return type can be iterator or boolean → handle carefully
    - max_element / min_element → work on unsorted data O(n)
    - max() / min() → compare two values O(1)
    - binary_search → returns true/false (sorted data required) O(log n)
    - lower_bound → first element >= target O(log n)
    - upper_bound → first element > target O(log n)
    */


    // ================================
    // max_element & min_element
    // ================================

    vector<int> arr1 = {10, 20, 30, 40, 50};

    auto maxIt = max_element(arr1.begin(), arr1.end());
    auto minIt = min_element(arr1.begin(), arr1.end());

    cout << "Max element: " << *maxIt << endl;
    cout << "Min element: " << *minIt << endl;


    // ================================
    // min & max (Two values)
    // ================================

    int a = 10, b = 15;

    cout << "Max(a, b): " << max(a, b) << endl;
    cout << "Min(a, b): " << min(a, b) << endl;


    // ================================
    // Binary Search & Bounds (Sorted Array)
    // ================================

    vector<int> arr2 = {10, 20, 30, 40, 50};

    int target1 = 40;

    auto lb = lower_bound(arr2.begin(), arr2.end(), target1);
    auto ub = upper_bound(arr2.begin(), arr2.end(), target1);

    cout << "Lower bound of 40: " << *lb << endl;
    cout << "Upper bound of 40: " << *ub << endl;


    // ================================
    // Binary Search (Existence Check)
    // ================================

    int target2 = 400;

    bool found = binary_search(arr2.begin(), arr2.end(), target2);

    cout << "Binary search (400): " << found << endl;


    // ================================
    // Homework Edge Case Handling
    // ================================

    int target3 = 55;

    auto it = lower_bound(arr2.begin(), arr2.end(), target3);

    if (it != arr2.end()) {
        cout << "Lower bound of 55: " << *it << endl;
    } else {
        cout << "Lower bound of 55: Not found (points to end)" << endl;
    }


    return 0;
}


// Max element: 50
// Min element: 10
// Max(a, b): 15
// Min(a, b): 10
// Lower bound of 40: 40
// Upper bound of 40: 50
// Binary search (400): 0
// Lower bound of 55: Not found (points to end)

// 🔥 Short Summary 
// max_element / min_element → find max/min in range
// max() / min() → compare two values
// binary_search → returns true/false (sorted data required)
// lower_bound → first element ≥ target
// upper_bound → first element > target
// Always check iterator before dereferencing ⚠️

// 🔥 Subtle but important (interview-level)
// lower_bound / upper_bound only work correctly on sorted data
// If element not found → may return end() ⚠️
// binary_search only tells existence → not position