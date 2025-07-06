class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            } else if (c == ']') {
                int repeat = numStack.top();
                numStack.pop();
                string temp = strStack.top();
                strStack.pop();
                string repeatedStr = "";
                for (int i = 0; i < repeat; i++) {
                    repeatedStr += currStr;
                }
                currStr = temp + repeatedStr;
            } else {
                currStr += c;
            }
        }
        
        return currStr;
    }
};