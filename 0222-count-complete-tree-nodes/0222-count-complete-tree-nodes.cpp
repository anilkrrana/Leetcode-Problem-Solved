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
    int countNodes(TreeNode* root) {


        if(!root) return 0;

        int x=0, y=0;

        TreeNode *l=root, *r=root;

        while(l) {x++;l=l->left;}

        while(r) {y++;r=r->right;}

        if(y==x) return pow(2,y)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }
};