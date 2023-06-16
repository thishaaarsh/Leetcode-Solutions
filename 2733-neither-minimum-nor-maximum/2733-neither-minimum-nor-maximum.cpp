class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        vector<int>temp;
        for(auto it : s){
            temp.push_back(it);
        }
        sort(temp.begin(),temp.end());
        n = temp.size();
        if(n<=2) return -1;
        else return temp[1];
    }
};