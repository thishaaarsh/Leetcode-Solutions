class Solution {
public:
    void solve(vector<int> adj[], vector<int>&vis, int node){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(auto it : adj[a]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

    void solve2(vector<int> adj[], vector<int>&vis, int src){
        vis[src] = 1;
        for(auto it : adj[src]){
            if(!vis[it]){
                solve2(adj,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] == 1 and i!=j){
                    adj[i].push_back(j);
                   // adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                solve2(adj,vis,i);
            }
        }
        return ans;

    }
};