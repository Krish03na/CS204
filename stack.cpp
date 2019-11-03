#include<bits/stdc++.h>

using namespace std;
// A structure to represent a stack
int top =-1;
void push (int Stack[ ] , int x , int n) {
 if ( top == n-1 ) {
    cout << "OVERFLOW" ;
    }
    else{
        top = top +1 ;
        Stack[ top ] = x ;
    }
}
 bool isEmpty ( ){
        if ( top == -1 )  //Stack is empty
        return true ;
        else
        return false;
    }


void pop (int Stack[ ] ,int n ){

        if( isEmpty ( ) )
        {
            cout << "Underflow" << endl ;
        }
        else
        {
             top = top - 1 ;
        }
    }

int topElement ( int Stack[]){
        return Stack[top];
    }


   int main(){
   	int s[5];
   	cout<<isEmpty()<<endl; //returns 1
   	push(s, 4, 5);
   	push(s, 5, 5);
   	push(s, 7, 5);
   	push(s, 3, 5);
   	push(s, 2, 5); // s[] = {4, 5, 7, 3, 2}
   	cout<<topElement(s); //2
   	pop(s, 5); //s[] = {4, 5, 7, 3}
   	cout<<topElement(s); //3
   	


   }
