🔹 queue
FIFO (First In First Out)
Access only front() and back()
No iteration / no indexing
Also an adapter (uses deque by default)
Cannot access middle elements

#include <iostream>
#include <queue>

using namespace std;

int main() {

    // ================================
    // Queue Swap Example
    // ================================

    queue<int> first;
    queue<int> second;

    first.push(10);
    first.push(20);

    second.push(100);
    second.push(200);

    // Swap contents
    first.swap(second);

    cout << "Front: " << first.front() << endl;
    cout << "Back: " << first.back() << endl;


    // ================================
    // Queue Creation & Operations
    // ================================

    /*
    queue<int> q;

    // Insertion
    q.push(10);  // 10
    q.push(20);  // 10, 20
    q.push(30);  // 10, 20, 30
    q.push(40);  // 10, 20, 30, 40

    cout << "Size: " << q.size() << endl;

    // Deletion
    q.pop();  // removes 10 → 20, 30, 40
    cout << "Size after pop: " << q.size() << endl;

    // Access
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    // Utility
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
    */


    return 0;
}