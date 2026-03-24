🔹 map
Stores keys in sorted order (by default ascending)
Implemented using Red-Black Tree
All operations → O(log n)
Keys are unique
table[key] → creates key if not present (important!)

🔹 unordered_map
Uses hashing (hash table)
Average → O(1) operations
Worst case → O(n) (collisions)
No order guaranteed
Faster than map in most cases

🔥 Subtle but important (many miss)
map → always sorted → good for ordered traversal
unordered_map → no order → faster lookups

🔥 Critical gotcha
table[key]:
If key exists → returns value
If NOT → creates new key with default value ⚠️

👉 Use find() when you don’t want accidental insertion

🔥 When to use what
Need ordering → map
Need speed → unordered_map
Competitive coding → mostly unordered_map
Edge cases / worst-case safety → map

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {

    // ================================
    // Ordered Map (map)
    // ================================

    map<int, string> table;

    table.insert(make_pair(3, "Love"));
    table.insert(make_pair(1, "Anita"));
    table.insert(make_pair(2, "Babita"));

    // Traversal (always sorted by key)
    for (auto it = table.begin(); it != table.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }


    // ================================
    // Map Operations
    // ================================

    /*
    map<string, string> table;

    // Insertion
    table["in"] = "India";
    table.insert(make_pair("en", "England"));

    pair<string, string> p;
    p.first = "br";
    p.second = "Brazil";
    table.insert(p);

    cout << "Size: " << table.size() << endl;

    // Searching
    if (table.count("im") == 0) {
        cout << "Key not found" << endl;
    }

    if (table.find("im") != table.end()) {
        cout << "Key found" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    // Access
    cout << table.at("in") << endl;

    table["in"] = "India3";
    cout << table.at("in") << endl;

    // Deletion
    table.erase(table.begin(), table.end());
    cout << "Size after erase: " << table.size() << endl;

    // Clear
    table.clear();

    if (table.empty()) {
        cout << "Map is empty" << endl;
    } else {
        cout << "Map is not empty" << endl;
    }
    */


    // ================================
    // Unordered Map (Hash Map)
    // ================================

    /*
    unordered_map<int, string> um;

    um[3] = "Love";
    um[1] = "Anita";
    um[2] = "Babita";

    // Traversal (NOT sorted)
    for (auto &p : um) {
        cout << p.first << " " << p.second << endl;
    }
    */


    return 0;
}