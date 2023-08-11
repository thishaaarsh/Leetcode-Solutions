class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int i = 0, j = arr[0].size()-1;
        while(i<arr.size() and j>=0){
            if(arr[i][j] == k) return true;
            else if(arr[i][j] > k){
                j--;
            }
            else i++;
        }
        return false;
    }
};