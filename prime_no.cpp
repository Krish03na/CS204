#include <bits/stdc++.h>
using namespace std;

string add_one(string s){
	reverse(s.begin(),s.end());
	int n=s.size();
	int carry=0;
	int sum=(s[0]-'0')+1;
	carry=sum/10;
	s[0]=(sum%10+'0');
	for(int i=1;i<n;i++){
		if(carry==0) {reverse(s.begin(),s.end()); return s;}
		else{
			sum=(s[i]-'0')+carry;
			s[i]=(sum%10+'0');
			carry=sum/10;
		}
	}
	if(carry) s+=(carry+'0');
	reverse(s.begin(),s.end());
	return s;
}
bool Smaller(string s1, string s2){
	int n1 = s1.length(), n2 = s2.length();

	if (n1 < n2)
	return true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (s1[i] < s2[i])
		return true;
	else if (s1[i] > s2[i])
		return false;

	return false;
}
bool small2(string s1, string s2){
	int n1 = s1.length(), n2 = s2.length();

	if (n1 < n2)
	return true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (s1[i] < s2[i])
		return true;
	else if (s1[i] > s2[i])
		return false;

	return true;
}

string Diff(string s1, string s2){
	if (Smaller(s1, s2))
		swap(s1, s2);
	string str = "";
	int n1 = s1.length(), n2 = s2.length();

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int carry = 0;

	for (int i=0; i<n2; i++){

		int sub = ((s1[i]-'0')-(s2[i]-'0')-carry);

		if (sub < 0){
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	for (int i=n2; i<n1; i++){
		int sub = ((s1[i]-'0') - carry);

		if (sub < 0){
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	reverse(str.begin(), str.end());

	return str;
}


string division(string a , string b){

	string ans="";
	string zero="0";
	if(Smaller(a,b)) {return zero;}
	string r=a.substr(0,b.size());
	
	if(Smaller(r,b)) {r+=a[b.size()];}
	int S=r.size();
	while(small2(b,r)){
		int i=0;
		while(small2(b,r)){
			r=Diff(b,r);
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) {r=r.substr(count,r.size()-count);}
			else{ r="";}
			i++;
		}
		ans+=(i+'0');
		if(S>=a.size()) break;
		r+=a[S];
		S++;
		int count=0;
    	for(int j=0;j<r.size();j++){
			if(r[j]!='0') break;
			else count++;
		}
		if(count<r.size()) r=r.substr(count,r.size()-count);
		else r="";
		while(Smaller(r,b) && S<a.size()){
			r+=a[S];
			S++;
			ans+='0';
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) r=r.substr(count,r.size()-count);
			else r="";
		}
	}
	if(r.size()==0) r="0";
	return r;
}

bool is_prime(string a){
	int n=a.size();
	string b="2";
	while(b.size()<=(n/2+1)&& Smaller(b,a)){
		string r=division(a,b);
		if(r=="0") return false;
		b=add_one(b);
	}
	return true;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		string a;
		cin>>a;
		if(a=="1" ) cout<<"Not a Prime"<<endl;
		if(is_prime(a)) cout<<"Prime"<<endl;
		else cout<<"Not a Prime"<<endl;
	}
	return 0;
}
