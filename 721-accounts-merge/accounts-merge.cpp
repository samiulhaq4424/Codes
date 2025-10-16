class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mails;
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mails.find(accounts[i][j]) == mails.end()){
                    mails[accounts[i][j]] = i;
                } else {
                    ds.unionBySize(i,mails[accounts[i][j]]);
                }
            }
        }

        vector<string> acc[n];
        for(auto it : mails){
            string str = it.first;
            int parent = ds.findParent(it.second);
            acc[parent].push_back(str);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(acc[i].size() == 0){
                continue;
            }
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(acc[i].begin(),acc[i].end());
            for(auto it : acc[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};