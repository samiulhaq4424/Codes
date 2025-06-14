class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream s1(version1 + "."), s2(version2 + ".");
        int n1, n2;
        char dot;
        while (s1.good() || s2.good()) {
            n1 = 0; n2 = 0;
            if (s1 >> n1 >> dot) {}
            if (s2 >> n2 >> dot) {}
            if (n1 < n2) return -1;
            if (n1 > n2) return 1;
        }
        return 0;
    }
};