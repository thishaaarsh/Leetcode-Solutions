class Solution {
public:
    bool dfs(int node, vector<vector<int>>adj, int clr,vector<int>&vis){
        vis[node] = clr;
        for(auto it : adj[node]){
            if(vis[it] == -1){
                if(dfs(it,adj,!clr,vis) == false) return false;
            }
            else if(vis[it] == clr) return false;
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>adj) {
        int n = adj.size();
        vector<int>vis(n,-1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(dfs(i,adj,1,vis) == false) return false;
            }
        }
        return true;
    }
};