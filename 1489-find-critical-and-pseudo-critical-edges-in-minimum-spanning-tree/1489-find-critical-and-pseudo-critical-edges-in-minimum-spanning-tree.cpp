class DSU{
private:
    vector<int> par, size;
public:
    DSU(int n){
        par = vector<int>(n+1);
        size = vector<int>(n+1);
        for(int i=0; i<=n; i++){
            par[i] = i;
        }
    }
    
    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) 
            return false;
        if(size[a] < size[b]){
            swap(a, b);
        }
        par[b] = a;
        return true;
    }
    
    int find(int node){
        if(par[node] == node){
            return node;
        }
        return par[node] = find(par[node]);
    }
    
    void reset(){
        for(int i=0; i<par.size(); i++){
            par[i] = i;
            size[i] = 1;
        }
    }
};

class Solution {
public:
    int getMstVal(DSU &d, vector<vector<int>>& edges, int n, int skip){
        int mstVal = 0;
        for(int i=0; i<edges.size(); i++){
            if(i == skip) continue;
            if(d.merge(edges[i][0], edges[i][1])){
                mstVal += edges[i][2];
                if(--n == 0){
                    return mstVal;      
                }
            }
        }
        return -1;     //invalid value to respresent disconnected tree
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        //find actual mst value
        
        // I will not use this edge and find mst value to compare
        // If it's same, it means it's not a critical
        // else it's critical
        
        //I will forcefully use this edge, and find mst value to compare
        //If it's same, it's psuedo critical
        //else not
        
        
        // To keep original index of each edge
        int orgIndex = 0;
        for(auto &edge:edges){
            edge.push_back(orgIndex++);
        }
        
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
            return a[2]<b[2];
        });
        
        DSU d(n);
        int actualMst = getMstVal(d, edges, n - 1, -1);
        vector<vector<int>> ans(2);
        for(int i=0; i<edges.size(); i++) {
            d.reset();
            int curMst = getMstVal(d, edges, n - 1, i);
            if(curMst != actualMst){
                ans[0].push_back(edges[i][3]);
                continue;
            }
            
            d.reset();
            d.merge(edges[i][0], edges[i][1]);
            curMst = edges[i][2] + getMstVal(d, edges, n - 2, -1);
            if(curMst == actualMst){
                ans[1].push_back(edges[i][3]);
                continue;
            }
        }
        return ans;
    }
};