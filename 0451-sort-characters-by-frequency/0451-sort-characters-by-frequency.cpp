class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto it : mp){
            q.push({it.second,it.first});
        }
        string ans = "";
        while(!q.empty()){
            int fre = q.top().first;
            char ch = q.top().second;
            q.pop();
            while(fre){
                ans.push_back(ch);
                fre--;
            }
        }
        return ans;
    }
};