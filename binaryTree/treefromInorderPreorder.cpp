#include<vector>
#include<map>
#include<iostream>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;

    TreeNode(int n){

    }
};
class Solution {
    private:
    void mapping(vector<int> inorder,map<int,int> &inorderIndex,int n){
        for(int i=0;i<n;i++){
            inorderIndex[inorder[i]]=i;
        }
    }

    TreeNode* solve(vector<int> pre,vector<int> in,int &index,int start,int end,map<int,int> &inorderIndex,int n){
        if(index>=n || start>end){
            return NULL;
        }
        int element=pre[index++];
        TreeNode* root=new TreeNode(element);
        int position=inorderIndex[element];

        root->left=solve(pre,in,index,start,position-1,inorderIndex,n);
        root->right=solve(pre,in,index,position+1,end,inorderIndex,n);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        int index=0;
        map<int,int> inorderIndex;
        mapping(inorder,inorderIndex,size);
        TreeNode* root=solve(preorder,inorder,index,0,size-1,inorderIndex,size);
        return root;   
    }
};