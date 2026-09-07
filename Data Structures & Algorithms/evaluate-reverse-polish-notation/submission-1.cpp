class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calculations;
        for (const string & token : tokens){
            if (token == "+"){
                int first = calculations.top();
                calculations.pop();
                int second = calculations.top();
                calculations.pop();
                calculations.push(first+second);
            } else if (token == "-"){
                int first = calculations.top();
                calculations.pop();
                int second = calculations.top();
                calculations.pop();
                calculations.push(second-first);
            } else if (token == "*"){
                int first = calculations.top();
                calculations.pop();
                int second = calculations.top();
                calculations.pop();
                calculations.push(first*second);
            } else if (token == "/"){
                int first = calculations.top();
                calculations.pop();
                int  second= calculations.top();
                calculations.pop();
                calculations.push(second/first);
            } else{
                calculations.push(stoi(token));
            }

        }
        return calculations.top();
        
    }
};
