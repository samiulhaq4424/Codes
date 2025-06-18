class Solution {
private:
    vector<pair<int, int>> ranges;

public:
    Solution(int limit, vector<int>& excluded) {
        sort(excluded.begin(), excluded.end());
        int last = 0;
        for (int num : excluded) {
            if (num - 1 >= last) {
                ranges.emplace_back(last, num - 1);
            }
            last = num + 1;
        }
        if (last <= limit - 1) {
            ranges.emplace_back(last, limit - 1);
        }
    }

    int pick() {
        int rangeIdx = rand() % ranges.size();
        auto [start, end] = ranges[rangeIdx];
        return start + rand() % (end - start + 1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */