/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }
        
        stack<NestedInteger> stk;
        int num = 0;
        int sign = 1;
        bool hasNum = false;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (c == '[') {
                stk.push(NestedInteger());
            } else if (c == '-' || isdigit(c)) {
                if (c == '-') {
                    sign = -1;
                } else {
                    num = num * 10 + (c - '0');
                    hasNum = true;
                }
            } else if (c == ',' || c == ']') {
                if (hasNum) {
                    stk.top().add(NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    hasNum = false;
                }
                if (c == ']' && !stk.empty()) {
                    NestedInteger curr = stk.top();
                    stk.pop();
                    if (!stk.empty()) {
                        stk.top().add(curr);
                    } else {
                        return curr;
                    }
                }
            }
        }
        
        return hasNum ? NestedInteger(sign * num) : stk.top();
    }
};