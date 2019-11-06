#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define M 1000000007


struct Edge{
    int u,v,e;
    double log;
};

bool compare(Edge a,Edge b){
    return a.log > b.log;
}
int root(int a,vector<int> &ID)
{
    while(ID[a] != a)
    {
        ID[a] = ID[ID[a]];
        a = ID[a];
    }
    return a;
}

void Union(int x, int y,vector<int> &ID)
{
    int p = root(x,ID);
    int q = root(y,ID);
    ID[p] = ID[q];
}
double kruskals(vector<Edge> graph, vector<int> vis, vector<int> &ID){
    ll r=1;
    for(Edge x:graph){
        
        int e = x.e;
        int u = x.u;
        int v = x.v;
        if(root(u,ID)!=root(v,ID)){
            vis[u] = 1;
            vis[v] = 1; 
            
            
            Union(u,v,ID);
            r *= e;
            r = r%M;
        }
        
    }
    bool ctd=true;
    for(int i=1;i<vis.size();i++){
        if(vis[i]==0){
            ctd = false;
            break;
        }
    }
    if(true){
        return r;
    }
    
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> vis(n+1,0);
    vector<Edge> graph;
    int e,u,v;
    while(m--){
        cin>>u>>v>>e;
        double x = log(e);
        graph.push_back({u,v,e,x});
    }
    sort(graph.begin(),graph.end(),compare);
    vector<int> ID(n+1);
    for (long i = 0; i < n; i++) ID[i] = i;
    double res = kruskals(graph,vis,ID);
    cout<<res<<'\n'; 
    
    return 0;
}
