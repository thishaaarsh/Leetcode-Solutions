//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int>adj[],vector<int>&vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        vector<int>arr[n];
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                if(adj[i][j]){
                    arr[i].push_back(j);
                }
            }
        }
        int ans = 0;
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,arr,vis);
                ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends