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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode* , int>>q;
        q.push({root,0});
        while(!q.empty()){
            int currmin = q.front().second;
            int size = q.size();
            int left,right;
            for(int i=0; i<size; i++){
                int currid = q.front().second-currmin;
                TreeNode* curr = q.front().first;
                q.pop();
                if(i==0) left = currid;
                if(i==size-1) right = currid;
                if(curr->left){
                    q.push({curr->left,2LL*currid+1});
                }
                if(curr->right){
                    q.push({curr->right,2LL*currid+2});
                }
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};