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
    int dfs(TreeNode * curr, bool & check){
        if (!curr) return 0;
        int left = dfs(curr->left, check);
        int right = dfs(curr->right, check);
        if (abs(left-right) > 1){
            check = false;
        }
        return 1 + max(left, right);

    }
public:
    bool isBalanced(TreeNode* root) {
        bool check = true;
        dfs(root, check);
        return check;

        
    }
};
