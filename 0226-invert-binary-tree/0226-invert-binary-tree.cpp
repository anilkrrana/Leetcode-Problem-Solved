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


//Recursive solution
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (!root) return root;
//         swap(root->left, root->right);
//         invertTree(root->left);
//         invertTree(root->right);
//         return root;
//     }
// };


// Iterative solution

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if (!curr) continue;
            s.push(curr->left);
            s.push(curr->right);
            swap(curr->left, curr->right);
        }
        return root;
    }
};