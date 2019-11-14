
#include<bits/stdc++.h>
using namespace std;

int buckets;

struct Node
{
  int data;
  struct Node *ptr;
};


void insertatstart(struct Node **st,int val)
{
  struct Node *temp = new Node;
  temp->data = val;
  temp->ptr = *st;
  *st = temp;
}


void insertatend(struct Node **start,int val)
{
  struct Node *temp;
  temp = *start;
  if(temp==NULL)
  {
    insertatstart(start,val);
  }
  else
  {
    while(temp->ptr!=NULL)
    {
      temp = temp->ptr;
    }
    struct Node *temp1 = new Node;
    temp1->data = val;
    temp1->ptr = NULL;
    temp->ptr = temp1;
  }
}


void search(struct Node *start,int val)
{
  struct Node *temp;
  temp = start;
  int n=0;
  while(temp!=NULL)
  {
    if(temp->data == val)
    {
      n++;
    }
    temp = temp->ptr;
  }
  if(n>0)
  cout << "Exists " << n << " times" << endl;
  else
  cout << "Doesn't exist" << endl;
}

void deletenode(struct Node **start,int val)
{
  struct Node *temp,*prev;
  temp = *start;
  while(temp!=NULL)
  {
    if(temp->data == val)
      break;
    prev = temp;
    temp = temp->ptr;
  }
  if(temp == NULL)
  {
    cout << "Element not found";
  }
  else if(temp == *start)
    *start = temp->ptr;
  else
    prev->ptr = temp->ptr;
  free(temp);
}

void print(struct Node *start)
{
  struct Node *temp;
  temp = start;
  while(temp!=NULL)
  {
    cout << " --> "<< temp->data ;
    temp = temp->ptr;
  }
  cout << '\n';
}

Node **arr;

void Hashmap()
{
  arr = new Node*[buckets];
  for(int i=0 ; i < buckets ; i++)
  {
            arr[i]=NULL;
  }
}

int Hashfunc(int k)
{
  return k%buckets;
}

void insert(int k)
{
    int index = Hashfunc(k);
    insertatend(&arr[index],k);
}

void searchkey(int k)
{
  int index = Hashfunc(k);
  search(arr[index],k);
}

void deletekey(int k)
{
  int index = Hashfunc(k);
  deletenode(&arr[index],k);
}

void printHash()
{
  for (int i = 0; i < buckets; i++)
  {
    cout << i;
    print(arr[i]);
    cout << endl;
  }
}

int main()
{
  cin >> buckets;
  Hashmap();
  int a[] = {15,11,27,8,12,32,3,4,54,67,87,65,76,89,9,89,45,
  79,8,898,9998,656,96,65,64,66
  };
  int n = sizeof(a)/sizeof(a[0]);
  for (int i = 0; i < n; i++)
    insert(a[i]);
  deletekey(12);
  searchkey(27);
  searchkey(88);
  printHash();

}
