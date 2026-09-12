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
private:
    bool dfs(TreeNode * curr, int min, int max){
        if (!curr) return true;
        if (curr->val <= min || curr->val >= max) 
            return false;
        return dfs(curr->left, min, curr->val) && dfs(curr->right, curr->val, max);   
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, -1000000000, 1000000000);
        
    }
};
