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

// class Solution {
// public: 
//     vector<int>store;

//      void dfs(TreeNode* node){ //dfs traversal
//          if(node==NULL) return;
//          store.push_back(node->val);
//          dfs(node->left);       //left call
//          dfs(node->right);      //right call
//       } 


//     int minDiffInBST(TreeNode* root) {
//         dfs(root);             //function calling
//         sort(store.begin(),store.end());
//         int result=INT_MAX;  
//         for(int i=0;i+1<store.size();++i){  //finding two no such that their differnce is minimum
//              if(store[i+1]-store[i]<result){
//                 result=store[i+1]-store[i];
//              }
//         }
//         return result;;
//     }
// };

class Solution {
public:
    void helper(TreeNode* r,vector<int>&v)
    {
        if(r==NULL)return;
        helper(r->left,v);
        v.push_back(r->val);
        helper(r->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>v;
        helper(root,v);
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
        
    }
};