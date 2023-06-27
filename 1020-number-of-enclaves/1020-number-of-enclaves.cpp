class Solution {
public:
    void solve(int row, int col, vector<vector<int>>&vis,vector<vector<int>>& grid){
        vis[row][col] = 1;
        int delrow[] = {0,0,-1,1};
        int delcol[] = {1,-1,0,0};
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 and ncol >=0 and nrow<grid.size() and ncol < grid[0].size() and
              !vis[nrow][ncol] and grid[nrow][ncol] == 1){
                solve(nrow,ncol,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       // queue<pair<int,int>>q;
        for(int i=0; i<m; i++){
            if(!vis[0][i] and grid[0][i] == 1){
                //q.push({0,i});
                //vis[0][i] = 1;
                solve(0,i,vis,grid);
            }
            if(!vis[n-1][i] and grid[n-1][i] == 1){
                //q.push({n-1,i});
               // vis[n-1][i] = 1;
                solve(n-1,i,vis,grid);
            } 
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] and grid[i][0] == 1){
                //q.push({i,0});
                //vis[i][0] = 1;
                solve(i,0,vis,grid);
            }
            if(!vis[i][m-1] and grid[i][m-1] == 1){
                //q.push({i,m-1});
                //vis[i][m-1] = 1;
                solve(i,m-1,vis,grid);
            }
        }
       
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(!vis[i][j] and grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};