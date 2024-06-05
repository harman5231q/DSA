#include"binaryTree.cpp"

// Preorder traversal without recursion and without stack  
void morrisTraversalPreorder(Node* root)  
{  
    while (root)  
    {  
        // If left child is null, print the current node data. Move to  
        // right child.  
        if (root->left == NULL)  
        {  
            cout<<root->data<<" ";  
            root = root->right;  
        }  
        else
        {  
            // Find inorder predecessor  
            Node* current = root->left;  
            while (current->right && current->right != root)  
                current = current->right;  
  
            // If the right child of inorder predecessor already points to  
            // this node  
            if (current->right == root)  
            {  
                current->right = NULL;  
                root = root->right;  
            }  
  
            // If right child doesn't point to this node, then print this  
            // node and make right child point to this node  
            else
            {  
                cout<<root->data<<" ";  
                current->right = root;  
                root = root->left;  
            }  
        }  
    }  
} 
 void flattenBinaryTree(Node* root) {
        Node* curr=root;
        while(curr!=NULL){
            if(curr->left){

                Node* pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        
    }

int main(){
    Node* root=NULL;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //1 2 -1 -1 3 -1 -1
    BinaryTree tree;
    root=tree.createTree(root);
    cout<<"Morris Traversal : ";
    morrisTraversalPreorder(root);
    cout<<endl;

 
   // tree.levelOrderTraversal(root)
    cout<<"Inorder traversal : ";
    
    tree.inorder(root);
    
    cout<<endl<<"Preorder traversal : ";
    tree.preorder(root);
    cout<<endl<<"Postorder traversal : ";
    tree.postorder(root);
    cout<<endl;
    cout<<"Reverse level order traversal : ";
    tree.reverseLevelOrder(root);
    cout<<endl;


    return 0;
}