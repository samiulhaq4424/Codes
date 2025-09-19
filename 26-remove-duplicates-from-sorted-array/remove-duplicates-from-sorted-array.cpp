class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int cnt=0;
        for(auto it : nums) {
            st.insert(it);
        }
        nums.clear();
        for(auto it : st) {
            nums.push_back(it);
            ++cnt;
        }
        return cnt;
    }
};