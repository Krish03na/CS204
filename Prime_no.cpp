#include <bits/stdc++.h>
using namespace std;
string sub(string s1,string s2){
    char a='0';
    int p=0, t;
    if(a.length()<b.length()){
       string temp=a;
       a=b;
       b=temp;
       cout<<"-";
    }
  if(a.length()==b.length()){
       for(int i=0;i<a.length();i++){
          if(a[i]>b[i]) break;
          if(a[i]<b[i]){
          string temp=a;
          a=b;
          b=temp;
          cout<<"-";
          break;
          }
          }
    }
    while(b.length()<a.length()){
       b.insert(0,"0",1);
    }

    string result="";
    for(int i=a.length()-1; i>=0  ;i--){
        t= (int)(a[i]-'0') - (int)(b[i] -'0') + p;
        p=0;
        if(t<0){
            p=-1;
            t+=10;
        }
       result.push_back((char) (t + (int)a )) ;
     }

     reverse(result.begin(), result.end());
     result.erase(0, result.find_first_not_of('0'));
     if(result=="") result="0";
     return result;
 }

int com(string a,string b){
    int i;
   if(a.length()>b.length()) return 1;
   else if(a.length()<b.length()) return 0;
   else{
       for(i=0;i<b.length();i++){
           if(a[i]>b[i]) return 1;
           if(b[i]>a[i]) return 0;
       }
       return 2;
       }
}
string rem(string a,string b){
    string res="";
    int n1=a.length();
    int n2=b.length();
    if(com(a,b)==0){ return s1;}
    if(com(a,b)==2) {return "0";}
    string x="";
    int j=n2-1,k=0;
    for(int i=0;i<n2;i++) x.push_back(a[i]);

    while(j<n1){
        k=0;
        while(com(x,b)!=0){
            x=sub(x,b);
            k++;
        }
        j++;
        if(j<n1) x.push_back(a[j]);
        x.erase(0, x.find_first_not_of('0'));
        if(x=="") x="0";
        res.push_back(k+'0');
    }
    res.erase(0, res.find_first_not_of('0'));
    return x;
}
string sum(string a,string b){
    char k='0';
    int p=0,t;
    if(a.length()<b.length()){
       string temp=a;
       a=b;
       b=temp;
    }
    while(b.length()<a.length()){
       b.insert(0,"0",1);
    }

    string result="";
    for(int i=a.length()-1; i>=0  ;i--){
        t= (int)(a[i]-'0') + (int)(b[i] -'0') + p;
        p=t/10;
        t=t%10;
        result.push_back((char) (t + (int)k )) ;
     }
     if(p==1) result.push_back('1');

      reverse(result.begin(), result.end());
     return result;
}

int main(){
    int T;
    cin>>T;
    while(T--){
    string s;
    cin>>s;
    string c="2";
    while(c.length()<= (s.length()/2 +1)){
       if(c==s) {cout<<"Prime"; return 0;}
       if(rem(s,c)=="0"){ cout<<"Not a Prime"<<endl; return 0;}
       c=sum(c,"1");
   }
   cout<<"Prime"<<endl;}
   return 0;
}
