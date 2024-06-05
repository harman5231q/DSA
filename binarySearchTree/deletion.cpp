#include"node.cpp"

    int bstMin(Node* root){
        Node* curr=root;
        while(curr!=NULL && curr->left!=NULL ){
            curr=curr->left;
        }
        return curr->data;
    }
    Node* deleteNode(Node* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->data==key){
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            //1 child
            
            //left child
            if(root->left!=NULL && root->right==NULL){
                Node* temp=root->left;
                delete root;
                return temp;
            }

            if(root->left==NULL && root->right!=NULL){
                Node* temp=root->right;
                delete root;
                return temp;
            }

            //2 child
            if(root->left!=NULL && root->right!=NULL){
                int mini=bstMin(root->right);
                root->data=mini;
                root->right= deleteNode(root->right,mini);
            }

        }
        else if(root->data > key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right= deleteNode(root->right,key);
        }
        return root;
        
    }