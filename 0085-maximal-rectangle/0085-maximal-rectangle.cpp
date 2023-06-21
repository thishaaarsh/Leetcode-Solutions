class Solution {
public:
    int solve(vector<int>& arr) {
        int ans = 0;
        stack<int>st;
        int n = arr.size();
        for(int i=0; i<n; i++){
            while(!st.empty() and arr[st.top()] >= arr[i]){
                int curr = st.top();
                st.pop();
                int temp = arr[curr] * ((st.empty()) ? i : (i-st.top()-1));
                ans = max(ans,temp);
            }
           st.push(i);
        }
         while(!st.empty()){
                int curr = st.top();
                st.pop();
                int temp = arr[curr] * (st.empty() ? n : (n-st.top()-1));
                ans = max(ans,temp);
            }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int>v(m,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++ ){
                if(mat[i][j] == '1'){
                    v[j]++;
                }
                else
                    v[j] = 0;
            }
            ans = max(ans,solve(v));
        }
        return ans;
    }
};