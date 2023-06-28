class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int ans = 1;
        q.push({0,0});
        vis[0][0] = 1;
        //int delrow[] = {-1,1,0,0};
        //int delcol[] = {0,0,1,-1};
        if(arr[0][0] == 1 || arr[n-1][m-1] == 1) return -1;
        if(n==1 and m == 1) return 1;
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int k=0; k<size; k++){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int j=-1; j<=1; j++){
                for(int i=-1; i<=1; i++){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow == n-1 and ncol == m-1) return ans;
                    if(nrow >=0 and ncol >=0 and nrow<n and ncol <m and 
                        !vis[nrow][ncol] and arr[nrow][ncol] == 0){
                            q.push({nrow,ncol});
                            vis[nrow][ncol] = 1;
                     }
                }
            
            }
        }
        
        }
        return -1;
    }
};