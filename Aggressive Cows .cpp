#include <bits/stdc++.h>
using namespace std;

// Function to check if we can place 'k' cows with at least 'm' distance apart
bool isPossible(int k, vector<int>& stalls, long long m) {
    int lastPlaced = stalls[0]; // Place the first cow at the first stall
    int cowsPlaced = 1; // First cow is already placed

    for (int i = 1; i < stalls.size(); i++) {
        if ((stalls[i] - lastPlaced) >= m) { // Check if we can place a cow
            cowsPlaced++;
            lastPlaced = stalls[i]; // Update the last placed cow's position

            if (cowsPlaced == k) // If all cows are placed successfully
                return true;
        }
    }
    return false; // Not possible to place all cows
}

int aggressiveCows(vector<int>& stalls, int k) {
    // Step 1: Sort the stall positions (Binary search requires sorted data)
    sort(stalls.begin(), stalls.end());

    // Step 2: Define binary search range
    int s = 1; // Minimum possible distance
    int e = stalls.back() - stalls.front(); // Maximum possible distance
    int ans = -1;

    // Step 3: Binary search to maximize the minimum distance
    while (s <= e) {
        int m = s + (e - s) / 2; // Midpoint distance

        if (isPossible(k, stalls, m)) {
            ans = m;  // Update answer if possible
            s = m + 1; // Try for a larger minimum distance
        } else {
            e = m - 1; // Reduce search space
        }
    }
    return ans; // Largest minimum distance found
}

