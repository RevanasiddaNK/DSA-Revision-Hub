class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int s=0, e=n-1;
        int area = 0;
        while(s <= e){
            area = max(area, (e-s) * min( height[s], height[e] ) );

            if(height[s] < height[e])
                s++;
            else
                e--;
        }
        return area;
    }
};