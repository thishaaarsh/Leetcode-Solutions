class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();
        if(n==0) return false;
        int i=0,j=m-1;
        while(i<n and j>=0){
            if(arr[i][j] == k) return true;
            else if(arr[i][j] > k){
                j--;
            }
            else
                i++;
        }
        return false;
    }
};