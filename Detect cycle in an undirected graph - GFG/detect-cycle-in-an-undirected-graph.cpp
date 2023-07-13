//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to detect cycle in an undirected graph.
    bool solve(int src,vector<int> adj[], int parent, vector<int>&vis ){
        vis[src] = 1;
        for(auto it : adj[src]){
            if(vis[it] == 0){
                if(solve(it,adj,src,vis) == true) return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                if(solve(i,adj,-1,vis) == true) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends