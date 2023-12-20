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
    void dfs(TreeNode*root,long long currSum,long long targetSum,int &path,unordered_map<long long,long long>&mp){
        if(!root) return;
        currSum+=root->val;
        path+=mp[currSum-targetSum];
        // freq increase later only  
        // ex:- root = [1] and target = 0 than curr_Sum=1 and currsum-target=1 and mp[1]=1 (freq increase before) 
        // path = 1 but actually path=0 thus later freq increase 
        mp[currSum]++; 
        dfs(root->left,currSum,targetSum,path,mp);
        dfs(root->right,currSum,targetSum,path,mp);
        mp[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int path=0;
        unordered_map<long long,long long>mp;
        mp[0]=1;
        dfs(root,0,targetSum,path,mp);
        return path;
    }
};

/*
class Solution {
public:
    void dfs(TreeNode*root,long long targetSum,int &path){
        if(!root) return;
        if(targetSum==root->val) {
            path++;
        }
        dfs(root->left,targetSum-root->val,path);
        dfs(root->right,targetSum-root->val,path);
    }
    void pre(TreeNode*root,long long  targetSum,int &path){
        if(!root) return;
        dfs(root,targetSum,path);
        pre(root->left,targetSum,path);
        pre(root->right,targetSum,path);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int path=0;
        pre(root,targetSum,path);
        return path;
    }
};
*/
/*
class Solution {
public:
    void dfs(TreeNode*root,long long targetSum,int &path){
        if(!root) return;
        if(targetSum==root->val) {
            path++;
        }
        long long left_sum = targetSum-root->val;
        dfs(root->left,left_sum,path);
        dfs(root->right,left_sum,path);
    }
    int pre(TreeNode*root,int targetSum){
        if(!root) return 0;
        int path=0;
        dfs(root,targetSum,path);
        return  path + pre(root->left,targetSum) + pre(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        return pre(root,targetSum);
    }
};
*/
