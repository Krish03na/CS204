#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e6+5;
int visit[1000000]={0};
long long int mod = (ll)1e9+7;
ll parent[N],size[N];

void BFS(vector <vector <int> > adj, int v, int e, int i)
{
    queue<int> q;
    q.push(i);

    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        visit[x]=1;

        cout<<x<<" ";
        for(int ik=0;ik<adj[x].size();ik++)
        {

            if(visit[adj[x][ik]]==0)
            {
                q.push(adj[x][ik]);
                visit[adj[x][ik]]=1;
            }
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
    for(int i=0;i<v;i++){
        if(visit[i]==0)
        BFS(adj,v,e,i);
    }
}
