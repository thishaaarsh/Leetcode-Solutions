//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &v, int N){
        vector<int>arr(v.begin(),v.end());
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int temp = 1;
        for(int i=0; i<N;i++){
            if(mp[arr[i]] == 0 ){
                mp[arr[i]] = temp;
                temp++;
            }
        }
        vector<int>ans;
        for(int i=0; i<N; i++){
            ans.push_back(mp[v[i]]);
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends