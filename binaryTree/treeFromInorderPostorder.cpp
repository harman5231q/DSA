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

    TreeNode* solve(vector<int> post,vector<int> in,int &index,int start,int end,map<int,int> &inorderIndex,int n){
        if(index<0 || start>end){
            return NULL;
        }
        //taking the last element
        int element=post[index--];
        //making the new node
        TreeNode* root=new TreeNode(element);
        //finding the positio of root in inorder by mapping
        int position=inorderIndex[element];
        // first right because in post order the right side element come first
        root->right=solve(post,in,index,position+1,end,inorderIndex,n);
        root->left=solve(post,in,index,start,position-1,inorderIndex,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=postorder.size();
        int index=size-1;
        map<int,int> inorderIndex;
        mapping(inorder,inorderIndex,size);
        TreeNode* root=solve(postorder,inorder,index,0,size-1,inorderIndex,size);
        return root;   
        
    }
};