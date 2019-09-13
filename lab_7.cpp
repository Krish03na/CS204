#include <bits/stdc++.h>
using namespace std;

void Sort(string X[], string Y[], int N)
{
	pair <string, string> p[N];
	for(long long int i = 0; i < N; i++)
	{
		p[i].first = X[i];
		p[i].second = Y[i];
	}
	sort(p,p+N);
	for(long long int i = 0; i < N; i++)
	{
		X[i]=p[i].first;
		Y[i]=p[i].second;
	}
}

int main()
{
	
    int T;
    cin>>T;
    while(T--)
    {
    	int N,Max=0; cin>>N;
    	string X[N],Y[N];
    	for(long long int i = 0; i < N; i++)
    	{
    		cin>>X[i];
    		if(Y[i].size()>Max) Max=X[i].size();
    	}
    	for(long long int i = 0; i < N; i++)
    	{
    		Y[i]=X[i];
    		while(Y[i].size() <= Max+1) Y[i]+=Y[i];
    		Y[i]=Y[i].substr(0,Max+1);
    	}
    	Sort(Y,X,N);
    	reverse(X,X+N);

    	for(long long int i = 0; i < N; i++) cout<<X[i];
    	cout<<endl;
    }
    return 0;
}
