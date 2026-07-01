class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int t) {
        vector<vector<int>> r;
        int n = v.size();
        if (n < 4) return r;
        
        sort(v.begin(), v.end());
        
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && v[i] == v[i - 1]) continue;
            if ((long long)v[i] + v[i + 1] + v[i + 2] + v[i + 3] > t) break;
            if ((long long)v[i] + v[n - 3] + v[n - 2] + v[n - 1] < t) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && v[j] == v[j - 1]) continue;
                if ((long long)v[i] + v[j] + v[j + 1] + v[j + 2] > t) break;
                if ((long long)v[i] + v[j] + v[n - 2] + v[n - 1] < t) continue;
                
                int x = j + 1;
                int y = n - 1;
                
                while (x < y) {
                    long long s = (long long)v[i] + v[j] + v[x] + v[y];
                    if (s == t) {
                        r.push_back({v[i], v[j], v[x], v[y]});
                        while (x < y && v[x] == v[x + 1]) x++;
                        while (x < y && v[y] == v[y - 1]) y--;
                        x++;
                        y--;
                    } else if (s < t) {
                        x++;
                    } else {
                        y--;
                    }
                }
            }
        }
        
        return r;
    }
};