#include <iostream>
#include <list>

using namespace std;

int main() {

    // ================================
    // Basic List Operations
    // ================================

    list<int> first;

    first.push_back(10);
    first.push_back(20);
    first.push_back(30);
    // 10 -> 20 -> 30

    // Insert at beginning
    first.insert(first.begin(), 100);
    // 100 -> 10 -> 20 -> 30

    cout << "Size: " << first.size() << endl;

    // Erase entire list
    first.erase(first.begin(), first.end());
    cout << "Size after erase: " << first.size() << endl;


    // ================================
    // Traversal Using Iterator
    // ================================

    /*
    list<int>::iterator it = first.begin();

    while (it != first.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    */


    // ================================
    // Swap Example
    // ================================

    /*
    list<int> second;

    second.push_back(100);
    second.push_back(200);
    second.push_back(300);
    // 100 -> 200 -> 300

    first.swap(second);

    list<int>::iterator it = first.begin();

    while (it != first.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    */


    // ================================
    // List Creation & Modifiers
    // ================================

    /*
    list<int> myList;

    // Insertion
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    // 10 -> 20 -> 30 -> 40

    myList.push_front(100);
    // 100 -> 10 -> 20 -> 30 -> 40

    // Deletion
    myList.pop_back();   // removes 40
    myList.pop_front();  // removes 100

    myList.push_back(10);
    // 10 -> 20 -> 30 -> 10

    // Before removing
    cout << "Before removing: " << endl;
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;

    // Remove all occurrences of 10
    myList.remove(10);

    // After removing
    cout << "After removing: " << endl;
    for (int val : myList) {
        cout << val << " ";
    }
    cout << endl;
    */


    // ================================
    // Utility Functions
    // ================================

    /*
    list<int> myList = {10, 20, 30, 40};

    cout << "Front: " << myList.front() << endl;
    cout << "Back: " << myList.back() << endl;

    cout << "Size: " << myList.size() << endl;

    myList.clear();
    cout << "Size after clear: " << myList.size() << endl;

    if (myList.empty()) {
        cout << "List is empty" << endl;
    } else {
        cout << "List is not empty" << endl;
    }
    */


    return 0;
}