class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int x : nums1) {
            int y = tot - x;
            res += freq2[y];
        }
        return res;
    }
};


/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */