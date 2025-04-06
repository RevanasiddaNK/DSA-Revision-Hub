class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> median;
        multiset<int> low, high;
        
        // Insert the first k elements into low.
        for (int i = 0; i < k; i++) {
            low.insert(nums[i]);
        }
        
        // Balance: ensure low has (k+1)/2 elements.
        while (low.size() > (k + 1) / 2) {
            auto it = prev(low.end());
            high.insert(*it);
            low.erase(it);
        }
        
        // Calculate median for the first window.
        if (low.size() == high.size()) {
            // For even k, median is the average of max(low) and min(high)
            median.push_back((*low.rbegin() + *high.begin()) / 2.0);
        } else {
            // For odd k, median is max(low)
            median.push_back((*low.rbegin()) * 1.0);
        }
        
        // Process each subsequent window.
        for (int i = k; i < nums.size(); i++) {
            int outgoing = nums[i - k];
            // Remove outgoing element safely from either low or high.
            auto it = low.find(outgoing);
            if (it != low.end()) {
                low.erase(it);
            } else {
                it = high.find(outgoing);
                if (it != high.end()) {
                    high.erase(it);
                }
            }
            
            // Insert the new element.
            int incoming = nums[i];
            if (!low.empty() && incoming <= *low.rbegin()) {
                low.insert(incoming);
            } else {
                high.insert(incoming);
            }
            
            // Rebalance: ensure low has exactly (k+1)/2 elements.
            while (low.size() > (k + 1) / 2) {
                auto it = prev(low.end());
                high.insert(*it);
                low.erase(it);
            }
            while (low.size() < (k + 1) / 2 && !high.empty()) {
                // Move the smallest element from high to low.
                auto it = high.begin();
                low.insert(*it);
                high.erase(it);
            }
            
            // Compute median for the current window.
            if (low.size() == high.size()) {
                median.push_back((*low.rbegin() + *high.begin()) / 2.0);
            } else {
                median.push_back((*low.rbegin()) * 1.0);
            }
        }
        return median;
    }
};
