	// link list.cpp : Defines the entry point for the console application.
//link list
//create link list
//insertion(at first point/at end/at position)
//deletion(at first point/at end/at position)	

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node* next;
};
node* head = NULL;
node* current = NULL;
void createlinklist(int a)
{
	node* temp = new node();
	temp->data = a;
	temp->next = NULL;
	if (head==NULL)
	{
		head = temp;
		current = temp;
		temp = NULL;
	}
	else
	{
		current->next = temp;
		current = temp;
	}
}
void display()
{
	node* temp = new node();
	temp = head;
	cout << "link list=	";
	while (temp != NULL)
	{
		cout << temp->data<<",";
		temp = temp->next;
	}

}
void deletefirstelement()
{
	node* temp = new node;
	temp = head;
	current = head->next;
	head = current;
}
void deletelastelement()
{
	node* temp = new node();
	node* temp1 = new node();
	temp = head;
	while (temp->next!= NULL)
	{
		temp1 = temp;
		temp = temp->next;
		
	}
	current = temp1;
	temp1->next = NULL;
}
void insertfirst(int a)
{
	node* temp = new node();
	temp->data = a;
	temp->next = head;
	head = temp;
}
void insertatpos(int position,int value)
{
	node* cur = new node();
	node* pre = new node();
	node* temp = new node();
	cur = head;
	for (int i = 1; i < position; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}
void deleteatpos(int position)
{
	node* cur = new node();
	node* pre = new node();
	cur = head;
	for (int i = 1; i < position; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = cur->next;
}
void main()
{
	int x, choice, pos;
	do {
		cout << "\nEnter 1 for createlinklist\nEnter 2 for display\nEnter 3 for delete first node\nEnter 4 for delete last node\nEnter 5 for insert at first\nEnter 6 to insert at pos\nEnter 7 to delete at position\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int n;
			cout << "enter number of node;";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "enter data of node";
				cin >> x;
				createlinklist(x);

			}
			break;
		case 2:
			display();
			break;
		case 3:
			deletefirstelement();
			break;
		case 4:
			deletelastelement();
			break;
		case 5:
			cout << "enter data to insert";
			cin >> x;
			insertfirst(x);
			break;
		case 6:
			cout << "enter position of node";
			cin >> pos;
			cout << "enter data to inser";
			cin >> x;
			insertatpos(pos,x);
			break;
		case 7:
			cout << "enter position of node";
			cin >> pos;
			deleteatpos(pos);
			break;
		default:
			cout << "envalid choice, try again :(";
			break;
		}
	} while (true);

}
