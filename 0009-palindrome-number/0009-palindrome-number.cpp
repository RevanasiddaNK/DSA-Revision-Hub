class Solution {
public:

    int reverse(int x) {
        
        long long rev=0;

        while(x != 0){
            int d = x%10;
            rev = rev*10+d;
            x /= 10;
        }
          return (rev < INT_MIN || rev > INT_MAX) ? 0 : (int)rev;
    }

    bool isPalindrome(int x) {
        if(x <0)
            return 0;
        int rev = reverse(x);
        return rev == x;
    }
};