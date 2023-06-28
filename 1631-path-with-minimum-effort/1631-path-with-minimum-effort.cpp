class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        int delrow[] = {1,-1,0,0};
        int delcol[] = {0,0,1,-1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 and col == m-1) return diff;
            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow >=0 and ncol >=0 and nrow < n and ncol < m){
                    int newdiff = max(diff,abs(arr[row][col]-arr[nrow][ncol]));
                    if(newdiff < dist[nrow][ncol]){
                        dist[nrow][ncol] = newdiff;
                        pq.push({newdiff,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};