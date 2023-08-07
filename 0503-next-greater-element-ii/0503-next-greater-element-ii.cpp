class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        stack<int>s;
    //     for(int i = 2*n-1; i>=0; i--){
    //         while(s.empty() == false and s.top() <= nums[i%n]){
    //             s.pop();
    //         }
    //         if(i<n){
    //             int ng = s.empty() ? -1 : s.top();
    //             ans.push_back(ng);
    //         }
    //         s.push(nums[i%n]);
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // 
    for(int i=n-1; i>=0; i--){
        s.push(nums[i]);
    }
    for(int i=n-1; i>=0; i--){
        while(s.empty()==false and s.top()<=nums[i]){
            s.pop();
        }
        int a = s.empty() ? -1 : s.top();
        ans.push_back(a);
        s.push(nums[i]);
    }
    reverse(ans.begin(),ans.end());
        return ans;
    }
};