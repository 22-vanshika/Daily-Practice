✌🏼deque vs vector (important comparison)

vector → fast at end only
deque → fast at both ends
vector → contiguous memory (better cache)
deque → slightly slower but more flexible


🔥 Bonus (interview gold)

vector → best default choice
list → rarely used in real-world unless needed
deque → used in sliding window problems
priority_queue → used in greedy + heap problems
stack/queue → mostly used for logic, not storage

🔹 vector

Not truly dynamic → grows by doubling capacity (amortized O(1) push_back)
Insertion/deletion in middle = O(n) (shifting happens)
Contiguous memory → supports indexing (arr[i])
Iterators may become invalid after reallocation
capacity() ≠ size()

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ================================
    // 2D Vector Initialization
    // ================================

    // Create a 5x4 2D vector initialized with 0
    vector<vector<int>> arr(5, vector<int>(4, 0));

    int totalRows = arr.size();
    int totalColumns = arr[0].size();

    // Jagged 2D vector (rows with different column sizes)
    vector<vector<int>> brr(4);

    brr[0] = vector<int>(4);
    brr[1] = vector<int>(2);
    brr[2] = vector<int>(5);
    brr[3] = vector<int>(3);

    int totalRowCount = brr.size();
    // int totalColumnCount = brr[i].size(); // depends on row


    // ================================
    // Basic Vector Operations
    // ================================

    /*
    vector<int> first;

    first.push_back(10);
    first.push_back(11);
    first.push_back(12);
    first.push_back(13);

    // Traversing using iterator
    vector<int>::iterator it = first.begin();

    while (it != first.end()) {
        cout << *it << " ";
        it++;
    }
    */


    // ================================
    // Swap Example
    // ================================

    /*
    vector<int> second;

    second.push_back(100);
    second.push_back(200);
    second.push_back(300);
    second.push_back(400);

    first.swap(second);

    // Print first
    for (int i : first) {
        cout << i << " ";
    }

    // Print second
    for (int i : second) {
        cout << i << " ";
    }
    */


    // ================================
    // Vector Creation & Modifiers
    // ================================

    /*
    vector<int> marks;

    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);
    marks.push_back(40);

    // Insert at beginning
    marks.insert(marks.begin(), 50);

    cout << "Size: " << marks.size() << endl;

    // Erase all elements
    marks.erase(marks.begin(), marks.end());
    cout << "Size after erase: " << marks.size() << endl;
    */


    // ================================
    // Accessing Elements
    // ================================

    /*
    vector<int> marks = {10, 20, 30, 40};

    cout << marks[0] << endl;       // Direct access
    cout << marks.at(0) << endl;    // Safe access

    marks[0] = 100;
    cout << marks[0] << endl;
    */


    // ================================
    // Utility Functions
    // ================================

    /*
    vector<int> marks = {10, 20, 30, 40};

    cout << "Size: " << marks.size() << endl;

    if (marks.empty()) {
        cout << "Vector is empty" << endl;
    } else {
        cout << "Vector is not empty" << endl;
    }

    marks.pop_back();

    cout << "Front: " << marks.front() << endl;
    cout << "Back: " << marks.back() << endl;

    cout << "First element using iterator: " << *(marks.begin()) << endl;
    */


    // ================================
    // Different Ways to Initialize
    // ================================

    /*
    vector<int> miles(10);         // size 10, default initialized (0)
    vector<int> distances(15, 0);  // size 15, all values = 0

    vector<int> age(100);
    age[0] = 10;
    */


    return 0;
}