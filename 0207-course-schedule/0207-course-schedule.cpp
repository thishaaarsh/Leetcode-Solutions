class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int>adj[n];
        for(int i=0; i<arr.size();i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int>indeg(n,0);
        for(int i=0; i<n; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        return cnt == n;
    }
};