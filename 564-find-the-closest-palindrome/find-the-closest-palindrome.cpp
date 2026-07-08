class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1) return to_string(stoll(n) - 1);

        vector<long long> cand;

        long long p1 = 1;
        for (int i = 0; i < len - 1; i++) p1 *= 10;
        cand.push_back(p1 - 1);
        cand.push_back(p1 * 10 + 1);

        long long pref = stoll(n.substr(0, (len + 1) / 2));

        for (int i = -1; i <= 1; i++) {
            string p = to_string(pref + i);
            string s = p;
            if (len % 2 != 0) s.pop_back();

            int l = 0, r = s.size() - 1;
            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
            cand.push_back(stoll(p + s));
        }

        long long num = stoll(n);
        long long ans = -1;
        long long minD = -1;

        for (long long c : cand) {
            if (c == num) continue;
            long long d = abs(c - num);
            if (minD == -1 || d < minD || (d == minD && c < ans)) {
                minD = d;
                ans = c;
            }
        }

        return to_string(ans);
    }
};