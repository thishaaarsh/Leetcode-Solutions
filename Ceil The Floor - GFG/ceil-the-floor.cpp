//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int low = -1;
    int hi = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] <= x){
            low = max(low,arr[i]);
        }
        if(arr[i] >= x){
            hi = min(hi,arr[i]);
        }
    }
    pair<int,int>v;
    v.first = low;
    if(hi!=INT_MAX) v.second = hi;
    else v.second = -1;
    return v;
}