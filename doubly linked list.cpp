#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
	public:
		Node *pre_add;
		int data;
		Node *next_add;
};
class Linked_List
{
	public:
		Node *head = NULL;
		Node *tail = NULL;
		void Insert()
		{
			int n;
			cout<<"\n\n Enter Value : ";
			cin>>n;
			Node *new_node = new Node;
			new_node -> pre_add = NULL;
			new_node -> data = n;
			new_node -> next_add = NULL;
			if(head == NULL)
			{
				head = new_node;
				tail = new_node;
			}
			else
			{
				tail -> next_add = new_node;
				new_node -> pre_add = tail;
				tail = new_node;
			}
			cout<<"\n\n***New Node inserted successfully***";
		}
		void Count()
		{
			if(head == NULL)
			{
				cout<<"\n\n Linked List is Empty...";
			}
			else
			{
				int n=0;
				Node *ptr = head;
				while(ptr != NULL)
				{
					n++;
					ptr = ptr -> next_add;
				}
				cout<<"\n\n Total Nodes : "<<n;
			}
		}
		void Search()
		{
			if(head == NULL)
			{
				cout<<"\n\n Linked List is Empty...";
			}
			else
			{
				int n,found=0;
				cout<<"\n\n Enter Value For Search : ";
				cin>>n;
				Node *ptr = head;
				while(ptr != NULL)
				{
					if(ptr -> data == n)
					{
						cout<<"\n\n Search Value "<<" Node";
						found++;
						break;
				     }
					ptr = ptr -> next_add;
				}
				if(found == 0)
				{
					cout<<"\n\n Search Value "<<n<<" Can't Found...";
				}
			}
		}
		void Update()
		{
			if(head == NULL)
			{
				cout<<"\n\n Linked List is Empty...";
			}
			else
			{
				int n,found=0;
				cout<<"\n\n Enter Value For Updation : ";
				cin>>n;
				Node *ptr = head;
				while(ptr != NULL)
				{
					if(n == ptr -> data)
					{
						cout<<"\n\n Enter New Value : ";
						cin>>ptr -> data;
						cout<<"\n\n***Value updated successfully***";
						found++;
						break;
					}
					ptr = ptr -> next_add;
				}
				if(found == 0)
				{
					cout<<"\n\n Updation Value "<<n<<" Can't Found...";
				}
			}
		}
		void del()
		{
			if(head == NULL)
			{
				cout<<"\n\n Linked List is Empty...";
			}
			else
			{
				int n,found=0;
				cout<<"\n\n Enter Value For Deletion : ";
				cin>>n;
				// First Node & Last Node
				if(head == tail && n == head -> data)
				{
					Node *ptr = head;
					head = NULL;
					tail = NULL;
					delete ptr;
					cout<<"\n\n***Node Deleted Successfully***";
					found++;
				}
				// First Node
				else if(n == head -> data)
				{
					Node *ptr = head;
					head = head -> next_add;
					head -> pre_add = NULL;
					delete ptr;
					cout<<"\n\n***Node Deleted Successfully***";
					found++;
				}
				// Last Node
				else if(n == tail -> data)
				{
					Node *ptr = tail;
					tail = tail -> pre_add;
					tail -> next_add = NULL;
					delete ptr;
					cout<<"\n\n Node Deleted Successfully...";
					found++;
				}
				// Between First & Last
				else
				{
					Node *pre_ptr = head; // 10 
					Node *ptr = head -> next_add; // 20
					Node *next_ptr = ptr -> next_add; // 30 
					while(ptr -> next_add != NULL)
					{
						if(n == ptr -> data)
						{
							pre_ptr -> next_add = next_ptr;
							next_ptr -> pre_add = pre_ptr;
							delete ptr;
							cout<<"\n\n***Node Deleted Successfully***";
							found++;
							break;	
						}
						pre_ptr = ptr;
						ptr = next_ptr; 
						next_ptr = next_ptr -> next_add;	
					}
					if(found == 0)
					{
						if(n == ptr -> data)
						{
							tail = tail -> pre_add;
							delete ptr;
							cout<<"\n\n***Node Deleted Successfully***";
							found++;	
						}	
					}
				}
				if(found == 0)
				{
					cout<<"\n\n Value "<<n<<" Can't Found...";
				}
			}
		}
		void ShowForward()
		{
			cout<<"\n\n";
			Node *ptr = head;
			while(ptr != NULL)
			{
				cout<<" "<<ptr -> data;
				ptr = ptr -> next_add;
			}
		}
		void ShowReverse()
		{
			cout<<"\n\n";
			Node *ptr = tail;
			while(ptr != NULL)
			{
				cout<<" "<<ptr -> data;
				ptr = ptr -> pre_add;
			}
		}
};
main()
{
	Linked_List obj;
	p:
	int choice;
	cout<<"\n\n 1. Insert Node";
	cout<<"\n\n 2. Count Nodes";
	cout<<"\n\n 3. Search Node";
	cout<<"\n\n 4. Update Node";
	cout<<"\n\n 5. Delete Node";
	cout<<"\n\n 6. Show Nodes";
	cout<<"\n\n 7. Exit";
	cout<<"\n\n\n Your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			obj.Insert();
			break;
		case 2:
			obj.Count();
			break;
		case 3:
			obj.Search();
			break;
		case 4:
			obj.Update();
			break;
		case 5:
			obj.del();
			break;
		case 6:
			if(obj.head == NULL)
				cout<<"\n\n Linked List is Empty...";
			else
			{
				obj.ShowForward();
				obj.ShowReverse();	
			}
			break;
		case 7:
			exit(0);
		default:
			cout<<"\n\n Invalid Choice...Please Try Again...";	
	}	
	getch();
	goto p;
}

