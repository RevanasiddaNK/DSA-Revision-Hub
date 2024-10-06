#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <cstdlib>
using namespace std;

class RandomizedCollection {
public:
    unordered_map<int, set<int>> mp;  // stores the value and the set of indices in the array
    vector<int> arr;                  // stores the values

    RandomizedCollection() {
        mp.clear();
        arr.clear();
    }

    bool insert(int val) {
        arr.push_back(val);           // Insert the value at the end of the array
        mp[val].insert(arr.size() - 1); // Insert the index into the set for this value

        // If it's the first occurrence of the value, return true; otherwise, false
        return mp[val].size() == 1;
    }

    bool remove(int val) {
        // Check if the value exists in the map
        auto it = mp.find(val);
        if (it != mp.end() && !mp[val].empty()) {
            int i = *mp[val].begin(); // Get the index of the element to be removed
            int lastVal = arr.back(); // Get the last value in the array

            // Swap the element to be removed with the last element in the array
            swap(arr[i], arr[arr.size() - 1]);

            // Remove the last element from the array
            arr.pop_back();

            // Update the map for the swapped element (lastVal)
            mp[lastVal].erase(arr.size());  // Remove the old index of the last element
            mp[val].erase(i);               // Remove the index of the removed element

            if (i < arr.size()) {
                mp[lastVal].insert(i);       // Update the index to the swapped position
            }

            // If val has no more indices in the map, erase it completely
            if (mp[val].empty()) {
                mp.erase(val);
            }

            return true;
        }

        return false; // If value not found, return false
    }

    int getRandom() {
        int random_index = rand() % arr.size(); // Generate a random index
        return arr[random_index];               // Return the element at that index
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedCollection* obj = new RandomizedCollection();
    
    // Test insertions
    cout << obj->insert(10) << endl;  // Output: 1 (true)
    cout << obj->insert(20) << endl;  // Output: 1 (true)
    cout << obj->insert(30) << endl;  // Output: 1 (true)
    cout << obj->insert(10) << endl;  // Output: 0 (false, duplicate)
    
    // Test removals
    cout << obj->remove(20) << endl;  // Output: 1 (true)
    cout << obj->remove(10) << endl;  // Output: 1 (true)
    cout << obj->remove(10) << endl;  // Output: 1 (true, last occurrence of 10)
    
    // Test random element selection
    cout << obj->getRandom() << endl; // Output: Random value from the remaining elements
    
    return 0;
}
