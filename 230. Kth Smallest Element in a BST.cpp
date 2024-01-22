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
    int kthSmallest(TreeNode* root, int k) {
    //int totalNoOfNodes = n; 
    //int search = n-k+1 ; 
    int search = k ; 
    TreeNode*curr=root; 
    int ans = 0; 

    while(curr!=NULL){
        if(curr->left==NULL){
            search--; 
            if(search==0) {
                ans=curr->val;
            }
        curr=curr->right;
        }
        else{
            TreeNode*prev= curr->left; 

            //right half to create thread 
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                //no thread created 
                prev->right=curr; 
                curr=curr->left; //move 
            }
            else if(prev->right==curr){
                //thread created 
                search--; 
                if(search==0) {
                    ans=curr->val;
                }
                prev->right=NULL; 
                curr=curr->right;
            }
        }
    }
return ans;
    }
};
