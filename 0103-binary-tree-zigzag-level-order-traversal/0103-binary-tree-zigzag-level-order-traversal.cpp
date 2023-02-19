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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty()){
           int sz=q.size();
           vector<int>v(sz);
           int j=0,n=sz;
           while(sz--){
               TreeNode * f=q.front();
               q.pop();
               if(i%2==0)
               v[j]=f->val;
               else v[n-j-1]=f->val;
               j++;
               if(f->left)q.push(f->left);
               if(f->right)q.push(f->right);
           }
           i++;
           ans.push_back(v);

        }
        return ans;
    
    }
};