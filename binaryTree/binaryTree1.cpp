#include"Node.cpp"

#include<queue>

#include<stack>

class BinaryTree{
    Node* root;
    public:
    BinaryTree(){
        this->root=NULL;
    }

    void createTreeUsingLevelOrder(){
        cout<<"Enter data for root node "<<endl;
        int data;
        cin>>data;
        root=new Node(data);

        queue<Node*> q;

        q.push(root);

        Node* temp=NULL;
        int newData;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            cout<<"Enter the data for left node of : "<<temp->data<<endl;

            cin>>newData;
            if(newData!=-1){
                temp->left=new Node(newData);
                q.push(temp->left);
            }
            cout<<"Enter the data for right node of : "<<temp->data<<endl;

            cin>>newData;
            if(newData!=-1){
                temp->right=new Node(newData);
                q.push(temp->right);
            }

        }     
    }

    void levelOrderTraversal(){
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

    void inorder(){
        //LRN
        stack<Node*> st;

        Node* curr= root;

        while(curr!=NULL || !st.empty()){


            //traverse to the left most node
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }


            //now the curr has reached the left most node which is null
            //now we have to point curr to the previous node before reaching to that state

            curr=st.top();
            st.pop();

            //now curr holds the left most node which has the data
            //lets print that data

            cout<<curr->data<<' ';


            //now we have traveled LN so we have to travel for R

            curr=curr->right;
        }
    }

    void preorder(){
        //NLR
        if(root==NULL){
            return;
        }
        stack<Node*> st;
        //first we have to print the node so push the rootNode
        st.push(root);

        //creating node for traversal
        Node* curr= NULL;
        while(!st.empty()){
            //getting the node from top to process
            curr=st.top();
            st.pop();
            //firstly printing which is N then traversing
            cout<<curr->data<<" ";


            //firstly traversing the right means R becaue we are using a stack 
            //first in last out 
            //pushing the right first so that it processed out last
            if(curr->right){
                st.push(curr->right);
            }

            //then traversing L which is left so that it comes first
            //pushing the left last so that it processed out first
            if(curr->left){
                st.push(curr->left);
            }
        }

    }

    void postorder(){
        if(root==NULL){
            return;
        }
        stack<Node*> st;
        st.push(root);

        Node* curr= NULL;
        //we have to create this stack to store the values
        stack<int> res;
        while(!st.empty()){
            curr=st.top();
            st.pop();


            //pushing the result into the another stack
            //so the node which goes first comes out last

            res.push(curr->data);


            //pushing the left first so that it processed out last
            if(curr->left){
                st.push(curr->left);
            }
            //pushing the right last so that it processed out first
            if(curr->right){
                st.push(curr->right);
            }
        }
        //printing the values present in result stack
        while(!res.empty()){
            cout<<res.top()<<" ";
            res.pop();
        }


    }
};

int main(){
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    //1 2 -1 -1 3 -1 -1
    BinaryTree tree;
    
    tree.createTreeUsingLevelOrder();
    tree.levelOrderTraversal();

    cout<<"Inorder traversal : ";
    tree.inorder();
    cout<<endl<<"Preorder traversal : ";
    tree.preorder();
    cout<<endl<<"Postorder traversal : ";
    tree.postorder();
    cout<<endl;

    //cout<<"Reverse level order traversal : ";
    //tree.reverseLevelOrder(root);
    cout<<endl;


    return 0;
}