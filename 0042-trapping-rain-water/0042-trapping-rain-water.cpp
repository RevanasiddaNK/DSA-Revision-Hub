class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        int n = height.size();
        int leftMax = height[0];
        int rightMax = height[n-1];

        int s=0, e=n-1;

        while(s <= e){

            leftMax = max(leftMax, height[s] );
            rightMax = max(rightMax, height[e] );
            
            if(height[s] < height[e]){
                water += ( min(leftMax, rightMax) - height[s++] );
            }else{
                water += ( min(leftMax, rightMax) - height[e--] );
            }
        }
        return water;
    }
};