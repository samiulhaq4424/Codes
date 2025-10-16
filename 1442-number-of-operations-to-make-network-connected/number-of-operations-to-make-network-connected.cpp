class DisjointSet {
  private:
  vector<int> parent,size;
  
  public:
  DisjointSet(int n){
	  parent.resize(n);
	  size.resize(n);
	  for(int i=0;i<n;i++){
		  parent[i]=i;
		  size[i]=i;
	  }
  }

  int findParent(int u){
	  if(u == parent[u]){
		  return u;
	  }
	  return parent[u]=findParent(parent[u]);
  }

  void unionBySize(int u, int v){
	  int ulp_u = findParent(u);
	  int ulp_v = findParent(v);
	  if(size[ulp_u] >= size[ulp_v]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countExtraEdges = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) == ds.findParent(v)){
                ++countExtraEdges;
            } else {
                ds.unionBySize(u,v);
            }
        }

        int countComp = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i) == i){
                ++countComp;
            }
        }

        if(countExtraEdges >= countComp-1){
            return countComp-1;
        } else {
            return -1;
        }
    }
};