class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
       priority_queue<int> max_heap;
       priority_queue<int, vector<int>, greater<int>> min_heap;
       unordered_map<int, int> lazy_counts;
       vector<double> ans;

       int max_size = 0;
       int min_size = 0;

       auto prune = [&](auto& heap) {
        while (!heap.empty() && lazy_counts[heap.top()] > 0) {
            lazy_counts[heap.top()]--;
            heap.pop();
        }
       };

       for (int i = 0; i < nums.size(); i++) {
        if (max_heap.empty() || nums[i] <= max_heap.top()) {
            max_heap.push(nums[i]);
            max_size++;
        } else {
            min_heap.push(nums[i]);
            min_size++;
        }

        if (max_size > min_size + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_size--;
            min_size++;
        } else if (max_size < min_size) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            max_size++;
            min_size--;
        }

        prune(max_heap);
        prune(min_heap);

        if (i >= k - 1) {
            if (k % 2 != 0) {
                ans.push_back((double)max_heap.top());
            } else {
                ans.push_back(((double)max_heap.top() + (double)min_heap.top()) / 2.0);
            }

            int out = nums[i - k + 1];
            lazy_counts[out]++;

            if (out <= max_heap.top()) {
                max_size--;
            } else {
                min_size--;
            }

            if (max_size > min_size + 1) {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_size--;
                min_size++;
            } else if (max_size < min_size) {
                max_heap.push(min_heap.top());
                min_heap.pop();
                max_size++;
                min_size--;
            }

            prune(max_heap);
            prune(min_heap);
        }
       }

       return ans;

    }
};