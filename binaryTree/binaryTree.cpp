#include"Node.cpp"
#include<queue>
#include<stack>

class BinaryTree{
    public:

    Node* createTree(Node* root){
        cout<<"enter data"<<endl;
        int d;
        cin>>d;
        root=new Node(d);
        if(d==-1){
            return NULL;
        }
        cout<<"enter the value for left child of "<<d<<endl;
        root->left= createTree(root->left);
        cout<<"Enter the value for the right of "<<d<<endl;
        root->right= createTree(root->right);

        return root;
    }

    void levelOrderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        Node* temp=NULL;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

        }
    }
    void reverseLevelOrder(Node* root){
        if(root==NULL){
            return;
        }

        queue<Node*> q;
        q.push(root);
        stack<Node*> st;
        Node* temp=NULL;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            st.push(temp);

            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
        while(!st.empty()){
            cout<<st.top()->data<<" ";
            st.pop();
        }
    }

    void inorder(Node* root){
        if(root==NULL){
            return ;
        }

        inorder(root->left);
        cout<<root->data<<' ';
        inorder(root->right);
    }
    void preorder(Node* root){
        if(root==NULL){
            return ;
        }
        cout<<root->data<<' ';

        preorder(root->left);

        preorder(root->right);
    }

    void postorder(Node* root){
        if(root==NULL){
            return ;
        }

        postorder(root->left);

        postorder(root->right);
    
        cout<<root->data<<' ';    
    }


};


