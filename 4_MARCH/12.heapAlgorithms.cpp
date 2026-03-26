// Subtle but important 
// pop_heap() does NOT delete → just moves max to end ⚠️
// You must call pop_back() after it
// Heap structure is not sorted internally
// Default heap = max heap

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    // ================================
    // Key Points (Heap Algorithms)
    // ================================
    /*
    - Default heap in C++ = Max Heap
    - make_heap → converts array into heap O(n)
    - push_heap → insert element into heap O(log n)
    - pop_heap → removes top element (move to end) O(log n)
    - You must call pop_back() after pop_heap() to remove it
    - sort_heap → converts heap into sorted array O(n log n)
    - Heap is NOT fully sorted → only top is guaranteed
    */


    // ================================
    // Create Heap
    // ================================

    vector<int> arr = {22, 11, 55, 66, 77};

    make_heap(arr.begin(), arr.end());

    cout << "After make_heap: ";
    for (int a : arr) cout << a << " ";
    cout << endl;


    // ================================
    // Insertion (push_heap)
    // ================================

    arr.push_back(99);
    push_heap(arr.begin(), arr.end());

    cout << "After push_heap (99): ";
    for (int a : arr) cout << a << " ";
    cout << endl;


    // ================================
    // Deletion (pop_heap)
    // ================================

    pop_heap(arr.begin(), arr.end());
    arr.pop_back(); // removes largest element

    cout << "After pop_heap: ";
    for (int a : arr) cout << a << " ";
    cout << endl;


    // ================================
    // Sorting Heap
    // ================================

    sort_heap(arr.begin(), arr.end());

    cout << "After sort_heap: ";
    for (int a : arr) cout << a << " ";
    cout << endl;


    return 0;
}


// After make_heap: 77 66 55 22 11
// After push_heap (99): 99 77 55 22 11 66
// After pop_heap: 77 66 55 22 11
// After sort_heap: 11 22 55 66 77