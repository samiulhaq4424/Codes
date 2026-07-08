class Solution {
public:
    string addStrings(string N1, string N2) {
        string ans = "";
        int i = N1.size() - 1;
        int j = N2.size() - 1;
        int c = 0;

        while (i >= 0 || j >= 0 || c > 0) {
            int sum = c;
            if (i >= 0) {
                sum += N1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += N2[j] - '0';
                j--;
            }
            c = sum / 10;
            ans += to_string(sum % 10);
        }

        int l = 0;
        int r = ans.size() - 1;
        while (l < r) {
            char tmp = ans[l];
            ans[l] = ans[r];
            ans[r] = tmp;
            l++;
            r--;
        }

        return ans;
    }
};