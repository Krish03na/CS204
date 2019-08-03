#include <bits/stdc++.h>
using namespace std;

bool smaller(string a, string b){
    int l1 = a.length();
    int l2 = b.length();

    if(l1<l2) return true;
    if(l2>l1) return false;

    for(int i=0; i<l1; i++){
        if(a[i]<b[i]) return true;
        else if(a[i]> b[i]) return false;
        else return false;
    }
}

string Diff(string a, string b){

if(smaller(a, b)) swap(a, b);


reverse(a.begin(), a.end());
reverse(b.begin(), b.end());

int l1 = a.length();
int l2 = b.length();

string ans = "";
int diff, carry=0;
for(int i=0; i< l2; i++){
    diff = (a[i]- '0') - (b[i]- '0');
    if(diff<0) {
        diff +=10;
        a[i+1]--;
    }
    ans.push_back(diff+'0');
}

for(int i=l2; i< l1; i++){
    diff = (a[i]- '0');
    ans.push_back(diff + '0');
}

reverse(ans.begin(), ans.end());
return ans;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << Diff(a, b) << endl;
    return 0;

}
