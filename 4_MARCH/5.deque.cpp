🔹 deque
Double-ended vector (push/pop front + back = O(1))
Not fully contiguous like vector
Slightly slower than vector for pure back operations
Supports random access (dq[i])
Internally multiple blocks (not a single array)

#include <iostream>
#include <deque>

using namespace std;

int main() {

    // ================================
    // Deque Creation & Insertion
    // ================================

    deque<int> dq;

    dq.push_back(10);   // 10
    dq.push_back(20);   // 10, 20
    dq.push_back(40);   // 10, 20, 40

    dq.push_front(100); // 100, 10, 20, 40
    dq.push_front(200); // 200, 100, 10, 20, 40
    dq.push_front(300); // 300, 200, 100, 10, 20, 40


    // ================================
    // Deletion Operations
    // ================================

    dq.pop_front(); // 200, 100, 10, 20, 40
    dq.pop_back();  // 200, 100, 10, 20

    cout << "Size: " << dq.size() << endl;

    // Erase all elements
    dq.erase(dq.begin(), dq.end());
    cout << "Size after erase: " << dq.size() << endl;


    // ================================
    // Additional Operations
    // ================================

    /*
    deque<int> dq;

    dq.insert(dq.begin(), 101); // 101

    cout << dq[0] << endl;      // Direct access
    cout << dq.at(0) << endl;   // Safe access

    // Traversal using iterator
    for (auto it = dq.begin(); it != dq.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    */


    // ================================
    // Utility Functions
    // ================================

    /*
    deque<int> dq = {10, 20, 30, 40};

    cout << "Size: " << dq.size() << endl;
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    dq.clear();

    if (dq.empty()) {
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }
    */


    return 0;
}