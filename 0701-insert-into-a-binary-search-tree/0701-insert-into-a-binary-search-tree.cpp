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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode *temp = new TreeNode(val);
            return temp;
        }
        TreeNode *curr = root;
        while(true){
            if(curr->val >= val){
                if(curr->left != NULL) curr = curr->left;
                else{
                    TreeNode *temp = new TreeNode(val);
                    curr->left = temp;
                    break;
                }
            }
            else{
                if(curr->right != NULL) curr = curr->right;
                else{
                    TreeNode *temp = new TreeNode(val);
                    curr->right = temp;
                    break;
                }
            }
        }
        return root;
    }
};