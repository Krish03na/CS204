#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int x;
        int y;
        Node *next;
};

void AddFirst( Node **head_ref, int a, int b){
 Node *new_node = new Node();
new_node->x = a;
new_node->y = b;
new_node->next = *head_ref;
*head_ref = new_node;
}

void DelFirst( Node **head_ref){
if(*head_ref == NULL) {cout << "-1\n"; return ;}

*head_ref = (*head_ref)->next;

}

void Del( Node **head_ref, int a, int b){
     Node *temp = *head_ref, *prev;

    if(temp==NULL){ cout << "-1\n"; return;}
	if(temp!=NULL && temp->x==a && temp->y==b){
		*head_ref = temp->next;
		free(temp);
		return;
	}

	while((temp != NULL)  && (temp->x !=a) && (temp->y !=b)){
        prev = temp;
        temp = temp->next;
	}

	if(temp==NULL) { cout << "-1\n"; return;}
	else{
	prev->next = temp->next;
	free(temp);}

}

void Search_d( Node **head_ref, float d){
    Node* temp;
    temp=*head_ref;
    int c=0;
	while(temp!=NULL)
	{
		float dist=(temp->x)*(temp->x)+(temp->y)*(temp->y);
		if(dist<=d*d) c++;
		temp=temp->next;
	}
	if(c==0) {cout << "-1"; return ;}
	else {cout<< c ; return ;}
}

int Search(Node **head_ref, int a, int b ){
Node *temp ;
temp = *head_ref;
while(temp != NULL){
    if((temp->x==a) && (temp->y==b)) return 1;
           temp = temp->next;
           }
if(temp ==NULL) return 0;
}

int Length( Node **head_ref){
int c=0;
 Node *temp = *head_ref;
while(temp != NULL){
    c++;
    temp = temp->next;
}
return c;

}

int main(){
    Node *head = NULL;

    long long int T;
    cin >>T;
    while(T--){
        int fn, x, y;
        float d;
        cin>>fn;
        switch(fn){

            case 1: cin >> x >> y;
                    AddFirst(&head, x, y);
                    break;
            case 2: DelFirst(&head);
                    break;
            case 3: cin >> x >> y;
                    Del(&head, x, y);
                    break;
            case 4: cin >> d;
                    Search_d(&head, d);
                    break;
            case 5: cin >> x >> y;
                    if(Search(&head, x, y))cout<<"True\n";
                    else cout<<"False\n";
                    break;
            case 6: cout << Length(&head) <<endl;
                    break;
            default: cout << "No such function" << endl;

    }
}
}
