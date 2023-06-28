class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& ed, int k) {
        vector<vector<int>>arr(n,vector<int>(n,INT_MAX));
        for(auto it:ed){
            arr[it[0]][it[1]] = it[2];
            arr[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++){
            arr[i][i] = 0;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(arr[i][k] == INT_MAX || arr[k][j] == INT_MAX) continue;
                    arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }
        int city = n;
        int ans = -1;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(arr[i][j] <=k){
                    cnt++;
                }
            }
            if(cnt <= city){
                city = cnt;
                ans = i;
            }
        }
        return ans;
    }
};