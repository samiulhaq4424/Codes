class Solution {
public:
    int thirdMax(vector<int>& N) {
       long long m1 = LONG_MIN;
       long long m2 = LONG_MIN;
       long long m3 = LONG_MIN;

       for (int i= 0; i < N.size(); i++) {
        int v = N[i];
        if (v == m1 || v == m2 || v == m3) {
            continue;
        }

        if (v > m1) {
            m3 = m2;
            m2 = m1;
            m1 = v;
        } else if (v > m2) {
            m3 = m2;
            m2 = v;
        } else if (v > m3) {
            m3 = v;
        }
       }

       if (m3 == LONG_MIN) {
        return m1;
       }
       return m3;
    }
};