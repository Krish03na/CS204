#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
    
      lli T;
      cin>>T;
      while(T--)
      {
      string a, b;
      cin>>a >>b;
      if(a[0]=='0'|| b[0]=='0')
      {
        cout<<"0";
        return 0;
      }
      vector<lli>v1, v2;
      for(lli i=0; i<a.size(); i++)
        v1.push_back(a[i]- '0');
        
        
      for(lli i=0; i<b.size(); i++)
        v2.push_back(b[i]- '0');
        
        
      reverse(v1.begin(),v1.end());
      reverse(v2.begin(),v2.end());
      
      
      if(v1.size()< v2.size())
        swap(v1, v2);
        
      vector<lli>v3(v1.size()+v2.size(), 0);
        lli carry =0;
      for(lli i=0; i<v2.size(); i++){
          carry=0;
          
          for(lli j=0; j<v1.size(); j++){
            lli num = v3[i+j] + v1[j]*v2[i] + carry;
            v3[i+j]=num%10;
            if(num/10==0)
              carry=0;
            else
              carry = num/10;
          }
          
          if(carry!=0){
            v3[i+v1.size()]+= carry;
          }
        }
    
    
    reverse(v3.begin(), v3.end());
    lli i=0;
    
    for(i=0; i<v3.size(); i++){
      if(v3[i]!=0)
        break;
    }
    for(lli j=i; j<v3.size(); j++)
      cout<<v3[j];
    cout<<endl;
  }
}
