#include"objects.cpp"

int main(){
    bool choice=true;
    Mylib obj;
    int val;
    int i;
    string str;
    while(choice){

        cout<<"Enter a valid function from the following choices : "<<endl;
        cout<<"1. Print all data"<<endl;
        cout<<"2. Add book to store"<<endl;
        cout<<"3. Issue from books available"<<endl;
        cout<<"4. Return book"<<endl;
        cout<<"5. Check availibility"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl<<endl;

        cin>>val;

        switch(val){
            case 1:
                obj.printData();
                break;
            
            case 2:
                cout<<"Enter book code"<<endl;
                cin>>i;
                cout<<"Enter book name if not then write no instead"<<endl;
                cin>>str;
                if(str=="no"){
                    obj.insertItem(i);
                }
                else{
                    obj.insertItem(i,str);
                }

                break;

            case 3:
                cout<<"Enter book code"<<endl;
                cin>>i;
                obj.issueBook(i);
                break;

            case 4:
                cout<<"Enter book code"<<endl;
                cin>>i;
                obj.returnBook(i);
                break; 

            case 5:
                cout<<"Enter book code"<<endl;
                cin>>i;
                obj.checkBook(i);
                break;  

            case 6:
                cout<<"Thanks for visiting "<<endl;
                choice=false;
                break;

            default:
                choice=false;                     
        }
        cout<<endl<<endl;

    }

    obj.flush();
}