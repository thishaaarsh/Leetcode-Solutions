class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int ans = 0;
        stack<int>s;
        for(int i=0; i<arr.size();i++){
            while(s.empty() == false and arr[s.top()] >= arr[i]){
                int tp = s.top();
                s.pop();
                int idx = s.empty() ? i : i-s.top()-1;
                ans = max(ans,arr[tp]*idx);
            }
            s.push(i);
        }
        int n = arr.size();
        while(s.empty() == false){
            int tp = s.top();
            s.pop();
            int idx = s.empty() ? n : n-s.top()-1;
            ans = max(ans,arr[tp]*idx);
        }
        return ans;
    }
};