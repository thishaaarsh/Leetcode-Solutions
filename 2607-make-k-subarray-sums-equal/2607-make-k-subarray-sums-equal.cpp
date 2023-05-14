class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans = 1ll*0;
        int n = arr.size();
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                vector<int>temp;
                while(vis[i] == 0){
                    temp.push_back(arr[i]);
                    vis[i] = 1;
                    i = (i+k)%n;
                }
                sort(temp.begin(),temp.end());
                int m = temp.size();
                if(m%2){
                    for(int j = 0; j<temp.size();j++){
                        ans+=abs(temp[j]-temp[temp.size()/2]);
                    }
                }
                else{
                    long long t = 0;
                    long long tt = 0;
                    int mid = temp.size()/2;
                    for(int j=0; j<temp.size();j++){
                        t+=1ll*abs(temp[j]-temp[mid]);
                        tt+=1ll*abs(temp[j]-temp[mid-1]);
                    }
                    ans+=1ll*min(t,tt);
                }
            }
        }
        return ans;
    }
};