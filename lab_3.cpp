#include <bits/stdc++.h>
using namespace std;

bool balanced(string a){

stack<char> s;
char x;
for(int i=0; i<a.length(); i++){

	if(a[i]=='(' || a[i]=='{' || a[i]=='[' || a[i]=='<' ){
		s.push(a[i]);
		continue;
	}
	if(a[i] == '|'){
		if(s.empty()) s.push(a[i]);
		else{if(s.top()=='|') s.pop(); 
			else s.push(a[i]);}
				
		continue;
	}

if(s.empty()) return false;

switch(a[i]){

	case ')': x = s.top();
		s.pop();
		if(x=='{' || x=='[' || x=='<' || x=='|' )
		return false;
		break;
	case '}': x = s.top();
		s.pop();
		if(x=='(' || x=='[' || x=='<' || x=='|' )
		return false;
		break;
	case ']': x = s.top();
		s.pop();
		if(x=='(' || x=='{' || x=='<' || x=='|' )
		return false;
		break;
	case '>': if(s.empty()) return false;
		x = s.top();
		s.pop();
		if(x=='(' || x=='[' || x=='{' || x=='|' )
		return false;
		break;
	
	}


}
return (s.empty());

}

int main(){
	int T;
	cin >> T;
	while(T--){
		string str;
		cin >> str;
		if(balanced(str)) cout << "YES\n";
		else cout << "NO\n";
	}
return 0;
}






