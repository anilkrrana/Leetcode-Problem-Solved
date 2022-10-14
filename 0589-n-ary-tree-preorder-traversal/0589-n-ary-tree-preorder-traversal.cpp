/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Solution {
// public:
//       void preorder(Node* root, vector<int> &res) {
//         if(root == NULL){
//             return;
//         }
//         res.push_back(root->val);
//         for (Node* ch: root->children) {
//             preorder(ch,res);
//         }
//         return ;
//     }
    
//     vector<int> preorder(Node* root) {
//         vector<int> res;
//         preorder(root,res);
//         return res;
    
//     }
  
// };



class Solution {
public:
      vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root,res);
        return res;
     }
    void preorder(Node* root, vector<int> &res) {
        if(root == NULL){
            return;
        }
        res.push_back(root->val);
        for (Node* ch: root->children) {
            preorder(ch,res);
        }
        return ;
    }
  
};