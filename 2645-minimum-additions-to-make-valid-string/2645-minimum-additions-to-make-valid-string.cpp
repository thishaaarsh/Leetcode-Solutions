class Solution {
public:
    int addMinimum(string arr) {
        int n = arr.size();
        int ans = 0;
        int i=0;
        while(i<n){
            int valid = 0;
            if(i<n and arr[i] == 'a'){
                valid++;
                i++;
            }
            if(i<n and arr[i] == 'b'){
                valid++;
                i++;
            }
            if(i<n and arr[i] == 'c'){
                valid++;
                i++;
            }
            ans+=(3-valid);
            
        }
        return ans;
    }
};