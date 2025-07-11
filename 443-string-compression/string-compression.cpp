class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, read = 0;
        while (read < chars.size()) {
            char curr = chars[read];
            int count = 0;
            while (read < chars.size() && chars[read] == curr) {
                read++;
                count++;
            }
            chars[write++] = curr;
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};