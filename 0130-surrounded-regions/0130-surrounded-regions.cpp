class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&vis,vector<vector<char>>& arr){
        vis[row][col]= 1;
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,1,-1};
        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 and ncol >= 0  and nrow < arr.size() and ncol < arr[0].size() and 
              !vis[nrow][ncol] and arr[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,arr);
            }
        }
    }
    void solve(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<m; i++){
            if(!vis[0][i] and arr[0][i] == 'O'){
                dfs(0,i,vis,arr);
            }
            if(!vis[n-1][i] and arr[n-1][i] == 'O'){
                dfs(n-1,i,vis,arr);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] and arr[i][0] == 'O'){
                dfs(i,0,vis,arr);
            }
            if(!vis[i][m-1] and arr[i][m-1] == 'O'){
                dfs(i,m-1,vis,arr);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] and arr[i][j] == 'O'){
                    arr[i][j] = 'X';
                }
            }
        }
       // return arr;
    }
};