class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        //vector<int>ans;
        int n = arr.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(arr[i] > 0)
                st.push(arr[i]);
            else{
                while(!st.empty() and st.top() < -arr[i] and st.top() > 0){
                    st.pop();
                } 
                if(!st.empty() and st.top() == -arr[i] )
                    st.pop();
                else if(!st.empty() and st.top() > -arr[i]){
                    
                }
                else st.push(arr[i]);
            }
        }
        
        vector<int>ans(st.size());
        for(int i = st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
        
    }
};