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
    TreeNode *build(vector<int>&arr, int &i, int bound ){
        if(i==arr.size() || arr[i] > bound) return NULL;
        TreeNode *root = new TreeNode(arr[i++]);
        root->left = build(arr,i,root->val);
        root->right = build(arr,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i =0;
        return build(arr,i,INT_MAX);
    }
};