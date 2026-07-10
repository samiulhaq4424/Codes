class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; i++) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[sorted_nodes[i].second] = i;
        }

        int LOG = 18;
        vector<vector<int>> st(n, vector<int>(LOG));

        int r = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && sorted_nodes[r].first - sorted_nodes[l].first <= maxDiff) {
                r++;
            }
            st[l][0] = r - 1;
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (u > v) {
                swap(u, v);
            }

            int steps = 0;
            for (int j = LOG - 1; j >= 0; j--) {
                if (st[u][j] < v) {
                    u = st[u][j];
                    steps += (1 << j);
                }
            }

            if (st[u][0] >= v) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};