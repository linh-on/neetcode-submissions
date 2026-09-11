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
    int dfs(TreeNode * curr, int & result){
            if (!curr) return 0;

            int left = dfs(curr->left, result);
            int right = dfs(curr->right, result);

            result = max(result, left+right);
            return 1 + max(left, right);
        }
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);

        return result;
        }


        
        
};
