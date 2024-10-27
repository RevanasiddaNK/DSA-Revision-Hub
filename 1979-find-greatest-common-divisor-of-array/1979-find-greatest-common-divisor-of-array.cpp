class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = INT_MAX, b = INT_MIN;
        for(int i : nums){
            a = min(a, i);
            b = max(b,i);
        }

        int d = a%b;
        while(d != 0){
            d = a % b;
            a = b;
            b = d;
        }
        return a;
    }
};