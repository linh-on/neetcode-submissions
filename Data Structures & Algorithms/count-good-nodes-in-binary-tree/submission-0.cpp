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
    int dfs(TreeNode * curr, int max){
        if (!curr) return 0;
        if (curr->val >= max){
            max = curr->val;
            //+1 to count
            return 1 + dfs(curr->left, max) + dfs(curr->right, max);
        }
        return dfs(curr->left, max) + dfs(curr->right, max);


    }
public:
    int goodNodes(TreeNode* root) {
        return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        
    }
};
