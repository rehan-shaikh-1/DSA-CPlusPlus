#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    // Create an unordered map: Key -> Value
    unordered_map<string, int> mp;


    // -------- INSERTION --------

    // Method 1: make_pair()
    pair<string, int> p = make_pair("rehan", 1);
    mp.insert(p);

    // Method 2: pair constructor
    pair<string, int> p2("shaikh", 2);
    mp.insert(p2);

    // Method 3: [] operator
    mp["bhai"] = 3;


    // -------- UPDATE --------

    // Update value of an existing key
    mp["bhai"] = 4;


    // -------- ACCESSING --------

    // Access using []
    cout << "rehan: " << mp["rehan"] << endl;

    // Access using at()
    cout << "shaikh: " << mp.at("shaikh") << endl;


    // -------- UNKNOWN KEY --------

    // [] creates the key with default value 0
    cout << "Unknown: " << mp["unknownkey"] << endl;

    // at() throws an error if key doesn't exist
    // cout << mp.at("anotherunknown") << endl;


    // -------- SIZE --------

    // Total number of key-value pairs
    cout << "Size: " << mp.size() << endl;


    // -------- CHECK KEY --------

    // count() returns 1 if key exists, otherwise 0
    cout << "Count for rehan: " << mp.count("rehan") << endl;

    // find() returns iterator to the key
    if (mp.find("rehan") != mp.end()) {
        cout << "rehan is present" << endl;
    } else {
        cout << "rehan is not present" << endl;
    }


    // -------- DELETE --------

    // Remove key and its value
    mp.erase("rehan");

    cout << "Size after erase: " << mp.size() << endl;


    // -------- RANGE-BASED LOOP --------

    // Each element is a key-value pair
    // Order is NOT guaranteed in unordered_map
    cout << "\nUsing range-based loop:" << endl;

    for (auto i : mp) {
        cout << i.first << " " << i.second << endl;
    }


    // -------- ITERATOR --------

    // Iterate using an iterator
    cout << "\nUsing iterator:" << endl;

    unordered_map<string, int>::iterator it = mp.begin();

    while (it != mp.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }


    // -------- ORDERED MAP --------

    // map stores keys in sorted order
    cout << "\nOrdered map (alphabetical order):" << endl;

    map<string, int> ordered_mp;

    ordered_mp["zebra"] = 10;
    ordered_mp["apple"] = 5;

    map<string, int>::iterator idx = ordered_mp.begin();

    while (idx != ordered_mp.end()) {
        cout << idx->first << " " << idx->second << endl;
        idx++;
    }

    return 0;
}