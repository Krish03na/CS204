#include <bits/stdc++.h>

using namespace std;

struct Node{
int x;
int y;
struct Node *next;
}

void AddFirst(Node **head_ref, int a, int b){
Node *new_node = new Node();
new_node->x = a;
new_node->y = b;
new_node->next = *head_ref;
*head_ref = new_node;
}

int DelFirst(Node **head_ref){
if(*head==NULL) return -1;
struct Node *temp = *head_ref;
head_ref = new_node; 
}

int Del(Node **head_ref, int a, int b){
	struct Node *temp = *head_ref;
	struct Node *prev = temp;

	while(temp!=NULL || (temp->x!=a && temp->y!=b)){
		prev = temp;
		temp = temp->next;
	}

	if(temp==NULL) return -1;

	prev->next = temp->next;
}

int search(Node **head_ref, int d){
struct Node *temp = *head_ref;
while(temp!=NULL){
if(sqrt(temp->x*temp->x + temp->y*temp->y) <d) cout << temp->x << temp->y;
temp = temp->next;
}

















}

