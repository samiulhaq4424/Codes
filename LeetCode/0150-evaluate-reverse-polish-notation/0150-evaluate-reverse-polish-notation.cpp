class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        for (auto& u : tokens) {
            if (u == "+" || u == "-" || u == "*" || u == "/") {
                long x = s.top(); s.pop();
                long y = s.top(); s.pop();
                if (u == "+") s.push(y + x);
                else if (u == "-") s.push(y - x);
                else if (u == "*") s.push(y * x);
                else s.push(y / x);
            } else {
                s.push(stoi(u));
            }
        }
        return s.top();
    }
};