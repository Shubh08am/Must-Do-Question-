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
    map<TreeNode*,map<int,int>>dp;
    int zigzag(TreeNode*root,int moveDir){
        bool left=0,right=1;
        if(!root) return 0;
        //if(dp[root][moveDir]>0) return dp[root][moveDir] ;
        if(dp.find(root)!=dp.end() && dp[root].find(moveDir)!=dp[root].end()) return dp[root][moveDir];
        if(moveDir==left){
            //now move right
            return dp[root][moveDir] = 1+zigzag(root->left,right);
        }
        else if(moveDir==right){
            //now move left
            return dp[root][moveDir]  = 1+zigzag(root->right,left);
        }
    return dp[root][moveDir] =1;
    }
    void preorder(TreeNode*root,int&ans){
        bool left=0,right=1;
        if(!root) return;
        if(root->right){
            //pass that node and try moving left 
            ans=max(ans,zigzag(root->right,left)); 
        }
        if(root->left){
            //pass that node and try moving right 
            ans=max(ans,zigzag(root->left,right)); 
        }
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        preorder(root,ans);
        return ans;
    }
};
