class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";

        for (char ch : path) {
            if (ch == '/') {
                if (curr == "..") {
                    if (!st.empty()) 
                        st.pop();
                }
                else if (!curr.empty() && curr != ".") {
                    st.push(curr); 
                }
                curr = "";
            }
            else {
                curr += ch;
            }
        }

        // Handle any remaining directory after the loop
        if (curr == ".." && !st.empty()) 
            st.pop();
        else if (!curr.empty() && curr != ".") 
            st.push(curr);

        // Construct simplified path
        string ans = "";
        while (!st.empty()) {
            if(st.top() != ".."){
                ans = "/" + st.top() + ans;
            }
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};

/*
TC : O(N)
SC : O(N)
*/
