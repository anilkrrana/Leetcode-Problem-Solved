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
    int sumNumbers(TreeNode* root, int num=0) {
        return root->left == root->right ? num * 10 + root->val :
            ((root->left ? sumNumbers(root->left, num * 10 + root->val) : 0) + 
            (root->right ? sumNumbers(root->right, num * 10 + root->val) : 0));
    }
};




// Method: DFS [T(n) = O(n) and S(n) = O(H) [recursion stack space]]
// Idea is to use DFS (Top Down) and generate number (starting with 0) going root to leaf. At each level, we have: currNum = prevNum * 10 + root->val. We compute this number for both left and right subtrees and finally return the sum of both subtree numbers.
// Base case: root->left == root->right (only possbile for leaf node).

// Dry Run:
// Suppose Binary Tree is:
// 		1
// 	  /    \
// 	2       3
// 		  /
// 		4
// Let func. name be DFS (for explaination only).
// DFS(1) = DFS(2, 1) + DFS(3, 1)
// DFS(2, 1) = 10 + 2 = 12     // Base case
// DFS(3, 1) = DFS(4, 10 + 3) + 0 = DFS(4, 13)
// DFS(4, 13) = 130 + 4 = 134    // Base Case
// => DFS(1) = 12 + 134 = 146
// NOTE:

// Below code (sumNumbers func. implementation) is actually 1 liner, Only for readability, I have presented it in 3 lines.
// This problem is a perfect example of how we can use already known solution(s) to solve a new problem. The below solution is very similar to 4th Nov 2021 Daily LC Challenge here on leetcode.
