class Solution {
public:
    string reverseWords(string data) {
        stringstream s(data);
        string str;
        //getline(str,s,' ');
        vector<string>ans;
        while(s>>str){
            ans.push_back(str);
            //getline(str,s," ");
        }
        reverse(ans.begin(),ans.end());
        string ss = "";
        for(int i=0; i<ans.size(); i++){
            ss+=ans[i];
            ss+=" ";
        }
        ss.pop_back();
        return ss;
    }
};