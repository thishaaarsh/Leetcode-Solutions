//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool solve(int mid, int arr[], int n, int m){
        int sum = 0;
        int std = 1;
        for(int i=0; i<n; i++){
            if(sum+arr[i] <= mid){
                sum+=arr[i];
            }
            else{
                sum = arr[i];
                std++;
            }
        }
        return std<=m;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m==0) return -1;
        if(m>n) return -1;
        int low = arr[0];
        int high = 0;
        for(int i=0; i<n; i++){
            low = max(low,arr[i]);
            high+=arr[i];
        }
        int ans = -1;
        while(low<=high){
            int mid = (low+high) >> 1;
            if(solve(mid,arr,n,m)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends