class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string curr = "";
        for(char ch : path){
            
            if(ch == '/'){
                if(curr == ".." && !st.empty())
                    st.pop();
                else if( !curr.empty() && curr != "." && curr != "..")
                    st.push(curr);
                
                curr = ""; 
            }
            else
                curr += ch;
        }

        if(curr == ".."  && !st.empty()){
            st.pop();
        }
        else if (!curr.empty() && curr != "." && curr != "..") {
            st.push(curr);
        }
    
        string ans = "";

        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;

    }
};