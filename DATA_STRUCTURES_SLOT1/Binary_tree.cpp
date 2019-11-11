#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *newnode(int key){
    struct node *a = (struct node*)malloc(sizeof(struct node));
    a->data=key;
    a->left=NULL;
    a->right=NULL;
    return a;
}

struct node *Insertright(struct node *root, int key){
	if(root == NULL) return newnode(key);
	root->right =  Insertright(root->right, key);
	return root;
}
struct node *Insertleft(struct node *root, int key){
	if(root == NULL) return newnode(key);
	root->left =  Insertleft(root->left, key);
	return root;
}

void inorder(struct node* root)
{
    if (!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(struct node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
bool Search(struct node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    bool l = Search(root->left, key);

    bool r = Search(root->right, key);

    return l || r;
}

int main(){
    struct node *root = NULL;
	root = Insertleft(root, 84);
	root = Insertright(root, 78);
	root = Insertright(root, 74);
	root = Insertright(root, 46);
	root = Insertright(root, 57);
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	cout<<Search(root, 84);
}
