#include <iostream>

using namespace std;

class Node{
	//Data
	public:
	int data;
	//Pointer to the next Node
	Node *next;
	//Constuctor that makes the pointer to NULL
	public:
	Node(){
		next=NULL;
	}
	
	
};

class LinkedList{
	//Head + Cirles inside linked with each other
	//Head -> Node type pointer
	public:
	Node *head;
	Node *tail; //stores last element
	//Constructor
	public:
	LinkedList(){
		head=NULL; tail= NULL;
	}

	//Circles inside linked with each other
	//Rules how circles will be linked

	//Insert
	void insert(int value){
		//For adding the first node
		Node *temp= new Node;
		//insert data in the node
		temp->data= value;
		//1st Node only. So to be executed only if head is null.
		if(head==NULL){
		head=temp;
		}
		//Any other Node. If head is not null, then it is not the first node.
		else{
		tail->next=temp;
		}
		tail=temp; //tail of the current node functions as the tail of the last node in the next turn, when the previous statement is 					executed.
	}

	//Deletion of the last element
	void del(){
		//store the tail in temp
		Node *temp=tail;
		Node *current=head;
		//before tail has to point to null, i.e. second last element
		while(current->next !=tail){
			current=current->next;
		}
		current->next=NULL;
		//update tail
		tail=current;
		//delete temp
		delete temp;
	}

	//Insertion at a point
	void InsertAt(int pos, int value){
		//Reach the place before the position
		Node *current=head;
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		if(current->next==NULL || current==NULL){
			cout<<"Linked List does not have that many elemnts."<<endl;
		}
		//create a node
		Node *temp= new Node;
		temp->data=value;
		temp->next=current->next;
		current->next=temp;
	}

	//Deletion at a point
	void DelAt(int pos){
		//Reach the place before the position
		Node *current=head;
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//create pointers for storing the address of the Node to be delete and the address of the next Node
		Node *temp=current->next;
		Node *temp1=temp->next;
		current->next=temp1;
		//Removing the required Node from the linked list
		temp->next=NULL; 
		delete temp; 
	}

	//Count the number of items in the linked list
	int countItems(){
		//counter variable
		int c=0;
		//pointer of Node type to move through the linked list
		Node *ptr=head;
		//loop to move through the linked list
		while(ptr!=NULL){
			c++;
			ptr=ptr->next;
		}
		//returning the value
		return c;
	}

	//Display
	void display(){
		Node *current=head;
		while(current!=NULL){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<"NULL";
		cout<<endl;
		cout<<endl;
	}
	
	//reversing a linked list
	void rev(){
	    reverse(head, head->next, NULL);
	}
	
	void reverse(Node *temp, Node *temp1, Node *temp2){
	    Node *current=temp1;
	    Node *temp3;
	    temp3=temp1->next;
	    current->next=temp;
	    temp->next=temp2;
	    head=temp1;
	    if(temp3!=NULL) reverse(temp1, temp3, temp);
	}
};

int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.display();
    l1.rev();
    l1.display();
}
