#include<bits/stdc++.h>

using namespace std;

struct NODE {
    int data;
    struct NODE *next; 
};

struct NODE* createNode(int data) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertHead(struct NODE** head, int data) {
    struct NODE* node = createNode(data);
    node->next = *head;
    *head = node;
}

void deleteHead(struct NODE** head) {
    if(*head == NULL) {
        cout << "Linked List already Empty\n";
        return;
    }
    struct NODE* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void insertTail(struct NODE** head, int data) {
    struct NODE* node = createNode(data);
    struct NODE* temp = *head;

    if(temp == NULL) {
        *head = node;
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;    
}

void deleteTail(struct NODE** head) {
    if(*head == NULL) {
        cout << "Linked List already empty\n";
        return;
    }

    if((*head)->next == NULL) {
        struct NODE* temp2 = *head;
        free(temp2);
        *head = NULL;
        return;
    }

    struct NODE* temp = *head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    struct NODE* temp2 = temp->next;
    free(temp2);
    temp->next = NULL;
}

void printList(struct NODE** head) {
    struct NODE* temp = *head;
    while(temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

int length(struct NODE** head) {
    int count = 0;
    struct NODE* temp = *head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    system("clear");
    int option = 1, x;
    struct NODE* head = NULL;
    while(option) {
        cout << "1. Insert at head\n";
        cout << "2. Delete at head\n";
        cout << "3. Insert at tail\n";
        cout << "4. Delete at tail\n";
        cout << "5. Length of Linked List\n";
        cout << "6. Print Linked Linest\n";
        cout << "0. Exit\n";
        cout << "Choose any option ";
        cin >> option;
        
        switch(option) {
            case 0:
                break;
            case 1:
                cout << "Enter any integer ";
                cin >> x;
                insertHead(&head, x);
                break;
            case 2:
                deleteHead(&head);
                break;
            case 3:
                cin >> x;
                insertTail(&head, x);
                break;
            case 4:
                deleteTail(&head);
                break;
            case 5:
                cout << length(&head) << '\n';
                break;
            case 6:
                printList(&head);
                break;
            default:
                cout << "Enter a valid option\n";
        }
        cout << '\n';
    }
    return 0;
}
