#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        next=NULL;
    }
 };
 
class lnlist{
    public:
    Node *head;
    Node *tail;
    lnlist(){
        head=NULL;
        tail=NULL;
    }
    
    //Insert at last of linked list
    void insert(int value){
        Node *temp=new Node;
        if(head==NULL){
            temp->data=value;
            temp->next=NULL;
            head=temp;
        }
        else{
            Node *current=head;
            while(current->next!=NULL){
                current=current->next;
            }
            temp->data=value;
            temp->next=NULL;
            current->next=temp;
        }
    }
    
    //Insert at any position
    void insertAt(int value, int pos){
        Node *temp=new Node;
        Node *current=head;
        int i=1;
        while(i<pos-1 && current!=NULL){
            i++;
            current=current->next;
        }
        if(current==NULL) cout<<"Out of bound"<<endl;
        else{
            temp->data=value;
            temp->next=current->next;
            current->next=temp;
        }
    }
    
    //Display function
    void display(){
        Node *current=head;
        while(current!=NULL){
            cout<<current->data<<"->";
            current=current->next;
        }
        cout<<"NULL"<<endl;
    }
    
    //delete element from last of linked list
    void del(){
        Node *temp;
        Node *current=head;
        while(current->next->next!=NULL && current->next!=NULL){
            current=current->next;
        }
        if(current==NULL) cout<<"Cannot delete from empty linked list."<<endl;
        else if(current->next==NULL){
            temp=head;
            head=NULL;
            delete temp;
        }
        else{
            temp=current->next;
            current->next=NULL;
            delete temp;
        }
    }
    
    //delete element at a given position
    void delAt(int pos){
        Node *temp;
        Node *current=head;
        int i=1;
        while(i<pos-1){
            i++;
            current=current->next;
        }
        if(current==NULL) cout<<"Cannot delete from empty linked list."<<endl;
        else if(current->next==NULL) {
            temp=head;
            head=NULL;
            delete temp;
        }
        else{
            temp=current->next;
            current->next=temp->next;
            temp->next=NULL;
            delete temp;
        }
    }
};

//function to compare two linked list
void compare(lnlist l1,lnlist l2){
    Node *temp1=l1.head;
    Node *temp2=l2.head;
    int c=0;
    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1->data == temp2->data) c=0;
        else if(temp1->data < temp2->data) {
            c=1;
            break;
        }
        else{
            c=2;
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(c==0) cout<<"Linked List are same."<<endl;
    if(c==1) cout<<"Linked List 1 comes first."<<endl;
    if(c==2) cout<<"Linked List 2 comes first."<<endl;
}

int main(){
    lnlist l1;
    lnlist l2;
    int i, x;
    cout<<"Linked List 1"<<endl;
    for(i=0; i<5; i++){
        cout<<"Enter value."<<endl;
        cin>>x;
        l1.insert(x);
        x=0;
    }
    cout<<"Linked List 2."<<endl;
    for(i=0; i<6; i++){
        cout<<"Enter value."<<endl;
        cin>>x;
        l2.insert(x);
        x=0;
    }
    compare(l1, l2);
    return 0;
}
