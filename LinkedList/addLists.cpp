#include<iostream>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode * next;

    ListNode(int data){
        this->data=data;
        this->next=NULL;
    }
    ~ListNode(){
        int value=this->data;
        // if node is pointing to some value
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"destructor called  for : "<<value<<endl;
    }

};
class Solution{
    private:
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next =NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }
    void insertTail(ListNode* &head,ListNode* &tail,int data){
        ListNode* temp= new ListNode(data);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }

    ListNode* addition(ListNode* first, ListNode* second){
        int carry=0;
        int sum=0;
        int digit=0;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(first!=NULL || second!=NULL || carry!=0){
            //if first list not null
            int val1=0;
            if(first!=NULL)
                val1=first->data;
            
            //if second list not null
            int val2=0;
            if(second!=NULL)
                val2=second->data;
            
            //addition
            sum=val1+val2+carry;
            digit=sum%10;
            insertTail(head,tail,digit);
            carry=sum/10;
            //if first list not null
            if(first!=NULL)
                first=first->next;
            
            //if second list not null
            if(second!=NULL)
                second=second->next;

        }
        return head;
    }
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1=reverse(l1);
        ListNode* list2=reverse(l2);

        //adding two list
        ListNode* ans=addition(list1,list2);

        //ans=reverse(ans);

        return ans;
        
    }
};
int main(){}
