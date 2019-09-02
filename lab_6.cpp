#include<bits/stdc++.h>
using namespace std;

int main(){

	int no_of_users, no_of_op, op_no, max=0, max_user=-1, user_id, amount;
	int A[no_of_op];
	cin>>no_of_users;
	cin>>no_of_op;

	for(int i=0; i<no_of_users; i++)
	A[i]=0;

	while(no_of_op--){
		cin>>op_no;
		if(op_no==2){
			if(max_user==-1) cout<<"No data available\n";
			else cout<<max_user<<endl;
		}else{
			//operation 1 

			cin>>user_id;
			cin>>amount;

			A[user_id]+= amount;

			if(A[user_id]>max) max_user=user_id;
		}
	}
}
