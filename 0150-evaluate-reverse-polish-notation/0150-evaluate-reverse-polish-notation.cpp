class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> Stack;
        for(auto e : tokens) {
            if(e == "+" || e == "-" || e == "*" || e == "/") {
                long long op1 = Stack.top();
                Stack.pop();
                long long op2 = Stack.top();
                Stack.pop();

                if(e == "+") Stack.push(op2 + op1);
                else if(e == "-") Stack.push(op2 - op1);
                else if(e == "*") Stack.push(op2 * op1);
                else if(e == "/") Stack.push(op2 / op1);
            }
            else {
                Stack.push(stoi(e));
            }
        }

        return Stack.top();
    }
};