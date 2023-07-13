class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        if(arr[0][0] == 1 || arr[n-1][n-1] == 1) return -1;
        if(n==1) return 1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dis = node.first;
            int row = node.second.first;
            int col = node.second.second;
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow >=0  and ncol >= 0  and nrow < n and ncol < n and 
                       dis+1 < dist[nrow][ncol] and arr[nrow][ncol] == 0){
                        dist[nrow][ncol] = dis+1;
                        if(nrow == n-1 and ncol == n-1) return dist[nrow][ncol];
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
        
    }
};