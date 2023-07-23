//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node, vector<int>&vis, vector<int>&pathVis,vector<int> adj[], vector<int>&safeNode ){
      vis[node] = 1;
      pathVis[node] =1;
      safeNode[node] = 0;
      for(auto it  : adj[node]){
          if(!vis[it]){
              if(dfs(it,vis,pathVis,adj,safeNode) == true) return true;
          }
          else if(pathVis[it]) return true;
      }
      pathVis[node] = 0;
      safeNode[node] =1;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>ans;
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>safeNode(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,adj,safeNode);
            }
        }
        for(int i=0; i<V; i++){
            if(safeNode[i]){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends