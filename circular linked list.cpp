#include<iostream>
#include<conio.h>
using namespace std;
int size = 0;
class Node
{
	public:
	   int data;
	   Node *next_add;
	   
};
class circular_linkedList
{
	public:
		Node*head = NULL;
		Node*tail = NULL;
		void insert()
		{
			int n;
			cout<<"\n\n Enter value : ";
			cin>>n;
			Node*new_node = new Node;
			new_node -> data = n;
			new_node -> next_add = NULL;
			if(head == NULL)
			{
				head = new Node;
				tail = new Node;
				new_node -> next_add = new_node;
			}
		else
		{
			tail -> next_add = new_node;
			tail = new_node;
			tail -> next_add = head;
			}
			size++;
			cout<<"\n\n***New Node inserted succesfully***"	;
		 }
		void count()
		{
			if(head == NULL)
			{
				cout<<"\n\n***Circular linked list is empty***";
			}
			else
			{ 
			   cout<<"\n\n Total Nodes : "<<size;
			}
		}
		void search()
		{
				if(head == NULL)
			{
				cout<<"\n\n***Circular linked list is empty***";
			}
			else
			{ 
			   int n,found = 0, c = 0;
			   cout<<"\n\n Enter value for search : ";
			   cin>>n;
			   Node *ptr = head;
			   while(c != size)
			   {
			   	if(n == ptr -> data)
			   	{
			   		cout<<"\n\n***Value is found successfully***";
			   		found++;
			   		break;
				   }
			   	c++;
			   	ptr = ptr -> next_add;
			   }
			   if(found == 0)
			   {
			   	cout<<"\n\n***Value can't found***";
			   }
			}
		}
		void update()
		{
			int n,found = 0, c = 0;
			   cout<<"\n\n Enter value for updation : ";
			   cin>>n;
			   Node *ptr = head;
			   while(c != size)
			   {
			   	if(n == ptr -> data)
			   	{
			   		cout<<"\n\nEnter new value: ";
			   		cin>>ptr -> data;
			   		cout<<"\n\n***Value updated successfully***";
			   		found++;
			   		break;
				   }
			   	c++;
			   	ptr = ptr -> next_add;
			   }
			   if(found == 0)
			   {
			   	cout<<"\n\n***Value can't found***";
			   }
			}
		void del()
		{
			if(head == NULL)
			{
				cout<<"\n\n***Circular linked list is empty***";
			}
			// Node is only one
			else
			{ 
			   int n,found = 0,c = 0;
			   cout<<"\n\nEnter value for deletion : ";
			   cin>>n;
			   if(size == 1 && n == head -> data)
			   {
			   	Node *ptr = head;
			   	head = NULL;
			   	tail = NULL;
			   	delete ptr;
			   	cout<<"\n\n***Node deleted successfully***";
			   	found++;
			   	size--;
			   }
			   //First Node
			   else if(n == head -> data)
			   {
			   	Node *ptr = head;
			   	head = head -> next_add;
			   	tail -> next_add = head;
			   	delete ptr;
			   	cout<<"\n\n***Node deleted successfully***";
			   	found++;
			   	size--;
			   }
			   //Last Node
			   else if(n == tail -> data)
			   {
			   	Node *ptr = head;
			   	Node *pre;
			   	while(ptr != tail)
			   	{
			   		pre = ptr;
			   		ptr = ptr -> next_add;
				   }
				tail = pre; 
				tail -> next_add = head;
				delete ptr;
			   	cout<<"\n\n***Node deleted successfully***";
			   	found++;
			   	size--;
			   }
			   //Between first and last node
			   else
			   {
			   	 Node *pre_ptr = head;
			   	 Node *ptr = head -> next_add;
			   	 while(c != size)
			   	 {
			   	 	if(n == ptr ->data)
			   	 	{
			   	 		pre_ptr -> next_add = ptr -> next_add;
			   	 		delete ptr;
			   	        cout<<"\n\n***Node deleted successfully***";
			   	        found++;
			   	        size--;
			   	        break;
						}
						c++;
						pre_ptr = ptr;
						ptr = ptr -> next_add;
					}
			   }
			   if (found == 0)
			   {
			   	cout<<"\n\n Value can't found";
			   }
			}
		}
		void show()
		{
			if(head == NULL)
			{
				cout<<"\n\n***Circular linked list is empty***";
			}
			else
			{ 
			   int c = 0;
			   Node *ptr = head;
			   cout<<"\n\n";
			   while(c != size)
			   {
			   	cout<<" "<<ptr -> data;
			   	c++;
			   	ptr = ptr -> next_add;
			   }
			}
		}
};
main()
{
	circular_linkedList obj;
	p:
		int choice;
		cout<<"\n\n 1. Insert Node";
		cout<<"\n\n 2. Count Node";
		cout<<"\n\n 3. Search Node";
		cout<<"\n\n 4. Update Node";
		cout<<"\n\n 5. Delete Node";
		cout<<"\n\n 6. Show Node";
		cout<<"\n\n 7. Exit";
        cout<<"\n\n Your choice : ";
        cin>>choice;
        switch(choice)
        {
        	case 1:
        		obj.insert();
			    break;
			case 2:
				obj.count();
			    break;
			case 3:
				obj.search();
			    break;  
			case 4:
				obj.update();
			    break;
			case 5:
			    obj.del();	
			    break;	  
			case 6:
				obj.show();
			    break;
			case 7:
			    exit(0);
			default:
			   cout<<"\n\n***Invalid choice***";		    
		}
	getch();
	goto p;	
	}	
		
