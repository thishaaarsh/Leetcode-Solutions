//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPos(int mid, vector<int>&arr,int n, int k){
        int c = 1;
        int last = arr[0];
        for(int i=0;i<n; i++){
            if(arr[i]-last >= mid){
                c++;
                last = arr[i];
            }
            if(c >= k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &arr) {
    
        // Write your code here
        sort(arr.begin(),arr.end());
        int l = 1;
        int h = arr[n-1]-arr[0];
        int ans = 1;
        while(l<=h){
            int mid = (l+h) >> 1;
            if(isPos(mid,arr,n,k)){
                l = mid+1;
                ans = l;
            }
            else
                h = mid-1;
        }
        return h;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends