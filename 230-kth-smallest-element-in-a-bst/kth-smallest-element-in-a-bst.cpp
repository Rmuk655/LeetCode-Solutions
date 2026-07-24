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
    void inorder(TreeNode* Node, vector<int> &vec){
        if(Node == nullptr){
            return ;
        }
        inorder(Node->left, vec);
        vec.push_back(Node->val);
        inorder(Node->right, vec);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        return vec[k - 1];
    }
};