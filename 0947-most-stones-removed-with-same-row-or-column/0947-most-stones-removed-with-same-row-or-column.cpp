class DisjointSet{
    vector<int>parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findUpar(int n){
            if(n == parent[n]) return n;
            return parent[n] = findUpar(parent[n]);
        }
        
        void unionBySize(int u, int v){
            int uu = findUpar(u);
            int uv = findUpar(v);
            if(uu==uv) return ;
            if(size[uu] > size[uv]){
                parent[uv] = uu;
                size[uu]+=size[uv];
            }
            else{
                parent[uu] = uv;
                size[uv]+=size[uu];
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& arr) {
        int mrow = 0, mcol = 0;
        for(auto it : arr){
            mrow = max(mrow,it[0]);
            mcol = max(mcol,it[1]);
        }
        DisjointSet ds(mrow+mcol+1);
        unordered_map<int,int>mp;
        for(auto it:arr){
            int row = it[0];
            int col = it[1]+mrow+1;
            ds.unionBySize(row,col);
            mp[row] = 1;
            mp[col] = 1;
        }
        int com = 0;
        // for(auto it:arr){
        //     int row = it[0];
        //     int col = it[1]+mrow+1;
        //     //ds.unionBySize(row,col);
        //     if(ds.findUpar(row) == row) com++;
        //     if(ds.findUpar(col) == col) com++;
        // }
        for(auto it : mp){
            if(ds.findUpar(it.first) == it.first) com++;
        }
        return arr.size()-com;
    }
};