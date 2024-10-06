class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prevSmaller(n,0);
        vector<int>nextSmaller(n,0);
        stack<int>st;
        for(int i=0; i<n; i++){

            while(!st.empty() && heights[st.top()] >= heights[i]  )
                st.pop();
            if(st.empty())
                prevSmaller[i] = 0;
            else
                prevSmaller[i] = st.top()+1;
            st.push(i);

        }

        while(!st.empty())
            st.pop();

        for(int i=n-1; i>=0 ; i--){

            while(!st.empty() && heights[st.top()] >= heights[i]  )
                st.pop();
            if(st.empty())
                nextSmaller[i] = n-1;
            else
                nextSmaller[i] = st.top()-1;

            st.push(i);

        }

        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int area =  (nextSmaller[i] - prevSmaller[i] + 1) *heights[i];
            maxA = max(maxA ,area);
        }

        return maxA;

    }
};