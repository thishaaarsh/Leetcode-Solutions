//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int N) {
        // code here
        long long n = (long long)N;
        long long sn = (long long)(n*(n+1))/2;
        long long s2n = (long long)(n*(n+1)*(2*n+1))/6;
        long long s = 0, s2 = 0;
        for(int i=0; i<n; i++){
            s+=(long long)arr[i];
            s2+= (long long)((long long)arr[i]*(long long)arr[i]);
        }
        long long val1 = s-sn;
        long long val2 = s2-s2n;
        val2 = val2/val1;
        long long x = (val1+val2)/2;
        long long y = x-val1;
        vector <int> ans = {(int)x,(int)y};
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends