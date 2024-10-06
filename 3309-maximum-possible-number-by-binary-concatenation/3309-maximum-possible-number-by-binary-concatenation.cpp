class Solution {
public:

    string DecimalToBinary(int N){
        string ans = "";
        while(N){
            ans += '0'+ N%2;
            N /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int expOfTwo(int n){
        int ans = 1;
        for(int i=0; i<n; i++)
            ans *= 2;
        return ans;
    }

    int BinaryToDecimal(string S){
        int ans = 0;
        int n = S.size();
        for(int i=0; i<n; i++){
            int digit = S[i] - '0';
            ans += digit * expOfTwo(n-1-i);
        }
        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        string s1 = DecimalToBinary(nums[0]);
        string s2 = DecimalToBinary(nums[1]);
        string s3 = DecimalToBinary(nums[2]);

        int maxDecimal = max({
        BinaryToDecimal(s1 + s2 + s3),
        BinaryToDecimal(s1 + s3 + s2),
        BinaryToDecimal(s2 + s1 + s3),
        BinaryToDecimal(s3 + s1 + s2),
        BinaryToDecimal(s2 + s3 + s1),
        BinaryToDecimal(s3 + s2 + s1)
        });
        return  maxDecimal;
    }
};