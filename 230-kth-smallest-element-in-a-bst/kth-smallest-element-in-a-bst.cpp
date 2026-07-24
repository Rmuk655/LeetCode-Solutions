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
        else if(Node->left == nullptr && Node->right == nullptr){
            vec.push_back(Node->val);
            return;
        }
        // TreeNode* prev;
        // while(Node != nullptr && Node->left != nullptr){
        //     prev = Node;
        //     Node = Node->left;
        // }
        inorder(Node->left, vec);
        vec.push_back(Node->val);
        inorder(Node->right, vec);
        // if(Node->left != nullptr){
        //     vec.push_back(Node->left->val);
        // }
        // vec.push_back(Node->val);
        // if(Node->right != nullptr){
        //     vec.push_back(Node->right->val);
        // }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        return vec[k - 1];
    }
};