class Solution {
public:
    void bfs(int node, vector<int>adj[], vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it: adj[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n  = arr.size();
        vector<int>adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(n,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                bfs(i,adj,vis);
            }
        }
        return ans;
    }
};