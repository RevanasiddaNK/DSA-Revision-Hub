class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> nextSmR(n, n);
        vector<int> nextSmL(n, -1);  // Missing in your code, declare here

        // Find next smaller element to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            nextSmR[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Clear stack to reuse for next smaller element to the left
        while (!st.empty()) st.pop();

        // Find next smaller element to the left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            nextSmL[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int width = nextSmR[i] - nextSmL[i] - 1;
            int area = h * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxRect = 0;
        for(int base=0; base<m; base++){
            vector<int>heights(n,0);
            for(int i=0; i<n ;i++){
                if(matrix[base][i] == '1')
                    heights[i] += 1;
            }

            for(int r=base+1; r<m; r++){
                for(int c=0; c<n; c++){
                    if(matrix[r][c] == '1' && r-base == heights[c] ){
                        heights[c] += 1;
                    }
                }
            }
            int rect = largestRectangleArea(heights);
            maxRect = max(maxRect, rect);

        }
        return maxRect;
    }
};