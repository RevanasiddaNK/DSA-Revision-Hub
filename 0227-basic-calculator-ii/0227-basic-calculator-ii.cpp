class Solution {
public:
    int calculate(string s) {
        char op = '+';
        stack<int>st;

        for(int i=0; i<s.size(); i++){

            if(iswspace(s[i]))
                continue;

            if(isdigit(s[i])){
                int n = 0;
                while(i < s.size() && isdigit(s[i])){
                    int n2 = s[i] - '0';
                    n *= 10;
                    n += n2;
                    i++;
                }
                i--;
               
                if(op == '+'){
                    st.push(n);
                    n=0;
                }
                else if(op == '-'){
                    st.push(-1*n);
                    n = 0;
                }
                else if(!st.empty() && op == '*' ){
                    int n1 = st.top();
                    st.pop();
                    st.push(n*n1);
                    n = 0;
                }
                else if(!st.empty() && op == '/' ){
                    int n1 = st.top();
                    st.pop();
                    st.push(n1/n);
                    n=0;
                }
            }
            else{
                op = s[i];
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};