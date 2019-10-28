#include <bits/stdc++.h>

using namespace std;

bool bipartite(int v,  vector<int> arr[], vector<int>& visited, vector<int>& colour){

visited[v] = 1;
for(int i : arr[v]){

	if(!visited[i]){
		visited[i]=1;
		colour[i]=1-colour[v];
		if(!bipartite(i, arr, visited, colour)) return false;
	}else{
		if(colour[i]==colour[v]) return false;	
	}

}
return true;
}



int main(){
	int n, m;
	cin>>n>>m;
	vector<int> arr[n+1];
	vector<int> visited(n+1);
	vector<int> colour(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		
		arr[u].push_back(v);
		arr[v].push_back(u);	
	}
	for(int i=0; i<n; i++){
		if(visited[i+1]==0)
		if(!bipartite(i+1, arr, visited, colour)){ cout<<"NO\n"; return 0;}
	
	}
	cout<<"YES\n";
	return 0;
	
	

}
