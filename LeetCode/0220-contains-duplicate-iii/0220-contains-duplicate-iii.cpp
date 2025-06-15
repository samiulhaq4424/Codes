class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2 || k == 0) return false;
        multiset<long> s;
        for (int i = 0; i < n; ++i) {
            if (i > k) s.erase(s.find((long)nums[i - k - 1]));
            long curr = nums[i];
            auto it = s.lower_bound(curr - t);
            if (it != s.end()) {
                long dif = *it - curr;
                if (dif <= t) return true;
            }
            if (it != s.begin()) {
                long dif = curr - *prev(it);
                if (dif <= t) return true;
            }
            s.insert(curr);
        }
        return false;
    }
};