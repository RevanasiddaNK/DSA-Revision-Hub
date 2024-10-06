class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
       int s=0, e=n-1;

       while(s < e){
            int h1 = height[s];
            int h2 = height[e];
            int w = e-s;
            int h = min(h1,h2);
            area = max(area, w*h);

            if(h1 > h2)
                e--;
            else
                s++;

       }
       return area;
    }
};