class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto it : tasks){
            mp[it]++;
        }
        priority_queue<int>q;
        for(auto it : mp){
            q.push(it.second);
        }
        int ans = 0;
        while(q.empty() == false){
            
            //int i=0;
            if(q.size() > n){
                vector<int>temp;
                for(int i=0;i<=n; i++){
                    int a = q.top();
                    q.pop();
                    a--;
                    ans++;
                    if(a>0) temp.push_back(a);
                }
                for(int i=0; i<temp.size(); i++){
                    q.push(temp[i]);
                }
                //ans+=n;
            }
            else{
                vector<int>temp;
                int size = q.size();
                while(q.empty() == false){
                    int a = q.top();
                    q.pop();
                    a--;
                    if(a>0) temp.push_back(a);
                }
                for(int i=0; i<temp.size(); i++){
                    q.push(temp[i]);
                }
                if(q.size() > 0) ans+=n+1;
                else ans+=size;
            }
        }
        return ans;
    }
};