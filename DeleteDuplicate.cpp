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
    
    //deleting duplicate nodes
    void deldup(){
        Node *current=head;
        int val=current->data;
        int p=1;
        while(current->next!=NULL){
            p++;
            current=current->next;
            while(current->data==val){
                delAt(p);
            }
            val=current->data;
        }
        
    }
    
};

int main()
{
    lnlist l1;
    l1.insert(1);
    l1.insert(1);
    l1.insert(1);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    //l1.insertAt(7,2);
    //l1.insertAt(8,4);
    //l1.display();
    //l1.del();
    //l1.display();
    //l1.delAt(5);
    //l1.display();
    //l1.insertAt(9,7);
    //l1.delAt(7);
    l1.deldup();
    l1.display();
}

