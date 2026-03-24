🔹 stack
Adapter (built on deque by default)
Only access: top() → no iteration
LIFO (Last In First Out)
No random access
Internally not a “real” container

#include <iostream>
#include <stack>

using namespace std;

int main() {

    // ================================
    // Stack Creation & Insertion
    // ================================

    stack<int> st;

    st.push(10);  // 10
    st.push(20);  // 10, 20
    st.push(30);  // 10, 20, 30

    cout << "Size: " << st.size() << endl;


    // ================================
    // Deletion & Access
    // ================================

    st.pop();  // removes 30 → 10, 20
    cout << "Size after pop: " << st.size() << endl;
    cout << "Top element: " << st.top() << endl;

    st.pop();  // removes 20 → 10
    cout << "Top element: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;


    // ================================
    // Utility Functions
    // ================================

    if (st.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }


    return 0;
}