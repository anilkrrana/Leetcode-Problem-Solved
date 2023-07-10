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
    int minDepth(TreeNode* root) {
            // Base case...
            // If the subtree is empty i.e. root is NULL, return depth as 0...
        if(root == NULL)  return 0;
            // Initialize the depth of two subtrees...
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
            // If the both subtrees are empty...
        if(root->left == NULL && root->right == NULL)
            return 1;
            // If the left subtree is empty, return the depth of right subtree after adding 1 to it...
        if(root->left == NULL)
            return 1 + rightDepth;
            // If the right subtree is empty, return the depth of left subtree after adding 1 to it...
        if(root->right == NULL)
            return 1 + leftDepth;
            // When the two child function return its depth...
            // Pick the minimum out of these two subtrees and return this value after adding 1 to it...
        return min(leftDepth, rightDepth) + 1;    // Adding 1 is the current node which is the parent of the two                                                    subtrees...
    }
};