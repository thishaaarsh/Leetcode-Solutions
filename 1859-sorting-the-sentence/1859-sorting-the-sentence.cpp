class Solution {
public:
    string sortSentence(string s) {
        reverse(s.begin(),s.end());
        vector<string>arr;
        string a = "";
        for(int i=0; i<s.size();i++){
            if(s[i] == ' '){
                arr.push_back(a);
                a = "";
            }
            else
                a.push_back(s[i]);
        }
        arr.push_back(a);
        sort(arr.begin(),arr.end());
        string ans = "";
        for(int i=0; i<arr.size();i++){
            reverse(arr[i].begin(),arr[i].end());
            for(int j=0; j<arr[i].size()-1;j++){
                ans.push_back(arr[i][j]);
            }
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
        
        
    }
};