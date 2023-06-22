class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n = arr.size();
        int m = arr[0].size();
        int i=0;
        int j = m-1;
        while(i<n and j>=0){
            if(arr[i][j] == x) return true;
            else if(arr[i][j] > x) j--;
            else i++;
        }
        return false;
    }
};