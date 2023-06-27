class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int clr = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
       // vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        //vis[sr][sc] = 1;
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,1,-1};
        image[sr][sc] = color;
        if(clr == color) return image;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow >= 0 and ncol >= 0 and nrow < n and ncol < m 
                   and image[nrow][ncol] == clr){
                   // vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};