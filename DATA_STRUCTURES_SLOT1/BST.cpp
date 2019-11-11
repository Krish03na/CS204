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

struct node* Insert(int key, struct node* root){
    struct node* a =newnode(key);
    if(root==NULL) return a;
    else{
        if(root->data >= key){
            root->left = Insert(key, root->left);
        }else{
            root->right = Insert(key, root->right);
        }
        return root;
    }
}

struct node *Search(int key, struct node *root){
    if(root == NULL || root->data == key) return root;
    if(root->data > key) return Search(key, root->left);
    return Search(key, root->right);
}

struct node *Min(struct node *root){
    while(root->left!=NULL) root = root->left;
    return root;
}

struct node *Delete(int key, struct node *root){
    if(root == NULL) return root;
    if(root->data > key) root->left = Delete(key, root->left);
    else if(root->data < key) root->right = Delete(key, root->right);
    else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = Min(root->right);
        root->data = temp ->data;
        root->right = Delete(temp->data, root->right);

    }
    return root;

}

struct node *inorder_successor(struct node *root, struct node *node){
    struct node *temp = Search(node->data, root);
    if(temp->right != NULL) return Min(temp->right);

    struct node *successor = NULL;

    while(root!= NULL){
        if(node ->data < root->data){
            successor = root;
            root = root->left;
        }
        else if(node->data > root->data){
            root = root->right;
        }else break;
    }
    return successor;
}

void inorder(struct node *root){
    if (root != NULL)
    {
        inorder(root->left);
        cout<< root->data<<" ";
        inorder(root->right);
    }
}
int Max(struct node *root){
    while(root->right!=NULL) root = root->right;
    return root->data;
}

struct node *join(struct node *t1, struct node *t2){
    if(t1 == NULL) return t2;
    if(t2 == NULL) return t1;

    int m = Max(t1);
    t1 = Delete(m, t1);
    struct node *t = newnode(m);
    t->left = t1;
    t->right = t2;
    return t;
}

vector<struct node *> split(struct node *root, int k){
    vector<struct node *>ans(2, NULL);

    if(root ==NULL) return ans;

    int x = root->data > k ? 1 : 0;
    int y = root->data > k ? 0 : 1;
    auto &N = root->data > k ? root->left : root->right;

    ans[x] = root;
    auto t = split(N, k);
    N = t[x];
    ans[y] = t[y];

    return ans;
}
int main(){
    struct node* t1=NULL;
    t1 = Insert(5, t1);
    Insert(1, t1);
    Insert(55, t1);
    Insert(65, t1);
    Insert(52, t1);
    Insert(32, t1);
    inorder(t1);
    cout<<endl;

    struct node* t2=NULL;
    t2 = Insert(100, t2);
    Insert(200, t2);
    Insert(351, t2);
    Insert(631, t2);
    Insert(3544, t2);
    Insert(655, t2);

    //struct node *t = join(t1, t2);
    //inorder(t);

    vector<struct node *> tr = split(t1, 55);
    inorder(tr[0]);
    cout<<endl;
    inorder(tr[1]);

    return 0;
}
