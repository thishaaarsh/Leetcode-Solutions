class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int a = 0;
        int b = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            int c = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    c++;
                }
            }
            if(c > b){
                b = c;
                a = i;
            }
        }
        vector<int>arr =  {a,b};
        return arr;
    }
};