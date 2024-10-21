class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '[')
                stack.push(ch);
            else{
                if(stack.empty() )
                    return 0;
                char top = stack.top();
                if( (top == '(' && ch == ')' ) || (top == '{' && ch == '}' ) || (top == '[' && ch == ']' )  ){
                    stack.pop();
                }
                else{
                    return 0;
                }
            }
        }

        if(!stack.empty()){
            return 0;
        }
        else
            return 1;


    }
};