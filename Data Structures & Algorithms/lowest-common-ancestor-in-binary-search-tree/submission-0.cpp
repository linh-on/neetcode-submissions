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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) 
            return lowestCommonAncestor(root, q, p);
        TreeNode * curr = root;
        while (curr){
            if (p->val == curr->val) return p;
            if(q->val == curr->val) return q;

            if (p->val < curr->val && curr->val < q->val){
                return curr;
            } else if (q->val < curr->val){
                curr = curr->left;
            } else {
                curr = curr->right;
            }

        }
        return root;
        
        
    }
};
