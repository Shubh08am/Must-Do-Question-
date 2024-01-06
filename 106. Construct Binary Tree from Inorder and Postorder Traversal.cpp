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
    TreeNode* solve(int inStart,int inEnd,vector<int>& inorder,int postStart,int postEnd,vector<int>& postorder,map<int,int>&inorder_node_to_pos){
        if(inStart>inEnd || postStart>postEnd) return NULL; 

        TreeNode*root= new TreeNode(postorder[postEnd]);
        int inMap = inorder_node_to_pos[postorder[postEnd]];
        int numsLeft = inMap-inStart;

        root->left = solve(inStart,inMap-1,inorder,postStart,postStart+numsLeft-1,postorder,inorder_node_to_pos);

        root->right = solve(inMap+1,inEnd,inorder,postStart+numsLeft,postEnd-1,postorder,inorder_node_to_pos);

    return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inorder_node_to_pos; 
        int n = inorder.size();
        for(int i=0;i<n;i++){
            inorder_node_to_pos[inorder[i]]=i;
        }
        return solve(0,n-1,inorder,0,n-1,postorder,inorder_node_to_pos);
    }
};
