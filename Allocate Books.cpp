#include <bits/stdc++.h>
using namespace std;

// Function to check if we can allocate within `maxTime`
bool isPossible(int n, vector<int>& time, long long maxTime) {
    int daysUsed = 1;  // Start from 1st day
    long long dailyTime = 0;  // Accumulated time for current day

    for (int i = 0; i < time.size(); i++) {
        if (dailyTime + time[i] > maxTime) {  
            // Move to the next day
            daysUsed++;
            dailyTime = time[i];

            if (daysUsed > n) return false; // More days needed than available
        } else {
            dailyTime += time[i];  // Accumulate study time in current day
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {
    long long start = *max_element(time.begin(), time.end()); // Min possible value
    long long end = accumulate(time.begin(), time.end(), 0LL); // Max possible value
    long long ans = end;

    while (start <= end) {
        long long mid = start + (end - start) / 2;

        if (isPossible(n, time, mid)) {
            ans = mid;  // Store the answer
            end = mid - 1; // Try for a smaller maxTime
        } else {
            start = mid + 1; // Increase maxTime
        }
    }
    return ans;
}

// Driver code
int main() {
    int n = 3, m = 5;
    vector<int> time = {10, 20, 30, 40, 50};  // Example input
    cout << "Minimal max time Ayush studies in a day: " << ayushGivesNinjatest(n, m, time) << endl;
    return 0;
}

//  https://www.naukri.com/code360/problems/ayush-and-ninja-test_1097574
