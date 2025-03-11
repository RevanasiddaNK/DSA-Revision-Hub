#include <bits/stdc++.h>
using namespace std;

// Function to check if we can allocate within `maxTime`
bool isPossible(int n, vector<int>& time, long long maxTime) {
    int daysUsed = n; 
    long long dailyTime = 0;  

    for (int i = 0; i < time.size(); i++) {
        if (dailyTime + time[i] > maxTime) {  
            
            daysUsed--;
            dailyTime = time[i];

            if (daysUsed <=  0) return false;
        } else {
            dailyTime += time[i];
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
            ans = mid;  
            end = mid - 1; 
        } else {
            start = mid + 1; 
        }
    }
    return ans;
}


