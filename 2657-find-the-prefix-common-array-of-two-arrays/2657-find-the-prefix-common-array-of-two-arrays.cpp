class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n);
        
        unordered_set<int>ss;
        for(int i=0; i<n; i++){
            ss.insert(A[i]);
        }
        for(int i=n-1; i>=0; i--){
            ans[i] = ss.size();
            ss.erase(A[i]);
            ss.erase(B[i]);
        }
        return ans;
    }
};