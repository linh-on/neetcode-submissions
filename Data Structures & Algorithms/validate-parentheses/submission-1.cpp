class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        for (char c : s){
            if (c == '(' || c == '[' || c == '{'){
                myStack.push(c);
            } else{
                if (myStack.empty()) return false;
                char check = myStack.top();
                if ((c == ')') && (check != '(')){
                    return false;
                } else if ((c == ']') && (check != '[')){
                    return false;
                }
                else if ((c == '}') && (check != '{')){
                    return false;
                } 
                else
                {
                    myStack.pop();
            }
        }
            }
        
        if (myStack.empty()) {
            return true;
        } else{
            return false;
        }
    
    }
};
