class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int s=0,e=n-1;
        int maxA = 0;
        while(s <= e){
            int hs =  height[s], he =  height[e];
            int temp = min(hs,he)*(e-s);
            maxA = max(maxA, temp);
            if(hs <= he)
                s++;
            else
                e--;
        }
        return maxA;
    }
};