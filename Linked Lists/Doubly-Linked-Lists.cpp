#include <iostream>
using namespace std;
#include <stdio.h> 
#include <stdlib.h> 

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};


void insert_at_beginning(struct node** head, int data)
{
	struct node* new_ptr = (struct node*) malloc(sizeof(struct node));
	new_ptr->data = data;	
	new_ptr->next = *head;
	new_ptr->prev = NULL:
	*head->prev = new_ptr;
	*head = new_ptr;
	return;
}

void insert_at_end(struct node** head, int data)
{
	struct node* ptr = *head;
	struct node* new_ptr = (struct node*) malloc(sizeof(struct node));
	new_ptr->data = data;
	new_ptr->link_node = NULL;
	if(ptr==NULL)
	{
		*head = new_ptr;
		return;
	}
	while(ptr->link_node!=NULL)
	{
		ptr = ptr -> link_node;	
	}
	ptr->link_node = new_ptr;
	return;
}

void insert_after_node(struct node* prev_node, int data)
{
	if(prev_node==NULL)
	{
		cout<<"Warning! The previous node pointer is Null. This operation will give you a list with one element:data"<<endl;
		insert_at_beginning(&prev_node,data);
	}
	struct node* new_ptr = (struct node*) malloc(sizeof(struct node));
	new_ptr->data = data;
	new_ptr->link_node = prev_node->link_node;
	prev_node->link_node = new_ptr;
}

node* find(struct node** head, int value)
{
	struct node* ptr = *head;
	cout<<"Usage Warning!, This function returns the first matching node pointer only"<<endl;
	if(ptr == NULL)
	{
		cout<<"List is Empty";
		return NULL;
	}
		
	while(ptr->data!=value && ptr!=NULL)
	{
		ptr = ptr->link_node;
	}
	
	if(ptr == NULL)
	{
		cout<<"No entry with value "<<value<<" is found. Returning Null Pointer"<<endl;
	}
	cout<<"Pointer is: "<<ptr<<endl;
	return ptr;	
}

int length(struct node** head)
{
	struct node* ptr = *head;
	int counter=0;
	while(ptr!=NULL)
	{
		counter+=1;
		ptr = ptr->link_node;
	}
	return counter;
}

void delete_node_from_end(struct node** head)
{
	struct node* ptr = *head;
	if (ptr == NULL)
	{
		cout<<"The list is empty.";
		return;
	}
	
	if(ptr->link_node == NULL)
	{
		*head = NULL;
		free(ptr);
		return;
	}
	
	while(ptr->link_node->link_node!=NULL)
	{
		ptr = ptr->link_node;
	}
	struct node* temp = ptr->link_node; 
	ptr->link_node = NULL;
	free(temp);
	return;
}


void delete_node_from_beginning(struct node** head)
{
	if (*head == NULL)
	{
		cout<<"The list is empty."<<endl;
		return;
	}
	struct node* temp = *head;
	*head = (*head)->link_node;
	free(temp);
	return;
}

void delete_node_with_value(struct node** head, int value)
{
	struct node* ptr = *head;
	if (ptr == NULL)
	{
		cout<<"The list is empty."<<endl;
		return;
	}
	
	if(ptr->link_node == NULL)
	{
		if(ptr->data==value)
		{
			*head = NULL;
			free(ptr);
		}
		else
		{
			cout<<"Element not found"<<endl;	
		}
		return;
	}
	
	while(ptr->link_node->data!=value)
	{
		ptr = ptr->link_node;
	}
	
	if(ptr->link_node == NULL)
	{
		cout<<"Element not found"<<endl;
		return;
	}
	struct node* temp = ptr->link_node; 
	ptr->link_node = ptr->link_node->link_node;
	temp->link_node = NULL;
	free(temp);
	return;
}

void print_sublist(struct node** head, int start,int end)
{
	struct node* ptr = *head;
	int i = start;
	int len = length(head);
	if (end<start || start<0 || end<0 || start>len-1 || end>len-1)
	{
		cout<<"Points positions are wrong or are in wrong order"<<endl;
		cout<<"Take start and endpoint of sublist within range 0 to "<<len-1<<endl;
		return;
	}
	
	while(start>0)
	{
		ptr = ptr->link_node;
		start--;
	}
	
	for(;i<=end; i++)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->link_node;
	}
	cout<<endl;
	return;
}

void print_list(struct node** head)
{
	struct node* ptr = *head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"->";
		ptr = ptr->link_node;
	}
	cout<<endl;
}

node* create_list(int number)
{
	if(number<=0)
	{
		cout<<"Check the size of list you Entered"<<endl;
		return NULL;
	}
	cout<<"Enter the elements"<<endl;
	struct node* head = (struct node*)malloc(sizeof(struct node));
	cin>>head->data;
	struct node* ptr = head;
	while((number-1)>0)
	{
		ptr->link_node = (struct node*)malloc(sizeof(struct node));
		ptr = ptr->link_node;
		cin>>ptr->data;
		number--;
	}
	ptr->link_node = NULL;
	return(head);
}


int main()
{
	int options,data;
	struct node* head = NULL;
	bool condition = true;
	do
	{
		cout<<"Enter 1 to create list"<<endl;
		cout<<"Enter 2 to insert a node at the end"<<endl;
		cout<<"Enter 3 to insert a node at the beginning"<<endl;
		cout<<"Enter 4 to find a node with a value"<<endl;
		cout<<"Enter 5 to insert a node after a given node"<<endl;
		cout<<"Enter 6 to print the list from starting element to end element"<<endl;
		cout<<"Enter 7 to print the length of the list"<<endl;
		cout<<"Enter 8 to delete a node from end"<<endl;
		cout<<"Enter 9 to delete a node from the beginning"<<endl;
		cout<<"Enter 10 to delete a node with a particular value"<<endl;
		cout<<"Enter 11 to print list"<<endl;
		cout<<"Enter 0 to exit"<<endl;
		cin>>options;
		
		
		
		switch(options)
		{
			case 1: {
			cout<<"Enter number of nodes you want to create: ";
					cin>>data;
					head = create_list(data);
					break;	
			}
			case 2: {
			cout<<"Enter value at node: ";
					cin>>data;
					insert_at_end(&head, data);
					break;
			}
			case 3: {
			cout<<"Enter value at node: ";
					cin>>data;
					insert_at_beginning(&head, data);
					break;	
			}
			case 4: {
			cout<<"Enter value to find: ";
					cin>>data;
					struct node* temp = find(&head, data);
					cout<<temp->data<<endl;
					break;	
			}
			case 5: {
			cout<<"Enter value after which you want to add the value: ";
					cin>>data;
					struct node* temp = find(&head, data);
					cout<<"Enter value at node: ";
					cin>>data;
					insert_after_node(temp, data);
					break;	
			}
			case 6: {
			cout<<"Enter start and end: ";
					int start,end;
					cin>>start>>end;
					print_sublist(&head, start,end);
					break;	
			}
			case 7: {
				int a = length(&head);
					cout<<a<<endl;
					break;
			}
			case 8: delete_node_from_end(&head);
					break;
			case 9: delete_node_from_beginning(&head);
					break;
			case 10:{
			cout<<"Enter value: ";
					cin>>data;
					delete_node_with_value(&head, data);
					break;	
			}
			case 11:print_list(&head);
			default: {
				break;
			}
		}
	}while(condition);
	
}
