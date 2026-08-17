// class Solution {
//     int memo[60][30][30][21][17];

//     void factorize(long long t, int& c2, int& c3, int& c5, int& c7, bool& valid) {
//         c2 = c3 = c5 = c7 = 0;
//         valid = true;
//         while (t % 2 == 0) { c2++; t /= 2; }
//         while (t % 3 == 0) { c3++; t /= 3; }
//         while (t % 5 == 0) { c5++; t /= 5; }
//         while (t % 7 == 0) { c7++; t /= 7; }
//         if (t > 1) valid = false;
//     }

//     void getFactorCounts(int d, int& f2, int& f3, int& f5, int& f7) {
//         f2 = f3 = f5 = f7 = 0;
//         if (d == 2) f2 = 1;
//         else if (d == 3) f3 = 1;
//         else if (d == 4) f2 = 2;
//         else if (d == 5) f5 = 1;
//         else if (d == 6) { f2 = 1; f3 = 1; }
//         else if (d == 7) f7 = 1;
//         else if (d == 8) f2 = 3;
//         else if (d == 9) f3 = 2;
//     }

//     // bool canForm(int pos, int c2, int c3, int c5, int c7) {
//     //     c2 = max(0, c2);
//     //     c3 = max(0, c3);
//     //     c5 = max(0, c5);
//     //     c7 = max(0, c7);

//     //     if (pos == 0) {
//     //         return (c2 == 0 && c3 == 0 && c5 == 0 && c7 == 0);
//     //     }

//     //     if (memo[pos][c2][c3][c5][c7] != -1) {
//     //         return memo[pos][c2][c3][c5][c7];
//     //     }

//     //     bool possible = false;
//     //     for (int d = 1; d <= 9; ++d) {
//     //         int f2, f3, f5, f7;
//     //         getFactorCounts(d, f2, f3, f5, f7);
//     //         if (canForm(pos - 1, c2 - f2, c3 - f3, c5 - f5, c7 - f7)) {
//     //             possible = true;
//     //             break;
//     //         }
//     //     }

//     //     return memo[pos][c2][c3][c5][c7] = possible;
//     // }

//     bool canForm(int pos, int c2, int c3, int c5, int c7) {
//         if (c2 <= 0 && c3 <= 0 && c5 <= 0 && c7 <= 0)
//         return true;

//         if (pos == 0)
//         return false;

//         c2 = max(0, c2);
//         c3 = max(0, c3);
//         c5 = max(0, c5);
//         c7 = max(0, c7);

//         if (c2 > 3 * pos || c3 > 2 * pos || c5 > pos || c7 > pos)
//         return false;

//         if (memo[pos][c2][c3][c5][c7] != -1)
//         return memo[pos][c2][c3][c5][c7];

//         bool possible = false;

//         for (int d = 1; d <= 9; ++d) {
//             int f2, f3, f5, f7;
//             getFactorCounts(d, f2, f3, f5, f7);

//             if (canForm(pos - 1,
//             c2 - f2,
//             c3 - f3,
//             c5 - f5,
//             c7 - f7)) {
//                 possible = true;
//                 break;
//             }
//         }

//         return memo[pos][c2][c3][c5][c7] = possible;
//     }

//     string construct(int len, int c2, int c3, int c5, int c7) {
//         string res = "";
//         for (int pos = len; pos >= 1; --pos) {
//             for (int d = 1; d <= 9; ++d) {
//                 int f2, f3, f5, f7;
//                 getFactorCounts(d, f2, f3, f5, f7);
//                 if (canForm(pos - 1, c2 - f2, c3 - f3, c5 - f5, c7 - f7)) {
//                     res += to_string(d);
//                     c2 = max(0, c2 - f2);
//                     c3 = max(0, c3 - f3);
//                     c5 = max(0, c5 - f5);
//                     c7 = max(0, c7 - f7);
//                     break;
//                 }
//             }
//         }
//         return res;
//     }

//     public:
//     string smallestNumber(string num, long long t) {
//         int req2, req3, req5, req7;
//         bool valid;
//         factorize(t, req2, req3, req5, req7, valid);
//         if (!valid) return "-1";

//         memset(memo, -1, sizeof(memo));

//         int n = num.length();

//         bool numValid = true;
//         int cur2 = 0, cur3 = 0, cur5 = 0, cur7 = 0;
//         for (char ch : num) {
//             if (ch == '0') {
//                 numValid = false;
//                 break;
//             }
//             int f2, f3, f5, f7;
//             getFactorCounts(ch - '0', f2, f3, f5, f7);
//             cur2 += f2; cur3 += f3; cur5 += f5; cur7 += f7;
//         }

//         if (numValid && cur2 >= req2 && cur3 >= req3 && cur5 >= req5 && cur7 >= req7) {
//             return num;
//         }

//         vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
//         vector<bool> hasZero(n + 1, false);

//         for (int i = 0; i < n; ++i) {
//             p2[i + 1] = p2[i];
//             p3[i + 1] = p3[i];
//             p5[i + 1] = p5[i];
//             p7[i + 1] = p7[i];
//             hasZero[i + 1] = hasZero[i];

//             if (num[i] == '0') {
//                 hasZero[i + 1] = true;
//             } else {
//                 int f2, f3, f5, f7;
//                 getFactorCounts(num[i] - '0', f2, f3, f5, f7);
//                 p2[i + 1] += f2;
//                 p3[i + 1] += f3;
//                 p5[i + 1] += f5;
//                 p7[i + 1] += f7;
//             }
//         }

//         for (int i = n - 1; i >= 0; --i) {
//             if (hasZero[i]) continue;

//             int startDigit = num[i] - '0' + 1;
//             for (int d = startDigit; d <= 9; ++d) {
//                 int f2, f3, f5, f7;
//                 getFactorCounts(d, f2, f3, f5, f7);

//                 int rem2 = req2 - (p2[i] + f2);
//                 int rem3 = req3 - (p3[i] + f3);
//                 int rem5 = req5 - (p5[i] + f5);
//                 int rem7 = req7 - (p7[i] + f7);

//                 int remPositions = n - 1 - i;
//                 if (canForm(remPositions, rem2, rem3, rem5, rem7)) {
//                     string prefix = num.substr(0, i);
//                     prefix += to_string(d);
//                     prefix += construct(remPositions, rem2, rem3, rem5, rem7);
//                     return prefix;
//                 }
//             }
//         }

//         for (int targetLen = n + 1; ; ++targetLen) {
//             if (canForm(targetLen, req2, req3, req5, req7)) {
//                 return construct(targetLen, req2, req3, req5, req7);
//             }
//         }

//         return "-1";
//     }
// };




class Solution {
    private:
    void factorize(long long t, int& c2, int& c3, int& c5, int& c7, bool& valid) {
        c2 = c3 = c5 = c7 = 0;
        valid = true;
        while (t % 2 == 0) { c2++; t /= 2; }
        while (t % 3 == 0) { c3++; t /= 3; }
        while (t % 5 == 0) { c5++; t /= 5; }
        while (t % 7 == 0) { c7++; t /= 7; }
        if (t > 1) valid = false;
    }

    void getFactorCounts(int d, int& f2, int& f3, int& f5, int& f7) {
        f2 = f3 = f5 = f7 = 0;
        if (d == 2) f2 = 1;
        else if (d == 3) f3 = 1;
        else if (d == 4) f2 = 2;
        else if (d == 5) f5 = 1;
        else if (d == 6) { f2 = 1; f3 = 1; }
        else if (d == 7) f7 = 1;
        else if (d == 8) f2 = 3;
        else if (d == 9) f3 = 2;
    }

    int getMinDigitsNeeded(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        c5 = max(0, c5);
        c7 = max(0, c7);

        int count = c7 + c5;
        count += c3 / 2;
        int rem3 = c3 % 2;

        count += c2 / 3;
        int rem2 = c2 % 3;

        if (rem2 == 2 && rem3 == 1) {
            count += 2;
        } else if (rem2 == 2 && rem3 == 0) {
            count += 1;
        } else if (rem2 == 1 && rem3 == 1) {
            count += 1;
        } else if (rem2 == 1 && rem3 == 0) {
            count += 1;
        } else if (rem2 == 0 && rem3 == 1) {
            count += 1;
        }

        return count;
    }

    bool canForm(int pos, int c2, int c3, int c5, int c7) {
        return getMinDigitsNeeded(c2, c3, c5, c7) <= pos;
    }

    string construct(int len, int c2, int c3, int c5, int c7) {
        string res = "";
        for (int pos = len; pos >= 1; --pos) {
            for (int d = 1; d <= 9; ++d) {
                int f2, f3, f5, f7;
                getFactorCounts(d, f2, f3, f5, f7);
                if (canForm(pos - 1, c2 - f2, c3 - f3, c5 - f5, c7 - f7)) {
                    res += ('0' + d);
                    c2 -= f2;
                    c3 -= f3;
                    c5 -= f5;
                    c7 -= f7;
                    break;
                }
            }
        }
        return res;
    }

    public:
    string smallestNumber(string num, long long t) {
        int req2, req3, req5, req7;
        bool valid;
        factorize(t, req2, req3, req5, req7, valid);
        if (!valid) return "-1";

        int n = num.length();

        bool numValid = true;
        int cur2 = 0, cur3 = 0, cur5 = 0, cur7 = 0;
        for (char ch : num) {
            if (ch == '0') {
                numValid = false;
                break;
            }
            int f2, f3, f5, f7;
            getFactorCounts(ch - '0', f2, f3, f5, f7);
            cur2 += f2; cur3 += f3; cur5 += f5; cur7 += f7;
        }

        if (numValid && cur2 >= req2 && cur3 >= req3 && cur5 >= req5 && cur7 >= req7) {
            return num;
        }

        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        vector<bool> hasZero(n + 1, false);

        for (int i = 0; i < n; ++i) {
            p2[i + 1] = p2[i];
            p3[i + 1] = p3[i];
            p5[i + 1] = p5[i];
            p7[i + 1] = p7[i];
            hasZero[i + 1] = hasZero[i];

            if (num[i] == '0') {
                hasZero[i + 1] = true;
            } else {
                int f2, f3, f5, f7;
                getFactorCounts(num[i] - '0', f2, f3, f5, f7);
                p2[i + 1] += f2;
                p3[i + 1] += f3;
                p5[i + 1] += f5;
                p7[i + 1] += f7;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            if (hasZero[i]) continue;

            int startDigit = num[i] - '0' + 1;
            for (int d = startDigit; d <= 9; ++d) {
                int f2, f3, f5, f7;
                getFactorCounts(d, f2, f3, f5, f7);

                int rem2 = req2 - (p2[i] + f2);
                int rem3 = req3 - (p3[i] + f3);
                int rem5 = req5 - (p5[i] + f5);
                int rem7 = req7 - (p7[i] + f7);

                int remPositions = n - 1 - i;
                if (canForm(remPositions, rem2, rem3, rem5, rem7)) {
                    string prefix = num.substr(0, i);
                    prefix += ('0' + d);
                    prefix += construct(remPositions, rem2, rem3, rem5, rem7);
                    return prefix;
                }
            }
        }

        int minLen = getMinDigitsNeeded(req2, req3, req5, req7);
        int targetLen = max(n + 1, minLen);
        return construct(targetLen, req2, req3, req5, req7);
    }
};