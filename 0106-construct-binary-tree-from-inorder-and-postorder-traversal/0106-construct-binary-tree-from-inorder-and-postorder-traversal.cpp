/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& in, int is, int ie, vector<int>& po, int ps, int pe, 
                    unordered_map<int,int>&mp){
        if(ps>pe || is>ie) return NULL;
        TreeNode *root = new TreeNode(po[pe]);
        int inroot = mp[root->val];
        int left = inroot-is;
        root->left = solve(in,is,inroot-1, po, ps, ps+left-1,mp);
        root->right = solve(in, inroot+1, ie, po, ps+left, pe-1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        if(in.size() != po.size()) return NULL;
        unordered_map<int,int>mp;
        for(int i=0; i<in.size();i++){
            mp[in[i]] = i;
        }
        return solve(in, 0, in.size()-1, po, 0, po.size()-1, mp);
    }
};