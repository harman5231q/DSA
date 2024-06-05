#include"node.cpp"

class Mylib{
    
    Node* head=NULL;

    public:

    void insertItem(int num){
        Node* temp =new Node(num);
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    void insertItem(int num,string str){
        Node* temp =new Node(num,str);
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
    }
    void printNode(Node* temp){
        if(temp==NULL){
            cout<<"No data is present"<<endl;
        }
        else{
            cout<<"Book name : "<<temp->name<<endl;
            cout<<"Book code : "<<temp->code<<endl;
            if(temp->available)
                cout<<"Book is available"<<endl;
            else
                cout<<"Book not available"<<endl;
            
        }
    }

    void printData(){
        cout<<endl<<endl<<endl;
        if(head==NULL){
            cout<<"No book is present"<<endl;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<"Book name : "<<temp->name<<endl;
            cout<<"Book code : "<<temp->code<<endl;
            if(temp->available)
                cout<<"Book is available"<<endl;
            else
                cout<<"Book not available"<<endl;
            
            temp=temp->next;
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
    }

    void issueBook(int providedCode){
        if(head==NULL){
            cout<<"No book is present in library to be issued"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            if(temp->code==providedCode && temp->available==true){
                cout<<"You have been issued a book having data as : "<<endl;
                printNode(temp);
                temp->available=false;
                return;
            }
            else if(temp->code==providedCode && temp->available==false){
                cout<<"Book is present in library but already issued"<<endl;
                return;
            }
            temp=temp->next;

        }
        if(temp==NULL){
            cout<<"No book is present of your choice"<<endl;
        }
    }
    void returnBook(int providedCode){
        if(head==NULL){
            insertItem(providedCode);
            return;
        }

        Node* temp=head;
        while(temp!=NULL){
            if(temp->code==providedCode){
                temp->available=true;
                cout<<"Thanks for returning a book having data as : "<<endl;
                printNode(temp);
                return;
            }
            temp=temp->next;
        }
        if(temp==NULL){
            insertItem(providedCode);

        }

    }
    void checkBook(int providedCode){
        if(head==NULL){
            cout<<"No item is present in data "<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            if(temp->code==providedCode && temp->available==true){
                cout<<"The book you are searching for is present with data as : "<<endl;
                printNode(temp);
                return;
            }
            else if(temp->code==providedCode && temp->available==false){
                cout<<"Book is presentin library but already issued"<<endl;
                return;
            }
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"No book is present of your choice"<<endl;
        }
    }
    void flush(){
        delete head;
    }



};