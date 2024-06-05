#include<vector>
#include<map>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int n){

    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        // Map to store nodes for each column and row
        map<int, map<int, vector<int>>> columns;
        
        // Queue for BFS traversal
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        //traversal
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            TreeNode* node = current.first;
            int row = current.second.first;
            int col = current.second.second;
            
            columns[col][row].push_back(node->val);
            
            if (node->left)
                q.push({node->left, {row + 1, col - 1}});
            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }
        
        // Construct the result
            for (auto i : columns) {
                vector<int> colNodes;
                for (auto j : i.second) {
                    sort(j.second.begin(), j.second.end());
                    for (int val : j.second) {
                        colNodes.push_back(val);
                    }
                }
                result.push_back(colNodes);
            }
                    
        return result;
    }
};