class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> s;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(s.find(k-arr[i]) != s.end()){
                ans.push_back(s[k-arr[i]]);
                ans.push_back(i);
                return ans;
            }
            else{
                
            s.insert({arr[i],i});
            }
                
        }
        return ans;
        
        
    }
};