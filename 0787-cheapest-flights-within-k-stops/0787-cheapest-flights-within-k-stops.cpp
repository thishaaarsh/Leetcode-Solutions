class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0; i<arr.size(); i++){
            adj[arr[i][0]].push_back({arr[i][1],arr[i][2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stop > k) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(cost+edW < dist[adjNode] and stop<=k){
                    dist[adjNode] = cost+edW;
                    q.push({stop+1,{adjNode,cost+edW}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};