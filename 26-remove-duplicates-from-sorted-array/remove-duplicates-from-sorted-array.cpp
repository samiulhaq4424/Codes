class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int cnt=0;
        for(auto it : nums) {
            st.insert(it);
        }
        
        int indx = 0;
        for(auto it : st) {
            nums[indx] = it;
            indx++;
        }
        return indx;
    }
};