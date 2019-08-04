#include <bits/stdc++.h>

using namespace std;

int min(int x,int y){
if(x<y) return x;
else return y;}

int max(int x,int y){
if(x>y) return x;
else return y;}

string SUM(string a, string b){
int l1 = a.length();
int l2 = b.length();
string ans = "";

reverse(a.begin(), a.end());
reverse(b.begin(), b.end());

int carry = 0, sum = 0;
for(int i=0; i< min(l1, l2); i++){
sum = (a[i]-'0')+(b[i]-'0') + carry;
ans.push_back(sum%10+'0');
carry = sum/10;
}

for(int j=min(l1, l2); j< max(l1, l2); j++){
if(l2>l1) sum = (b[j]-'0')+carry;
else sum = (a[j]-'0')+carry;
ans.push_back(sum%10+'0');
carry = sum/10;
}
if(carry) ans.push_back(carry+'0');

reverse(ans.begin(), ans.end());
return ans;
}

int main(){

    int T;
    cin >> T;
    while(T--){
        string a, b;
        cin >> a;
        cin >> b;
        cout << SUM(a, b) << endl;}
return 0;
}
