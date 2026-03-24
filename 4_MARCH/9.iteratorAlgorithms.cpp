#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ================================
// Utility Functions
// ================================

void printDouble(int a) {
    cout << 2 * a << " ";
}

bool checkEven(int a) {
    return a % 2 == 0;
}

int main() {

    // ================================
    // Key Points (Iterator Algorithms)
    // ================================
    /*
    - Most STL algorithms work on iterator ranges [begin, end)
    - They do NOT change container size (except erase/remove pattern)
    - Many algorithms return iterators (important to use correctly)
    - Some algorithms rearrange elements (partition, sort, rotate)
    - Always check iterator before dereferencing (avoid runtime errors)
    */


    vector<int> arr = {10, 11, 12, 13, 14, 15};


    // ================================
    // partition (Even first, then odd)
    // ================================

    auto it = partition(arr.begin(), arr.end(), checkEven);

    cout << "Partition: ";
    for (int a : arr) {
        cout << a << " ";
    }
    cout << endl;


    // ================================
    // unique (Remove consecutive duplicates)
    // ================================

    vector<int> arr2 = {1, 1, 2, 2, 3, 3, 3, 4};

    auto it2 = unique(arr2.begin(), arr2.end());
    arr2.erase(it2, arr2.end());

    cout << "Unique: ";
    for (int a : arr2) {
        cout << a << " ";
    }
    cout << endl;


    // ================================
    // Left Rotate
    // ================================

    vector<int> arrL = {1, 2, 3, 4, 5};
    int k1 = 2;

    rotate(arrL.begin(), arrL.begin() + k1, arrL.end());

    cout << "Left Rotate by " << k1 << ": ";
    for (int x : arrL) cout << x << " ";
    cout << endl;


    // ================================
    // Right Rotate
    // ================================

    vector<int> arrR = {1, 2, 3, 4, 5};
    int k2 = 2;

    rotate(arrR.begin(), arrR.end() - k2, arrR.end());

    cout << "Right Rotate by " << k2 << ": ";
    for (int x : arrR) cout << x << " ";
    cout << endl;


    // ================================
    // sort & reverse
    // ================================

    vector<int> arr4 = {5, 2, 8, 1, 3};

    sort(arr4.begin(), arr4.end());

    cout << "Sorted: ";
    for (int a : arr4) {
        cout << a << " ";
    }
    cout << endl;

    reverse(arr4.begin(), arr4.end());

    cout << "Reversed: ";
    for (int a : arr4) {
        cout << a << " ";
    }
    cout << endl;


    // ================================
    // count & count_if
    // ================================

    int evenCount = count_if(arr.begin(), arr.end(), checkEven);
    cout << "Even count: " << evenCount << endl;

    int target = 11;
    int freq = count(arr.begin(), arr.end(), target);
    cout << "Frequency of " << target << ": " << freq << endl;


    // ================================
    // find & find_if
    // ================================

    auto it3 = find_if(arr.begin(), arr.end(), checkEven);

    if (it3 != arr.end()) {
        cout << "First even: " << *it3 << endl;
    }

    auto it4 = find(arr.begin(), arr.end(), target);

    if (it4 != arr.end()) {
        cout << "Found target: " << *it4 << endl;
    }


    // ================================
    // for_each
    // ================================

    cout << "Double values: ";
    for_each(arr.begin(), arr.end(), printDouble);
    cout << endl;


    return 0;
}