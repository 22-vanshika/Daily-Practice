#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// ================================
// Key Points (Custom Comparator / Functors)
// ================================
/*
- Custom comparator defines sorting or priority logic
- Return true → first argument should come before second
- Used in sort() and priority_queue
- For priority_queue → comparator defines priority (not sorting)
- Can handle complex conditions (multiple fields)
*/


// ================================
// Student Class
// ================================

class Student {
public:
    int marks;
    string name;

    Student() {}

    Student(int m, string n) {
        marks = m;
        name = n;
    }
};


// ================================
// Comparator for Student (Sort)
// ================================

class StudentSortComparator {
public:
    bool operator()(Student a, Student b) {
        if (a.marks == b.marks) {
            return a.name < b.name;   // ascending name
        }
        return a.marks > b.marks;     // descending marks
    }
};


// ================================
// Comparator for Integers (Sort)
// ================================

class IntComparator {
public:
    bool operator()(int a, int b) {
        return a > b; // descending order
    }
};


// ================================
// Comparator for Priority Queue
// ================================

class StudentPQComparator {
public:
    bool operator()(Student a, Student b) {
        return a.marks < b.marks; // max heap based on marks
    }
};


int main() {

    // ================================
    // Sorting Custom Objects
    // ================================

    vector<Student> students = {
        {90, "Love"},
        {90, "Lakshay"},
        {95, "Kunal"}
    };

    sort(students.begin(), students.end(), StudentSortComparator());

    cout << "Sorted Students:" << endl;
    for (auto s : students) {
        cout << s.marks << " " << s.name << endl;
    }


    // ================================
    // Sorting Integers
    // ================================

    vector<int> arr = {20, 10, 15};

    sort(arr.begin(), arr.end(), IntComparator());

    cout << "Sorted Integers: ";
    for (int x : arr) cout << x << " ";
    cout << endl;


    // ================================
    // Priority Queue with Custom Objects
    // ================================

    priority_queue<Student, vector<Student>, StudentPQComparator> pq;

    pq.push(Student(90, "Love"));
    pq.push(Student(27, "Lakshay"));
    pq.push(Student(99, "Amit"));
    pq.push(Student(82, "Sharma"));

    cout << "Priority Queue Output:" << endl;

    while (!pq.empty()) {
        cout << pq.top().marks << " " << pq.top().name << endl;
        pq.pop();
    }


    // ================================
    // Output
    // ================================
    /*
    Sorted Students:
    95 Kunal
    90 Lakshay
    90 Love

    Sorted Integers: 20 15 10

    Priority Queue Output:
    99 Amit
    90 Love
    82 Sharma
    27 Lakshay
    */

    return 0;
}