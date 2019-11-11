#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e6+5;
int visit[1000000]={0};
ll parent[N],size[N];

void DFS(vector <vector<int> > adj,int v,int e,int i)
{
        cout<<i<<" ";
        visit[i]=1;
        for(int ik=0;ik<adj[i].size();ik++)
        {
            if(visit[adj[i][ik]]==0)
            {
                DFS(adj,v,e,adj[i][ik]);
            }
        }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int> > adj(v);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<v;i++)
    {
        if(visit[i]==0)
        DFS(adj,v,e,i);
    }
}
