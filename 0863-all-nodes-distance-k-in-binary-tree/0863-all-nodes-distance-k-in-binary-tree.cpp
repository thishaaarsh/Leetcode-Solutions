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
    void trackper(TreeNode* root,unordered_map<TreeNode *, TreeNode *> &mp){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr->left){
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root == NULL) return ans;
        unordered_map<TreeNode *, TreeNode *> mp;
        trackper(root,mp);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        int dis = 0;
        while(q.empty() == false){
            if(dis == k) break;
            dis++;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left and !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right and !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(mp[node] and !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
            
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};