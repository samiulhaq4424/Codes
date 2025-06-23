class Solution {
public:
    vector<vector<int>> graph;
    int used[12];
    int n;
    int result = 0;

    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        graph.resize(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double sum_sqrt = sqrt(nums[i] + nums[j]);
                if (sum_sqrt == (int)sum_sqrt)
                    graph[i].push_back(j);
            }
        }

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            used[i] = 1;
            explore(nums, i, 1);
            used[i] = 0;
        }

        return result;
    }

private:
    void explore(vector<int>& nums, int curr, int cnt) {
        if (cnt == n) {
            result++;
            return;
        }
        int prev_val = -1;
        for (int next : graph[curr]) {
            if (used[next]) continue;
            if (nums[next] == prev_val) continue;
            used[next] = 1;
            explore(nums, next, cnt + 1);
            prev_val = nums[next];
            used[next] = 0;
        }
    }
};