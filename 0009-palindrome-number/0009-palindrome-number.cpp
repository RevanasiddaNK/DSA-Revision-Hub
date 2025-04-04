class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return 0;
        long long rev = 0;
        int n = x;
        while(n > 0){
            int d = n%10;
            rev = rev*10+d;
            n /= 10;
        }
        return x == rev;
    }
};