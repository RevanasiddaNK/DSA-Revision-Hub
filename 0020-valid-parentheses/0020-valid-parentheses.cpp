class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(char ch : s){

            char t;
            if(!st.empty()){
                t = st.top();
            }

            if( (ch == '{' || ch == '(') || ch == '['){
                st.push(ch);
            }else if( !st.empty() && (  ( (ch == ')' && t == '(') || (ch == ']' && t == '[') ) || (ch == '}' && t == '{') ) ){
                st.pop();
            }else{
               return 0;
            }
        }
        return st.empty();
    }
};