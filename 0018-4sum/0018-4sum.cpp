class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                unordered_set<long long>ss;
                for(int k=j+1; k<n; k++){
                    long long sum = (long long)nums[i]+(long long)nums[j];
                    sum+=nums[k];
                    long long last = (long long)(target-sum);
                    if(ss.find(last) != ss.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k],(int)last};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                        
                    }
                    ss.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};