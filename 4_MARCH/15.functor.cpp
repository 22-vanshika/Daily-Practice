#include <iostream>
using namespace std;

// ================================
// Key Points (Functors)
// ================================
/*
- Functor = class with operator() overloaded
- Acts like a function but is an object
- Used for custom comparison (sorting, priority_queue, etc.)
- Can store state unlike normal functions
- Frequently used in STL algorithms
*/


// ================================
// Functor Example (Basic Comparator)
// ================================

class FunctorOne {
public:
    bool operator()(int a, int b) {
        return a > b; // descending order logic
    }
};


// ================================
// Custom Class (Student)
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
// Functor for Student Comparison
// ================================

class StudentComparator {
public:
    bool operator()(Student a, Student b) {
        return a.marks < b.marks; // compare based on marks
    }
};


int main() {

    // ================================
    // Functor with Primitive Types
    // ================================

    FunctorOne cmp1;

    if (cmp1(10, 5)) {
        cout << "10 is greater than 5" << endl;
    } else {
        cout << "10 is less than 5" << endl;
    }


    // ================================
    // Functor with Custom Objects
    // ================================

    Student s1(93, "love");
    Student s2(97, "lakshay");

    StudentComparator cmp2;

    if (cmp2(s1, s2)) {
        cout << "love k marks lakshay se kam hai" << endl;
    } else {
        cout << "lakshay k marks love se kam hai" << endl;
    }


    // ================================
    // Output
    // ================================
    /*
    10 is greater than 5
    love k marks lakshay se kam hai
    */

    return 0;
}