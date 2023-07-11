/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markPer(TreeNode *root, unordered_map<TreeNode*, TreeNode*>&trackper){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left){
                trackper[curr->left] = curr;
                q.push(curr->left);
            }
                
            if(curr->right){
                trackper[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>trackper;
        markPer(root,trackper);
        int currlev = 0;
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;
        vis[target] = true;
        while(q.empty() == false){
            int size = q.size();
            if(currlev++ == k)
                break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left and !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right and !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(trackper[curr] and !vis[trackper[curr]]){
                    q.push(trackper[curr]);
                    vis[trackper[curr]] = true;
                }
            }
        }
        vector<int>ans;
        while(q.empty() == false){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};