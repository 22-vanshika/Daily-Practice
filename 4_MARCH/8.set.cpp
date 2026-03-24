🔹 set
Stores unique elements only (duplicates ignored)
Always sorted (ascending by default)
Implemented using Red-Black Tree
Insert/Search/Delete → O(log n)
No indexing → st[i] ❌

🔹 unordered_set
Uses hashing
Average → O(1) operations
Worst case → O(n)
No order guaranteed
Faster than set in most cases

🔥 Subtle but important
Inserting duplicate in set → ignored silently
Order in set ≠ insertion order → always sorted
unordered_set → completely unpredictable order

🔥 count vs find (small but asked in interviews)
count(x) → returns 0 or 1 (since unique elements)
find(x) → returns iterator
Prefer find() when you need iterator usage

🔥 Critical gotcha
You cannot modify elements inside a set
(they are treated as const)
→ because it would break ordering

🔥 When to use what
Need sorted unique data → set
Need fast lookup → unordered_set
Need order + uniqueness → set

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {

    // ================================
    // Ordered Set (set)
    // ================================

    set<int> st;

    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(4);

    // Searching
    if (st.count(155)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    if (st.find(155) != st.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    // Deletion
    st.erase(st.begin(), st.end());
    cout << "Size after erase: " << st.size() << endl;

    // Clear
    st.clear();
    cout << "Size after clear: " << st.size() << endl;

    // Check empty
    if (st.empty()) {
        cout << "Set is empty" << endl;
    } else {
        cout << "Set is not empty" << endl;
    }


    // ================================
    // Traversal
    // ================================

    /*
    set<int> st = {10, 15, 8, 4};

    for (auto val : st) {
        cout << val << " ";
    }
    cout << endl;
    */


    // ================================
    // Unordered Set (Hash Set)
    // ================================

    /*
    unordered_set<int> ust;

    ust.insert(10);
    ust.insert(15);
    ust.insert(8);
    ust.insert(4);

    // Traversal (no order)
    for (auto val : ust) {
        cout << val << " ";
    }
    cout << endl;
    */


    return 0;
}