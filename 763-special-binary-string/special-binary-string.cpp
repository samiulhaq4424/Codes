class Solution {
public:
    string makeLargestSpecial(string input) {
        if (input.empty()) return "";
        
        vector<string> segments;
        int balance = 0, start = 0;
        for (int end = 0; end < input.size(); end++) {
            balance += input[end] == '1' ? 1 : -1;
            
            if (balance == 0) {
                string inner = makeLargestSpecial(input.substr(start + 1, end - start - 1));
                segments.push_back('1' + inner + '0');
                start = end + 1;
            }
        }
        
        sort(segments.begin(), segments.end(), greater<string>());
        string result;
        for (const auto& segment : segments) {
            result += segment;
        }
        
        return result;
    }
};