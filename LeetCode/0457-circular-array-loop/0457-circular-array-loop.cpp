class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        
        auto getNext = [&](int curr) {
            return ((curr + nums[curr]) % n + n) % n;
        };
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue; 
            
            int slow = i, fast = i;
            bool isForward = nums[i] > 0;
            
            do {
                slow = getNext(slow);
                if (nums[slow] * nums[i] < 0) break; 
                fast = getNext(fast);
                if (nums[fast] * nums[i] < 0) break;
                fast = getNext(fast);
                if (nums[fast] * nums[i] < 0) break; 
            } while (slow != fast && fast != -1);
            
            if (slow != fast || slow == getNext(slow)) continue;
            
            int curr = slow;
            int cycleLen = 0;
            do {
                cycleLen++;
                curr = getNext(curr);
            } while (curr != slow);
            
            if (cycleLen > 1) {
                curr = slow;
                bool valid = true;
                do {
                    if (nums[curr] * nums[i] < 0) {
                        valid = false;
                        break;
                    }
                    curr = getNext(curr);
                } while (curr != slow);
                
                if (valid) return true;
            }

            curr = slow;
            do {
                int next = getNext(curr);
                nums[curr] = 0; 
                curr = next;
            } while (curr != slow);
        }
        
        return false;
    }
};