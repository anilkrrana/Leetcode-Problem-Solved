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
    TreeNode* buildActualTree(unordered_map<int, int>& inorderMap, vector<int>& postorder, int inorderLeft, int inorderRight)  
{
    //Base case of recursion
    if(inorderLeft > inorderRight)
        return NULL;

    //Last element of postorder vector is the root of the current (sub)tree
    int rootValue = postorder.at(postorder.size()-1);   
    postorder.pop_back();   //that element won't be used again

    //Create a new node with the value of 'rootValue'
    TreeNode* root = new TreeNode(rootValue);

    //get index of this element in inorder vector
    int inorderRoot = inorderMap[rootValue];
    //remove it from the map becuase it won't be used again; also, subsequent map searches will be quicker
    inorderMap.erase(rootValue);

    //recursively generate right and then left subtrees
    root->right = buildActualTree(inorderMap, postorder, inorderRoot+1, inorderRight);
    root->left = buildActualTree(inorderMap, postorder, inorderLeft, inorderRoot-1);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    //Map: inorderValue -> inorderIndex; Used to find the 'root' in inorder vector quickly
    unordered_map<int, int> inorderMap;

    for(int index = 0; index<inorder.size(); index++)
    {
        inorderMap[inorder.at(index)] = index;
    }

    //the last 2 parameters refer to the range of elements in the inorder vector which would come under the 
    //root of "postorder.end()" 
    return buildActualTree(inorderMap, postorder, 0, inorder.size()-1);
}
};