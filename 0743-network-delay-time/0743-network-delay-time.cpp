class Solution {
public:
    int networkDelayTime(vector<vector<int>>& arr, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0; i<arr.size();i++){
            adj[arr[i][0]].push_back({arr[i][1],arr[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>q;
        q.push({0,k});
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        while(!q.empty()){
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                if(dis+edgeW < dist[adjNode]){
                    dist[adjNode] = dis+edgeW;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};