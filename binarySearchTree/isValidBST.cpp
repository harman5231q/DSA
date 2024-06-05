#include"node.cpp"
#include<vector>

class Solution {
    void solve(Node* root,vector<int> &ans){
        if(root==NULL)
            return ;


        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
public:
    bool isValidBST(Node* root) {
        vector<int> ans;
        solve(root ,ans);
        int n=ans.size();
        int i=0;
        int j=1;
        while(j<n){
            if(ans[i++]>=ans[j++])
                return false;
        }
        return true;

    }
};