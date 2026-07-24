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
    void inorder(TreeNode* root, vector<int> &inorder_tree){
        if(root == nullptr){
            return;
        }
        inorder(root->left, inorder_tree);
        inorder_tree.push_back(root->val);
        inorder(root->right, inorder_tree);
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return true;
        }
        vector<int> inorder_tree;
        inorder(root, inorder_tree);
        vector<int> sorted_inorder_tree = inorder_tree;
        sort(sorted_inorder_tree.begin(), sorted_inorder_tree.end());
        for(int i = 1; i < sorted_inorder_tree.size(); i++){
            if(sorted_inorder_tree[i] == sorted_inorder_tree[i - 1]){
                return false;
            }
        }
        return inorder_tree == sorted_inorder_tree;
    }
};