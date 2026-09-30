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
    unordered_map<int, int> inorderIndexes;
    int pre = 0;
    TreeNode * build(vector<int>& preorder, int lo, int hi){
        if (lo > hi) return nullptr;
        TreeNode * root = new TreeNode(preorder[pre++]);

        int mid = inorderIndexes[root->val]; //find the break point

        root->left = build(preorder, lo, mid-1);
        root->right = build(preorder, mid+1, hi);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            inorderIndexes[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1);
        
        
    }
};
